from cs50 import get_string
count = 0
k = 1
while k > 0:
    m = 0
    nomer = get_string("Number: ")
    for c in nomer:
        if ord(c) < 48 or ord(c) > 57:
            m += 1
    k = m
if len(nomer) == 15 and nomer[0] == "3" and (nomer[1] == "4" or nomer[1] == "7"):
    for d in range(len(nomer)):
        l = int(nomer[d])
        if d % 2 == 1:
            if l >= 5:
                l *= 2
                l = l % 10 + 1
                count += l
            else:
                l *= 2
                count += l
        else:
            count += l
    if count % 10 == 0:
        print("AMEX")
    else:
        print("INVALID")
elif len(nomer) == 16 and nomer[0] == "5" and (nomer[1] == "1" or nomer[1] == "2" or nomer[1] == "3" or nomer[1] == "4" or nomer[1] == "5"):
    for d in range(len(nomer)):
        l = int(nomer[d])
        if d % 2 == 1:
            count += l
        else:
            if l >= 5:
                l *= 2
                l = l % 10+1
                count += l
            else:
                l *= 2
                count += l
    if count % 10 == 0:
        print("MASTERCARD")
    else:
        print("INVALID")
elif len(nomer) == 16 and nomer[0] == "4":
    for d in range(len(nomer)):
        l = int(nomer[d])
        if d % 2 == 1:
            count += l
        else:
            if l >= 5:
                l *= 2
                l = l % 10+1
                count += l
            else:
                l *= 2
                count += l
    if count % 10 == 0:
        print("VISA")
    else:
        print("INVALID")
elif len(nomer) == 13 and nomer[0] == "4":
    for d in range(len(nomer)):
        l = int(nomer[d])
        if d % 2 == 1:
            if l >= 5:
                l *= 2
                l = l % 10 + 1
                count += l
            else:
                l *= 2
                count += l
        else:
            count += l
    print(count)
    if count % 10 == 0:
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")


