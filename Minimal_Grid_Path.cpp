/**
 *    author:  Meet
 *    created: 30.12.2025 14:08:14
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

#define ll int

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        vector<string> grid(n);
        for(ll i=0; i<n; ++i) cin >> grid[i];

        vector<vector<bool>> vis(n, vector<bool>(n,0));
        vector<pair<ll,ll>> prev;

        string ans;
        prev.push_back({0,0});
        ans.push_back(grid[0][0]);

        for(ll ch=2; ch<2*n; ++ch) {
            char mn = 'z';
            for(auto& [i,j] : prev) {
                if(i+1 < n) mn = min(mn, grid[i+1][j]);
                if(j+1 < n) mn = min(mn, grid[i][j+1]);
            }
            ans.push_back(mn);
            vector<pair<ll,ll>> curr;
            for(auto& [i,j] : prev) {
                if(i+1 < n && grid[i+1][j] == mn && !vis[i+1][j]) {
                    curr.push_back({i+1,j});
                    vis[i+1][j] = true;
                }
                if(j+1 < n && grid[i][j+1] == mn && !vis[i][j+1]) {
                    curr.push_back({i,j+1});
                    vis[i][j+1] = true;
                }
            }
            prev = curr;
        }

        cout << ans << "\n";
    }
    return 0;
}