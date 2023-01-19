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
vi height;

// We can't do path compression while maintaining the height parameter calculated.
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
    
    if(height[u] < height[v])
        swap(u, v);

    parent[v] = u;

    if(height[v] == height[u])
        height[u]++;
}

signed main()
{
    int n, m;
    cin >> n >> m;

    parent.clear();
    height.clear();
    parent.resize(n + 1, -1);
    height.resize(n + 1);

    for(int i = 0; i <= n; i++)
    {
        height[i] = 1;
        parent[i] = i;
    }
    return 0;
}