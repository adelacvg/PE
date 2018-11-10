x = 2**1000
ans=0
while x:
    ans += x%10
    x //= 10
print(ans)

