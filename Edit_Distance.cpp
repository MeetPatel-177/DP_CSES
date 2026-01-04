/**
 *    author:  Meet
 *    created: 29.12.2025 12:18:08
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

vector<vector<ll>> dp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    string s,t;
    cin >> s >> t;

    //dp[i][j] is the min edits for making s[i...n] and t[j...m] equal

    ll n = s.size(), m = t.size();
    dp.assign(n+1, vector<ll>(m+1,INF));

    //if any of one is exhausted then other has no option then removing characters to make them equal this is base case
    for(ll i=0; i<=m; ++i) dp[n][i] = (m - i);
    for(ll i=0; i<=n; ++i) dp[i][m] = (n - i);

    for(ll i=n-1; i>=0; --i) {
        for(ll j=m-1; j>=0; --j) {
            if(s[i] == t[j]) {
                dp[i][j] = dp[i+1][j+1];
            }else {
                ll rep = dp[i+1][j+1] + 1;
                ll rem = dp[i+1][j] + 1;
                ll ins = dp[i][j+1] + 1;
                dp[i][j] = min({rep,rem,ins});
            }
        }
    }

    cout << dp[0][0] << "\n";
    return 0;  
}