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

int dfs(int v, int p, vvi& adj_list, vector<bool>& visited, vi& arv, int& timer, set<int>& cut_Vertex)
{
    visited[v] = true;
    arv[v] = ++timer;
    int dbe = arv[v];
    int children = 0;

    for (int adj : adj_list[v])
    {
        if(adj == p) // if parent
            continue;
        
        if(visited[adj]) // back-edge
            dbe = min(dbe, arv[adj]);
        else
        {
            children++;
            int dbe_adj = dfs(adj, v, adj_list, visited, arv, timer, cut_Vertex);
            if(dbe_adj >= arv[v] && p != -1)
            {
                cout << "vertex " << v <<" is the cut vertex." << endl; 
                cut_Vertex.insert(v);
            }
        }
    }

    if(p == -1 && children > 1)
    {
        cout << "vertex " << v <<" is the cut vertex." << endl; 
        cut_Vertex.insert(v);
    }

    return dbe;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    // for 1 based indexing assign n + 1
    vvi adj_list(n + 1);
    forn(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].pb(v);
        adj_list[v].pb(u);
    }

    vector<bool> visisted(n + 1, false);
    set<int> cut_vertex;
    vi arv(n + 1, 0);
    int timer = 0;
    forn(i, 1, n + 1l)
    {
        if(!visisted[i])
        {
            dfs(i, -1, adj_list, visisted, arv, timer, cut_vertex);
        }
    }   

    cout << endl << endl << "cut vertices are: ";
    for(int cv : cut_vertex)
    {
        cout << cv << ", ";
    }
    cout << endl;
    return 0;
}