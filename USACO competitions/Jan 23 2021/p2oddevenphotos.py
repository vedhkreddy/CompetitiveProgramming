def is_even(i):
    return (i % 2 == 0)
N = int(input())
biglist = input().split()
even = []
odd = []
for i in biglist:
    i = int(i)
    if is_even(i):
        even.append(i)
    else:
        odd.append(i)
while True:
    if len(even) == len(odd) or len(even) == len(odd)+1:
        break
    elif len(odd) > len(even):
        x = odd.pop()
        y = odd.pop()
        z = x + y
        even.append(z)
    else:
        x = even.pop()
        odd[0] += x
print(len(odd) + len(even))


