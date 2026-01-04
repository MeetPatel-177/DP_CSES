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

int main() {
    setupIO();
    ll n;
    cin >> n;
    // we can do this by dp also but it will take more time as compared to greedy
    ll steps = 0;
    while(n) {
        ll max_dig = 0;
        ll dup = n;
        while(n) {
            max_dig = max(max_dig, n%10);
            n /= 10;
        }
        n = dup;
        n -= max_dig;
        ++steps;
    }
    cout << steps << "\n";
    return 0;
}