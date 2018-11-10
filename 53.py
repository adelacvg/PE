def f(n,m):
    ans=1
    for i in range(1,n-m+1):
        ans*=(m+i)/i
    return ans

ans=0
for i in range(1,101):
    for j in range (1,i+1):
        if f(i,j)>1000000:
            ans+=1
print(ans)
