#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n && n)
    {
        if (!n) break;
        else cout<<n/2<<endl;
    }
    return 0;
}
