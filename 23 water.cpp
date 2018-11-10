#include<iostream>
#include<vector>
#include<algorithm>

int flag[100000];
using namespace std;
vector<int> v;
int f(int n)
{
    int ans=0;
   for(int i=1;i<n;i++)
   {
        if(n%i==0)
            ans+=i;
   }
   return ans;
}


int main()
{
    for(int i=1;i<=28123;i++)
    {
        if(f(i)>i)
        {
            v.push_back(i);
            for(auto j : v)
            {
                flag[i+j]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=28123;i++)
    {
        if(!flag[i])
            ans+=i;
    }
    cout<<ans;
}
