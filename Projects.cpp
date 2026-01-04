/**
 *    author:  Meet
 *    created: 31.12.2025 12:00:33
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
    
    ll n;
    cin >> n;

    vector<vector<ll>> arr;
    for(ll i=0; i<n; ++i) {
        ll s,e,p;
        cin >> s >> e >> p;
        arr.push_back({s,e,p});
    }
    
    sort(whole(arr), [](auto& v1, auto& v2) {
        return v1[1] < v2[1];
    });
    
    vector<ll> ending(n,0);
    for(ll i=0; i<n; ++i) ending[i] = arr[i][1];

    vector<ll> dp(n+1, 0);
    //dp[i] is the largest reward we can get from [1....i]

    dp[0] = 0;

    for(ll i=1; i<=n; ++i) {
        ll s = arr[i-1][0], p = arr[i-1][2];
        ll ind = lower_bound(whole(ending), s) - ending.begin();
        // after ind all the projects are blocked if we take ith project as they have larger ending time than the ith starting time
        dp[i] = max(dp[i-1], p + dp[ind]);
    }

    cout << dp[n] << "\n";
    return 0;
}