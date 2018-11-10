#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int f(int x)
{
    string s;
    s=bitset<64>(x).to_string();
    s.erase(0,s.find_first_not_of('0'));
    string ss=s;
    reverse(s.begin(),s.end());
    return s==ss;
}
int main()
{
    ull ans=0;
    for(int i=1;i<1000000;i++)
    {
        string s=to_string(i);
        string ss=s;
        reverse(s.begin(),s.end());
        if(s==ss&&f(i))
            ans+=i;
    }
    cout<<ans;
}
