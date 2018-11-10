#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int a=1,b=2;
    unsigned long long sum=2;
    for(int c=a+b;c<=4000000;c=a+b)
    {
        if(c%2==0)
            sum+=c;
        a=b;
        b=c;
    }
    cout<<sum;
}
