non = int(input())
info = []
il = 1
ids = []
squares = {}
for i in range(non):
    inf = input()
    linf = inf.split()
    info.append([il, linf[0], int(linf[1]), int(linf[2])])
    squares[il] = 1
    ids.append(il)
    il += 1
if len(info) == 1:
    print("Infinity")
    exit()
eaten = []
"""
def terminal(x):
    infinitysquares = []
    for i in x:
        inf = True
        for j in x:
            if inf == False:
                break
            if i[1] == j[1]:    
                continue
            else:
                if i[1] == "N" and j[2] > i[2]:
                    continue
                elif i[1] == "E" and j[3] > i[3]:
                    continue
                else:
                    inf = False
        if inf == False:
            break
    return inf
"""
x = 0
for i in info:
    eaten.append((i[2], i[3]))
while True:
    print(info)
    if len(info) == 0:
        break
    lag = terminal(info)
    if lag == True:
        for i in info:
            squares[i[0]] = "Infinity"
        break


    for i in info:
        if i[1] == "E":
            i[2] += 1
            if (i[2], i[3]) in eaten:
                print("got here")
                info.remove(i)
            else:
                if squares[i[0]] == "Infinity":
                    pass
                else:
                    squares[i[0]] += 1
                eaten.append((i[2], i[3]))
        if i[1] == "N":
            i[3] += 1
            if (i[2], i[3]) in eaten:
                print("got here")
                info.remove(i)
            else:
                if squares[i[0]] == "Infinity":
                    pass
                else:
                    squares[i[0]] += 1
                eaten.append((i[2], i[3]))
    x += 1
for i in ids:
    print(squares[i])    

