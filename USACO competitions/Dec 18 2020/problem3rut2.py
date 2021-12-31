numcows = int(input())
cowinfo = []
squares_eaten = {}
esquaresrow = {}
esquarescolumn = {}
for cowid in range(numcows):
    cow = str(input()).split()
    # entering the direction, coordinates, num of squares eaten, and current state(not_stopped, stopped, or infinity)
    currentcowinfo = [cow[0], int(cow[1]), int(cow[2]), 1, "not_stopped"]
    squares_eaten[str((currentcowinfo[1], currentcowinfo[2]))] = True
    cowinfo.append(currentcowinfo)

def allinf(info):
    for cow in info:
        for cow1 in info:
            if cow[0] == cow1[0]:
                continue
            if cow[0] == "N":
                if cow[2] < cow1[2]:
                    return False
                for i in esquaresrow[cow[2]]:
                    if i > cow[1]:
                        return False
                continue
            else:
                if cow[2] > cow1[2]:
                    return False
                for i in esquarescolumn[cow[1]]:
                    if i > cow[2]:
                        return False
                continue
    return True
        
while True:
    if allinf(cowinfo):
        for cow in cowinfo:
            cow[3] = "Infinity"
        break
    for cow in cowinfo:
        if cow[0] == "N" and cow[4] == "not_stopped":
            try:
                if squares_eaten[str((cow[1],cow[2]+1))] == True:
                    cow[4] == "stopped"
                    continue
            except(KeyError):
                cow[3] += 1
                cow[2] += 1
                squares_eaten[str((cow[1],cow[2]))] = True
               try:                                                                      
                    esquarescolumn[cow[1]].append(cow[2])
                except:
                    esquarescolumn[cow[1]] = [cow[2]]
                try:
                    esquarescolumn[cow[2]].append(cow[1])
                except:
                    esquarescolumn[cow[2]] = [cow[1]]
            
        if cow[0] == "E" and cow[4] == "not_stopped":
            try:
                if squares_eaten[str((cow[1]+1,cow[2]))] == True:
                    cow[3] += 1
                    cow[4] = "stopped"
                    continue
            except(KeyError):
                cow[3] += 1
                cow[1] += 1
                squares_eaten[str((cow[1],cow[2]))] = True
                try:
                    esquarescolumn[cow[1]].append(cow[2])
                except:
                    esquarescolumn[cow[1]] = [cow[2]]
                try:
                    esquarescolumn[cow[2]].append(cow[1])
                except:
                    esquarescolumn[cow[2]] = [cow[1]]
    print(cowinfo)
for i in cowinfo:
    print(i[3])
