#include <bits/stdc++.h>
using namespace std;

#define N 10000001
int minp[N];

int inv(int a,int P)
{
	int x0=1,x1=0,x;
	int b=P,c;
	while(b)
	{
		int q=a/b;
		c=a-q*b;a=b;b=c;
		x=x0-q*x1;x0=x1;x1=x;
	}
	return x0<0?x0+P:x0;
}

int main()
{
	long long res=0;
	int i,j;
	for(i=2;i<N;i++) {
		if(!minp[i])
			for(j=i;j<N;j+=i)
				if(!minp[j]) minp[j]=i;
		int pw[10];
		int n=0;
		for(int x=i;x>1;)
		{
			int q=1;
			int p=minp[x];
			for(;x%p==0;x/=p) q*=p;
			pw[n++]=q;
		}
		int maxa=0;
		for(int mask=0;mask<(1<<n);mask++)
		{
			int m1=1,m2=1;
			for(int k=0;k<n;k++)
				if(mask & 1<<k) m1*=pw[k]; else m2*=pw[k];
			int a=m1*inv(m1,m2);
			if(maxa<a) maxa=a;
		}
		res+=maxa;
	}
	printf("%lld\n",res);
	return 0;
}
