/*
* Problem : 25369
* Author : Shifa Yang
* Date : 2020-04-22-13.07.42
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
const int N=1e2+10;
string str,str1,str2;
std::map<string,int>mp;
int cnt[30];
void get_puke(string str,vector<string> &e)
{
    int pos = str.find(' ');
    while(pos!=-1)
    {
        e.push_back(str.substr(0,pos));
        str=str.substr(pos+1);
        pos = str.find(' ');
    }
    e.push_back(str);
}
pair<int,int> solve(string str)
{
    memset(cnt,0,sizeof(cnt));
    vector<string> e;
    get_puke(str,e);
    int boom=-1;
    int three=-1;
    int two=-1;
    int one=-1;
    for(auto it=e.begin();it!=e.end();++it)
    {
        cnt[mp[*it]]++;
        if (cnt[mp[*it]]==4 && mp[*it]>boom) boom=mp[*it];
        if (cnt[mp[*it]]==3 && mp[*it]>three) three=mp[*it];
        if (cnt[mp[*it]]==2 && mp[*it]>two) two=mp[*it];
        if (cnt[mp[*it]]==1 && mp[*it]>one) one=mp[*it];

    }
    //1、王炸
    if (cnt[18] && cnt[20]) return make_pair(1,20);
    //2、炸弹
    if (boom!=-1) return make_pair(1,boom);
    //3、三个
    if (three!=-1) return make_pair(2,three);
    //4、对子
    if (two!=-1) return make_pair(3,two);
    //5、顺子
    rep(i,3,11)
    {
        if (cnt[i] && cnt[i+1] && cnt[i+2] &&cnt[i+3] && cnt[i+4])
        return make_pair(4,i);
    }
    //6、个子
    return make_pair(5,one);
}
void init()
{
    mp["3"]=3; mp["4"]=4; mp["5"]=5; mp["6"]=6;
    mp["7"]=7; mp["8"]=8; mp["9"]=9; mp["10"]=10;
    mp["J"]=11; mp["Q"]=12; mp["K"]=13; mp["A"]=14;
    mp["2"]=16; mp["joker"]=18; mp["JOKER"]=20;
}
int main(){
//    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    while(getline(cin,str))
    {
        int pos = str.find('-');
        str1=str.substr(0,pos);
        str2=str.substr(pos+1);
        pair<int,int> v1=solve(str1);
        pair<int,int> v2=solve(str2);
        logs(v1.first,v1.second)
        logs(v2.first,v2.second)
        if (v1.first==v2.first)
        {
            cout<<(v1.second>v2.second?str1:str2)<<endl;
        }
        else if (v1.first==1)
        {
            cout<<str1<<endl;
        }
        else if (v2.first==1)
        {
            cout<<str2<<endl;
        }
        else cout<<"ERROR"<<endl;
    }
    return 0;
}
