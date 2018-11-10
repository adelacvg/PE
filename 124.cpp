#include<bits/stdc++.h>
using namespace std;
vector<int> rad(100010,1);
vector<int> flag(100010,0);
int main()
{
    rad[1]=1;
    for(int i=2;i<=100000;i++)
    {
        if(!flag[i])
        {
            rad[i]=i;
            for(int j=2*i;j<=100010;j+=i)
            {
                rad[j]*=i;
                flag[j]=1;
            }
        }
    }
    vector<pair<int,int>> v;
    for(int i=0;i<=100000;i++)
        v.push_back(make_pair(rad[i],i));
    sort(v.begin(),v.begin()+100001);

    cout<<v[10000].second<<endl;
}
