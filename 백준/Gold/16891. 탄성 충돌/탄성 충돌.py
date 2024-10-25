from fractions import Fraction

N = int(input())
m1 = Fraction(1, 1)
m2 = Fraction(N * N, 1)

x1 = (m1 - m2) / (m1 + m2)
y1 = (m2 + m2) / (m1 + m2)
x2 = (m1 + m1) / (m1 + m2)
y2 = (m2 - m1) / (m1 + m2)

u1 = Fraction(0, 1)
u2 = Fraction(-1, 1)
col = 0

while True:
    # Collision of A and B
    col += 1

    # New Velocity
    v1 = x1 * u1 + y1 * u2
    v2 = x2 * u1 + y2 * u2
    u1, u2 = v1, v2

    if u1 == 0: 
        break

    # Collision with Wall
    if u1 < 0:
        u1 = abs(u1)
        col += 1

    if u2 > 0 and u1 <= u2: break

print(col)
