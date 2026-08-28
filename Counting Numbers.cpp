/**
 *    author:  Meet
 *    created: 08.08.2026 15:49:53
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
const ll M = 1e9 + 7;
//const ll M = 998244353;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"

//dp[i][prev][tight][started]
ll dp[20][11][2][2];

ll rec(string& num, ll i, ll prev, bool tight, bool started) {
    if(i == num.size()) return 1;

    if(dp[i][prev][tight][started] != -1) return dp[i][prev][tight][started];

    ll ans = 0;
    ll ub = tight ? num[i] - '0' : 9;

    for(ll dig=0; dig<=ub; ++dig) {
        if(!started && dig == 0) {
            ans += rec(num, i+1, 10, 0, 0);
        }else {
            if(dig != prev) ans += rec(num, i+1, dig, tight && (dig == ub), 1);
        }
    }

    return dp[i][prev][tight][started] = ans;
}

ll solve(ll n) {
    string num = to_string(n);

    memset(dp, -1, sizeof(dp));

    return rec(num, 0, 10, 1, 0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll a,b;
    cin >> a >> b;

    ll ans = solve(b);
    if(a > 0) ans -= solve(a - 1);

    cout << ans << "\n";
    return 0;
}