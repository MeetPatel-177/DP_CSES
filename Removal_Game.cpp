/**
 *    author:  Meet
 *    created: 30.12.2025 15:15:11
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

#define ll long long int
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

vector<ll> arr;

const ll N = 5001;
ll dp[N][N][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        arr.assign(n,0);
        for(ll i=0; i<n; ++i) cin >> arr[i];
        
        for(ll i=0; i<n; ++i) {
            dp[i][i][0] = arr[i];
            dp[i][i][1] = 0;
        }

        for(ll len=2; len<=n; ++len) {
            ll l = 0, r = l + len - 1;
            while(r < n) {
                dp[l][r][0] = max(arr[l] + dp[l+1][r][1], arr[r] + dp[l][r-1][1]);
                dp[l][r][1] = min(dp[l+1][r][0], dp[l][r-1][0]);
                ++l;
                ++r;
            }
        }

        ll ans = dp[0][n-1][0];
        cout << ans << "\n";
    }
    return 0;
}