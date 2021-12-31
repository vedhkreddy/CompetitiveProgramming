N = input().split()
ustrl = []
lstrl = []

for i in range(int(N[0])):
    j = input()
    ustrl.append(j)
    lstrl.append(list(j))

count = 0

for i in ustrl:
    if i.find("CGC") != -1:
        count += 1

dstrl = []

firstr = True
for i in ustrl:
    
    if firstr == True:
        for j in i:
            dstrl.append(j)
        firstr = False
    else:
        c = 0
        for j in i:
            dstrl[c] += j
            c += 1

ready = True
for i in dstrl:
    ready = True
    while ready == True:
        if i.find("CGC") != -1:
            count += 1
        else:
            ready = False

row = 0
print("gothere")
for iunj in lstrl:
    i = "".join(iunj)
    print(i)
    allg = None
    while allg != True:
        ct = 010
        x = i.find("G")
        if x == -1:
            allg = True
            print("gothere")
        else:
            first = lstrl[row][x + 1]
            second = lstrl[row][x - 1]
            third = lstrl[row + 1][x]
            fourth = lstrl[row - 1][x]

            if first == "C":
                ct += 1
            if second == "C":
                ct += 1
            if third == "C":
                ct += 1
            if fourth == "C":
                ct += 1
            
            if ct == 2:
                count += 1

            del lstrl[row][x]
            lstrl[row].insert(x,['.'])

print(count)


    
