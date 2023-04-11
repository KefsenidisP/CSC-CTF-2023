from Crypto.Util.number import *
import colorama
from colorama import Fore, Style
import time

FLAG = b"CSC{f4k3_fl3g_3xampl3_12345}"

def menu():
    p,q,N,e = get_secure_rsa()
    print(Fore.GREEN+"\nHell0 Fri3nd!\n")
    while True:
        print(Fore.GREEN+"[0] Give a custome flag?")
        print("[1] Tell me a scecret!")
        print("[2] Print public_(fake)_keyz!")
        print("[3] Exit")
        option = int(input("\n> "))
        if (option==0):
            flag = input("flag: ")
            flag = bytes_to_long(bytes(flag,'utf-8'))
            enc_flag = pow(flag,e,N)
            print(f"\nYour encrypted flag is : {enc_flag}\n")
        elif (option==1):
            print("\nI don't have much time you have to hurry friend\n")
            time.sleep(2)
            print("What I am about to tell you is TOP SECRET\n")
            time.sleep(2)
            print(f"Only the 1% knows about this : {hex(p)}")
            time.sleep(2)
            print(f"{Fore.RED}\nTHEY are after me\nFIND THE FLAG AS QUICK AS POSSIBLE!\n\n")
            time.sleep(2)
        elif (option==2):
            print("\nN = ",N,"\n")
            print("e = ",e,"\n")
        elif (option==3):
            print("\nDont leave me here :(\n")
            exit(1)
        else:
            print("\nWrong Option!\n")
            exit(1)

def get_secure_rsa():
    p = getPrime(1024)
    q = getPrime(1024)
    N = p*q
    e = 0x10001
    enc_p = p - 100 << 1
    phi = (p-1)*(q-1)
    d = inverse(e,phi)
    return enc_p,q,N,e

menu()
