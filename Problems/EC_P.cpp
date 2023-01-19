// https://www.spoj.com/problems/EC_P/

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

int dfs(int v, int parent, vvi& adj_list, vi& arv, vii& back_edges, int& timer)
{
    arv[v] = timer++;
    int dbe = arv[v];

    for (int adj : adj_list[v])
    {
        if (adj == parent)
            continue;
        if (arv[adj] != -1) // back - edge
            dbe = min(dbe, arv[adj]);
        else // child..
            dbe = min(dbe, dfs(adj, v, adj_list, arv, back_edges, timer));
    }

    if (dbe == arv[v] && parent != -1)
    {
        if (parent > v)
            swap(parent, v);
        back_edges.pb({ parent, v });
    }
    return dbe;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i, t = 1;
    cin >> t;
    forn(tc, 1, t + 1)
    {
        int n, m;
        cin >> n >> m;
        vvi adj_list(n + 1);

        forn(i, 0, m)
        {
            int u, v;
            cin >> u >> v;
            adj_list[u].pb(v);
            adj_list[v].pb(u);
        }

        vi arv(n + 1, -1);
        int timer = 0;

        vii back_edges;
        dfs(1, -1, adj_list, arv, back_edges, timer);

        cout << "Caso #" << tc << endl;
        if (back_edges.size() == 0)
        {
            cout << "Sin bloqueos" << endl;
            continue;
        }

        cout << back_edges.size() << endl;
        sort(back_edges.begin(), back_edges.end());
        for (pii& edge : back_edges)
        {
            cout << edge.ff << " " << edge.ss << endl;
        }
    }
    return 0;
}