/*
* Problem : B
* Author : Shifa Yang
* Date : 2020-04-18-19.05.20
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
bool check(int x,int n, int m)
{
    rep(i,0,n)
    {
        if (x<=20) break;
        x = x/2+10;
    }
    rep(j,0,m)
    {
        x-=10;
    }
    if (x>0) return false;
    else return true;

}
int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        int x,n,m;
        cin>>x>>n>>m;
        if (check(x,n,m)) cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}
