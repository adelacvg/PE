#include<bits/stdc++.h>
using namespace std;

int main()
{
    fstream f;
    f.open("79.txt");

    map<char,set<char>> pre;

    for(int i=1;i<=50;i++)
    {
        string line;
        f>>line;
        pre[line[0]];
        for(int i=1;i<line.size();i++)
        {
            pre[line[i]].insert(line[i-1]);
        }
    }
    string ans;
    while(!pre.empty())
    {
        auto emptyset = pre.begin();
        while(emptyset!=pre.end()&&!emptyset->second.empty())
            emptyset++;
        auto t = emptyset->first;
        ans+=t;

        pre.erase(t);

        for(auto& i : pre)
        {
            i.second.erase(t);
        }
    }
    cout<<ans;
}
