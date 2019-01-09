#include<bits/stdc++.h>
using namespace std;
long long A(long long n)
{
    if(__gcd((long long)10,n)!=1)
        return 0;
    long long t=1,k=1;
    while(t!=0)
    {
        t=(t*10+1)%n;
        k++;
    }
    return k;
}
int main()
{
    long long M=1e6+1;
    long long n=1e6+1;
    while(A(n)<M)
    {
        n+=2;
    }
    cout<<n<<endl;
}
