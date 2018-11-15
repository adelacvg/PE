#include<bits/stdc++.h>
using namespace std;
int sudo[10][10];

bool solve()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(sudo[i][j]!=0)
                continue;
            int flag[10];
            memset(flag,0,sizeof(flag));
            for(int t=1;t<=9;t++)
            {
                if(sudo[t][j])
                {
                    flag[sudo[t][j]]=1;
                }
                if(sudo[i][t])
                {
                    flag[sudo[i][t]]=1;
                }
            }
            int x=((i-1)/3)*3;
            int y=((j-1)/3)*3;
            for(int xx=1;xx<=3;xx++)
            {
                for(int yy=1;yy<=3;yy++)
                {
                    if(sudo[x+xx][y+yy]!=0)
                        flag[sudo[x+xx][y+yy]]=1;
                }
            }
            for(int x=1;x<=9;x++)
            {
                if(!flag[x])
                {
                    sudo[i][j]=x;
                    if(solve())
                        return true;
                }
            }
            sudo[i][j]=0;
            return false;
        }
    }
    return true;
}
                        
int main()
{
    ifstream f;
    int ans=0;
    f.open("96.txt");
    string arg0,arg1;
    char c;
    int cnt=1;
    for(int i=1;i<=50;i++)
    {
        f>>arg0>>arg1;
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                f>>c;
                sudo[i][j]=c-'0';
            }
        }
        solve();
        cout<<"case: "<<(cnt++)<<endl;
        for(int x=1;x<=9;x++)
        {
            for(int y=1;y<=9;y++)
                cout<<sudo[x][y]<<" ";
            cout<<endl;
        }
        int t=0;
        for(int y=1;y<=3;y++)
        {
            t=t*10+sudo[1][y];
        }
        cout<<t<<endl;
        ans+=t;
    }
    cout<<ans;
}
