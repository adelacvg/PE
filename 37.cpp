#include<bits/stdc++.h>
using namespace std;
int flag[1000010];
vector<int> v;
void init()
{
    flag[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        for(unsigned long long j=i*i;j<=1000000;j+=i)
        {
            flag[j]=1;
        }
    }
    for(int i=2;i<=1000000;i++)
        if(flag[i]==0)
            v.push_back(i);
}
int main()
{
    int ans=0;
    init();
    for(auto i : v)
    {
        int f=1;
        int tmp=i,tmp1=i;
        string s=to_string(i);
        for(int j=1;j<=s.length();j++)
        {
           if(flag[tmp])
           {
               f=0;
               break;
           }
           if(flag[tmp1])
           {
               f=0;
               break;
           }
           tmp/=10;
           tmp1%=(int)pow(10,s.length()-j);
        }
        if(f)
        {
            cout<<i<<'\n';
            ans+=i;
        }
    }
    ans-=17;
    cout<<ans;
}
