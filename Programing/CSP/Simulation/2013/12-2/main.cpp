#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N=20;
char s[N];
int main()
{
    scanf("%s",s);
    int p=0,sum=0;
    for(int i=0; i<11; ++i)
    {
        if (i==1 || i==5) continue;
        sum+=(s[i]-'0')*(++p);
    }
    sum%=11;
    if (sum==10 && s[12]=='X' || sum==s[12]-'0')
    {
        strcpy(s,"Right");
    }
    else if(sum==10)
    {
        s[12]='X';
    }
    else s[12]='0'+sum;
    printf("%s\n",s);

    return 0;
}
