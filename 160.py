ans=1
for i in range(1,2560001):
    cur = i
    while cur%5==0:
        cur//=5
        ans//=2
    ans*=cur%100000
    ans%=1000000000
print(ans%100000)
