import math
ans=0
n=1
while 10**((n-1)/n) <= 9:
    for x in range(math.ceil(10**((n-1)/n)),10):
        ans+=1
    n+=1
print(ans)
