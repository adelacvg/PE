def sieve(n):
    flag =[True]*n
    flag[0]=flag[1]=False
    for (i,isprime) in enumerate(flag):
        if isprime:
            yield i
            for j in range(i*i,n,i):
                flag[j]=False

if __name__ == "__main__":
    p = list(sieve(100000000))
    ans=sum(((i-3)*pow(8,i-2,i))%i for i in p if i>=5)
    print(ans)

