cards = []

with open('./inputs/4.txt', 'r') as file:
    for line in file:
        card = []
        # Remove the "Card X:" part
        line = line.split(': ', 1)[1]
        parts = line.strip().split('|')
        split_lists = [x.split() for x in parts]
        cleaned_lists = [[item for item in sublist if item.strip()] for sublist in split_lists]
        cards.append((cleaned_lists[0], cleaned_lists[1]))

def get_score(n):
    if n == 0:
        return 1
    else:
        return 2 * n

scores = []
for id, card in enumerate(cards):
    win, elf = card
    running_score = 0
    for n in elf:
        if n in win:
            running_score = get_score(running_score)
    scores.append(running_score)

print(sum(scores))