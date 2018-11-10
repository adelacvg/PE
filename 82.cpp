#include<bits/stdc++.h>
using namespace std;
struct Cell
{
    int x,y;
    long long int w;
    Cell(int _x,int _y,int _w):x(_x),y(_y),w(_w){}
    bool operator < (const Cell& cell) const
    {
        return w > cell.w;
    }
};
long long int mat[110][110];
long long int vis[110][110];
long long int search()
{
    priority_queue<Cell> next;
    for(int i = 1;i<=80;i++)
        next.push(Cell(i,1,mat[i][1]));
    while(!next.empty())
    {
        Cell cell = next.top();
        next.pop();
        if(vis[cell.x][cell.y])
            continue;
        vis[cell.x][cell.y]=1;
        if(cell.y==80)
            return cell.w;
        if(cell.y+1<=80)
            next.push(Cell(cell.x,cell.y+1,cell.w+mat[cell.x][cell.y+1]));
        if(cell.x+1<=80)
            next.push(Cell(cell.x+1,cell.y,cell.w+mat[cell.x+1][cell.y]));
        if(cell.x>1)
            next.push(Cell(cell.x-1,cell.y,cell.w+mat[cell.x-1][cell.y]));
    }

}
int main()
{
    fstream f;
    f.open("82.txt");
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
    cout<<search();
}
