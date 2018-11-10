ans=0
for i in range(1,100):
    for j in range(1,100):
        t=i**j
        sm=0
        for k in str(t):
            sm+=ord(k)-ord('0')
        ans=max(ans,sm)
print(ans)
