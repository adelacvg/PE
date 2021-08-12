#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>

int main()
{
    unsigned int limit = 10000;
    unsigned long long sum = 0;

    std::vector<unsigned int> open(limit);
    std::iota(open.begin(),open.end(),1);
    if(limit>=9999)
    {
        sum+=11112222222222222222ULL/9999;
        open.erase(open.begin()+9999-1);
    }
    std::vector<unsigned long long> zerOneTwo = {1,2};

    while(!open.empty())
    {
        std::vector<unsigned int> next;
        for(auto cur:open)
        {
            bool lastMustZero = cur%5==0;
            bool found = false;
            for(auto multiple : zerOneTwo)
            {
                if(lastMustZero)
                    multiple*=10;
                if(multiple%cur==0)
                {
                    sum+=multiple/cur;
                    found = true;
                    break;
                }
            }
            if(!found)
                next.push_back(cur);
        }
        open = std::move(next);
        if(!open.empty())
        {
            std::vector<unsigned long long> longer;
            for(auto multiple : zerOneTwo)
            {
                longer.push_back(multiple*10);
                longer.push_back(multiple*10+1);
                longer.push_back(multiple*10+2);
            }
            zerOneTwo = std::move(longer);
        }
    }
    std::cout<<sum<<'\n';
    return 0; 
}
