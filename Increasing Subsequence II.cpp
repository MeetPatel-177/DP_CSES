/**
 *    author:  Meet
 *    created: 21.08.2026 19:50:09
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

class Fenwick {
    vector<ll> bit;
    ll n;
    public :
    Fenwick(ll n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(ll i, ll val) {
        for(; i<=n; i += (i & (-i))) {
            bit[i] = (bit[i] + val) % M;
        }
    }

    ll query(ll i) {
        ll ans = 0;
        for(; i>0; i -= (i & (-i))) {
            ans = (ans + bit[i]) % M;
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n;
    cin >> n;

    vector<ll> arr(n);
    for(ll i=0; i<n; ++i) cin >> arr[i];

    //when we are at some i we are iterating obviously from left to right so we have access to all the leftwards positions
    //so if we want to take this i as the last position of any subsequence means subsequences ending at i so we can extend any of the previous values which have value less than the arr[i] and then sum of all those subsequences i can extend and one more subsequence which is basically i start a subsequence from i itself 

    vector<ll> temp = arr;
    sort(whole(temp));
    temp.erase(unique(whole(temp)), temp.end());

    ll sz = temp.size();
    Fenwick ft(sz);

    ll ans = 0;
    for(ll i=0; i<n; ++i) {
        ll idx = lower_bound(whole(temp), arr[i]) - temp.begin() + 1;
        ll sum = ft.query(idx - 1);
        ans = (ans + (sum + 1) % M) % M;
        ft.update(idx, sum + 1);
    }

    cout << ans << "\n";
    return 0;
}