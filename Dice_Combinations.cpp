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

vll dp(1e6+1, 0);
int main() {
    setupIO();
    ll n;
    cin >> n;
    //dp[k] is the no of ways to get a sum of k by throwing dices
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=6; j++) {
            if(i-j >= 0) {
                dp[i] = (dp[i] + dp[i-j])%M;
            }
        }
    }
    // cout << dp[n] << "\n";

    deque<ll> prev = {1};
    for(int i=1; i<=n; i++) {
        int val = 0;
        for(auto& curr : prev) {
            val = (val + curr) % M;
        }
        prev.push_back(val);
        if(prev.size() > 6) prev.pop_front();
    }
    cout << prev.back() << "\n";
    return 0;
}