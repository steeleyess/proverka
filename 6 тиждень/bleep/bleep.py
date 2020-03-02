from cs50 import get_string
from sys import argv
import os
import sys


def slovnik(filename):
    with open(filename, "r") as files:
        words = files.read()
        words = words.replace("\n", " ")
        words = words.strip()
        words = words.split(" ")
        return (words)


def main():
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        sys.exit(1)
    if not os.path.exists(argv[1]):
        print("Usage: python bleep.py dictionary")
        sys.exit(1)
    words = slovnik(argv[1])
    vvedit = get_string("What message would you like to censor?\n")
    vvedit1 = vvedit.split(" ")
    for lol in vvedit1:
        proverka = lol.lower()
        if proverka in words:
            print("*" * len(proverka), end=" ")
        else:
            print(lol, end=" ")
    print()


if __name__ == "__main__":
    main()