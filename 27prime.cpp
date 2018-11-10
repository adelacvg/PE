#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int flag[1010];

void eseive()
{
    for(int i=2;i<=1000;i++)
    {
        if(!flag[i])
            v.push_back(i);
        for(int j=i*i;j<=1000;j+=i)
        {
            flag[j]=1;
        }
    }
}

int is_prime(int n)
{
    int f=1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            f=0;
            break;
        }
    }
    return f;
}

int main()
{
    int ans=0,mx=0;
    eseive();
    /*
    for(auto i : v)
        cout<<i<<'\n';
    */
    for(int i=-999;i<1000;i++)
    {
        for(auto j:v)
        {
            int n=0,t=0;
            while(n*n+i*n+j>0)
            {
                if(is_prime(n*n+i*n+j))
                {
                    t++;
                    n++;
                }
                else
                    break;
            }
            if(t>mx)
            {
                cout<<t<<'\n';
                mx=t;
                ans=i*j;
            }
        }
    }
    cout<<ans;
}
