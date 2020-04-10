/*
* Problem : 03-4
* Date : 2020-03-04-14.27.28
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
    #define loga(...)
#endif
typedef long long LL;
typedef unsigned long long ULL;
using std::cin; using std::cout; using std::endl;
const LL INF=1<<30;
const LL MOD=1e9+7;
const int N=2e2+10;
LL x[N],y[N];
LL d[N][N];
LL dis(int i,int j)
{
    return 1LL*sqr(x[i]-x[j])+1LL*sqr(y[i]-y[j]);
}
int n,m,k;
LL r;
int main(){
//    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(d,0,sizeof(d));
    cin>>n>>m>>k>>r;
    logs(n,m,k,r);
    rep(i,0,n)
    {
        cin>>x[i]>>y[i];
    }
    rep(i,0,m)
    {
        cin>>x[n+i]>>y[n+i];
    }
    rep(i,0,n+m)
    {
        rep(j,0,i)
        {
            logs(i,j);
            logs(x[i],y[i],x[j],y[j]);
            logs(dis(i,j),r*r);
            if (dis(i,j)<=1LL*r*r) d[i][j]=d[j][i]=1;
        }
    }
    rep(i,0,n+m)
    {
        rep(j,0,n+m)
        {
            cout<<d[i][j];
        }
        cout<<endl;
    }
    return 0;
}

/*

5 3 1 3
0 0
5 5
0 3
0 5
3 5
3 3
4 4
3 0


2 0 0 3
0 0
5 5


*/
