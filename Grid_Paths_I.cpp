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
    vs grid(n);
    f(i,0,n) cin >> grid[i];
    //dp[i][j] is the no of paths from (i,j) to (n-1,m-1) with avoiding obstacles
    // vvll dp(n+1, vll(n+1)); 
    vll nextRow(n+1,0);
    nextRow[n-1] = 1;
    // dp[n-1][n-1] = 1;
    fr(i,n,0) {
        vll currRow(n+1,0);
        fr(j,n,0) {
            //when we have obstacle there is no path to going from that perticular point
            if(grid[i][j] == '*') {
                currRow[j] = 0;
                // dp[i][j] = 0;
                continue;
            }
            //dp[i][j] = (dp[i][j] + dp[i+1][j]) % M
            currRow[j] = (currRow[j] + nextRow[j]) % M;
            //dp[i][j] = (dp[i][j] + dp[i][j+1]) % M
            currRow[j] = (currRow[j] + currRow[j+1]) % M;
        }
        nextRow = currRow;
    }
    cout << nextRow[0] << "\n";
    //dp[0][0] 
    return 0;
}