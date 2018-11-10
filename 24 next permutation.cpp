#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s = "0123456789";

    for(int i=1;i<1e6;i++)
    {
        next_permutation(s.begin(),s.end());
    }
    cout<<s;
}
