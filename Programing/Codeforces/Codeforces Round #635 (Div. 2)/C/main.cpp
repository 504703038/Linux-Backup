/*
* Problem : C
* Author : Shifa Yang
* Date : 2020-04-20-13.41.43
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
const int N=2e5+10;
int n,k;
bool v[N];
int deep[N],cnt[N];
int ans[N];
std::vector<int>a[N];
int dfs(int x)
{
    cnt[x]=1,v[x]=1;
    rep(i,0,a[x].size())
    {
        int y = a[x][i];
        if (v[y]) continue;
        deep[y]=deep[x]+1;
        cnt[x]+=dfs(y);
    }
    ans[x]=deep[x]-cnt[x];
    return cnt[x];
}
bool cmp(int x,int y)
{
    return x>y;
}
int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(v,0,sizeof(v));
    cin>>n>>k;
    rep(i,1,n)
    {
        int x,y; cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    logs(1)
    deep[1]=1;
    dfs(1);
    std::sort(ans+1,ans+1+n,cmp);
    LL sum=0LL;
    rep(i,0,k)
    {
        sum+=ans[i+1];
    }
    cout<<sum<<endl;
    return 0;
}
