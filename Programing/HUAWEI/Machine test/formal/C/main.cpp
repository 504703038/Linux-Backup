#include <iostream>

using namespace std;
const int N=600;
int m,k;
int a[N];
bool check(int c)
{
    int tot=0;
    for(int i=0;i<m;)
    {
        int sum=0;
        while (i<m && sum<c) sum+=a[i++];
        if (sum>=c) tot++,sum=0;
    }
    if (tot>=k) return true;
    else return false;
}
void output(int c)
{
    int j=0;
    for(int i=1;i<k;i++)
    {
        int sum=0;
        while(j<m && sum<c)
        {
            cout<<a[j]<<' ';
            sum+=a[j++];
        }
        if (j<m) cout<<"/ ";
    }
    for(;j<m;j++)
    {
        cout<<a[j]<<' ';
    }
    cout<<endl;
}
int main()
{
    while(cin>>m>>k)
    {
        int sum=0;
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        int l=0,r=sum,ans=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if (check(mid))
            {
                ans=mid,l=mid+1;
            } else r=mid-1;
        }
//        cout<<ans<<endl;
        output(ans);
    }
    return 0;
}
