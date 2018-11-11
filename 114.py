ans=0
n=50
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
ans = solve(3,assign,n,0)
print(ans)
'''
def compute():
	n = 50
	ways = [0] * (n + 1)
	for n in range(len(ways)):
		if n < 3:
			ways[n] = 1
		else:
			ways[n] = ways[n - 1] + sum(ways[ : n - 3]) + 1
	return str(ways[-1])


if __name__ == "__main__":
	print(compute())
'''
