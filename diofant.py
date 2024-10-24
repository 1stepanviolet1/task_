

def extended_gcd(a, b):
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = extended_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y

def solve_diophantine(a, b, c):
    gcd, x0, y0 = extended_gcd(abs(a), abs(b))
    
    print(f"{gcd=}")
    
    #if gcd == 1: return "Нет решений"

    if c % gcd != 0:
        return "Нет решений"
    
    x0 *= c // gcd
    y0 *= c // gcd
    
    if a < 0:
        x0 = -x0
    if b < 0:
        y0 = -y0
    
    k_x0 = abs(b) // gcd
    while x0 < 0:
        x0 += k_x0
    while x0 > k_x0:
        x0 -= k_x0
    
    k_y0 = abs(a) // gcd
    while y0 < 0:
        y0 += k_y0
    while y0 > k_y0:
        y0 -= k_y0
        
    return x0, y0

a, b, c = map(int, input().split())

result = solve_diophantine(a, b, c)

if result == "Нет решений":
    print(result)
else:
    x0, y0 = result
    print(f"{x0} {y0}")


