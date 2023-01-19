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

void dfs(int source, int parent, vvi& adj_list, vector<bool>& visited)
{
    if (visited[source])
        return;

    visited[source] = true;
    for (auto adj : adj_list[source])
    {
        if (adj == parent)
            continue;

        if (visited[adj]) // back edge
            continue;

        // else forward edge / tree edge

        dfs(adj, source, adj_list, visited);
    }
}

signed main()
{
    int n, m; // n -> #vertices, m -> #edges
    cin >> n >> m;

    vvi adj_list(n + 1); // for 1 based indexing keep practice to declare n + 1.
    vector<bool> visited(n + 1, false);

    forn(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].pb(v);
        adj_list[v].pb(u);
    }

    vi roots;
    forn(i, 1, n + 1)
    {
        if (!visited[i])
        {
            dfs(i, -1, adj_list, visited);
            roots.pb(i);
        }
    }

    cout << roots.size() - 1 << endl;
    forn(i, 1, roots.size())
    {
        cout << roots[i] << " " << roots[i - 1] << endl;
    }
    return 0;
}