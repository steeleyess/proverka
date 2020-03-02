import sys
from sys import argv
from cs50 import get_string


def main():
    if len(argv) != 2 or argv[1].isalpha() == False:
        print("Usage: python vigenere.py k ")
        sys.exit(1)
    vvid = get_string("plaintext:  ")
    i1 = 0
    print("ciphertext: ", end="")
    for i in range(len(vvid)):
        symbol1 = ord(vvid[i])
        k = (i-i1) % len(argv[1])
        if symbol1 >= 97 and symbol1 <= 122:
            symbol1 += hesh(argv[1][k])
            if symbol1 > 122:
                symbol1 -= 26
            print(chr(symbol1), end="")
        elif symbol1 >= 65 and symbol1 <= 90:
            symbol1 += hesh(argv[1][k])
            if symbol1 > 90:
                symbol1 -= 26
            print(chr(symbol1), end="")
        else:
            print(chr(symbol1), end="")
            i1 += 1
    print()
    return 0


def hesh(char):
    char1 = ord(char)
    if char1 >= 97 and char1 <= 122:
        return (char1-97)
    else:
        return (char1-65)


if __name__ == "__main__":
    main()