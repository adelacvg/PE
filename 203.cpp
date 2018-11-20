#include<bits/stdc++.h>
using namespace std;
unsigned long long dp[200][200];
int isfree(unsigned long long x,int rownum)
{
	for(int i=2;i<=rownum;i++)
	{
		if(x%(i*i)==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	dp[1][1]=1;
	set<unsigned long long> se;
	int rownum=51;
	for(int i=2;i<=rownum;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
			if(j<=(i+1)/2&&isfree(dp[i][j],rownum))
				se.insert(dp[i][j]);
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	unsigned long long ans=0;
	for(auto i:se)
	{
		ans+=i;
	}
	cout<<ans<<endl;
}
