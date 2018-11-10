#include<bits/stdc++.h>
using namespace std;
int f(int n)
{
    double x = (sqrt(1+24*n)+1)/6.0;
    return x==(int)x;
}
int main()
{
    int i=1;
    int ans;
    while(1)
    {
        int ff=1;
        int n = i*(3*i-1)/2;
        for(int j=1;j<=i-1;j++)
        {
            int m = j*(3*j-1)/2;
            if(f(n+m)&&f(n-m))
            {
                ans=n-m;
                ff=0;
                break;
            }
        }
        i++;
        if(!ff)
            break;
    }
    cout<<ans;

}
