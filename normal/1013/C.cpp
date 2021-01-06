//May the force be with me
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;


void solve(){
	ll n;
	cin >> n;
	vll a(2*n);
	for(auto &it:a)cin >> it;
	n*=2;
	ll d = (n+1)/2, ans = inf;
	sort(all(a));	
	// for(auto it:a)cout << it << " ";
	// cout<<endl;
	for(ll i = 0; i < n; i++){
		if(i+d-1>n-1)break;
		ll l, r;
		if(!i)l=a[i+d];
		else l=a[0];
		if(i+d-1 >= n-1)r=a[i-1];
		else r = a[n-1];
		ans = min(ans, (r-l)*(a[i+d-1]-a[i]));
		// cout << l << " " << r << endl;
	}
	cout<<ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi