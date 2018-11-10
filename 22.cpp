#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
/*
std::vector<std::string> Split(const std::string& subject) {
    static const std::regex re{"\\s+"};
    std::vector<std::string> container{
        std::sregex_token_iterator(subject.begin(), subject.end(), re, -1), 
        std::sregex_token_iterator()
    };
    return container;
}
*/
vector<string> Split(const string& subject)
{
    istringstream ss{subject};
    using StrIt = istream_iterator<string>;
    vector<string> container{StrIt{ss}, StrIt{}};
    return container;
}
vector<string> v;

int main()
{
    ifstream f("22.txt");
    string s;
    cin>>s;
    split(s,"\",\"");
    sort(v.begin(),v.end());
    ull ans=0;
    int tt=1;
    for(auto i:v)
    {
        cout<<i<<'\n';
        int t=0;
        for(int j=0;j<i.length();j++)
        {
            t+=i[j]-'A';
        }
        ans+=(ull)t*(tt++);
    }
    cout<<ans;
}
