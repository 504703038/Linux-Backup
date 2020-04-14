#include <iostream>
#include <cstring>
using namespace std;
const int N=1010;
char s[N];
bool v[N];
int main()
{
    while(cin>>s)
    {
        int n=strlen(s);
        memset(v,0,sizeof(v));
        for(int i=0;i<n;++i)
        {
            char c = s[i];
            if (!v[s[i]])
            {
                cout<<s[i];
                v[s[i]]=true;
            }
        }
        cout<<endl;
    }
    return 0;
}
