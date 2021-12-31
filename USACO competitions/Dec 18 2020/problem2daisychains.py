N = int(input())
nlflowers = input()
count = 0
nflowers = nlflowers.split()
flowers = []
for i in nflowers:
    flowers.append(int(i))
tc  = []
indexposition = 0
lenth = 1
while indexposition < len(flowers):

    if lenth > len(flowers):
        indexposition += 1
        lenth = indexposition + 1
    tc.append(flowers[indexposition:lenth])
    lenth += 1
tc.remove([])
for i in tc:
    avrg = 0
    cnt = 0
    for j in i:
        avrg += j
    avrg = avrg/len(i)
    alread = False
    for j in i:
        if j == avrg and alread == False:

            count += 1
            alread = True
print(count)
    
