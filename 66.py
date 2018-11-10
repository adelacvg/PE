import math
res = 0
ans = 0
for i in range(2,1001):
    q = math.floor(math.sqrt(i))
    if (q*q)==i:
        continue
    s = i
    a=q
    m=0
    d=1
    n1=1
    n2=a
    d1=0
    d2=1
    while n2*n2-i*d2*d2!=1:
        m=a*d-m
        d=(s-m*m)//d
        a=math.floor((math.sqrt(i)+m)/d)
        t1=n2
        t2=d2
        n2=a*n2+n1
        d2=a*d2+d1
        n1=t1
        d1=t2
    if n2>ans:
        ans=n2
        res=i
print(res)

