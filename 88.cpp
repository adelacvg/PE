#include<iostream>
#include<cmath>
#include<vector>
std::vector<unsigned int> mink(20000,100000000);
bool valid(unsigned int n,unsigned int k)
{
    if(k>12000)
        return false;
    if(mink[k]>n)
    {
        mink[k]=n;
        return true;
    }
    return false;
}
int get( unsigned int n,unsigned int product,unsigned int sum,unsigned int depth = 1,unsigned int minfac = 2)
{
    if(product == 1)
        return valid(n,depth+sum-1)?1:0;
    unsigned int result = 0;
    if(depth>1)
    {
        if(product == sum)
            return valid(n,depth)?1:0;
        if(valid(n,depth+sum-product))
            result++;
    }
    for(unsigned int i=minfac;i*i<=product;i++)
        if(product%i==0)
            result+=get(n,product/i,sum-i,depth+1,i);
    return result;
}
int main()
{
    unsigned int ans = 0;
    unsigned int todo = 12000-1;
    int n = 4;
    while(todo)
    {
        unsigned int found = get(n,n,n);
        if(found > 0)
        {
            todo -= found;
            ans  += n;
        }
        n++;
    }
    std::cout<<ans<<'\n';
}
