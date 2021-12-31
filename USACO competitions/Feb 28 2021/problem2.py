N = int(input())
cows=[]
plist = []
if N <= 3:
    for i in range(N):
        print(0)
else:
    x = input().split()
    y = input().split()
    z = input().split()   
    cows.append(x)
    cows.append(y)
    cows.append(z)
    plist.append(0)
    plist.append(0)
    plist.append(0)
    for i in x:
        i = int(i)
    for i in y:
        i = int(i)
    for i in z:
        i = int(i)
    for i in range(N-3):
        x = input().split()
        for i in x:
            i = int(i)
        cows.append(x)
        for i in cows:
            count = 0
            cowcount = 0
            for j in cows:
                if i == j:
                    continue
                else:
                    if i[1] == j[1] and (int(i[0]) == (int(j[0])+1 or int(j[0])-1)):
                        count += 1
                    elif i[0] == j[0] and (int(i[1]) == (int(j[1])+1 or int(j[1])-1)):
                        count += 1
            if count == 3:
                cowcount += 1
        plist.append(cowcount)
for i in plist:
    print(i)



