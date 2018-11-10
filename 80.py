def sqrt(x):
    i = 1
    while i*i<=x:
        i*=2
    y=0
    while i>0:
        if(y+i)**2<=x:
            y+=i
        i//=2
    return y
t=100**100
print(sum(
    int(c) for c in str(sqrt(t*2))[:100]
    ))
ans = sum(
        sum(int(c) for c in str(sqrt(i * t))[ : 100])
	for i in range(1,101)
	if sqrt(i)**2 != i)
print(str(ans))
