ans=0
a=[None]*1010
b=[None]*1010
a[0]=1
b[0]=1
a[1]=3
b[1]=2
for i in range(2,1001):
    a[i]=2*a[i-1]+a[i-2]
    b[i]=2*b[i-1]+b[i-2]
    if(len(str(a[i]))>len(str(b[i]))):
        ans+=1
print(ans)
