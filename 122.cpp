#include<iostream>
#include<vector>
std::vector<int> cost(201,10000000);
std::vector<int> path(201,0);

void backtrack(int power,int depth=0)
{
    if(power>200||depth>cost[power]) return;
    cost[power] = depth;
    path[depth] = power;
    for(int i=depth;i>=0;i--)
    {
        backtrack(power+path[i],depth+1);
    }
}

int main()
{
    int ans = 0;
    
    backtrack(1,0);
     
    for(int i=1;i<=200;i++)
        ans+=cost[i];
    std::cout<<ans<<'\n';
}
