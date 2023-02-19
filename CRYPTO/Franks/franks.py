# This code was created by Geeks for Geeks.
# I modified a little bit though.

from flag import FLAG

def keygen(dectxt, key):
    txtlen = len(dectxt)
    keylen = len(key)
    
    if txtlen == keylen:
        return key

    else:
        key = list(key)
        for i in range(0, txtlen - keylen):
            key.append(key[i % keylen])
            keylen += 1

    return("".join(key))

def enctxt(dectxt, key):
    enctxt = []
    dectxtlen = len(dectxt)

    for i in range(0, dectxtlen):
        enchr = chr(((ord(dectxt[i]) + ord(key[i])) % 26) + ord('A'))
        enctxt.append(enchr)

    return("".join(enctxt))

keyword = FLAG[:4]
key = keygen(FLAG, keyword)
encflag = enctxt(FLAG, key)

print(encflag)