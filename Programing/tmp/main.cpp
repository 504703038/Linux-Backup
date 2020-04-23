#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ans=0;
int dg(int n)
{
    ans++;
    if (n==1) return 1;
    return 4*dg(n/2)+n;
}
int main()
{
    int n;
    cin>>n;
    dg(n);
    cout<<ans;
    return 0;
}
