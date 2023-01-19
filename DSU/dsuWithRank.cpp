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
vi parent;
vi rank_set;

// Union by Rank.

// Initially all the elements have an equal rank.
// for Union of n1 rank set and n2 rank set (n1 <= n2), n1 -> n2.
// n2's representative will be the union's representative.

// With this we will maintain the height of n nodes tree <= log2(n)
// Here we can use path compression, rank is just basically upper bound height only.

int find(int v)
{
    if(parent[v] == v)
        return v;
    else
        return find(parent[v]);
}

void union_sets(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    if(rank_set[u] < rank_set[v])
        swap(u, v);
    
    parent[v] = u;
    if(rank_set[u] == rank_set[v])
        rank_set[u]++;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    
    parent.resize(n + 1);
    rank_set.resize(n + 1);

    forn(i, 1, n + 1)
    {
        rank_set[i] = 0;
        parent[i] = i;
    }

    vii edges;
    forn(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    return 0;
}