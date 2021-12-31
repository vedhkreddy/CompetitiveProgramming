alphabet = input()
string = input()
looking = 0
rotations = 0
for i in alphabet*1001:
    if i == string[looking]:
        looking += 1
        if looking == len(string):
            rotations += 1
            break
    if i == alphabet[25]:
        rotations+= 1
print(rotations)