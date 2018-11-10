#include<bits/stdc++.h>
using namespace std;
int c(int n,int m)
{
    int res=1;
    for(int i=1;i<=m;i++)
    {
        res=res*(n-m+i)/i;
    }
    return res;
}
int main()
{
    int aim = 2000000;
    int area=0;
    int delta = 100000000;
    for(int i=2;i<=4000;i++)
    {
        for(int j=2;j<=4000;j++)
        {
            if(abs(c(i+1,2)*c(j+1,2)-aim)<delta)
            {
                area = i*j;
                delta = abs(c(i+1,2)*c(j+1,2)-aim);
            }
        }
    }
    cout<<area;
}
