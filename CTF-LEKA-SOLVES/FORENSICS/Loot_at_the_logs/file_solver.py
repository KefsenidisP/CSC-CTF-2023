from base64 import * 
import time

data = open("system.log","r")
out = open("out.txt","w")

for i in data:
    out.write(i[40:])
data.close()
out.close()
time.sleep(1)

out = open("out.txt","r")
for i in out:
    try:
        flag = b64decode(i)
        if(flag.find(b'CSC')>=0):
            print("\n",flag,"\n")
            break
    except:
        continue
