#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull pt[110][110];

int main()
{
    int ans=0;
    for(int i=0;i<=100;i++)
    {
        pt[i][0]=1;
    }
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=i;j++)
        {
            pt[i][j]=pt[i-1][j-1]+pt[i-1][j];
            if(pt[i][j]>1000000)
                ans++;
        }
    }
    cout<<ans;
}
