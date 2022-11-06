a = input().partition(' ')
day = 0
for i in range(1,int(a[0])):
    if i in [1,3,5,7,8,10,12] :
        day = day + 31
    elif i == 2 :
        day = day + 28
    elif i in [4,6,9,11] :
        day = day + 30

day = day + int(a[2])
if day % 7 == 0 :
    print("SUN")
elif day % 7 == 1 :
    print("MON")
elif day % 7 == 2 :
    print("TUE")
elif day % 7 == 3 :
    print("WED")
elif day % 7 == 4 :
    print("THU")
elif day % 7 == 5 :
    print("FRI")
elif day % 7 == 6 :
    print("SAT")