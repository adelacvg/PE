def sum(n):
    s=0
    while n:
        s+=n%10
        n//=10
    return s

def factorial(n):
    a=1
    for i in range(1,n+1):
        a*=i
    return a

x=sum(factorial(100))
print(x)
