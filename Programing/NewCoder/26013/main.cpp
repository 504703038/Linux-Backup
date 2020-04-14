#include <iostream>

using namespace std;
const int N=15;
int a[N][N],n;
bool v[N];
bool over = false;
struct Node
{
    int x,y;
}s,q[100];
//列验证
bool f_c(int c)
{
//    cout<<"f_c{c}:"<<c<<endl;
    for(int i=1;i<10;++i) v[i]=false;
    for(int i=1;i<10;++i)
    {
        if (!a[i][c] || !v[a[i][c]]) v[a[i][c]]=true;
        else return false;
    }
    return true;
}
//行验证
bool f_r(int r)
{
    for(int i=1;i<10;++i) v[i]=false;
    for(int i=1;i<10;++i)
    {
        if (!a[r][i] || !v[a[r][i]]) v[a[r][i]]=true;
        else return false;
    }
    return true;
}
//块验证
bool f_block(Node s)
{
    for(int i=1;i<10;++i) v[i]=false;
//    (1,1)
    if (s.x<=3 && s.y<=3)
    {
        for(int i=1;i<=3;++i)
        {
            for(int j=1;j<=3;++j)
            {
                if (!a[i][j] || !v[a[i][j]]) v[a[i][j]]=true;
                else return false;
            }
        }
        return true;
    }
//    (1,2)
    if (s.x<=3 && s.y>=4 && s.y<=6)
    {
        for(int i=1;i<=3;++i)
        {
            for(int j=4;j<=6;++j)
            {
                if (!a[i][j] || !v[a[i][j]]) v[a[i][j]]=true;
                else return false;
            }
        }
        return true;
    }
//    (1,3)
    if (s.x<=3 && s.y>=7)
    {
        for(int i=1;i<=3;++i)
        {
            for(int j=7;j<=9;++j)
            {
                if (!a[i][j] || !v[a[i][j]]) v[a[i][j]]=true;
                else return false;
            }
        }
        return true;
    }
//    (2,1)
    if (s.x>=4 && s.x<=6 && s.y<=3)
    {
        for(int i=4;i<=6;++i)
        {
            for(int j=1;j<=3;++j)
            {
                if (!a[i][j] || !v[a[i][j]]) v[a[i][j]]=true;
                else return false;
            }
        }
        return true;
    }
//    (2,2)
    if (s.x>=4 && s.x<=6 && s.y>=4 && s.y<=6)
    {
        for(int i=4;i<=6;++i)
        {
            for(int j=4;j<=6;++j)
            {
                if (!a[i][j] || !v[a[i][j]]) v[a[i][j]]=true;
                else return false;
            }
        }
        return true;
    }
//    (2,3)
    if (s.x>=4 && s.x<=6 && s.y>=7)
    {
        for(int i=4;i<=6;++i)
        {
            for(int j=7;j<=9;++j)
            {
                if (!a[i][j] || !v[a[i][j]]) v[a[i][j]]=true;
                else return false;
            }
        }
        return true;
    }
//    (3,1)
    if (s.x>=7 && s.y<=3)
    {
        for(int i=7;i<=9;++i)
        {
            for(int j=1;j<=3;++j)
            {
                if (!a[i][j] || !v[a[i][j]]) v[a[i][j]]=true;
                else return false;
            }
        }
        return true;
    }
//    (3,2)
    if (s.x>=7 && s.y>=4 && s.y<=6)
    {
        for(int i=7;i<=9;++i)
        {
            for(int j=4;j<=6;++j)
            {
                if (!a[i][j] || !v[a[i][j]]) v[a[i][j]]=true;
                else return false;
            }
        }
        return true;
    }
//    (3,3)
    if (s.x>=7 && s.y>=7)
    {
        for(int i=7;i<=9;++i)
        {
            for(int j=7;j<=9;++j)
            {
                if (!a[i][j] || !v[a[i][j]]) v[a[i][j]]=true;
                else return false;
            }
        }
        return true;
    }
    return true;
}
//深搜
void dfs(int  t)
{
    if (t==n)
    {
        over=true;
        return;
    }
    Node s=q[t];
    for(int i=1;i<10;++i)
    {
        a[s.x][s.y]=i;
        if (f_r(s.x) && f_c(s.y) && f_block(s))
        {
            dfs(t+1);
        }
        if (over) return;
        a[s.x][s.y]=0;
    }
}
void output()
{
    for(int i=1;i<10;++i)
    {
        for(int j=1;j<10;j++)
        {
            cout<<a[i][j]<<(j==9?'\n':' ');
        }
    }
}
int main()
{
    n=0;
    for(int i=1;i<10;++i)
    {
        for(int j=1;j<10;++j)
        {
            cin>>a[i][j];
            if (!a[i][j])
            {
                q[n++]=(Node){i,j};
            }
        }
    }
    dfs(0);
    output();
    fclose(stdout);
    return 0;
}
