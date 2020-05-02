/*
* Problem : A
* Author : Shifa Yang
* Date : 2020-04-29-19.20.24
*/
#include<bits/stdc++.h>
#define rep(i,s,e) for(int i=(s);i<(e);++i)
#define per(i,s,e) for(int i=(s)-1;i>=(e);--i)
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
LL min(LL x,LL y)
{
    if (x<y) return x;
    return y;
}
int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        LL x,y,a,b;
        cin>>x>>y>>a>>b;
        LL ans=0;
        if (x || y)
        {
            if (a*b>=0)
            {
                if (x<0 || y<0) x=-x,y=-y;
                ans+=a*abs(x-y);
                if (b<=2*a) ans+=b*min(x,y);
                else ans+=a*2*min(x,y);
            }
            else
            {
                ans+=a*(abs(x)+abs(y));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
