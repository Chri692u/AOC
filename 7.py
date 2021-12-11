def findAlignment1(alignment):
	global input
	fuel = 0

	for i in input:
		fuel = fuel + abs(i - alignment)

	return fuel

def partOne():
	global input
	global alignmentCosts
	
	for i in input:
		alignmentCosts.append(findAlignment1(i))



input = []
alignmentCosts = []

file = open("./inputs/7.txt", "r")
content = file.read()
for i in content.split(","):
	input.append(int(i))
file.close()

partOne()
print(min(alignmentCosts))
