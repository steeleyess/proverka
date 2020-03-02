from cs50 import get_int
while True:
    n = get_int("Height: ")
    if n>=1 and n<=8:
        break
k = n-1
for i in range(n):
    print(" " *k, end="")
    print("#" *(i+1))
    k-=1
