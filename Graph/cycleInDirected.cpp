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

void print_cycle(int start, int end, vi& par) // start = adj, end = vertex
{
    vi path;
    int trace = end;
    path.pb(trace);
    while(trace != start)
    {
        trace = par[trace];
        path.pb(trace);
    }
    // path -> end to start

    reverse(path.begin(), path.end()); // path -> start to end
    for(int v : path)
    {
        cout << v << " -> ";
    }
    
    cout << start << endl;
}
void dfs(int v, int p, vvi& adj_list, vi& arv, vi& dep, vi &par, int& timer)
{
    arv[v] = timer++;
    par[v] = p;

    for(int adj : adj_list[v])
    {
        if (arv[adj] == 0) // tree edge
        {
            dfs(adj, v, adj_list, arv, dep, par, timer);
            continue;
        }

        // forward edge -> dfs(adj) is already completed dep[adj] != 0
        // cross edge -> dfs(adj) is already completed dep[adj] != 0
        // back edge -> we are still in the recursion of dfs(adj), adj is ancestor of v(including the parent p)
        //              dep[adj] == 0
        //              hence back edge (v, adj) creates cycle.
        
        if(dep[adj] == 0) 
        {
            cout << "edge " << v << " -> " << adj << " creates cycle." << endl;
            print_cycle(adj, v, par); // adj -> starting vertex of the cycle, v -> last vertex.
        }
    } 
    dep[v] = timer++;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    
    vvi adj_list(n + 1); // directed edge list 
    forn(i, 0, m)
    {
        int u, v;
        cin >> u >> v; // there is an edge between u -> v
        adj_list[u].pb(v);
    }

    
    vi arv(n + 1, 0);
    vi dep(n + 1, 0);
    vi par(n + 1, 0); // if 0 is vertex assign with -1.
    // we will give timer with 1 based, if the arv[vertex] > 0 -> visited. 
    int timer = 1;
    dfs(1, -1, adj_list, arv, dep, par, timer);
    return 0;
}