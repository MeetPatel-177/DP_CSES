/**
 *    author:  Meet
 *    created: 05.09.2026 17:07:16
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

const ll N = 1e6 + 10;
ll dp[N][2];
//dp[i][0] defines the number of ways to build height i with the top as separate two columns (two columns independently trying to extend) (|_|_|)
//dp[i][1] defines the number of ways to build height i with the top as merged (single column) (one block is trying to extend) (|__|)

void precompute() {
    dp[1][0] = dp[1][1] = 1; //either put two vertical tiles or one horizontal tile

    //at the end whether we have the block trying to extend or two columns trying to extend doesn't matter we can just put a bar and close both the states

    for(ll i=2; i<=N; ++i) {
        //now if i-1 is separate then we have 4 possibilities for i also as separate (left block and right extend), (right block and left extend), (both bloked then extend), (both open and continue extending)
        //now if i-1 is merged means one block then we only have 1 possibility to close that block and start with two vertical tiles at i
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1]) % M;
        //now if i-1 is separate then we have only one possibility of close the block at i-1 and start a new block with two vertical tiles at i
        //now if i-1 is merged means one block then we have two possibilities of making i as one block (close the i-1 the block and start a new block with 1 horizontal tile at i) (continue the previous one block and extend it as it is)
        dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1]) % M;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    precompute();

    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        //now at the end we can put a bar on both single block or two columns so both will be counted in number of ways
        cout << (dp[n][0] + dp[n][1]) % M << "\n";
    }
    return 0;
}