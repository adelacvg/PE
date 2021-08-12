import random
import bisect
import math
import itertools
def sieve(limit):
    a = [True]*limit
    a[0] = a[1]=False
    for (i,isprime) in enumerate(a):
        if isprime:
            yield i
            for n in range(i*i,limit,i):
                a[n]=False
def power(x,y,p):
    res=1
    x = x%p
    while y>0:
        if y&1:
            res = (res*x)%p
        y=y>>1
        x = (x*x)%p
    return res
def miillerTest(d,n):
    a = 2+random.randint(10,10000000)%(n-4)
    x = power(a,d,n)
    if x==1 or x==n-1:
        return True;
    while d!=n-1:
        x=(x*x)%n
        d*=2
        if x==1:
            return False
        if x==n-1:
            return True
    return False
def isPrime(n,k):
    if n<=1 or n==4:
        return False
    if n<=3:
        return True
    d = n-1
    while d%2==0:
        d//=2
    for i in range(0,k):
        if miillerTest(d,n) == False:
            return False
    return True
limit = 10**12
ham=[]
p=[]
for two in [2**x for x in range(0,int(math.log(limit,2))+1) if 2**x<=limit]:
    for three in [3**x for x in range(0,int(math.log(limit,3))+1) if two*(3**x)<=limit]:
        for five in [5**x for x in range(0,int(math.log(limit,5))+1) if two*three*(5**x)<=limit]:
            cur = two*three*five
            #print(cur)
            ham.append(cur)
            if isPrime(cur+1,6) and cur>5:
                p.append(cur+1)
ham.sort()
p.sort()
print("ham size",len(ham))
print("prime size",len(p))
todo=[[1,1],]
Sum=0
while todo:
    num = todo[-1][0]
    largestPrime = todo[-1][1]
    todo.pop()

    for x in ham:
        nxt = x*num
        if nxt>limit:
            break
        Sum=Sum+nxt

    nextPrime = bisect.bisect_right(p,largestPrime)
    for i in p[nextPrime:]:
        nxt = i*num
        if nxt>limit:
            break
        todo.append([nxt,i])
Sum=Sum&0xFFFFFFFF
print(Sum)

