#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull width=9;
ull height=12;
bitset<200> emptyrow(0);
bool use(ull pos,bitset<200>& row)
{
    bitset<200> mask(1<<pos);
    bool res = ((row&mask)==0);
    row|=mask;
    return res;
}
ull search(ull rowsleft,bitset<200> rowA,bitset<200> rowB,bitset<200> rowC)
{
    if(rowsleft==0)
        return 1;
    bitset<200> fullrow((1<<width)-1);
    if(rowA == fullrow)
        return search(rowsleft-1,rowB,rowC,emptyrow);
    ull pos=0;
    bitset<200> mask(1<<pos);
    //cout<<rowA<<'\n';
    while((rowA&mask)!=0)
    {
        pos++;
        mask=1<<pos;
        //cout<<mask<<'\n';
    }
    bitset<200> hash(0);
    hash = rowsleft;
    hash<<=width;
    hash|=rowA;
    hash<<=width;
    hash|=rowB;
    hash<<=width;
    hash|=rowC;
    static unordered_map<bitset<200>,ull> cache;
    if(cache.find(hash)!=cache.end())
        return cache[hash];
    ull res=0;
    
    bitset<200> a(0),b(0),c(0);
    //  **
    //  *
    a=rowA,b=rowB,c=rowC;
    if(rowsleft>=2&&pos<=width-2&&use(pos,a)&&use(pos+1,a)&&use(pos,b))
        res+=search(rowsleft,a,b,c);
    //  **
    //   *
    a=rowA,b=rowB,c=rowC;
    if(rowsleft>=2&&pos<=width-2&&use(pos,a)&&use(pos+1,a)&&use(pos+1,b))
        res+=search(rowsleft,a,b,c);
    //  *
    //  **
    a=rowA,b=rowB,c=rowC;
    if(rowsleft>=2&&pos<=width-2&&use(pos,a)&&use(pos,b)&&use(pos+1,b))
        res+=search(rowsleft,a,b,c);
    //   *
    //  **
    a=rowA,b=rowB,c=rowC;
    if(rowsleft>=2&&pos>=1&&pos<=width-1&&use(pos,a)&&use(pos,b)&&use(pos-1,b))
        res+=search(rowsleft,a,b,c);
    //  *
    //  *
    //  *
    a=rowA,b=rowB,c=rowC;
    if(rowsleft>=3&&pos<=width-1&&use(pos,a)&&use(pos,b)&&use(pos,c))
        res+=search(rowsleft,a,b,c);
    //  ***
    a=rowA,b=rowB,c=rowC;
    if(rowsleft>=1&&pos<=width-3&&use(pos,a)&&use(pos+1,a)&&use(pos+2,a))
        res+=search(rowsleft,a,b,c);
    cache[hash]=res;
    return res;
}
int main()
{
    if(width>height)
        swap(width,height);
    cout<<search(height,emptyrow,emptyrow,emptyrow);
}
