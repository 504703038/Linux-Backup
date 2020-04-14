#include <iostream>

using namespace std;

int main()
{
    int n;
    for(int i=0;i<10;i++)
    {
        cin>>n;
        if (!n) break;
        else cout<<n/2<<endl;
    }
    return 0;
}
