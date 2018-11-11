#include<bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
int div_num[10000010];
vector<bool> f(10000010,0);
int min_div[10000010];
vector<int> p;
void init()
{
	for(ull i=2;i<=1e7;i++)
	{
		if(!f[i])
		{
			p.push_back(i);
			min_div[i]=1;
			div_num[i]=2;
		}
		for(auto j:p)
		{
			if(j*i>1e7)break;
			f[i*j]=1;
			if(i%j==0)
			{
				min_div[i*j]=min_div[i]+1;
				div_num[i*j]=div_num[i]/(min_div[i]+1)*(min_div[i]+2);
				break;
			}
			min_div[i*j]=1;
			div_num[i*j]=div_num[i]*div_num[j];
		}
	}
}

int main()
{
	ull ans=0;
	init();
	for(int i=2;i<1e7;i++)
	{
		if(div_num[i]==div_num[i+1])
		ans++;
	}
	cout<<ans<<endl;
}
