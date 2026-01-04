/**
 *    author:  Meet
 *    created: 13.12.2025 15:37:06
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

vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n,m;
        cin >> n >> m;
        arr.assign(n+1,0);
        for(ll i=1; i<=n; ++i) cin >> arr[i];

        vector<vector<ll>> dp(n+1, vector<ll>(m+1,0));
        //dp[i][x] is the no of valid arrays having last element as x

        if(arr[1] == 0) {
            for(ll i=1; i<=m; ++i) dp[1][i] = 1;
        }else {
            dp[1][arr[1]] = 1;
        }

        for(ll i=2; i<=n; ++i) {
            if(arr[i] != 0) {
                ll x = arr[i];
                ll poss = 0;
                if((x-1) >= 1) poss += dp[i-1][x-1];
                poss += dp[i-1][x];
                if((x+1) <= m) poss += dp[i-1][x+1];
                dp[i][x] = poss % M;
                continue;
            }
            for(ll x=1; x<=m; ++x) {
                ll poss = 0;
                if((x-1) >= 1) poss += dp[i-1][x-1];
                poss += dp[i-1][x];
                if((x+1) <= m) poss += dp[i-1][x+1];
                dp[i][x] = poss % M;
            }
        }

        ll ans = 0;
        if(arr[n] == 0) {
            for(ll x=1; x<=m; ++x) ans = (ans + dp[n][x]) % M;
        }else {
            ans = dp[n][arr[n]];
        }   

        cout << ans << "\n";
    }
    return 0;
}