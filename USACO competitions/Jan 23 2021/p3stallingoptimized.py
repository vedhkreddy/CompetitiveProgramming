import math
N = int(input())
array1 = input().split()
array2 = input().split()
for i in array1:
    i = int(i)
for i in range(N):
    i = int(i)

    
psres=[]
for i in array1:
    for j in range(len(array2)):
        if i > array2[j]:
            psres.append((i,j))
factorial = math.factorial(N)
part = factorial / N
mcount = 0
for i in psres:
    if i[1] == 0:
        mcount += part
        continue
    
