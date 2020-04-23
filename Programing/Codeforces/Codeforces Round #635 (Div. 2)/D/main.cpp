/*
* Problem : D
* Author : Shifa Yang
* Date : 2020-04-20-14.09.17
*/
#include<bits/stdc++.h>
#define rep(i,s,e) for(int i=s;i<e;++i)
#define per(i,s,e) for(int i=s;i>e;--i)
#define sqr(x) ((x)*(x))
#define cub(x) ((x)*(x)*(x))
//using namespace std;
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
const int N=1e5+10;
int nr,ng,nb;
LL r[N],g[N],b[N];
LL cul(int x,int y,int z)
{
    return sqr(1LL*x-1LL*y)+sqr(1LL*y-1LL*z)+sqr(1LL*z-1LL*x);
}
LL min(LL x,LL y)
{
    if (x<y) return x;
    return y;
}
int main(){
//    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&nr,&ng,&nb);
        logs(nr,ng,nb);
        rep(i,0,nr) {scanf("%lld",&r[i]);}
        rep(i,0,ng) {scanf("%lld",&g[i]);}
        rep(i,0,nb) {scanf("%lld",&b[i]);}
        std::sort(r,r+nr);
        std::sort(g,g+ng);
        std::sort(b,b+nb);
        LL ans=cul(r[0],g[0],b[0]);
        rep(i,0,nr)
        {
            int pos_1 = std::lower_bound(g,g+ng,r[i])-g;
            int pos_2 = pos_1-1;
            int pos_3 = std::lower_bound(b,b+nb,r[i])-b;
            int pos_4 = pos_3-1;
            if (pos_1>=0 && pos_1<ng)
            {
                if (pos_3>=0 && pos_3<nb)
                {
                    ans=min(ans,cul(r[i],g[pos_1],b[pos_3]));
                }
                if (pos_4>=0 && pos_4<nb)
                {
                    ans=min(ans,cul(r[i],g[pos_1],b[pos_4]));
                }
            }
            if (pos_2>=0 && pos_2<ng)
            {
                if (pos_3>=0 && pos_3<nb)
                {
                    ans=min(ans,cul(r[i],g[pos_2],b[pos_3]));
                }
                if (pos_4>=0 && pos_4<nb)
                {
                    ans=min(ans,cul(r[i],g[pos_2],b[pos_4]));
                }
            }
            logs(ans);
        }

        rep(i,0,ng)
        {
            int pos_1 = std::lower_bound(r,r+nr,g[i])-r;
            int pos_2 = pos_1-1;
            int pos_3 = std::lower_bound(b,b+nb,g[i])-b;
            int pos_4 = pos_3-1;
            if (pos_1>=0 && pos_1<nr)
            {
                if (pos_3>=0 && pos_3<nb)
                {
                    ans=min(ans,cul(g[i],r[pos_1],b[pos_3]));
                }
                if (pos_4>=0 && pos_4<nb)
                {
                    ans=min(ans,cul(g[i],r[pos_1],b[pos_4]));
                }
            }
            if (pos_2>=0 && pos_2<nr)
            {
                if (pos_3>=0 && pos_3<nb)
                {
                    ans=min(ans,cul(g[i],r[pos_2],b[pos_3]));
                }
                if (pos_4>=0 && pos_4<nb)
                {
                    ans=min(ans,cul(g[i],r[pos_2],b[pos_4]));
                }
            }
            logs(ans);
        }

        rep(i,0,nb)
        {
            int pos_1 = std::lower_bound(g,g+ng,b[i])-g;
            int pos_2 = pos_1-1;
            int pos_3 = std::lower_bound(r,r+nr,b[i])-r;
            int pos_4 = pos_3-1;
            if (pos_1>=0 && pos_1<ng)
            {
                if (pos_3>=0 && pos_3<nr)
                {
                    ans=min(ans,cul(b[i],g[pos_1],r[pos_3]));
                }
                if (pos_4>=0 && pos_4<nr)
                {
                    ans=min(ans,cul(b[i],g[pos_1],r[pos_4]));
                }
            }
            if (pos_2>=0 && pos_2<ng)
            {
                if (pos_3>=0 && pos_3<nr)
                {
                    ans=min(ans,cul(b[i],g[pos_2],r[pos_3]));
                }
                if (pos_4>=0 && pos_4<nr)
                {
                    ans=min(ans,cul(b[i],g[pos_2],r[pos_4]));
                }
            }
            logs(ans);
        }
        printf("%lld\n",ans);

    }
    return 0;
}

/*
1
3 2 2
3 4 5
6 7
1 2

*/
