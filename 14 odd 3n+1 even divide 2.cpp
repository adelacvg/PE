#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#define ull unsigned long long
using namespace std;
map<ull,ull> c;
ull f(ull i)
{
    ull cnt=0;
    if(i==1)
        return 1;
    if(c[i]!=0)
        return c[i];
    if(i%2==1)
        cnt+=f(3*i+1);
    else
        cnt+=f(i/2);
    cnt++;
    c[i]=cnt;
    return cnt;
}
int main()
{
    ull mx=0,ans=0;
    for(ull i=1;i<1000000;i++)
    {
        cout<<i<<endl;
        if(f(i)>mx)
        {
            mx=c[i];
            ans=i;
        }
    }
    cout<<ans;
}
