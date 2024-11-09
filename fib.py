from math import sqrt


def fibonacci_iterative(n):
    return ( ( (1 + sqrt(5)) / 2 )**n - ( (1 - sqrt(5)) / 2 )**n ) / sqrt(5)

n = int(input())
print(fibonacci_iterative(n)) 


