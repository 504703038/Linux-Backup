#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int>a;
int main()
{
    a.clear();
    int x;
    bool f=1;
    while(~scanf("%x",&x))
    {
        a.push_back(x);
        if (x==0x5a && a.size()>1)
        {
            bool fine=1;
            int n=a.size();
            int tot=0;
            for(int i=1;i<n-2;i++)
            {
                tot++;
                if (a[i]==0x5b)
                {
                    if (a[i+1]==0xba || a[i+1]==0xbb) tot--;
                    else {fine=0;break;}
                }
            }
            if (tot==a[n-2] && tot && fine)
            {
                if (f)
                {
                    printf("5a ");
                    f=0;
                }
                for(int i=1;i<a.size();i++)
                {
                    printf("%02x ",a[i]);
                }
            }
            a.clear();
            a.push_back(0x5a);
        }
    }
    return 0;
}
