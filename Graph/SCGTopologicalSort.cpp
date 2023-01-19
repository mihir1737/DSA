#include <bits/stdc++.h>
#define int ll
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define vii vector<pii>
#define vb vector<bool>
#define pb push_back
#define mp make_pair
#define forn(i, a, n) for(int i = a; i < n; ++i)
#define comment(x) cout << x << endl;
#define whatis(x) //cout <<"#######" << #x <<"  is  "<< x << endl;
using namespace std;

bool check_scg(int v, vvi& edge_list, vb& visited, vi& arv, int timer, int& o_e)
{
    visited[v] = true;
    arv[v] = timer++;
    int out_edge = arv[v];

    bool ans = true;
    for(int adj : edge_list[v])
    {
        if (!visited[adj])
        {
            ans = check_scg(adj, edge_list, visited, arv, timer, o_e);
            if(ans == false)
                return false;
            out_edge = min(out_edge, o_e);
        }
        else
            out_edge = min(out_edge, arv[adj]);
    }
    o_e = out_edge;
    // For root we don't require to check if the edge is going out of the tree or not.
    // Why because We are checking for all the adjacent of the root,
    // and for the first adjacent, there we are checking if that sub tree is connected to the
    // lower arrival time(root) or not.
    // If there is no edge going back from (first adjacent's sub trees of root) to the root
    // then check_scg(adj of the root) -> will gives a false
    if(out_edge == arv[v] and arv[v] != 0)
    {
        ans = false;
    }
    return ans;
}
signed main()
{
    // Write a algorithm for cheking if the given graph is
    // strongly connected or not using topological sort.

    int n, m;
    cin >> n >> m;

    vvi edge_list(n + 1);
    vb visited(n + 1, false);
    vi arv(n + 1);
    forn(i, 0, m)
    {
        int u, v;
        cin >> u >> v;

        edge_list[u].pb(v);
    }
    int temp = 0;
    if(check_scg(1, edge_list, visited, arv, 0, temp))
        cout << "The graph is strongly connected." << endl;
    else
        cout << "The graph is not strongly connected." << endl;
}