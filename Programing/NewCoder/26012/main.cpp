#include <iostream>

using namespace std;
const int N = 1010;
int n,a[N];
bool v[N];
void init(int n)
{
    for(int i=0;i<n;++i)
    {
        a[i]=i;
        v[i]=false;
    }
}
int main()
{
    while(cin>>n && n)
    {
        init(n);
        int t=0;
        for(int i=1;i<n;++i)
        {
            while(v[t]) t = (t+1)%n;
            t=(t+1)%n;
            while(v[t]) t = (t+1)%n;
            t=(t+1)%n;
            while(v[t]) t = (t+1)%n;
            v[t]=true;
//            cout<<t<<endl;
        }
        while(v[t]) t=(t+1)%n;
        cout<<t<<endl;
    }
    return 0;
}
