/**
 *    author:  Meet
 *    created: 30.12.2025 17:38:10
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

ll binExp(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n;
    cin >> n;

    ll sum = n*(n+1)/2;

    if(sum & 1) {
        cout << 0 << "\n";
    }else {
        ll req = sum/2;

        //dp[i][s] is the no of ways we can make sum s from first i numbers
        // vector<vector<ll>> dp(n+1, vector<ll>(req+1,0));

        // for(ll i=0; i<=n; ++i) dp[i][0] = 1;

        vector<ll> prev(req+1,0);
        prev[0] = 1;

        for(ll i=1; i<=n; ++i) {
            vector<ll> curr(req+1,0);
            curr[0] = 1;
            for(ll s=1; s<=req; ++s) {
                if(i <= s) {
                    curr[s] = (prev[s] + prev[s - i]) % M;
                }else {
                    curr[s] = prev[s];
                }
            }
            prev = curr;
        }

        ll ans = prev[req] * binExp(2, M-2);
        ans %= M;

        cout << ans << "\n";
    }
    return 0;
}