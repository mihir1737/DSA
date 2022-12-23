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

// to find the shortest path from 1 to n
void find_path(int n, vvi& adj_list)
{
    vi parent(n + 1, 0);
    queue<int> q;
    parent[1] = -1 ;
    q.push(1);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(int adj : adj_list[v])
        {
            if (parent[adj] != 0) // already visited in case of 1 -> -1 != 0
                continue;
            parent[adj] = v;
            q.push(adj);
        }
    }

    if(!parent[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vi path;
    int v = n;
    while(v != -1)
    {
        path.pb(v);
        v = parent[v];
    }
    cout << path.size() << endl;
    for(auto it = path.rbegin(); it != path.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m ;
    cin >> n >> m;

    vvi adj_list(n + 1);

    forn(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].pb(v);
        adj_list[v].pb(u);
    }

    find_path(n, adj_list);
    return 0;
}