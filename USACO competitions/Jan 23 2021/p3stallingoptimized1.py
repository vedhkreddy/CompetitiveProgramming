N = int(input())
cows1 = input().split()
stalls1 = input().split()
cows = []
stalls = []
for i in cows1:
    cows.append(int(i))
for i in stalls1:
    stalls.append(int(i))

cows.sort()
stalls.sort()
cows.reverse()
stalls.reverse()

cannot_go = {}
for i in cows:
    cannot_go[str(i)] = 0
    for j in stalls:
        if j < i:
            cannot_go[str(i)] += 1

minuscount = 0
plist = []
for i in cows:
    plist.append(N-cannot_go[str(i)]-minuscount)
    minuscount += 1

start = plist.pop()
for i in plist:
    start *= i
print(start)