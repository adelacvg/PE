def f(n):
    ans=0
    while(n):
        ans+=n%10
        n//=10
    print(ans)
a = 2
b = 3
x = 2
for i in range(3,101):
    if i%3==0:
        a = x*b + a
        x+=2
    else:
        a = b + a
    a^=b
    b^=a
    a^=b
    print(b)
    f(b)
