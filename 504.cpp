#include<bits/stdc++.h>
using namespace std;
int issquare[2000020];
int gcd[110][110];
void init()
{
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=i;j++)
        {
            gcd[i][j]=gcd[j][i]=__gcd(i,j);
        }
    }
    for(int i=1;i*i<=2000020;i++)
    {
        issquare[i*i]=1;
    }
}
int main()
{
    int ans=0;
    init();
    for(int a=1;a<=100;a++)
    {
        for(int b=1;b<=100;b++)
        {
            for(int c=1;c<=100;c++)
            {
                for(int d=1;d<=100;d++)
                {
                    int area=(a+c)*(b+d)/2;
                    int bound=gcd[a][b]+gcd[b][c]+gcd[c][d]+gcd[d][a];
                    int i=area-bound/2+1;
                    if(issquare[i])
                    {
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
}
