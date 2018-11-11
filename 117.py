def f(n):
	fac=[None]*(n+10)
	fac[0]=1;
	for i in range(1,n+1):
		fac[i]=i*fac[i-1]
	return fac
n=50
fac=f(n)
ans=0
for i in range(n/2+1):
	for j in range((n-2*i)/3+1):
		for k in range((n-2*i-3*j)/4+1):
			b=n-i*2-j*3-k*4
			ans+=fac[b+i+j+k]//fac[b]//fac[i]//fac[j]//fac[k]
print(ans)
