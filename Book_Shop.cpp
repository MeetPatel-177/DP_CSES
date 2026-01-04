/**
 *    author:  Meet
 *    created: 13.12.2025 14:50:05
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

vector<ll> h, p;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n, x;
        cin >> n >> x;
        h.assign(n+1,0);
        p.assign(n+1,0);
        for(ll i=1; i<=n; ++i) cin >> h[i];
        for(ll i=1; i<=n; ++i) cin >> p[i];

        // vector<vector<ll>> dp(n+1, vector<ll>(x+1,0));
        vector<ll> prevState(x+1,0);
        //dp[i][x] is the max pages from [0...i] with x money
        //dp[i][x] = max(dp[i-1][x], dp[i-1][x-h[i]] + p[i])
        //ans = dp[n][x]

        for(ll i=1; i<=n; ++i) {
            vector<ll> currState(x+1,0);
            for(ll cost=1; cost<=x; ++cost) {
                ll skipped = prevState[cost];
                // ll skipped = dp[i-1][cost];
                ll taken = 0;
                if((cost - h[i]) >= 0) taken = prevState[cost - h[i]] + p[i];

                currState[cost] = max(skipped, taken);
            }
            prevState = currState;
        }

        cout << prevState[x] << "\n";
    }
    return 0;
}