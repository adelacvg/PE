#include<bits/stdc++.h>
using namespace std;
void roll(int dices,int sides,vector<int>& count,int sum=0)
{
    if(dices==0)
    {
        count[sum]++;
        return;
    }
    for(int i=1;i<=sides;i++)
        roll(dices-1,sides,count,sum+i);
}
int main()
{
    double ans=0;
    vector<int> colin(40,0),peter(40,0);
    cout<<"ok"<<'\n';
    roll(9,4,peter);
    roll(6,6,colin);
    cout<<"ok"<<'\n';
    int sump=0,sumc=0;
    for(auto i:peter)
        sump+=i;
    for(auto i:colin)
        sumc+=i;
    for(int i=9;i<=36;i++)
    {
        int winnum=0;
        for(int j=6;j<i;j++)
        {
            winnum+=colin[j];
        }
        ans+=(double)winnum/sumc*peter[i]/sump*1.0;
        cout<<ans<<'\n';
    }
    cout<<setprecision(7)<<ans;
}
