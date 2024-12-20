left = []
right = []

with open('inp.txt', 'r') as file:
	data = file.readlines()
	for line in data:
		sp = line.rstrip().split("  ")
		left.append(int(sp[0]))
		right.append(int(sp[1]))
		
leftS = set(left)
dist = 0
for l in leftS:
	dist += l * right.count(l)
	
print(dist)