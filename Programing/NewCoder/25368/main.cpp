/*
* Problem : 25368
* Author : Shifa Yang
* Date : 2020-04-22-10.57.46
*/
#include<bits/stdc++.h>
#include<string>
#define rep(i,s,e) for(int i=(s);i<(e);++i)
#define per(i,s,e) for(int i=(s)-1;i>=(e);--i)
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
#endif
typedef long long LL;
typedef unsigned long long ULL;
using std::cin; using std::cout; using std::endl;
const LL INF=1<<30;
const LL MOD=1e9+7;
const int N=1e6+10;
string path;
int line;
std::map<pair<string,int>,pair<int,int> > mp;
string get_filename(string path)
{
    int n = path.length();
    per(i,n,0)
    {
        if (path[i]=='\\')
        {
            return path.substr(i+1);
        }
    }
}
struct Node
{
    string name;
    int line;
    int cnt;
    int id;
    bool operator <(const Node &a)const
    {
        if (cnt==a.cnt) return id<a.id;
        return cnt>a.cnt;
    }
}ans[N];
int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    int t=0;
    while(cin>>path>>line)
    {
        string filename = get_filename(path);
        auto it = mp.find(make_pair(filename,line));
        if (it!=mp.end())
        {
            (it->second).first++;
//            pair<int,int> p = mp[make_pair(filename,line)];
//            p.first++;
//            mp[make_pair(filename,line)] = p;
        }
        else mp[make_pair(filename,line)]=make_pair(1,t++);
    }
    int n=0;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        pair<string,int> p = it->first;
        pair<int,int> q = it->second;
        string filename = p.first;
        int line = p.second;
        int cnt = q.first;
        int id = q.second;
        if (filename.length()>16) filename=filename.substr(filename.length()-16);
        ans[n++]={filename,line,cnt,id};
    }
    sort(ans,ans+n);
    n=min(n,8);
    rep(i,0,n)
    {
        cout<<ans[i].name<<' '<<ans[i].line<<' '<<ans[i].cnt<<endl;
        logs(ans[i].id);
    }
//    fclose(stdin);
    return 0;
}
