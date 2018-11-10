#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int flag[10010];
vector<ull> v;
vector<string> vi;
vector<string> vj;
vector<string> vk;
void init()
{
    for(ull i=2;i<=10000;i++)
    {
        if(!flag[i]&&i>1000&&i<10000)
            v.push_back(i);
        for(ull j=i*i;j<=10000;j+=i)
        {
            flag[j]=1;
        }
    }
}

int main()
{
    init();
    string ans="";
    for(int j=1;j<v.size()-1;j++)
    {
        int i=j-1,k=j+1;
        while(i>=0&&k<v.size())
        {
            if(v[i]+v[k]==2*v[j])
            {
                vi.push_back(to_string(v[i]));
                vj.push_back(to_string(v[j]));
                vk.push_back(to_string(v[k]));
                i--,k++;
            }
            else if(v[i]+v[k]>2*v[j])
            {
                i--;
            }
            else
            {
                k++;
            }
        }
    }
    for(int i=0;i<vi.size();i++)
    {
        int f1=0,f2=0;
        for(int j=1;j<=24;j++)
        {
            next_permutation(vi[i].begin(),vi[i].end());
            if(vi[i]==vj[i])
                f1=1;
            if(vi[i]==vk[i])
                f2=1;
        }
        if(f1&&f2)
        {
            ans=vi[i]+vj[i]+vk[i];
            cout<<ans<<'\n';
        }
    }
}
