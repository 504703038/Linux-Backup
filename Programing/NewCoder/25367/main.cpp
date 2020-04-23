/*
* Problem : 25367
* Author : Shifa Yang
* Date : 2020-04-22-10.56.44
*/
#include<bits/stdc++.h>
#define rep(i,s,e) for(int i=(s);i<(e);++i)
#define per(i,s,e) for(int i=(s)-1;i>=(e);--i)
#define sqr(x) ((x)*(x))
#define cub(x) ((x)*(x)*(x))
using namespace std;
#ifdef LOCAL
    void dbg() { std::cout << "\033[39;0m\n"; }
    template<typename T, typename... A>
    void dbg(T a, A... x) { std::cout << a << ' '; dbg(x...); }
    #define logs(x...) cout << "---------------- \033[32;1m" << #x << " -> "; dbg(x);
    #define loga(a,s,t) for(int i=s;i<=t;i++) { cout << "---------------- \033[32;1m" << #a << '[' << i << ']' << " -> "; dbg(a[i]); }
#else
    #define logs(...)
#endif
typedef long long LL;
typedef unsigned long long ULL;
using std::cin; using std::cout; using std::endl;
const LL INF=1<<30;
const LL MOD=1e9+7;
const int N=3e6+10;
int n,m,a[N];
struct node
{
    int l,r,v;
}tree[N<<1];
void build(int l,int r,int x)
{
    tree[x].l=l,tree[x].r=r;
    if (l==r)
    {
        tree[x].v=a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,x<<1);
    build(mid+1,r,x<<1|1);
    tree[x].v=max(tree[x<<1].v,tree[x<<1|1].v);
}
int quest(int l,int r,int x)
{
    if (tree[x].l==l && tree[x].r==r) return tree[x].v;
    int mid=(tree[x].l+tree[x].r)>>1;
    if (r<=mid)
    {
        return quest(l,r,x<<1);
    }
    else if (l>mid)
    {
        return quest(l,r,x<<1|1);
    }
    else
    {
        return max(quest(l,mid,x<<1),quest(mid+1,r,x<<1|1));
    }
}
void update(int p,int v,int x)
{
    if (tree[x].l==p && tree[x].r==p)
    {
        tree[x].v=v;
        return;
    }
    int mid = (tree[x].l+tree[x].r)>>1;
    if (p<=mid) update(p,v,x<<1);
    else update(p,v,x<<1|1);
    tree[x].v=max(tree[x<<1].v,tree[x<<1|1].v);
}
int main(){
    while(cin>>n>>m)
    {
        rep(i,1,n+1)
        {
            cin>>a[i];
        }
        build(1,n,1);
        rep(i,0,m)
        {
            char c;
            int x,y;
            cin>>c>>x>>y;
            logs(c,x,y);
            if (c=='Q')
            {
                if (x>y) swap(x,y);
                cout<<quest(x,y,1)<<endl;
                logs(1)
            }
            else
            {
                update(x,y,1);
                logs(2)
            }
        }

    }
    return 0;
}
