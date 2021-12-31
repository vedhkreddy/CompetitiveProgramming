def is_comfortable(cowlist, x, y):
    count = 0
    p1 = [str(x),str(y+1)]
    p2 = [str(x+1),str(y)]
    p3 = [str(x-1),str(y)]
    p4 = [str(x),str(y-1)]
    if str(p1) in cowlist:
        count += 1

    if str(p2) in cowlist:
        count += 1
    
    if str(p3) in cowlist:
        count += 1

    if str(p4) in cowlist:
        count += 1

    if count == 3:
        return True

# setting up data structures
N = int(input())

plist = []
cowlist = {}
#A cow can't be adject to 3 other cows when there are only two other cows or less
if N <= 3:
    for i in range(N):
        print(0)
else:
    #getting first three inputs
    inp1 = input().split()
    inp2 = input().split()
    inp3 = input().split()   
    print(0)
    print(0)
    print(0)
    cowlist[str(inp1)] = 0
    cowlist[str(inp2)] = 0
    cowlist[str(inp3)] = 0
    cowcount = 0
    for i in range(N-3):
        count = 0
        pos = input().split()
        cowlist[str(pos)] = 0
        x = int(pos[0])
        y = int(pos[1])
        #Is this new cow comfortable?
        if is_comfortable(cowlist,x,y) == True:
            cowcount += 1
            cowlist[str(pos)] = 1
            
        if str([str(x),str(y+1)]) in cowlist:
            comfortable_already = cowlist[str([str(x),str(y+1)])]
            if is_comfortable(cowlist,x,y+1):
                if comfortable_already != 1:
                    cowcount += 1
                cowlist[str([str(x),str(y+1)])] = 1
            else:
                if comfortable_already == 1:
                    cowlist[str([str(x),str(y+1)])] = 0
                    cowcount -= 1

        if str([str(x+1),str(y)]) in cowlist:
            comfortable_already = cowlist[str([str(x+1),str(y)])]
            if is_comfortable(cowlist,x+1,y):
                if comfortable_already != 1:
                    cowcount += 1
                cowlist[str([str(x+1),str(y)])] = 1
            else:
                if comfortable_already == 1:
                    cowlist[str([str(x+1),str(y)])] = 0
                    cowcount -= 1

        if str([str(x-1),str(y)]) in cowlist:
            comfortable_already = cowlist[str([str(x-1),str(y)])]
            if is_comfortable(cowlist,x-1,y):
                if comfortable_already != 1:
                    cowcount += 1
                cowlist[str([str(x-1),str(y)])] = 1
            else:
                if comfortable_already == 1:
                    cowlist[str([str(x-1),str(y)])] = 0
                    cowcount -= 1

        if str([str(x),str(y-1)]) in cowlist:
            comfortable_already = cowlist[str([str(x),str(y-1)])]
            if is_comfortable(cowlist,x,y-1):
                if comfortable_already != 1:
                    cowcount += 1
                cowlist[str([str(x),str(y-1)])] = 1
            else:
                if comfortable_already == 1:
                    cowlist[str([str(x),str(y-1)])] = 0
                    cowcount -= 1

        print(cowcount)
    