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

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> maz(n);

    forn (i, 0, n)
        cin >> maz[i];
    
    forn (i, 0, n)
    {
        check(i, 0);
        check(i, m - 1);
    }

    forn (j, 1, m - 1)
    {
        check(0, j);
        check(n -1, j);
    }

    pii player;
    vii mosters;

    return 0;
}