/*
* Problem : B
* Author : Shifa Yang
* Date : 2020-04-20-18.26.01
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
int n,a[N];
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
        std::sort(a,a+n);
        int i=(n-1)/2,j=(n+1)/2;
        if (n&1) cout<<a[i--]<<' ';
        else cout<<a[i--]<<' '<<a[j++];
        while(i>=0 && j<n)
        {
            cout<<' '<<a[i--]<<' '<<a[j++];
        }
        cout<<endl;
    }
    return 0;
}
