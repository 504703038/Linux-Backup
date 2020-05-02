/*
* Problem : B
* Author : Shifa Yang
* Date : 2020-04-29-19.32.56
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
const int N=1e3+10;
char s[N];
int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        cin>>s;
        int l=strlen(s);
        int cnt=0;//0的个数
        rep(i,0,l)
        {
            if (s[i]=='0') cnt++;
        }
        if (cnt==l || cnt==0) cout<<s<<endl;
        else
        {
            rep(i,0,l)
            {
                cout<<"01";
            }
            cout<<endl;
        }
    }
    return 0;
}
