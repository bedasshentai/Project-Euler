from sympy import *
from itertools import *
from pwn import *

with open('cipher.txt', 'r') as f:
    ciphertext = f.readline().split(',')
    ciphertext = b''.join(chr(int(i)).encode('utf-8') for i in ciphertext)
    for key in product(string.ascii_lowercase, repeat=3):
        plaintext = xor(key, ciphertext)
        if plaintext.count(b'the') > 8:
            print(plaintext)
            ans = 0
            for s in plaintext:
                ans += s
            print(ans)