#include <bits/stdc++.h>
#define whatis(x) //cout << "***********" << #x << " is " << x << endl;
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

void find_path(vector<string>& maz)
{
    int n = maz.size();
    int m = maz[0].length();
    int bx = -1, by = -1;
    forn(i, 0, n)
    {
        forn(j, 0, m)
        {
            if (maz[i][j] == 'B')
            {
                bx = i;
                by = j;
            }
        }
    }

    whatis(bx);
    whatis(by);

    queue<pii> q;
    q.push({ bx, by });
    vector<vii> parent(n, vii(m, { -1, -1 }));
    parent[bx][by] = { -2, -2 };

    int ax = -1;
    int ay = -1;
    while (!q.empty())
    {
        pii v = q.front();
        q.pop();
        int x = v.first;
        int y = v.second;
        int dx[4] = { 0, 0, 1, -1 };
        int dy[4] = { 1, -1, 0, 0 };

        forn(i, 0, 4)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (min(xx, yy) < 0 || xx >= n || yy >= m) // out of boundry
                continue;

            if (maz[xx][yy] == '#' || parent[xx][yy].ff != -1) // already visited or wall..
                continue;

            if (maz[xx][yy] == 'A') // if maz have 'A' store its value
            {
                ax = xx;
                ay = yy;
            }
            parent[xx][yy] = { x, y };
            q.push({ xx, yy });
        }
    }

    if (ax == -1)
    {
        cout << "NO" << endl;
        return;
    }

    whatis(ax);
    whatis(ay);
    string path;
    while (true)
    {
        pii v = parent[ax][ay];
        int d_ax = v.first - ax;
        int d_ay = v.second - ay;

        if(d_ax == -1 && d_ay == 0)
            path += 'U';
        if(d_ax == 1 && d_ay == 0)
            path += 'D';
        if(d_ax == 0 && d_ay == 1)
            path += 'R';
        if(d_ax == 0 && d_ay == -1)
            path += 'L';
            
        ax = v.first;
        ay = v.second;
        if(ax == bx && ay == by)
            break; 
    }

    cout << "YES" << endl;
    cout << path.length() << endl;
    cout << path << endl;
}

signed main()
{
    int n, m;

    cin >> n >> m;

    vector<string> maz(n);
    forn(i, 0, n)
        cin >> maz[i];

    find_path(maz);

    return 0;
}