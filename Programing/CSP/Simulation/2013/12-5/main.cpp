#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define P pair<int,int>
const int N = 60;
char mp[N][N];
int n, m;
bool flg_t[N][N], flg_s[N][N];
queue<P> Q;

void bfs(P s, bool *flg) //起点与标记数组
{
    while(!Q.empty()) Q.pop();
    Q.push(s);
    *(flg + s.first * N + s.second) = true;
    while(!Q.empty())
    {
        P v = Q.front();
//        cout << v.first << ' ' << v.second << ' ' << *(flg + v.first * N + v.second) << endl;
        Q.pop();
        //向上移动
        if(mp[v.first][v.second] == '+' || mp[v.first][v.second] == '|' || mp[v.first][v.second] == 'S' || mp[v.first][v.second] == 'T')
        {
            if (v.first > 0 && mp[v.first - 1][v.second] != '#' && *(flg + (v.first - 1)*N + v.second) == false)
            {
                Q.push(P(v.first - 1, v.second));
                *(flg + (v.first - 1)*N + v.second) = true;
            }
        }
        //向下移动
        if(mp[v.first][v.second] == '+' || mp[v.first][v.second] == '|' || mp[v.first][v.second] == 'S' || mp[v.first][v.second] == 'T' || mp[v.first][v.second] == '.')
        {
            if(v.first + 1 < n && mp[v.first + 1][v.second] != '#' && *(flg + (v.first + 1)*N + v.second) == false)
            {
                Q.push(P(v.first + 1, v.second));
                *(flg + (v.first + 1)*N + v.second) = true;
            }
        }
        //向左或向右移动
        if(mp[v.first][v.second] == '+' || mp[v.first][v.second] == '-' || mp[v.first][v.second] == 'S' || mp[v.first][v.second] == 'T')
        {
            //向左移动
            if (v.second > 0 && mp[v.first][v.second - 1] != '#' && *(flg + v.first * N + v.second - 1) == false)
            {
                Q.push(P(v.first, v.second - 1));
                *(flg + v.first * N + v.second - 1) = true;
            }
            //向右移动
            if (v.second + 1 < m && mp[v.first][v.second + 1] != '#' && *(flg + v.first * N + v.second + 1) == false)
            {
                Q.push(P(v.first, v.second + 1));
                *(flg + v.first * N + v.second + 1) = true;
            }
        }
    }

}
int main()
{
    memset(flg_s, false, sizeof(flg_s));
    memset(flg_t, false, sizeof(flg_t));
    cin >> n >> m;
    P s, t;
    for(int i = 0; i < n; ++i)
    {
        cin >> mp[i];
    }
//    cout << "read over." << endl;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if (mp[i][j] == 'S')
            {
                s.first = i;
                s.second = j;
            }
            else if (mp[i][j] == 'T')
            {
                t.first = i;
                t.second = j;
            }
        }
    }
    bfs(s, &flg_s[0][0]);
    if (!flg_s[t.first][t.second])
    {
        cout << "I'm stuck!" << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {

            if  (!flg_s[i][j]) continue;
            memset(flg_t, false, sizeof(flg_t));
            bfs(P(i, j), &flg_t[0][0]);
            if (!flg_t[t.first][t.second]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

/*

5 5
--+-+
..|#.
..|##
S-+-T
####.


2 2
#S
T#

*/


//二维数组指针
//https://blog.csdn.net/nice__xixi/article/details/82081595
