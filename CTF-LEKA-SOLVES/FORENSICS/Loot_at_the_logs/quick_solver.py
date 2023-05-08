from base64 import *

data = open("system.log","r")

for i in data:
    try:
        flag = b64decode(i[40:])
        if(flag.find(b'CSC{')>=0):
            print("\nFLAG = ",flag,"\n")
            break
    except:
        continue
