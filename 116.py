def f(n):
	fac=[None]*100
	fac[0]=1;
	for i in range(1,n+1):
		fac[i]=i*fac[i-1]
	return fac
n=50
fac=f(n)
ans=0
for i in range(1,n/2+1):
	b=n-i*2
	ans+=fac[i+b]//fac[i]//fac[b];
for i in range(1,n/3+1):
	b=n-i*3
	ans+=fac[i+b]//fac[i]//fac[b]
for i in range(1,n/4+1):
	b=n-i*4
	ans+=fac[i+b]//fac[i]//fac[b]
print(ans)
