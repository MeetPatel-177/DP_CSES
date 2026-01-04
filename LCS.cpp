/**
 *    author:  Meet
 *    created: 29.12.2025 13:25:23
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

const ll INF = 4e18;
const ll MINF = -4e18;
const ll M = 1e9 + 7;
//const ll M = 998244353;
const ll M1 = 111053273;
const ll M2 = 4011052531;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"

vector<ll> a,b;
vector<vector<ll>> dp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n,m;
        cin >> n >> m;
        a.assign(n,0);
        b.assign(m,0);
        for(ll i=0; i<n; ++i) cin >> a[i];
        for(ll i=0; i<m; ++i) cin >> b[i];
        
        //dp[i][j] is the longest len subseq. from a[i...n] and b[j....m]
        dp.assign(n+1, vector<ll>(m+1,INF));

        for(ll i=0; i<=m; ++i) dp[n][i] = 0;
        for(ll i=0; i<=n; ++i) dp[i][m] = 0;

        for(ll i=n-1; i>=0; --i) {
            for(ll j=m-1; j>=0; --j) {
                if(a[i] == b[j]) {
                    dp[i][j] = dp[i+1][j+1] + 1;
                }else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        cout << dp[0][0] << "\n";

        ll curr = dp[0][0];
        for(ll i=0; i<n; ++i) {
            for(ll j=0; j<m; ++j) {
                if(dp[i][j] == curr && a[i] == b[j]) {
                    cout << a[i] << " ";
                    --curr;
                    break;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}