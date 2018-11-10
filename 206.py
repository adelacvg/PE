import math
def f(n):
    return not all(int(str(n)[x*2]) == x+1 for x in range(9))

n = math.ceil(math.sqrt(19293949596979899))
while f(n*n): n-=2

print(n*10)
