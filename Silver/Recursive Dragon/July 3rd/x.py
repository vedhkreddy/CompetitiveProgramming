with open("herding.in", "r") as fin:
    a, b, c = map(int, fin.readline().split())
if a > b:
    a, b = b, a
if b > c:
    b, c = c, b
if a > b:
    a, b = b, a

with open("herding.out", "w") as fout:
    if c == a + 2:
        fout.write("0\n")
    elif b == a + 2 or c == b + 2:
        fout.write("1\n")
    else:
        fout.write("2\n")
    fout.write(str(max(b - a, c - b) - 1) + "\n")