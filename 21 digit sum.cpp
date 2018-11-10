#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int sum(int n)
{
    int a=0;
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
            a+=i;
    }
    return a;
}
int main()
{
    int ans=0;
    for(int i=1;i<10000;i++)
    {
        int x=sum(i);
        if(i==sum(x)&&i!=x)
        {
            ans+=i;
        }
    }
    cout<<ans<<'\n';
    cout<<sum(220)<<'\n';
    cout<<sum(284)<<'\n';
}
