#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull cache[80*6];
ull count(ull day,ull absent=0,ull late=0)
{
    if(absent==3)
        return 0;
    if(late>1)
        return 0;
    if(day==0)
        return 1;
    ull hash = day*6+absent*2+late;
    if(cache[hash])
        return cache[hash];
    ull res = count(day-1,0,late);
    res+= count(day-1,absent+1,late);
    res+=count(day-1,0,late+1);
    return cache[hash]=res;
}
int main()
{
    int day=30;
    cout<<count(day);
}
