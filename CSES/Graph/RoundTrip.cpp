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

bool find_cycle(int src, vvi& adj_list, vector<bool>& visited, vi& parent, vi& level, int& start, int& end)
{
    queue<int> q;
    visited[src] = true;
    parent[src] = -1;
    level[src] = 0;
    q.push(src);

    while (!q.empty())
    {
        if (start)
            break;
        int vertex = q.front();
        q.pop();
        for (auto adj : adj_list[vertex])
        {
            if (adj == parent[vertex])
                continue;
            
            if (visited[adj])
            {
                start = adj;
                end = vertex;
                return true;
            }

            parent[adj] = vertex;
            level[adj] = level[vertex] + 1;
            visited[adj] = true;
            q.push(adj);
        }
    }
    return false;
}

void print_cycle(vi& parent, int &src, int& start, int& end)
{
    vi src_to_start;
    vi src_to_end;

    int v = start; // v -> start to src -> leaf to ancestors...
    while(v != -1)
    {
        src_to_start.pb(v);
        v = parent[v];
    }
    reverse(src_to_start.begin(), src_to_start.end());
    v = end; // v -> end to src -> leaf to ancestors...
    while(v != -1)
    {
        src_to_end.pb(v);
        v = parent[v];
    }
    reverse(src_to_end.begin(), src_to_end.end());
    
    int lca = 0;
    while (true)
    {
        if (src_to_start[lca + 1] != src_to_end[lca + 1])
            break;
        ++lca;
    }

    // print -> start to lca -> lca + 1_to_end -> start; 
    vi cycle;

    for (int i = src_to_start.size() - 1; i >= lca; i--)
    {
        cycle.pb(src_to_start[i]);
    }

    for (int i = lca + 1; i < src_to_end.size(); i++)
    {
        cycle.pb(src_to_end[i]);
    }
    cycle.pb(start);

    cout << cycle.size() << endl;
    for (auto &x : cycle)
    {
        cout << x << " ";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; // n = #vertices, m = #edges
    cin >> n >> m;

    vvi adj_list(n + 1);
    forn(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].pb(v);
        adj_list[v].pb(u);
    }
    vector<bool> visited(n + 1 , false);
    vi parent(n + 1, 0);
    vi level(n + 1, 0);    
    int start = 0;
    int end = 0;

    forn(i, 0, n)
    {
        if (visited[i])
            continue;

        if (find_cycle(i, adj_list, visited, parent, level, start, end))
        {
            print_cycle(parent, i, start, end);
            break;
        }
    }

    if (!start)
        cout << "IMPOSSIBLE" << endl;
    return 0;
}