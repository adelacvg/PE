#include<bits/stdc++.h>
using namespace std;

set<string> res;

unsigned int sz;
unsigned int tripletSum;

void fillLine(unsigned int pos,
 vector<unsigned int> inner,
 vector<unsigned int> outer,unsigned int used)
{
    if(pos==sz-1)
    {
        outer[sz-1]=tripletSum-(inner[0]+inner[sz-1]);
        unsigned int mask=1<<outer[sz-1];
        if(used&mask)
            return;
        for(auto x:outer)
        {
            if(x<outer[0])
                return;
        }
        string id;
        for(auto i=0u;i<sz;i++)
        {
            id+=to_string(outer[i])+
            to_string(inner[i])+
            to_string(inner[(i+1)%sz]);
        }
        res.insert(id);
        return;
    }

    for(auto i=1u;i<=2*sz;i++)
    {
        unsigned int innerMask = 1<<i;
        if(innerMask&used)
            continue;
        inner[pos+1]=i;
        unsigned int nextUsed=used|innerMask;

        outer[pos]=tripletSum-(inner[pos]+i);
        unsigned int outerMask=1<<outer[pos];
        if(nextUsed&outerMask)
            continue;
        nextUsed |= outerMask;

        fillLine(pos+1, inner, outer, nextUsed);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>sz>>tripletSum;

    vector<unsigned int> inner(sz),outer(sz);
    unsigned int allowed = ~((1<<(2*sz+1))-2);

    std::chrono::duration<double, std::milli> ms1,ms2,ms3,ms4,ms5;
    auto t1 = std::chrono::high_resolution_clock::now();
    for(auto i=1u;i<=2*sz;i++)
    {
        inner[0]=i;
        fillLine(0,inner,outer,allowed|(1<<i));
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    ms1 = t2 - t1;
    cout<<ms1.count()<<endl;
    for(auto i:res)
        cout<<i<<endl;
}