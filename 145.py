'''ans=0
for i in range(1,89990002,2):
    f=1
    for j in str(int(str(i)[::-1])+i):
        if int(j)%2==0:
            f=0
            break
    if f:
        ans+=2
print(ans)'''
def count_reversibles(numdigits):
    if numdigits % 2 == 0:
            return 20 * 30**(numdigits // 2 - 1)
    elif numdigits % 4 == 3:
            return 100 * 500**((numdigits - 3) // 4)
    elif numdigits % 4 == 1:
            return 0
    else:
            raise AssertionError()
ans = sum(count_reversibles(d) for d in range(2, 10))
print(ans)
