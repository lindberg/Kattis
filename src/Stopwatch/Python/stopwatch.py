n = int(input())

running = False
start = 0
time = 0

for i in range(n):
    if not running:
        start = int(input())
        running = True
    else:
        time += int(input()) - start
        running = False

if running:
    print("still running")
else:
    print(time)
