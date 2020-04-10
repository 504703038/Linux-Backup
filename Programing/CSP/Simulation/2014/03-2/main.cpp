#include <iostream>
using namespace std;
const int N=15;
struct Matrix
{
    int x1,x2,y1,y2;
    int seq;
    bool inside(int x,int y)
    {
        if (x>=x1 && x<=x2 && y>=y1 && y<=y2) return true;
        return false;
    }
}a[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
        a[i].seq=i;
    }
    for(int j=0;j<m;++j)
    {
        int x,y,p; cin>>x>>y;
        p=-1;
        for(int i=0;i<n;++i)
        {
            if (a[i].inside(x,y))
            {
                if (p==-1 || a[p].seq<a[i].seq) p=i;
            }
        }
        if (p==-1)
        {
            cout<<"IGNORED"<<endl;
            continue;
        }
        cout<<p+1<<endl;
        for(int i=0;i<n;++i)
        {
            if (a[i].seq>a[p].seq) a[i].seq-=1;
        }
        a[p].seq=n-1;
    }
    return 0;
}


/*

3 4
0 0 4 4
1 1 5 5
2 2 6 6
1 1
0 0
4 4
0 5

*/
