/*
* Problem : C
* Author : Shifa Yang
* Date : 2020-04-20-19.09.15
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
const int N=1e6+10;
int n;
LL a[N];
int resolve(LL x)
{
    int res=0;
    while(x>0)
    {
        res++,x>>=1;
    }
    return res;
}
int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        rep(i,0,n)
        {
            cin>>a[i];
        }
        int ans=0;
        LL maxn=a[0];
        rep(i,1,n)
        {
            if (a[i]<maxn)
            {
                ans=std::max(ans,resolve(maxn-a[i]));
            }
            maxn = maxn>a[i]?maxn:a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
