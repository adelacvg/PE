#include<bits/stdc++.h>
using namespace std;
int cnt[50];
random_device rd;
mt19937 ran(rd());
int dice(int n)
{
    uniform_int_distribution<int> uid(1,n);
    return uid(ran);
}
int main()
{
    int dice_size=4;
    int show_fields=3;
    int rolls=1e6;
    srand(time(0));
    int num_fields=40;
    int GO =0;
    int JAIL=10;
    int G2J=30;
    int CC[3]={2,17,33};
    int CH[3]={7,22,36};
    int R[3]={15,25,5};
    int U[3]={12,28,12};
    vector<int> chance,community;
    for(int i=0;i<16;i++)
    {
        chance.push_back(i);
        community.push_back(i);
    }
    random_shuffle(chance.begin(),chance.end());
    random_shuffle(community.begin(),community.end());
//Monte-Carlo simulation
    int cur=GO;
    int doubles=0;
    for(int ro=1;ro<=rolls;ro++)
    {
        int dice1=dice(dice_size);
        int dice2=dice(dice_size);
        int nxt=(cur+dice1+dice2)%num_fields;

        if(dice1==dice2)
            doubles++;
        else
            doubles=0;
        if(doubles==3)
        {
            nxt=JAIL;
            doubles=0;
        }
        for(int i=0;i<3;i++)
        {
            if(CH[i]==nxt)
            {
                switch(chance[0])
                {
                    case 0:nxt=GO;break;
                    case 1:nxt=JAIL;break;
                    case 2:nxt=11;break;
                    case 3:nxt=24;break;
                    case 4:nxt=39;break;
                    case 5:nxt=5;break;
                    case 6:
                    case 7:nxt=R[i];break;
                    case 8:nxt=U[i];break;
                    case 9:nxt-=3;break;
                }
                rotate(chance.begin(),chance.begin()+1,chance.end());
            }
        }
        for(int i=0;i<3;i++)
        {
            if(nxt==CC[i])
            {
                switch(community[0])
                {
                    case 0:nxt=GO;break;
                    case 1:nxt=JAIL;break;
                }
                rotate(community.begin(),community.begin()+1,community.end());
            }
        }
        if(nxt==G2J)
            nxt=JAIL;
        cnt[nxt]++;
        cur=nxt;
    }
    multimap<double,int> m;
    for(int i=0;i<40;i++)
    {
        m.insert(make_pair(1.0*cnt[i]/rolls,i));
    }
    auto i=m.rbegin();
    for(int j=1;j<=3;j++)
    {
        cout<<setw(2)<<setfill('0')<<(*i++).second;
    }
}
