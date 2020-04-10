#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e4+10;
int cnt[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
    int p=1;
    for(int i=1; i<N; i++)
    {
        if(cnt[p]<cnt[i]) p=i;
    }
    cout<<p;
    return 0;
}
