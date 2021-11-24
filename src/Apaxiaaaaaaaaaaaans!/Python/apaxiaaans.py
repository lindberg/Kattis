chars = [c for c in input()]

list = [chars[0]]
for i in range(1, len(chars)):
    if list[len(list)-1] != chars[i]:
        list.append(chars[i])

print(''.join(list))
