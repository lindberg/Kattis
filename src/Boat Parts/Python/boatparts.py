p, n = [int(i) for i in input().split()]

list = []
days = 0
for _ in range(n):
    str = input()
    if not str in list:
        list.append(str)
    days += 1
    if len(list) == p:
        break

if len(list) < p:
    print("paradox avoided")
else:
    print(days)
