#include <bits/stdc++.h>
using namespace std;

#define ll int
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
    ll n,x;
    cin >> n >> x;
    vll c(n);
    f(i,0,n) cin >> c[i];
    vll nextState(x+1,0);
    nextState[0] = 1;
    //c1 c1 c2 c2 c4 = x
    //c1 c2 c4 c2 c1 = x
    //this both should count as 1 because of their order
    //so we will always think of first case i.e. finish out all the occurences of any single coin for the current way of producing the sum k
    //so here we have to take care of coin also which we can pick
    //dp[i][k] is the number of distinct ways in which we can make sum of k using coins from ci to cn
    //dp[i][0] = 1;
    //why the inner loop runs from right to left it's because we need the answer of dp[0][x] so always remember whatever answer we needed we have to make that answer from bigger problem so here we need to make x from smaller values so loop from 1 to x and we have to make 0 as ind so runs a loop from n-1 to 0
    //dp[i][k] = dp[i+1][k] + dp[i][k-c[i]]
    //so i depends on i and i+1 i.e. we only need currentState(i) and nextState(i+1) for solving the question
    fr(i,n,0) {
        vll currentState(x+1,0);
        currentState[0] = 1;
        f(sum,1,x+1) {
            ll skipping = nextState[sum];
            ll picking = 0;
            if(sum - c[i] >= 0) 
            picking = currentState[sum - c[i]];
            currentState[sum] = (picking + skipping) % M;
        }
        nextState = currentState;
    }
    cout << nextState[x] << "\n";
    //dp[0][x] 
    return 0;
}