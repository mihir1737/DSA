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

int dfs(int v, int parent,vvi& adj_list, vector<bool>& visited,vi &arv, vii& bridges, int &timer)
{
    visited[v] = true;
    arv[v] = timer++;
    int dbe = arv[v]; // deepest back edge.

    for (int adj: adj_list[v])
    {
        if (adj == parent)
            continue;
        
        if (visited[adj]) // back - edge
            dbe = min(dbe, arv[adj]);
        
        else // tree - edge -> child
            dbe = min(dbe, dfs(adj, v, adj_list, visited, arv, bridges, timer));
    }
    
    if (dbe == arv[v] && parent != -1)
        bridges.pb({v, parent});
    
    return dbe;
}
signed main()
{
    int n, m; // n = #vertices, m = #edges
    cin >> n >> m;

    vvi adj_list(n + 1); // 1 based indexing.

    forn(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].pb(v);
        adj_list[v].pb(u);
    }

    vii bridges;
    vector<bool> visited(n + 1, false);
    vi arv(n + 1, -1); // arrival time of the node in dfs tree. if not visited it

    int timer = 0;
    dfs(1, -1, adj_list, visited, arv, bridges, timer);

    if(bridges.size() == 0)
    {
        cout << "There is no bridges, hence graph is 2-edge connected." << endl;
    }
    else
    {
        cout << "There are " << bridges.size() << " bridges." << endl;
        for (pii &edge : bridges)
        {
            cout << edge.first << " -> " << edge.second << endl;
        }
    }
}