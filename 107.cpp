#include<bits/stdc++.h>
using namespace std;
int fa[50],sz[50];
int fd(int n)
{
    return fa[n]=((n==fa[n])?fa[n]:fd(fa[n]));
}
class Edge
{
    public:
        int from,to,w;
        Edge(int _from,int _to,int _w):from(_from),to(_to),w(_w){}
        bool operator < (const Edge edge)const
        {
            return w>edge.w;
        }
};
int main()
{
    fstream f;
    f.open("107.txt");
    priority_queue<Edge> q;
    int sum=0;
    for(int i=1;i<=40;i++)
    {
        for(int j=1;j<=40;j++)
        {
            char c=0;
            int w=0;
            while(c!=','&&c!='\n')
            {
                c = f.get();
                if(c>='0'&&c<='9')
                {
                    w=w*10+c-'0';
                }
            }
            if(w&&i<j)
            {
                q.push(Edge(i,j,w));
                sum+=w;
            }
        }
    }
    cout<<sum<<'\n';
    for(int i=1;i<=40;i++)
        fa[i]=i,sz[i]=1;
    int ans=0;
    while(1)
    {
        Edge e = q.top();
        q.pop();
        int f1 = fd(e.from),f2=fd(e.to);
        if(fd(e.from)!=fd(e.to))
        {
            fa[f2]=f1;
            sz[f1]+=sz[f2];
            ans+=e.w;
        }
        if(sz[fd(e.from)]==40)
        {
            cout<<sum-ans<<'\n';
            break;
        }
    }
}
