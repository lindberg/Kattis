n = int(input())

list = []
for _ in range(n):
    list.append(input())

score = 0;
for i in range(len(list)-1):
    if list[i] == list[i+1]:
        score += 1;

print(score)
