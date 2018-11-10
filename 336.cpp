#include<bits/stdc++.h>
using namespace std;
int fac[20];
void init()
{
    fac[0]=fac[1]=1;
    for(int i=2;i<=20;i++)
    {
        fac[i]=i*fac[i-1];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    init();
    cout.tie(0);
    int len=11;
    vector<int> x;
    for(auto i ='A';i<'A'+len;i++)
    {
        x.push_back(i);
    }
    auto tt=x;
    int cnt=0;
    int MAX=fac[len];
    while(MAX--)
    {
        int tc='A';
        int rot=0;
        auto t=tt;
        for(int i=0;i<len;i++,tc++)
        {
            if(t[i]==tc||t[len-1]==tc&&i<len-2)
                break;
            auto f = find(t.begin(),t.end(),tc);
            
            if(f<t.end()-1)
            {
                reverse(f,t.end());
                rot++;
            }
            
            if(i<len-1)
            {
                reverse(t.begin()+i,t.end());
                rot++;
            }
            
        }
        //cout<<rot<<endl;
        if(rot==2*(len-2)+1)
        {
            cnt++;
        }
        if(cnt==2011)
        {
            for(auto i:tt)
                cout<<(char)i;
            break;
        }
        next_permutation(tt.begin(),tt.end());
    }
    return 0;
}
