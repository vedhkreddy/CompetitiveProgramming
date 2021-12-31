# Initialization of Variables
numcows = int(input())
info = []
eaten = []
for cid in range(numcows):
   cow = str(input()).split()
   # entering the direction, coordinates, num of squares eaten, and current state(not_stopped, stopped, or infinity)
   cinfo = [cow[0], int(cow[1]), int(cow[2]), 0, "not_stopped"]
   eaten.append([(cinfo[1], cinfo[2]), (cinfo[1], cinfo[2])])
   info.append(cinfo)

# Infinity check for a cow function
def isinfinity(inpcow, info, eaten):
    inf = True

    if inpcow[4] == "stopped" or inpcow[4] == "Infinity":
        return False
    if inpcow[0] == "N":
        for cow in info:
            if cow[0] == "E":
                if inpcow[2] < cow[2]:
                    inf = False
                    break
    if inpcow[0] == "E":
        for cow in info:
            if cow[0] == "N":
                if inpcow[1] < cow[1]:
                    inf = False
                    break
    return inf

#Main Loop
end = False
i = 0
while end == False:
    #checking if all cows are stopped or are infinity
    end = True
    for cow in info:
        if cow[4] == "not_stopped":
            end = False
            break
    #move the cow
    curid = 0
    for cow in info:
        # if stopped don't eat further and just go the next cow
        if cow[4] == "stopped":
            continue
        # else just eat and change the position of the cow
        if cow[3] != "Infinity":
            cow[3] += 1
        if cow[0] == "N":
            cow[2] += 1
        else:      
            cow[1] += 1
        eaten[curid][1] = (cow[1], cow[2])
        curid += 1
    for cow in info:
        # if the cow lands on an eaten square, then just stop the cow and it won't be increased on the next iteration
        for patches in eaten:
            if cow[0] == "E":
                if (cow[1], cow[2]) in eaten.keys():
                    cow[4] = "stopped"
        # check for infinity cow
    for cow in info:                                             
        if isinfinity(cow, info, eaten) == True:
            cow[4] = "infinity"
            cow[3] = "Infinity"

    #i += 1
    #print(info)

for cow in info:
    print(cow[3])
        
    


        