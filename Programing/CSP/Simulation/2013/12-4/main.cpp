#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const int MOD = 1e9+7;
const int N=1e3+10;
LL C[N][N];
void init()
{
    C[0][0]=C[1][0]=C[1][1]=1;
    for(int i=2; i<=1000; i++)
    {
        C[i][0]=1;
        for(int j=1; j<=i; j++)
        {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
}
int main()
{
    init();
    int n;
    cin>>n;
    LL ans=0;
    for (int i=2; i<=n-2; ++i)
    {
        int j=n-i;
        //i表示2和3的个数，j表示0和1的个数
        ans=(ans+((i-1)*(j-1)%MOD)*C[n-1][j-1]%MOD)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
