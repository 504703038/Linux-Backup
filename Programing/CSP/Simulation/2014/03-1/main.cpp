#include <iostream>

using namespace std;
const int N=510;
int a[N];
int main()
{
    int n,ans=0; cin>> n;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        for(int j=0;j<i;++j)
        {
            if (a[i]==-a[j]) ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}
