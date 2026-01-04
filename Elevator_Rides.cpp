/**
 *    author:  Meet
 *    created: 31.12.2025 14:04:07
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,x;
    cin >> n >> x;

    vector<ll> arr(n);
    for(ll i=0; i<n; ++i) cin >> arr[i];

    ll N = (1 << n);
    vector<pair<ll,ll>> dp(N, {n+1,0});
    //dp[i] is {r,w} stores min rides r to make rides for that perticular mask with last weight as w

    dp[0] = {1,0};

    for(ll mask=1; mask<N; ++mask) {
        for(ll i=0; i<n; ++i) {
            if((mask >> i) & 1) {
                pair<ll,ll> prev = dp[mask ^ (1 << i)];
                ll r = prev.first, w = prev.second;
                pair<ll,ll> curr;
                if((w + arr[i]) <= x) {
                    curr = {r, w + arr[i]};
                }else {
                    curr = {r+1, arr[i]};
                }
                dp[mask] = min(dp[mask], curr);
            }
        }
    }

    cout << dp[N-1].first << "\n";
    return 0;
}