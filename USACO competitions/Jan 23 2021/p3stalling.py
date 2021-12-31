import itertools
N = int(input())
array1 = input().split()
array2 = input().split()
perms = itertools.permutations(array1)
count = 0
for i in perms:
    notgood = False
    for j in range(N):
        if int(i[j]) > int(array2[j]):
            notgood = True
            break
    if notgood == False:
        count += 1
print(count)