N = input().split()
import itertools
lstrl = []
id = 0
for i in range(int(N[0])):
    j = input()
    idj = list(j)
    for iter in range(len(idj)):
        if idj[iter] == "C":
            idj[iter] = idj[iter] + str(id)
            id += 1
    lstrl.append(l  ist(idj))

friendships = []
    

count = 0
row = 0

for iunjoined in lstrl:
    gthere = True
    while gthere == True:
        i = "".join(iunjoined)
        ind = i.find("G")

        if ind == -1:

            gthere = False
        else:
            adjacentcount = 0
            adj1c = True
            adj2c = True
            adj3c = True
            adj4c = True
            cowsadjacent = []
            if row == 0:
                if ind == 0:
                    adj1 = lstrl[row+1][ind]
                    adj2 = lstrl[row][ind+1]
                    adj3 = '.'
                    adj4 = '.'
                elif ind == int(N[1]) - 1:
                    adj1 = lstrl[row+1][ind]
                    adj2 = "."
                    adj3 = "."
                    adj4 = lstrl[row][ind-1]  
                else:
                    adj1 = lstrl[row+1][ind]
                    adj2 = "."
                    adj3 = lstrl[row][ind+1]
                    adj4 = lstrl[row][ind-1]
            elif row == int(N[0]) - 1:
                if ind == 0:
                    adj1 = '.'
                    adj2 = lstrl[row-1][ind]
                    adj3 = lstrl[row][ind+1]
                    adj4 = '.'
                elif ind == int(N[1]) - 1:
                    adj1 = '.'
                    adj2 = lstrl[row-1][ind]
                    adj3 = "."
                    adj4 = lstrl[row][ind-1]
                else:
                    adj1 = '.'
                    adj2 = lstrl[row-1][ind]
                    adj3 = lstrl[row][ind+1]
                    adj4 = lstrl[row][ind-1]
            else:
                if ind == 0:
                    adj1 = lstrl[row+1][ind]
                    adj2 = lstrl[row-1][ind]
                    adj3 = lstrl[row][ind+1]
                    adj4 = '.'
                elif ind == int(N[1]) - 1:
                    adj1 = lstrl[row+1][ind]
                    adj2 = lstrl[row-1][ind]
                    adj3 = "."
                    adj4 = lstrl[row][ind-1]
                else:
                    adj1 = lstrl[row+1][ind]
                    adj2 = lstrl[row-1][ind]
                    adj3 = lstrl[row][ind+1]
                    adj4 = lstrl[row][ind-1]

            if adj1[0] == "C":
                adjacentcount += 1
                cowsadjacent += adj1
            if adj2[0] == "C":
                adjacentcount += 1
                cowsadjacent += adj2
            if adj3[0] == "C":
                adjacentcount += 1
                cowsadjacent += adj3
            if adj4[0] == "C":
                adjacentcount += 1
                cowsadjacent += adj4
            
            if adjacentcount >= 2:
                if len(cowsadjacent) > 2:
                    combs = itertools.combinations(cowsadjacent, 2)
                    for combination in combs:
                        if combination not in friendships:
                            friendships.append(i)
                            count += 1
                else:
                    if tuple(cowsadjacent) not in friendships:
                        friendships.append(tuple(cowsadjacent))
                        count += 1
            lstrl[row][ind] = "."
    row += 1

print(count)
