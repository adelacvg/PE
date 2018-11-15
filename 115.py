ans=0
n=200
def f(n):
	fac=[0]*(n+10)
	fac[0]=1
	for i in range(1,n+5):
		fac[i]=i*fac[i-1]
	return fac
def c(n,m):
	return fac[n]//fac[n-m]//fac[m]
def solve(i,asn,b,other):
	res=0
	if i>b:
		if other>b+1:
			return 0
		else:
			t=fac[b+1]//fac[b+1-other]
			for j in asn:
				if j:
					t//=fac[j]
			return t
	for j in range(b/i+1):
		asn[i]=j
		res+=solve(i+1,asn,b-i*j,other+j)
		asn[i]=0
	return res;
fac=f(n)
assign = [0]*(n+10)
#ans = solve(3,assign,n,0)
ans=50
while solve(50,assign,ans,0)<1000000:
	ans+=1
print(ans)
