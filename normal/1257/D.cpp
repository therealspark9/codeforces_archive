//May the force be with me
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
#define endl "\n"
using namespace std;


void solve(){
	ll n;
	cin >> n;
	vll a(n);
	for(auto &it:a)cin>>it;
	ll m;
	cin >> m;
	vector<pll> b(m), sb(m);
	for(auto &it:b)cin>>it.f>>it.s;
	sort(all(b));
	sb[m-1].f = b[m-1].s, sb[m-1].s = m-1;
	for(ll i = m-2; i >= 0; i--){
		sb[i] = sb[i+1];
		if(b[i].s > sb[i].f) sb[i].f = b[i].s, sb[i].s = i;
	}
	ll sta = 0, str = 0, idx = -inf, ans = 0;
	for(ll i = 0; i < n; i++){
		if(str > a[i] and sta){
			sta--;
			continue;
		}
		ll l = 0, r = m-1, midd = -1;
		while(l <= r){
			ll mid = l + (r-l)/2;
			if(b[mid].f < a[i])l=mid+1;
			else{
				midd = mid;
				r = mid-1;
			}
		}
		if(midd == -1){
			cout<<-1;
			return;
		}
		ll nsta = sb[midd].f, nstr = b[sb[midd].s].f;
		if(nstr >= str and nsta >= (i-idx)+1){
			str = nstr;
			sta = nsta-((i-idx)+1);
		}
		else idx = i, sta = nsta-1, str = nstr, ans++;
	}
	cout<<ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi