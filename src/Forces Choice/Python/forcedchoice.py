n,p,s = [int(i) for i in input().split()]

for _ in range(s):
    cards = [int(i) for i in input().split()]
    cards.remove(cards[0])
    if p in cards:
        print("KEEP")
    else:
        print("REMOVE")
