#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int ans;
    for(int a=1;a<=1000;a++)
    {
        for(int b=a;b<=1000;b++)
        {
            if(a*a+b*b==(1000-a-b)*(1000-a-b))
            {
                ans=a*b*(1000-a-b);
            }
        }
    }
    cout<<ans;
}
