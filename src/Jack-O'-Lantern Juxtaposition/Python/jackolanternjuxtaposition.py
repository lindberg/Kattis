numbers = [int(digit) for digit in input().split()]

prod = 1
for digit in numbers:
    prod *= digit

print(prod)