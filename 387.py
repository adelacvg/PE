import random
def power(x,y,p):
    res=1
    x%=p
    while y:
        if y&1:
            res=(res*x)%p
        y>>=1
        x=(x*x)%p
    return res
def millerTest(d,n):
    a = 2+random.randint(1,n)%(n-4)
    x = power(a,d,n)
    if x==1 or x==n-1:
        return True
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
    d=n-1
    while d%2==0:
        d//=2
    for i in range(0,k):
        if millerTest(d,n) == False:
            return False
    return True
def f():
    ans=[0]
    MAX=10**14
    def find(n,digsum,strong):
        m=n*10
        s=digsum
        for i in range(10):
            if m>=MAX:
                break
            if strong and isPrime(m,4):
                ans[0]+=m
            if m%s == 0:
                find(m,s,isPrime(m//s,4))
            m+=1
            s+=1
    for i in range(1,10):
        find(i,i,False)
    return str(ans[0])
if __name__ =="__main__":
    print(f())
