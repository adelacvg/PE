#include<bits/stdc++.h>
using namespace std;

map<int,int> m;

int f(int n)
{
    if(m[n])
        return m[n];
    int t=0;
    while(n)
    {
        t+=(n%10)*(n%10);
        n/=10;
    }
    if(t==1||t==89)
        return t;
    return m[n]=f(t);
}

int main()
{
    int ans=0;
    for(int i=1;i<10000000;i++)
    {
        if(f(i)==89)
            ans++;
    }
    cout<<ans;
}
