/**
 *    author:  Meet
 *    created: 19.12.2025 11:24:34
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

const ll N = 1e6;
ll dp[N+1][2];
//dp[i][0] is the no of ways to fill first i rows when ith row has two tiles 
//dp[i][1] is the no of ways to fill first i rows when ith row has one tile

void compute() {

    dp[1][0] = dp[1][1] = 1;

    for(ll i=2; i<=N; ++i) {
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1]) % M;
        dp[i][1] = (2*dp[i-1][1] + dp[i-1][0]) % M;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    compute();
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        ll ans = (dp[n][0] + dp[n][1]) % M;

        cout << ans << "\n";
    }
    return 0;
}