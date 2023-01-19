#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vb vector<bool>
#define pb push_back
#define mp make_pair
#define whatis(x) cout << "***********" << #x << " is " << x << endl;
#define comment(x) cout<<x<<endl
#define endl "\n"
#define MOD 1000000007
#define MAX 100005
#define forn(i, a, n) for (int i = a; i < n; i++) //[a,n)
using namespace std;

void dfs(int v, vvi& adj_list, vb& visited)
{
    visited[v] = true;

    for(int adj : adj_list[v])
    {
        if(!visited[adj])
            dfs(adj, adj_list, visited);
    }
}

bool check_scg(int n, int m, vvi& adj_list, vb& visited)
{
    vvi r_adj_list(n + 1);
    vb r_visited(n + 1, false);

    forn (i, 1, n + 1)
    {
        vi &list = adj_list[i];
        for (int j : list)
        {
            r_adj_list[j].pb(i);
        }
    }
    dfs(1, adj_list, visited);
    dfs(1, r_adj_list, r_visited);
    forn(i, 1, n + 1)
    {
        if(!visited[i] || !r_visited[i])
            return false;
    }
    return true;
}


signed main()
{
    // Given a directed graph, write kosaraju's algorithm for checking
    // if the graph is strongly connected.

    int n, m;
    cin >> n >> m;

    vvi adj_list(n+1);
    forn (i , 0 , m)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].pb(v);
    }

    vb visited(n + 1, false);
    if (check_scg(n, m, adj_list, visited))
        cout << "Given graph is strongly connected.";
    else
        cout << "Given graph is not strongly connected.";
    
    return 0;
}