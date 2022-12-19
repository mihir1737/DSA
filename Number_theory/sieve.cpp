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
#define forn(i, a, n) for (int i = a; i < n; i++) //[a,n)
using namespace std;

bool is_prime[MAX];
vi prime;
void simple_sieve(int N)
{
    /*CUT AND PASTE IT TO GLOBLE AREA.............
    bool is_prime[MAX];
    vi prime;
    */
    forn(i, 0, N) is_prime[i] = true;
    is_prime[1] = false;
    int no;
    for (no = 2; no * no <= N; no++)
    {
        if (is_prime[no])
        {
            prime.pb(no);
            for (int i = no; i * no <= N; i++)
                is_prime[i * no] = false;
        }
    }
    for(;no<=N;no++)
    {
        if(is_prime[no])prime.pb(no);
    }
}

void print_prime_numbers(int N)
{
    for_each(prime.begin(),prime.end(),[](int &a){cout<<a<<", ";});
    cout<<endl;
}

signed main()
{
    int i, t = 1;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        simple_sieve(N);
        print_prime_numbers(N);
    }
    return 0;
}