#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int flag[1000010];
vector<int> v;
void init()
{
    for(int i=2;i<=1000000;i++)
    {
        for(ull j=i*i;j<=1000000;j+=i)
        {
            flag[j]=1;
        }
    }
    for(int i=2;i<1000000;i++)
    {
        if(flag[i]==0)
            v.push_back(i);
    }
}


int main()
{
    init();
    int ans=0;
    for(auto i : v)
    {
        int f=1;
        int tmp=i;
        for(int j=1;j<=to_string(i).length();j++)
        {
            if(flag[tmp])
            {
                f=0;
                break;
            }
            tmp=tmp/10+(tmp%10)*pow(10,to_string(i).length()-1);
        }
        if(f)
        {
            cout<<i<<'\n';
            ans++;
        }
    }
    cout<<ans;
}
