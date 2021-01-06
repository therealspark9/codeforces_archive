//May the force be with me
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update> 
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
#define endl "\n"
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vll a(n), b(n+1,0);
	for(auto &it:a)cin >> it;
	ordered_set s;
	for(ll i = n-1; i >= 0; i--){
		b[a[i]] += s.order_of_key(a[i]);
		s.insert(a[i]);
	}
	ll mx = -inf;
	for(auto it:b)mx = max(mx, it);
	for(ll i = 1; i < n+1; i++){
		if(mx == b[i]){
			cout << i;
			return;
		}
	}
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