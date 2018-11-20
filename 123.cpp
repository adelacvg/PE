#include<bits/stdc++.h>
using  namespace std;
vector<unsigned long long> v;
int flag[10000010];
void sieve()
{
	for(unsigned long long i=2;i<=10000000;i++)
	{
		if(!flag[i])
		{
			v.push_back(i);
			for(unsigned long long j=i*i;j<=10000000;j+=i)
			{
				flag[j]=1;
			}
		}
	}
}
int main()
{
	sieve();
	int n=1;
	unsigned long long r=0;
	while (r<1e10)
	{
		n+=2;
		unsigned long long p = v[n-1];
		r = 2 * p * n;
	}
	cout<<n<<endl;
}
