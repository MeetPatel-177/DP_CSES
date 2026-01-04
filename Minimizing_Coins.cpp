#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vs vector<string>
#define vp vector<pair<ll,ll>>

#define f(i,a,b) for(ll i=a; i<b; ++i)
#define fr(i,a,b) for(ll i=a-1; i>=b; --i)
#define fa(v) for(auto& it : v)
#define ff first
#define ss second
#define whole(x) (x).begin(), (x).end()

#define yes cout << "Yes\n"
#define no cout << "No\n"

const ll M = 1e9 + 7;

void setupIO() {
    ios_base::sync_with_stdio(false); //disables the sync between ios and stdio
    cin.tie(0); //untie cin and cout
    cout.tie(0); //optional
}

vll dp(1e6+1, INT_MAX);
int main() {
    setupIO();
    ll n,x;
    cin >> n >> x;
    vll v(n);
    f(i,0,n) cin >> v[i];
    //dp[k] is the minimal coins to make a sum k
    dp[0] = 0;
    for(int i=1; i<=x; i++) {
        for(int j=0; j<n; j++) {
            if(i - v[j] >= 0)
            dp[i] = min(dp[i], dp[i-v[j]] + 1);
        }
    }
    if(dp[x] == INT_MAX) cout << -1 << "\n";
    else cout << dp[x] << "\n";
    return 0;
}