import math
import random
def sieve(n):
    flag = [True]*n
    flag[0]=flag[1]=False
    for (i,isprime) in enumerate(flag):
        if isprime:
            yield i
            for j in range(i*i,n,i):
                flag[j]=False
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
def is_prime(a,b):
    l1=0;l2=0
    t1=a;t2=b
    while t1:
        l1+=1
        t1//=10
    while t2:
        l2+=1
        t2//=10
    if not isPrime(a*pow(10,l2)+b,4) or not isPrime(b*pow(10,l1)+a,4):
        return 0
    return 1
if __name__=='__main__':
    p=list(sieve(20000))
    ans=100000000
    n=len(p)
    for a in range(n):
        if p[a]*5>=ans:
            break
        for b in range(a+1,n):
            if p[a]+4*p[b]>=ans:
                break
            if not is_prime(p[a],p[b]):
                continue
            for c in range(b+1,n):
                if p[a]+p[b]+3*p[c]>=ans:
                    break
                if not is_prime(p[a],p[c]) or not is_prime(p[b],p[c]):
                    continue
                for d in range(c+1,n):
                    if p[a]+p[b]+p[c]+2*p[d]>=ans:
                        break
                    if not is_prime(p[d],p[a]) or not is_prime(p[d],p[b]) or not is_prime(p[d],p[c]):
                        continue
                    for e in range(d+1,n):
                        if p[a]+p[b]+p[c]+p[d]+p[e]>=ans:
                            break
                        if not is_prime(p[e],p[a]) or not is_prime(p[e],p[b]) or not is_prime(p[e],p[c]) or not is_prime(p[e],p[d]):
                            continue
                        print(p[a],p[b],p[c],p[d],p[e],sep=" ")
                        ans=min(ans,p[a]+p[b]+p[c]+p[d]+p[e])
    print(ans)





