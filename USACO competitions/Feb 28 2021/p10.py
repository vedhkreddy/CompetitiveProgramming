N = int(input())
commands=[]
animals = {"Ox":0, "Tiger":1, "Rabbit":2, "Dragon":3, "Snake":4, "Horse":5, "Goat":6, "Monkey":7, "Rooster":8, "Dog":9, "Pig":10, "Rat":11}
for i in range(N):
    inp = input().split()
    commands.append(inp)
bessiecmds = []
cows={"Bessie":[0,"Ox"]}
for i in commands:
    if i[7] == "Bessie":
        bessiecmds.append(i)
    cows[i[0]] = [0,i[4]]
for i in commands:
    curcow = i[0]
    action = i[3]
    animal = i[4]
    ocurcow = i[7]
    ocuranimal2 = cows[ocurcow]
    ocuranimal1 = ocuranimal2[1]
    ocuranimal = animals[ocuranimal1]
    if action == "previous":
        if ocuranimal < animals[animal]:
            froms = -1*(12-animals[animal]+ocuranimal)
        else:
            froms = ocuranimal - animals[animal]
    else:
        if animals[animal]<ocuranimal:
            froms = 12-ocuranimal+animals[animal]
        else:
            froms = animals[animal] - ocuranimal
    cows[curcow][0]=cows[i[7]][0]+froms
print(abs(cows["Elsie"][0]))
