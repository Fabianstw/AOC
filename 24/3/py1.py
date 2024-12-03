import re

pattern = r"mul\(\d{1,3},\d{1,3}\)"

lines = []

res = 0

with open('inp.txt', 'r') as file:
	data = file.readlines()
	for line in data:
		for match in re.finditer(pattern, line.rstrip()):
			x, y = map(int, match.group()[4:-1].split(","))
			res += x * y
			
print(res)