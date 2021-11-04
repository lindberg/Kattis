input = input() + ".."

for idx, c in enumerate(input):
    if c == ':' and (input[idx+1] == ')' or input[idx+1:idx+3] == "-)"):
        print(idx)
    if c == ';' and (input[idx+1] == ')' or input[idx+1:idx+3] == "-)"):
        print(idx)
