#include<bits/stdc++.h>
using namespace std;
int ans[10];
vector<int> num[10];
vector<int> generate(int n)
{
    vector<int> num;
    for(int i=1;;i++)
    {
        int x = (n-2)*i*(i-1)/2+i;
        if(x>=1000&&x<10000)
            num.push_back(x);
        if(x>=1e5)
            break;
    }
    return num;
}
int find(int last,int len)
{
    for(int i=5;i>=0;i--)
    {
        if(ans[i]!=0) continue;
        for(int j=0;j<num[i].size();j++)
        {
            bool unique=true;
            for(int k=5;k>=0;k--)
            {
                if(ans[k]==num[i][j])
                {
                    unique=false;
                    break;
                }
            }
            if(unique&&num[i][j]%100==ans[last]/100)
            {
                ans[i]=num[i][j];
                if(len==5)
                {
                    if(ans[i]/100==ans[5]%100)
                        return true;
                }
                if(find(i,len+1))return true;
            }
        }
        ans[i]=0;
    }
    return false;
}
int main()
{
    for(int i=0;i<=5;i++)
    {
        num[i]=generate(i+3);
    }
    for(int i=0;i<num[5].size();i++)
    {
        ans[5]=num[5][i];
        if(find(5,1))break;
    }
    int anssum=0;
    for(int i=0;i<=5;i++)
    {
        cout<<ans[i]<<" ";
        anssum+=ans[i];
    }
    cout<<'\n';
    cout<<anssum<<endl;
}
