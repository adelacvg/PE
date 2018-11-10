#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int f(unsigned long long x)
{
    int cnt=0;
    for(unsigned long long i=1;i<=sqrt(x);i++)
    {
        if(x%i==0&&i!=sqrt(x))
            cnt+=2;
        else if(x%i==0&&i==sqrt(x))
            cnt++;
    }
    return cnt;
}

int main()
{
    unsigned long long i=0,j=1;
    while(1)
    {
        i+=j;
        j++;
        if(f(i)>500)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}
