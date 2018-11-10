#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull A000914(ull n)
{
    return n*(n+1)*(n+2)*(3*n+5)/24;
}
ull A228317(ull n)
{
    return n*(n-1)*(n-2)*(3*n-5)/8;
}
ull A236770(ull n)
{
    return n*(n+1)*(3*n*n+3*n-2)/8;
}
int main()
{
    ull sum=0;
    ull i000914=1;
    ull i228317=3;
    ull i236770=1;
    for(int i=3;i<=12345;i++)
    {
        if(i%3==0)
            sum+=A236770(i236770++);
        else if(i%3==1)
            sum+=A228317(i228317++);
        else
            sum+=3*A000914(i000914++);
    }
    cout<<sum<<endl;
}
