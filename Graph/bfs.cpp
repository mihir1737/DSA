#include<bits/stdc++.h>
#define whatis(x) cout << "***********" << #x << "is " << x << endl;
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
#define forn(i,a,n) for (int i = a; i < n; i++) //[a,n)
using namespace std;

int vertices;
int edges;
vi adj_list[MAX];
int source;

vi depth(MAX); // shortest path length from the source for weight of edge is 1.
vector<bool> visited(MAX); // if visited = true -> there is a path between source and vertex.
vi parent(MAX); // who gives the depth to the vertex.

void bfs()
{
    queue<int> q;

    q.push(source);
    visited[source] = true;
    depth[source] = 0;
    parent[source] = -1; // predecessor.

    while (!q.empty())
    {
        int vertex = q.front(); // we will take first element from the queue 
        q.pop();
        cout << vertex << ", ";
        for (auto adj: adj_list[vertex]) // for all it's adjacent element.
        {
            if (visited[adj]) // if adj already visited/used do nothing , else
                continue;
            depth[adj] = depth[vertex] + 1; 
            parent[adj] = vertex;
            visited[adj] = true;
            q.push(adj); // push adjacent to queue with depth = depth[parent vertex] + 1
        }
    }

    cout << endl << "vertex - depth - Parent" << endl; 
    forn (i, 0, vertices + 1)
    {
        cout << i << "\t   " << depth[i] << "  \t" << parent[i] << endl;
    }

}

// return true, and print the path if path exists otherwise false;
bool check_path(int vertex) 
{
    if(!visited[vertex])
        return false;
    
    cout << "Path from vertex " << vertex << " to source " << source << endl;
    int v = vertex;
    while(v != source)
    {    
        cout << v << "," ;
        v = parent[v];
    }
    cout << source << endl;
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> vertices;
    cin >> edges;
    // cin >> source;
    source = 1;

    int a, b;

    forn (i, 0, edges) 
    {
        cin >> a >> b;
        adj_list[a].pb(b);
        adj_list[b].pb(a);
    }

    forn (i, 0, vertices + 1) 
    {
        cout << i << "-> " ;
        forn (j, 0, adj_list[i].size())
        {
            cout << adj_list[i][j] << ", ";
        }
        cout << endl;
    }

    
    bfs();

    int qry;
    cin >> qry;

    cout << "Path to source vertex will be checked here:" << endl;
    
    forn (i, 0, qry)
    {
        int vertex;
        cin >> vertex;
        check_path(vertex);
    }
    return 0;
}