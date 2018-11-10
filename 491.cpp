#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll nextNumberWithSameBits(ll x)
{
    auto rightone = x&-x;
    auto nextHigherOneBitAndLeft = x + rightone;
    auto rightOnes = nextHigherOneBitAndLeft ^ x;
    return ((rightOnes/rightone)>>2)|nextHigherOneBitAndLeft;
}
ll get(ll maxDigit)
{
    ull result=0;
    int digitSum=90;
    auto numDigit=20;

    ull fac=1;
    for(int i=1;i<=10;i++)
        fac*=i;
    ull permutationRepeated[10];
    for(int i=0;i<=9;i++)
        permutationRepeated[i]=fac>>i;
    auto minBitMask = (1<<(maxDigit+1))-1;
    auto maxBitMask = minBitMask<<(maxDigit+1);
    for(auto bitmask = minBitMask;bitmask<=maxBitMask;bitmask=nextNumberWithSameBits(bitmask))
    {
        auto reduce = bitmask;
        bool ok=1;
        while(reduce>0)
        {
            if((reduce&3)==2)
            {
                ok=0;
                break;
            }
            reduce>>=2;
        }
        if(!ok)
        {
            continue;
        }
        int sum=0;
        auto repeated=0;
        for(ull pos = 0;pos<numDigit;pos++)
        {
            if(bitmask&(1<<pos))
            {
                sum+=pos/2;
                if(pos&1)
                    repeated++;
            }
        }
        if((digitSum-2*sum)%11==0)
            result+=permutationRepeated[repeated]*permutationRepeated[repeated];
    }
    return result*maxDigit/(maxDigit+1);
}
int main()
{
    int numDigit=9;
    cout<<get(numDigit)<<endl;
    return 0;
}
