import re

pattern = r"mul\(\d{1,3},\d{1,3}\)"

longLine = ""

res = 0

with open('inp.txt', 'r') as file:
	data = file.read()
	for line in data:
		longLine += line
	split = longLine.rstrip().split("do()")
	for i in range(len(split)):
		secondSplit = split[i].split("don't()")
		for match in re.finditer(pattern, secondSplit[0]):
			x, y = map(int, match.group()[4:-1].split(","))
			res += x * y

print(res)