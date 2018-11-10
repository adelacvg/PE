#include<bits/stdc++.h>
using namespace std;
int M = 1000000;
int fac[20]={1,1,2,6,24,120,720,5040,40320,362880};
int cash[1000001];

int f(int n)
{
    int sum=0;
    while(n)
    {
        sum+=fac[n%10];
        n/=10;
    }
    return sum;
}
int main()
{
    cash[169]=3;
    cash[363601]=3;
    cash[1454]=3;
    cash[871]=2;
    cash[45361]=2;
    cash[872]=2;
    cash[45362]=3;
    int ans = 0;
    for(int i=69;i<M;i++)
    {
        int n=i;
        int count = 0;
        vector<int> seq;
        seq.push_back(0);
        while(n!=seq[seq.size()-1])
        {
            seq.push_back(n);
            n = f(n);
            count++;
            if(n<M&&cash[n])
            {
                count+=cash[n];
                break;
            }
        }
        if(count==60)
        {
            ans++;
        }
        for(int j=1;j<seq.size();j++)
        {
            if(seq[j]<M)cash[seq[j]] = count;
            count--;
        }
    }
    cout<<ans;
}
