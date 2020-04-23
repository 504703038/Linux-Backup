#include <iostream>
#include <cstring>
using namespace std;
const int N=1e6+10;
bool v[1010];
char s[N];
int main()
{
    while(cin>>s)
    {
        memset(v,0,sizeof(v));
        int n=strlen(s);
        for(int i=0;i<n;++i)
        {
            if (v[s[i]]) continue;
            else
            {
                cout<<s[i];
                v[s[i]]=1;
            }
        }
        cout<<endl;

    }
    return 0;
}
