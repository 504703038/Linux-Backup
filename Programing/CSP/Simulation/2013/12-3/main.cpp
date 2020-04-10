#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e3+10;
int a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int i=1; i<=n; ++i)
    {
        int l=i,r=i;
        while(l>=1 && a[l]>=a[i]) l--;
        while(r<=n && a[r]>=a[i]) r++;
        if((r-l-1)*a[i]>ans) ans=(r-l-1)*a[i];
    }
    cout<<ans<<endl;
    return 0;
}
