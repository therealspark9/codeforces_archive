//May the force be with me
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e19
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

ll sq(ll x){return x*x;}
ll ans = inf;

void rando(vll vr, vll vg, vll vb){
	for(auto it:vg){
		auto jt_r = upper_bound(all(vr), it);
		if(jt_r == vr.end())jt_r--;
		ll jt = *jt_r;
		auto kt_r = upper_bound(all(vb), it);
		if(kt_r == vb.end())kt_r--;
		ans = min(ans, sq(it-jt) + sq((*kt_r)-jt) + sq((*kt_r)-it));
		if(kt_r != vb.begin()){
			kt_r--;
			ans = min(ans, sq(it-jt) + sq((*kt_r)-jt) + sq((*kt_r)-it));
		}
		if(jt_r != vr.begin()){
			jt_r--;
			jt = *jt_r;
			kt_r = upper_bound(all(vb), it);
			if(kt_r == vb.end())kt_r--;
			ans = min(ans, sq(it-jt) + sq((*kt_r)-jt) + sq((*kt_r)-it));
			if(kt_r != vb.begin()){
				kt_r--;
				ans = min(ans, sq(it-jt) + sq((*kt_r)-jt) + sq((*kt_r)-it));
			}
		}
	}
}



void solve(){
	ans = inf;
	ll r, g, b;
	cin >> r >> g >> b;
	vll vr, vg, vb;
	vr.resize(r), vb.resize(b), vg.resize(g);
	for(auto &it:vr)cin>>it;
	for(auto &it:vg)cin>>it;
	for(auto &it:vb)cin>>it;
	sort(all(vr));
	sort(all(vg));
	sort(all(vb));
	rando(vr, vg, vb);
	rando(vb, vg, vr);
	rando(vg, vr, vb);
	rando(vb, vr, vg);
	rando(vr, vb, vg);
	rando(vg, vb, vr);
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