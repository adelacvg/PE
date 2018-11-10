#include<bits/stdc++.h>
using namespace std;
double cal(vector<int> a)
{
    double exp = 0;
    int cnt=0;
    for(auto i:a)
            cnt+=i;
    if(cnt==1)
    {
        if(a[5]==1)
            return 0;
        if(a[1]==0)
            exp=1;
    }
    for(int i=1;i<=5;i++)
    {
        if(a[i])
        {
            auto x = a;
            x[i]--;
            for(int j=i+1;j<=5;j++)
                x[j]++;
            exp+=a[i]/(double)cnt*cal(x);
        }
    }
    return exp;
}
int main()
{
    vector<int> a={0,1,0,0,0,0};
    double ans=cal(a);
    cout<<setprecision(6)<<ans;
}
