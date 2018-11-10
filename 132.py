def sieve(n):
    flag=[True]*n
    flag[0]=flag[1]=False
    for (i,isprime) in enumerate(flag):
        if isprime:
            yield i
            for j in range(i*i,n,i):
                flag[j]=False
if __name__ == "__main__":
    cnt=0
    ans=0
    p = list(sieve(1000000))
    for i in p:
        if pow(10,10**9,9*i)//9%i == 0:
            ans+=i
            cnt+=1
            if cnt==40:
                print(ans)
                break
