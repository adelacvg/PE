#include<bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int main()
{
    int n=1;
    //cout<<pi<<endl;
    while(1)
    {
        double theta = asin((n*sqrt(2*n)-n+1)/(n*n+1));
        double area = 2*(1+sin(theta)-cos(theta)-theta)/(4-pi);
        //cout<<theta<<endl;
        //cout<<area<<endl;
        if(area<0.001)
            break;
        n++;
    }
    cout<<n<<endl;
}
