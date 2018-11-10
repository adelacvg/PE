#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int f(int x,int n)
{
    map<int,int> mm;
    int t=x*n;
    while(t)
    {
        mm[t%10]++;
        t/=10;
    }
    for(auto [i,j]:m)
    {
        if(j!=mm[i])
            return 0;
    }
    return 1;
}
int main()
{
    int ans;
    int x=1;
    while(1)
    {
        m.clear();
        int tmp=x;
        while(tmp)
        {
            m[tmp%10]++;
            tmp/=10;
        }
        if(f(x,1)&&f(x,2)&&f(x,3)&&f(x,4)&&f(x,5)&&f(x,6))
        {
            ans=x;
            break;
        }
        x++;
    }
    cout<<ans;
}
