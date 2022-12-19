#include <bits/stdc++.h>
using namespace std;
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
#define MAX 200005
#define forn(i,a,n) for (int i = a; i < n; i++) //[a,n)

int nodes;
vi edges[MAX];
int total_edges;

bool visited[MAX];
void dfs(int root) {
    cout << root << endl;
    visited[root] = true;
    for (auto child : edges[root]) {
        if (!visited[child]) {
            dfs(child);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> nodes;
    cin >> total_edges;

    int a, b;

    forn(i, 0, total_edges) {
        cin >> a >> b;
        edges[a].pb(b);
        edges[b].pb(a);
    }

    forn(i, 0, nodes + 1) {
        forn(j, 0, edges[i].size())
        {
            cout << i << "->" << edges[i][j] << endl;
        }
    }
    dfs(1);
    return 0;
}

