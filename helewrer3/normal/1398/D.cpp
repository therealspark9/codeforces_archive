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
	ll r, g, b;
	cin >> r >> g >> b;
	vll x(r), y(g), z(b);
	for(auto &it:x)cin>>it;
	for(auto &it:y)cin>>it;
	for(auto &it:z)cin>>it;
	sort(rall(x));
	sort(rall(y));
	sort(rall(z));
	ll q = 0, w = 0, e = 0, ans = 0;
	while(1){
		ll ans1 = -inf, ans2 = -inf, ans3 = -inf;
		if(q < r and w < g)ans1 = x[q]*y[w];
		if(q < r and e < b)ans2 = x[q]*z[e];
		if(w < g and e < b)ans3 = z[e]*y[w];
		if(ans1 == -inf and ans2 == -inf and ans3 == -inf)break;
		else if(ans1 >= ans2 and ans1 >= ans3){
			ans+=ans1;
			q++, w++;
		}
		else if(ans2 >= ans1 and ans2 >= ans3){
			ans+=ans2;
			q++, e++;
		}
		else if(ans3 >= ans2 and ans3 >= ans2){
			ans+=ans3;
			e++, w++;
		}
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