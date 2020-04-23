#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string s;
int cnt[16];
int main()
{
    while(cin>>s)
    {
        memset(cnt,0,sizeof(cnt));
        int l =s.length();
        for(int i=0;i<l;i++)
        {
            if (s[i]>='0' && s[i]<='9')
            {
                cnt[s[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++)
        {
//            cout<<i<<' '<<cnt[i]<<endl;
            for(int j=1;j<=cnt[i];j++)
            {
                cout<<i;
            }
        }
        cout<<endl;
    }

    return 0;
}
