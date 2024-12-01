left = []
right = []

with open('inp.txt', 'r') as file:
    data = file.readlines()
    for line in data:
        sp = line.rstrip().split("  ")
        left.append(int(sp[0]))
        right.append(int(sp[1]))
        
        
left.sort()
right.sort()

dist = 0

for i in range(0, len(left)):
    dist += abs(right[i] - left[i])
    
print(dist)