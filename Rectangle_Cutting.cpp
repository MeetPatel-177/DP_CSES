/**
 *    author:  Meet
 *    created: 30.12.2025 10:59:24
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll a,b;
        cin >> a >> b;

        vector<vector<ll>> dp(a+1, vector<ll>(b+1,0));
        
        for(ll i=1; i<=a; ++i) {
            for(ll j=1; j<=b; ++j) {
                if(i == j) continue;
                ll ans = INF;
                //vertical
                for(ll v=1; v<j; ++v) {
                    ans = min(ans, 1 + dp[i][v] + dp[i][j - v]);
                }
                //horizontal
                for(ll h=1; h<i; ++h) {
                    ans = min(ans, 1 + dp[h][j] + dp[i - h][j]);
                }
                dp[i][j] = ans;
            }
        }

        cout << dp[a][b] << "\n";
    }
    return 0;
}