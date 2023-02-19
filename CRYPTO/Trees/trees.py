from flag import FLAG
import random

seed = 0xbeef
random.seed(seed)

xorvals = []
for i in range(0, len(FLAG)):
    xorvals.append(random.randint(1, 1000))

enc = []
for i in range(0, len(FLAG)):
    enc.append(ord(FLAG[i]) ^ xorvals[i])

print(enc)