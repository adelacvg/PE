#include<bits/stdc++.h>
#define ull unsigned long long
const ull M = 200000010;
using namespace std;

bool flag[M];
vector<ull> prime;
void sieve()
{
    flag[0]=flag[1]=1;
    for(ull i=2;i<=M;i++)
    {
        if(!flag[i])
        {
            prime.push_back(i);
            for(ull j=i*i;j<=M;j+=i)
            {
                flag[j]=1;
            }
        }
    }
}

int main()
{
    ull ans=0;
    sieve();
    for (auto m:prime)
    {
        if(m>100000000)
            break;
        auto n = m-1;
        if (flag[1 + n])
            continue;
        if (flag[2 + n/2])
            continue;
        bool valid = 1;
        for (ull i = 3; i*i <= n; i++)
        {
            if (n%i==0&&flag[i + n / i])
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            ans += n;
            if(n<100)
            cout<<n<<endl;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
