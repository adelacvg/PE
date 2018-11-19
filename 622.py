#(2^60)-1==k*m m is odd
import math
import random
def sieve(limit):
    a = [True]*limit
    a[0] = a[1]=False
    for (i,isprime) in enumerate(a):
        if isprime:
            yield i
            for n in range(i*i,limit,i):
                a[n]=False
def pollard_rho(number):
    cycle_size=2
    x=2
    x_fixed=2
    factor=1
    while factor==1:
        count=1
        while count<=cycle_size and factor<=1:
            x=(x*x+1)%number
            factor=math.gcd(x-x_fixed,number)
            count+=1
        cycle_size*=2
        x_fixed = x
    return factor
def miillerTest(d,n):
    a = 2+random.randint(10,n)%(n-4)
    x = pow(a,d,n)
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
# Fucnction return smallest + ve
# integer that holds condition
# A ^ k(mod N ) = 1
def multiplicativeOrder(A, N) :
    if (GCD(A, N ) != 1) :
        return -1
    # result store power of A that rised
    # to the power N-1
    result = 1
    K = 1
    while (K < N) :
        # modular arithmetic
        result = (result * A) % N
        # return samllest + ve integer
        if (result == 1) :
            return K
        # increment power
        K = K + 1
    return -1
number=(1<<60)-1
v=[]
#number=10403
print(number)
p=list(sieve(100))
for i in p:
    while number%i==0:
        number//=i
        v.append(i)
while isPrime(number,4)==False:
    x = pollard_rho(number)
    number//=x
    v.append(x)
if number!=1:
    v.append(number)
t=1
v=sorted(v)
for i in v:
    print(i)
    t*=i
print(t)
ans=0
