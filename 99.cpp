#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans,cnt=1,a,b;
    double max=0;
    fstream f;
    f.open("99.txt");
    for(int i=1;i<=1000;i++)
    {
        string s;
        getline(f,s);
        sscanf(s.c_str(),"%d,%d",&a,&b);
        cout<<a<<' '<<b<<'\n';
        double t = b*log10(a);
        if(t>max)
        {
            max=t;
            ans=cnt;
        }
        cnt++;
    }
    cout<<ans;
}
