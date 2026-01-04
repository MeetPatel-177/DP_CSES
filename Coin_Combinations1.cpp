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

vll dp(1e6+1,0);
int main() {
    setupIO();
    ll n,x;
    cin >> n >> x;
    vll c(n);
    f(i,0,n) cin >> c[i];
    //dp[k] no of ways to construct a sum of k
    dp[0] = 1;
    for(int i=1; i<=x; i++) {
        for(int j=0; j<n; j++) {
            if(i - c[j] >= 0)
            dp[i] = (dp[i] + dp[i-c[j]])%M;
        }
    }
    cout << dp[x] << "\n";
    return 0;
}