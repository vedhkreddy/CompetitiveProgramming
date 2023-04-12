t = int(input())
for y in range(t):
    n = int(input())
    x = int((((n) * (n + 1) * (2*n + 1) / 6 + (n-1) * (n) * (n + 1) / 3) * 2022) % 1000000007)
    print(x)