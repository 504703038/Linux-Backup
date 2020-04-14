#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;
int n,a[N];
int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;++i)
        {
            if(!i || a[i]!=a[i-1])
                cout<<a[i]<<endl;
        }

    }

    return 0;
}
