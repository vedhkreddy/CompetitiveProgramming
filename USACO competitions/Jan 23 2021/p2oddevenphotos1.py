def is_even(i):
    return (i % 2 == 0)
N = int(input())
biglist = input().split()
even = 0
odd = 0
for i in biglist:
    i = int(i)
    if is_even(i):
        even += 1
    else:
        odd += 1
while True:
    if even == odd or even == odd+1:
        break
    elif odd > even:
        odd -= 2
        even += 1
    else:
        even =- 1
        
print(even+odd)


