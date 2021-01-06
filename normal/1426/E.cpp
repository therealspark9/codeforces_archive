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

ll n;

void input(){
	cin >> n;
}

void solve(){
	vll a(3), b(3);
	ll x = 0, y = 0;
	for(auto &it:a)cin >> it;
	for(auto &it:b)cin >> it;
	//rsp
	x = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
	y = max({y, a[0] - b[0] - b[2], a[1] - b[1] - b[0], a[2] - b[1] - b[2]});
	cout << y << " " << x;
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