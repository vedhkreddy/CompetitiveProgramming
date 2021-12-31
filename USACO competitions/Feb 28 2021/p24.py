def is_comfortable(cowlist, x, y):
    count = 0
    if (x,y+1) in cowlist:
        count += 1
    if (x+1,y) in cowlist:
        count += 1
    if (x-1,y) in cowlist:
        count += 1
    if (x,y-1) in cowlist:
        count += 1

    if count == 3:
        return True

# setting up data structures
N = int(input())

plist = []
cowlist = {}
cowcount = 0
for i in range(N):
    count = 0
    pos = input().split()
    x = int(pos[0])
    y = int(pos[1])
    cowlist[(x,y)] = 0
    #Is this new cow comfortable?
    if is_comfortable(cowlist,x,y) == True:
        cowcount += 1
        cowlist[(x,y)] = 1
        
    if (x,y+1) in cowlist:
        comfortable_already = cowlist[(x,y+1)]
        if is_comfortable(cowlist,x,y+1):
            if comfortable_already != 1:
                cowcount += 1
            cowlist[(x,y+1)] = 1
        else:
            
            if comfortable_already == 1:
                cowlist[(x,y+1)] = 0
                cowcount -= 1

    if (x+1,y) in cowlist:
        comfortable_already = cowlist[(x+1,y)]
        if is_comfortable(cowlist,x+1,y):
            if comfortable_already != 1:
                cowcount += 1
            cowlist[(x+1,y)] = 1
        else:
            if comfortable_already == 1:
                cowlist[(x+1,y)] = 0
                cowcount -= 1

    if (x-1,y) in cowlist:
        comfortable_already = cowlist[(x-1,y)]
        if is_comfortable(cowlist,x-1,y):
            if comfortable_already != 1:
                cowcount += 1
            cowlist[(x-1,y)] = 1
        else:
            if comfortable_already == 1:
                cowlist[(x-1,y)] = 0
                cowcount -= 1

    if (x,y-1) in cowlist:
        comfortable_already = cowlist[(x,y-1)]
        if is_comfortable(cowlist,x,y-1):
            if comfortable_already != 1:
                cowcount += 1
            cowlist[(x,y-1)] = 1
        else:
            if comfortable_already == 1:
                cowlist[(x,y-1)] = 0
                cowcount -= 1

    print(cowcount)
    