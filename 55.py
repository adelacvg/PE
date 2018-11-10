ans=0
for i in range(10000):
    flag=0
    tmp=i
    for t in range(1,50):
        tmp+=int(str(tmp)[::-1])
        if str(tmp)==str(tmp)[::-1]:
            flag=1
            break
    if flag==0:
        ans+=1
print(ans)
