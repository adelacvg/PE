#include<iostream>
#include<vector>
#include<bitset>
std::vector<int> p;
std::vector<bool> flag(20000000,1);
std::vector<int> spf(20000000,0);
const std::bitset<10000> segment[10]
{
    // 000
    //1   2
    //1   2
    // 333
    //4   5
    //4   5
    // 666
    0b1110111,
    0b0100100,
    0b1011101,
    0b1101101,
    0b0101110,
    0b1101011,
    0b1111011,
    0b0100111,
    0b1111111,
    0b1101111
};
void sieve(unsigned long long N)
{
    flag[0]=flag[1]=0;
    for(unsigned long long i=2;i<=N;i++)
    {
        if(flag[i])
        {
            p.emplace_back(i);
            spf[i]=i;
        }
        for(unsigned long long j=0;j<p.size()
                &&p[j]*i<=N
                &&p[j]<=spf[i];j++)
        {
            flag[i*p[j]]=0;
            spf[i*p[j]]=p[j];
        }
    }
}
unsigned int digitSum(unsigned int x)
{
    unsigned int result = 0;
    while(x)
    {
        result+=x%10;
        x/=10;
    }
    return result;
}
std::bitset<10000> getSegments(unsigned int x)
{
    std::bitset<10000> result(0);
    unsigned int shift = 0;
    while(x)
    {
        std::bitset<10000> current = segment[x%10];
        result|=(current<<shift);
        x/=10;
        shift+=8;
    }
    return result;
}
unsigned long long sam(unsigned int x)
{
    auto segments = getSegments(x);
    auto result = 2*segments.count();

    if(x>9)
        result+=sam(digitSum(x));

    return result;
}
unsigned long long max(unsigned int x,std::bitset<10000> preSegments = 0)
{
    auto segments = getSegments(x);
    auto transition = segments^preSegments;
    auto result = transition.count();

    if(x>9)
        result += max(digitSum(x), segments);
    else
        result+=segments.count();

    return result;
}
int main()
{
    int N = 1e7;
    sieve(2*N);
    /*
    for(int i=0;i<10;i++)
        std::cout<<p[i]<<'\n';
    */
    unsigned long long Sam=0,Max=0;
    //for(auto i:segment)
    //    std::cout<<i<<std::endl;
    for(auto i = (N|1);i<=2*N;i+=2)
    {
        if(flag[i])
        {
            Sam += sam(i);
            Max += max(i);
        }
    }
    std::cout<<Sam - Max<<std::endl;
    return 0;
}
