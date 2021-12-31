N = int(input())
cows=[]
plist = []
cowlist = {}
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
    cowlist[str(x)] = 0
    cowlist[str(y)] = 0
    cowlist[str(z)] = 0
    for z in range(N-3):
        x = input().split()
        cows.append(x)
        cowlist[str(x)] = 0
        cowcount = 0
        for i in cows:
            count = 0
            p1 = [i[0],str(int(i[1])+1)]
            p2 = [str(int(i[0])+1),i[1]]
            p3 = [i[0], str(int(i[1])-1)]
            p4 = [str(int(i[0])-1),i[1]]
            try:
                if cowlist[str(p1)] == 0:
                    count += 1
            except:
                pass
            try:
                if cowlist[str(p2)] == 0:
                    count += 1
            except:
                pass
            try:
                if cowlist[str(p3)] == 0:
                    count += 1
            except:
                pass
            try:
                if cowlist[str(p4)] == 0:
                    count += 1
            except:
                pass
            if count == 3:
                cowcount += 1
        plist.append(cowcount)
for i in plist:
    print(i)



"""
"""