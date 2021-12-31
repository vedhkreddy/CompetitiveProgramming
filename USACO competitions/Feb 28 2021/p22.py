def is_comfortable(cowlist, x, y):
    count = 0
    p1 = [str(x),str(y+1)]
    p2 = [str(x+1),str(y)]
    p3 = [str(x-1),str(y)]
    p4 = [str(x),str(y-1)]
    try:
        cowlist[str(p1)] == cowlist[str(p1)]
        count += 1

    except:
        pass
    try:
        cowlist[str(p2)] == cowlist[str(p2)]
        count += 1
    except:
        pass
    try:
        cowlist[str(p3)] == cowlist[str(p3)]
        count += 1
    except:
        pass
    try:
        cowlist[str(p4)] == cowlist[str(p4)]
        count += 1
    except:
        pass
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
        p1exists = False
        p2exists = False
        p3exists = False
        p4exists = False
        try:
            cowlist[str([str(x),str(y+1)])] = cowlist[str([str(x),str(y+1)])]
            p1exists = True
        except:
            pass
        try:
            cowlist[str([str(x+1),str(y)])] = cowlist[str([str(x+1),str(y)])]
            p2exists = True
        except:
            pass
        try:
            cowlist[str([str(x-1),str(y)])] = cowlist[str([str(x-1),str(y)])]
            p3exists = True
        except:
            pass
        try:
            cowlist[str([str(x),str(y-1)])] = cowlist[str([str(x),str(y-1)])]
            p4exists = True
        except:
            pass
        if p1exists:
            comfortable_already = cowlist[str([str(x),str(y+1)])]
            if is_comfortable(cowlist,x,y+1):
                if comfortable_already == 1:
                    pass
                else:
                    cowcount += 1
                cowlist[str([str(x),str(y+1)])] = 1
            else:
                if comfortable_already == 1:
                    cowlist[str([str(x),str(y+1)])] = 0
                    cowcount -= 1
        if p2exists:
            comfortable_already = cowlist[str([str(x+1),str(y)])]
            if is_comfortable(cowlist,x+1,y):
                if comfortable_already == 1:
                    pass
                else:
                    cowcount += 1
                cowlist[str([str(x+1),str(y)])] = 1
            else:
                if comfortable_already == 1:
                    cowlist[str([str(x+1),str(y)])] = 0
                    cowcount -= 1
        if p3exists:
            comfortable_already = cowlist[str([str(x-1),str(y)])]
            if is_comfortable(cowlist,x-1,y):
                if comfortable_already == 1:
                    pass
                else:
                    cowcount += 1
                cowlist[str([str(x-1),str(y)])] = 1
            else:
                if comfortable_already == 1:
                    cowlist[str([str(x-1),str(y)])] = 0
                    cowcount -= 1
        if p4exists:
            comfortable_already = cowlist[str([str(x),str(y-1)])]
            if is_comfortable(cowlist,x,y-1):
                if comfortable_already == 1:
                    pass
                else:
                    cowcount += 1
                cowlist[str([str(x),str(y-1)])] = 1
            else:
                if comfortable_already == 1:
                    cowlist[str([str(x),str(y-1)])] = 0
                    cowcount -= 1
        print(cowcount)
    