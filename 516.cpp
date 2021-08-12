#include<random>
#include<ctime>
#include<iostream>
#include<vector>
#include<algorithm>
using ull = unsigned long long;
std::vector<ull> ham;
std::vector<ull> p;
ull power(ull x, ull y, ull p) 
{ 
    ull res = 1;
    x = x % p;
    while (y > 0) 
    {
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 
bool millerTest(ull d, ull n) 
{ 
    srand(std::time(0));
    ull a = 2 + rand() % (n - 4); 
    ull x = power(a, d, n); 
  
    if (x == 1  || x == n-1) 
       return true; 
    while (d != n-1) 
    { 
        x = (x * x) % n; 
        d *= 2; 
  
        if (x == 1)      return false; 
        if (x == n-1)    return true; 
    }
    return false; 
}
bool isPrime(ull n, ull k) 
{ 
    if (n <= 1 || n == 4)  return false; 
    if (n <= 3) return true; 
    ull d = n - 1; 
    while (d % 2 == 0) 
        d /= 2; 
    for (ull i = 0; i < k; i++) 
         if (millerTest(d, n) == false) 
              return false; 
    return true; 
} 
int main()
{
    ull limit = 1e12;
    for(ull two = 1;two<=limit;two*=2)
    {
        for(ull three = 1;two*three<=limit;three*=3)
        {
            for(ull five = 1;two*three*five<=limit;five*=5)
            {
                auto cur = two*three*five;
                ham.emplace_back(cur);
                if(isPrime(cur+1,6)&&cur>5)
                    p.emplace_back(cur+1);
            }
        }
    }
    std::sort(ham.begin(),ham.end());
    std::sort(p.begin(),p.end());
    std::cout<<p.size()<<'\n';
    std::vector<std::pair<ull,ull>> todo;
    todo.push_back({1,1});
    ull sum = 0;
    while(!todo.empty())
    {
        auto num = todo.back().first;
        auto largestPrime = todo.back().second;
        todo.pop_back();

        for(auto x:ham)
        {
            auto next  = x*num;
            if(next>limit)
                break;
            sum+=next;
        }

        auto nextPrime = std::upper_bound(p.begin(),p.end(),largestPrime);
        for(;nextPrime!=p.end();nextPrime++)
        {
            auto next = *nextPrime*num;
            if(next>limit)
                break;

            todo.push_back({next,*nextPrime});
        }
    }
    sum&=0xFFFFFFFF;
    std::cout<<sum<<'\n';
}
