#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int is_palind(ull a)
{
    if(a%10==0)return 0;
    ull r = a%10,re=a/10;
    while(re)
    {
        r=r*10+re%10;
        re/=10;
    }
    
    return a==r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ull t,n,d;
    cin>>t;
    vector<ull> v;
    while(t--)
    {
        ull ans=0;
        cin>>n>>d;
        ull a=1,tmp;
        for(ull i=1;i*i*2<n;i++)
        {
            a=i*i;
            tmp=d;
            a+=(i+tmp)*(i+tmp);
            while(a<n)
            {
                if(is_palind(a))
                    v.push_back(a);
                tmp+=d;
                a+=(i+tmp)*(i+tmp);
            }
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(auto i:v)
        {
            ans+=i;
        }
        cout<<ans<<endl;
        v.clear();
    }
}
