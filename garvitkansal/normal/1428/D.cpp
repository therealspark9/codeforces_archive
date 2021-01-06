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
using namespace std;

ll const nax = 1e5 + 5;
vll mt1(nax), mt2(nax), mt3(nax), vis(nax,0);

void solve(){
	ll n;
	cin >> n;
	vll a(n);
	for(auto &it:a)cin>>it;
	for(ll i = 0; i < n; i++)mt1[i] = mt2[i] = mt3[i] = -1;
	stack <ll> st1, st2, st3;
	for(ll i = n-1; i >= 0; i--){
		if(a[i] == 2){
			if(st1.empty()){cout << -1; return;}
			mt1[i] = st1.top();
			st1.pop();
		}
		else if(a[i] == 3){
			if(sz(st1) + sz(st2) + sz(st3) == 0){cout << -1; return;}
			if(sz(st3)){
				mt3[i] = st3.top();
				st3.pop();
			}
			else if(sz(st2)){
				mt2[i] = st2.top();
				st2.pop();
			}
			else if(sz(st1)){
				mt3[i] = st1.top();
				st1.pop();
			}
		}
		if(a[i] == 1)st1.push(i);
		if(a[i] == 2)st2.push(i);
		if(a[i] == 3)st3.push(i);
	}
	ll h = 1;
	vector<pll> ans;
	for(ll i = 0; i< n; i++){
		if(!a[i] or vis[i])continue;
		if(a[i] == 1){
			ans.pb({h,i+1});
			h++;
		}
		else if(a[i] == 2){
			ans.pb({h,i+1});
			ans.pb({h,mt1[i]+1});
			vis[mt1[i]] = 1;
			h++;
		}
		else if(a[i] == 3){
			ans.pb({h,i+1});
			if(mt3[i] != -1)ans.pb({h,mt3[i]+1});
			if(mt2[i] != -1)ans.pb({h,mt2[i]+1});
			if(mt1[i] != -1)ans.pb({h,mt1[i]+1});
			h++;
		}
	}
	cout << sz(ans) <<endl;
	for(auto it:ans)cout<<it.f<<" "<<it.s<<endl;
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