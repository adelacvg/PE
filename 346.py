ans = 1
n =1000000000000
m = {}
for i in range(2,n):
    t = i*i
    j = 1+i
    while j+t<n:
        j+=t
        t*=i
        if m[j]==1:
            continue
        ans+=j
        m[j]=1
        print(j)
print(ans)
