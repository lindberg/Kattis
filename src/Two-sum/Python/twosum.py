import sys

for line in sys.stdin:
    numbers = [int(digit) for digit in line.split()]
    print(sum(numbers))
