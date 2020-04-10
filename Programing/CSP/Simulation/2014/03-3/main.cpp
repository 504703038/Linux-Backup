/*
* Problem : 03-3
* Date : 2020-03-03-17.53.04
*/
#include<bits/stdc++.h>
#include <string>
#define rep(i,s,e) for(int i=(s);i<(e);++i)
#define per(i,s,e) for(int i=(s);i>(e);--i)
#define sqr(x) ((x)*(x))
#define cub(x) ((x)*(x)*(x))
using namespace std;
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
//using std::cin; using std::cout; using std::endl;
const LL INF=1<<30;
const LL MOD=1e9+7;
const int N=300;
map<string,string> mp;
vector<string> v;
string s;
int opt[N],n;
bool visi[30];
//0表示无，1表示无参，2表示带参
void prep()
{
    v.clear(); mp.clear();
    memset(visi,0,sizeof(visi));
    int l=0,r;
    r=s.find(' ',l);
    while(r!=string::npos)
    {
        v.push_back(s.substr(l,r-l));
        l=r+1; r=s.find(' ',l);
    }
    cout<<r<<endl;
    v.push_back(s.substr(l,s.length()-l));
}
bool is_lc(char c)
{
    return c>='a' && c<='z';
}
int main(){
//    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("in","r",stdin);
    memset(opt,0,sizeof(opt));
    cin>>s;
    for(int i=0;i<s.length();++i)
    {
        if (s[i]==':') opt[s[i-1]-'a']=2;
        else opt[s[i]-'a']=1;
    }
    cin>>n; getline(cin,s);
    rep(i,0,n)
    {
        getline(cin,s);
        prep();
        rep(j,1,v.size())
        {
            //是否符合选项条件
            if (v[j].length()==2 && v[j][0]=='-' && is_lc(v[j][1]))
            {
                int c = v[j][1]-'a';
                if (opt[c]==0) break;
                else if (opt[c]==1) visi[c]=true,mp[v[j]]="";
                else if (opt[c]==2)
                {
                    //判断v[i+1]是否符合参数条件
                    if (j+1>=v.size()) break;
                    visi[c]=true;
                    mp[v[j]]=v[j+1];
                    j+=1;
                }
            }
            else break;
        }
        cout<<"Case "<<i+1<<":";
        for(auto it=mp.begin();it!=mp.end();++it)
        {
            string key = it->first;
            string value = it->second;
            if (opt[key[1]-'a']==2) cout<<" "+key+" "+value;
            else cout<<" "+key;
        }
        cout<<endl;
    }
    return 0;
}

