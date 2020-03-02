from cs50 import get_float
coins = 0
while True:
    zdacha = get_float("Change owed: ")
    if zdacha >= 0:
        break
k = round(zdacha*100)
if k >= 25:
    n = k//25
    coins += n
    k %= 25
if k >= 10:
    n = k//10
    coins += n
    k %= 10
if k >= 5:
    n = k//5
    coins += n
    k %= 5
coins += k
print(coins)