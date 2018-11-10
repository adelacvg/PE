#include<bits/stdc++.h>
using namespace std;
int mat[100][100],vis[100][100];
struct Cell
{
    int x,y,w;
    Cell(int _x,int _y,int _w):
        x(_x),y(_y),w(_w){}
    operator < (const Cell& cell)const
    {
        return w>cell.w;
    }
};
int main()
{
    fstream f;
    f.open("83.txt");
    char c;
    for(int i=1;i<=80;i++)
    {
        for(int j=1;j<=80;j++)
        {
            f>>mat[i][j];
            if(j!=80)
                f>>c;
        }
    }
    priority_queue<Cell> q;
    q.push(Cell(1,1,mat[1][1]));
    while(!q.empty())
    {
        Cell cur = q.top();
        q.pop();
        vis[cur.x][cur.y]=1;
        if(cur.x==80&&cur.y==80)
        {
            cout<<cur.w;
            return 0;
        }
        if(cur.x>1&&!vis[cur.x-1][cur.y])
            q.push(Cell(cur.x-1,cur.y,cur.w+mat[cur.x-1][cur.y]));
        if(cur.y>1&&!vis[cur.x][cur.y-1])
            q.push(Cell(cur.x,cur.y-1,cur.w+mat[cur.x][cur.y-1]));
        if(cur.x<80&&!vis[cur.x+1][cur.y])
            q.push(Cell(cur.x+1,cur.y,cur.w+mat[cur.x+1][cur.y]));
        if(cur.y<80&&!vis[cur.x][cur.y+1])
            q.push(Cell(cur.x,cur.y+1,cur.w+mat[cur.x][cur.y+1]));
    }
}
