/**
 *    author:  Meet
 *    created: 23.08.2026 22:35:31
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

vector<ll> nextGreater(vector<ll>& arr) {
    ll n = arr.size();
    vector<ll> nge(n, n);

    stack<ll> stk;
    for(ll i=0; i<n; ++i) {
        while(!stk.empty() && arr[stk.top()] < arr[i]) {
            nge[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }

    return nge;
}

vector<ll> prevGreater(vector<ll>& arr) {
    ll n = arr.size();
    vector<ll> pge(n, -1);

    stack<ll> stk;
    for(ll i=n-1; i>=0; --i) {
        while(!stk.empty() && arr[stk.top()] < arr[i]) {
            pge[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }

    return pge;
}

ll rec(ll i, ll n, vector<ll>& nge, vector<ll>& pge, vector<ll>& dp) {
    if(dp[i] != 0) return dp[i];

    ll ans = 1;
    if(nge[i] != n) ans = max(ans, 1 + rec(nge[i], n, nge, pge, dp));
    if(pge[i] != -1) ans = max(ans, 1 + rec(pge[i], n, nge, pge, dp));

    return dp[i] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n;
    cin >> n;

    vector<ll> arr(n);
    for(ll i=0; i<n; ++i) cin >> arr[i];

    //basically the idea is that it is always better to go to immediate next greater and prev greater element because that would give me more room to jump otherwise if we skip immediate and try to go to any other it would give me less possibilities
    //now to make that work we need to sort array from greater to smaller and then we will have all the transitions that any element can have so we can process iterative dp with O(nlogn) for sorting
    //but here is the catch we can implement memoised recursive solution to avoid that sorting step and we try to find the max answer from everyone which is O(n)

    vector<ll> nge = nextGreater(arr);
    vector<ll> pge = prevGreater(arr);

    ll ans = 1;
    vector<ll> dp(n, 0);

    for(ll i=0; i<n; ++i) {
        ans = max(ans, rec(i, n, nge, pge, dp));
    }

    cout << ans << "\n";
    return 0;
}