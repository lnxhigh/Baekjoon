import math
N = int(input())

# Pell's Equation
B, C, D, E = 1, 2, 3, 1
while math.log10(D) <= N:
    D, B = 3 * D + 8 * B, D + 3 * B

print(B, C)
print(D, E)
