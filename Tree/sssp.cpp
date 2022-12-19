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
#define MAX 10005
#define int ll
#define forn(i,a,n) for (int i = a; i < n; i++) //[a,n)

int nodes;
vi edges[MAX];
int total_edges;
int path_length[MAX];

bool visited[MAX];
void dfs(int root,int len){
    visited[root]=true;
    path_length[root]=len;
    for(auto child:edges[root]){
        if(!visited[child]){
            dfs(child,len+1);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>nodes;
    int a,b;
    
    forn(i,0,nodes-1){
        cin>>a>>b;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    int q;
    cin>>q;
    vector<int> girl(q);
    forn(i,0,q)
        cin>>girl[i];
    sort(girl.begin(),girl.end());
    dfs(1,1);
    int ans=MAX-1;
    path_length[ans]=MAX;
    forn(i,0,q)
        if(path_length[girl[i]]<path_length[ans])
        {
            ans=girl[i];
            whatis(girl[i]);
            whatis(path_length[girl[i]]);
        }
    cout<<ans;
    return 0;
}

