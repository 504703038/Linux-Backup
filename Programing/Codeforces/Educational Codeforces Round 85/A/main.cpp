/*
* Problem : A
* Author : Shifa Yang
* Date : 2020-04-21-18.59.00
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
const int N=1e3+10;
int n,a[N],b[N];
int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        rep(i,0,n)
        {
            cin>>a[i]>>b[i];
        }
        bool fine = true;
        rep(i,0,n)
        {
            if (b[i]>a[i] ||  i && (a[i]<a[i-1] || b[i]<b[i-1] || a[i]-a[i-1]<b[i]-b[i-1]))
            {
                fine=false;
                break;
            }
        }
        cout<<(fine?"YES":"NO")<<endl;
    }
    return 0;
}
