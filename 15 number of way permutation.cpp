#include<iostream>
#include<cmath>
#define ull unsigned long long
using namespace std;
ull c(ull m,ull n)
{
    ull ans=1;
    for(int i=1;i<=n-m;i++)
    {
        ans=ans*(m+i)/i;
    }
    return ans;
}
int main()
{
    cout<<c(20,40);
}
