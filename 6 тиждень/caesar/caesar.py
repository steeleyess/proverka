import sys
from cs50 import get_string
from sys import argv
if len(argv) != 2:
    print("Usage: python caesar.py k ")
    sys.exit(1)
kod = int(argv[1])
kod %= 26
if kod < 0:
    print("Usage: python caesar.py k ")
    sys.exit(1)
vvid = get_string("plaintext:  ")
print("ciphertext: ", end="")
for c in vvid:
    symbol = ord(c)
    if symbol >= 97 and symbol <= 122:
        symbol += kod
        if symbol > 122:
            symbol -= 26
        print(chr(symbol), end="")
    elif symbol >= 65 and symbol <= 90:
        symbol += kod
        if symbol > 90:
            symbol -= 26
        print(chr(symbol), end="")
    else:
        print(chr(symbol), end="")
print()
sys.exit(0)





