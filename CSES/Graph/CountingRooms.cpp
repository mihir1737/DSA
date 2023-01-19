#include <bits/stdc++.h>
#define whatis(x) cout << "***********" << #x << " is " << x << endl;
#define MOD 1000000007
#define endl "\n"
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define MAX 100005
#define int ll
#define forn(i,a,n) for (int i = a; i < n; i++) //[a,n)
using namespace std;

void dfs(int x, int y, vector<string>& maz, vector<vector<bool>>& visited, int n, int m)
{
    visited[x][y] = true;

    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    forn (i, 0, 4)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(min(xx, yy) < 0 || xx >= n || yy >= m || visited[xx][yy] || maz[xx][yy] == '#')
            continue;

        dfs(xx, yy, maz, visited, n, m);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<string> maz(n);
    forn(i, 0, n)
        cin >> maz[i];

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    int ans = 0;
    forn(i, 0, n)
    {
        forn(j, 0, m)
        {
            if(visited[i][j] || maz[i][j] == '#')
                continue;
            
            dfs(i, j, maz, visited, n, m);
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}