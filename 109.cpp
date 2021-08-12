#include<bits/stdc++.h>
using namespace std;
vector<int> score;
vector<int> doubles;
int main()
{
    int ans=0;
    for(int i=1;i<=20;i++)
    {
        score.emplace_back(i);
        score.emplace_back(i*2);
        score.emplace_back(i*3);
    }
    score.emplace_back(25);
    score.emplace_back(50);
    for(int i=1;i<=20;i++)
    {
        doubles.emplace_back(i*2);
    }
    doubles.emplace_back(50);
    for(auto i: doubles)
    {
        if(i<100)
            ans++;
    }
    for(auto i:score)
    {
        for(auto j:doubles)
        {
            if(i+j<100)
                ans++;
        }
    }
    for(int i=0;i<score.size();i++)
    {
        for(int j=i;j<score.size();j++)
        {
            for(auto k:doubles)
            {
                if(score[i]+score[j]+k<100)
                    ans++;
            }
        }
    }
    cout<<ans<<endl;
}

