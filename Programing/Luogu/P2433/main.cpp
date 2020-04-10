/*
* Problem : P2433
* Date : 2020-03-28-15.01.42
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
const int N=1e6+10;
const double pi=3.141593;
int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    switch(t)
    {
        case 1:
        {cout<<"I love Luogu!"<<endl; break;}
        case 2:
        {cout<<"6 4"<<endl; break;}
        case 3:
        {cout<<"3\n12\n2"<<endl; break;}
        case 4:
        {cout<<std::setprecision(6)<<500.0/3<<endl; break;}
        case 5:
        {cout<<(260+220)/32<<endl; break;}
        case 6:
        {cout<<sqrt(sqr(6)+sqr(9))<<endl; break;}
        case 7:
        {cout<<"110\n90\n0"<<endl; break;}
        case 8:
        {cout<<2*pi*5<<endl<<pi*sqr(5)<<endl<<4.0/3*pi*cub(5)<<endl; break;}
        case 9:
        {cout<<"22"<<endl; break;}
        case 10:
        {cout<<"9"<<endl; break;}
        case 11:
        {cout<<100/3.0<<endl; break;}
        case 12:
        {cout<<'M'-'A'+1<<endl<<(char)('A'+17)<<endl; break;}
        case 13:
        {cout<<(int)pow(4.0/3*pi*(cub(4)+cub(10)),1.0/3)<<endl; break;}
        case 14:
        {cout<<"50"<<endl; break;}

    }
    return 0;
}
