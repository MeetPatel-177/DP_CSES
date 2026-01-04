/**
 *    author:  Meet
 *    created: 01.01.2026 11:25:59
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

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"

const ll mod = 1e9 + 7;
const ll M = 1001, N = 11;

ll dp[M][1 << N];

void generate_next_masks(ll row, ll curr_mask, ll next_mask, vector<ll>& next_masks, ll n) {
    if(row == n) {
        next_masks.push_back(next_mask);
        return;
    }

    //if the curr col has this bit on then there is nothing to put so go on row+1
    if((curr_mask >> row) & 1) {
        generate_next_masks(row+1, curr_mask, next_mask, next_masks, n);
    }

    //if it is not a last row we can put vertical tile and go from row+2
    if(row != n-1) {
        if(!((curr_mask >> row) & 1) && !((curr_mask >> (row+1)) & 1)) {
            generate_next_masks(row+2, curr_mask, next_mask, next_masks, n);
        }
    }

    //if we want to put a horizontal tile on the curr row then next mask will have this bit as on
    if(!((curr_mask >> row) & 1)) {
        generate_next_masks(row+1, curr_mask, next_mask | (1 << row), next_masks, n);
    }

}

ll rec(ll col, ll mask, ll m, ll n) {
    
    //return ways from [col...M] if we have this mask already filled of col
    if(col == m) {
        return (mask == 0);
    }

    if(dp[col][mask] != -1) return dp[col][mask];

    ll ans = 0;
    vector<ll> next_masks;
    generate_next_masks(0,mask,0,next_masks,n);

    for(auto& next_mask : next_masks) {
        ans = (ans + rec(col+1, next_mask, m, n)) % mod;
    }

    return dp[col][mask] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,m;
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));
    //ans is to fill col 0 to m with having no tile as filled i.e. mask 0
    cout << rec(0, 0, m, n) << "\n";

    return 0;
}