/*May the force be with me*/
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb push_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

ll x, y, x2, y2;

void input(){
	cin >> x >> y >> x2 >> y2;
}

void solve(){
	ll n, ans = 0;
	cin >> n;
	while(n--){
		ll a, b, c;
		cin >> a >> b >> c;
		if(abs(a*x+b*y+c)/(a*x+b*y+c) != abs(a*x2+b*y2+c)/(a*x2+b*y2+c))ans++;
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
        cout<<endl;
	}
	cin.get();
	return 0;
}