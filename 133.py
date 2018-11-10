def sieve(n):
    flag=[True]*n
    flag[0]=flag[1]=False
    for (i,isprime) in enumerate(flag):
        if isprime:
            yield i
            for j in range(i*i,n,i):
                flag[j]=False
if __name__ == "__main__":
    p = list(sieve(100000))
    ans = sum(i for i in p if (pow(10,10**20,9*i)-1) // 9 % i != 0)
    print(ans)

