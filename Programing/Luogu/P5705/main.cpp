/*
* Problem : P5705
* Date : 2020-03-28-14.50.45
*/
#include<bits/stdc++.h>
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define per(i,s,e) for(int i=s;i>=e;--i)
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
const int N=10;
char s[N];
int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    int l=strlen(s);
    while(l>0)
    {
        cout<<s[l-1];
        l--;
    }
    cout<<endl;
    return 0;
}