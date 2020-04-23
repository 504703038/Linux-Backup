/*
* Problem : C
* Author : Shifa Yang
* Date : 2020-04-21-19.40.42
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
const LL INF=1LL<<60;
const LL MOD=1e9+7;
const int N=3e5+10;
const double eps=1e-9;
int n;
LL a[N],b[N];
LL max(LL a,LL b)
{
    return a>b?a:b;
}
LL min(LL a,LL b)
{
    return a<b?a:b;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        LL ans=0;
        rep(i,0,n)
        {
            cin>>a[i]>>b[i];
        }
        rep(i,0,n)
        {
            int j=(i+1)%n;
            if (b[i]<a[j]) ans+=a[j]-b[i],a[j]=b[i];
        }
        LL minn=INF;
        rep(i,0,n)
        {
            minn=min(minn,a[i]);
        }
        cout<<ans+minn<<endl;

    }
    return 0;
}
