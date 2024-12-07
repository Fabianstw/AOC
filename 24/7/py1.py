from itertools import product


def checkSum(goal, values):
	for comb in product(['+', '*'], repeat=len(values) - 1):
		tmp = values[0]
		for i in range(1, len(values)):
			if comb[i - 1] == '+':
				tmp += values[i]
			else:
				tmp *= values[i]
		if tmp == goal:
			return True
	return False


res = 0
with open('inp.txt', 'r') as file:
	for line in file:
		line = line.strip()
		key, value = line.split(': ', 1)
		numbers = list(map(int, value.strip().split()))
		if checkSum(int(key), numbers):
			res += int(key)
		

print(f"Result: {res}")