from itertools import combinations
inp = input()
inplist = sorted(inp.split())
inplist = [int(i) for i in inplist]
inplist = sorted(inplist)
for i in inplist:
    i = int(i)
x = list(combinations(inplist, 3))
for i in x:
    i = sorted(i)
outpts = {}

for i in x:
    outpts[i] = sorted([int(i[0]) , int(i[1]), int(i[2]), int(i[0]) + int(i[1]), int(i[0]) + int(i[2]), int(i[1]) + int(i[2]), int(i[0]) + int(i[1]) + int(i[2])])
for i in outpts:
    if sorted(outpts[i]) == sorted(inplist):
        x = sorted(i)
        print(str(x[0]) + " " + str(x[1]) + " " + str(x[2]))
        