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

ll n, Q;
const ll nax = 3 * 10e5 + 5;
set<ll> s[nax];
queue<pll> q; 

void input(){
	cin >> n >> Q;
}

void solve(){
	ll idx = 1, cnt = 0;
	while(Q--){
		ll a, b;
		cin >> a >> b;
		if(a == 1){
			q.push({b, idx});
			s[b].insert(idx);
			idx++;
			cnt++;
		}
		else if(a == 2){
			cnt -= sz(s[b]);
			s[b].clear();
		}
		else{
			ll ans = 0;
			while(!q.empty() and q.front().s <= b){
				pll v = q.front();
				q.pop();
				if(s[v.f].find(v.s) != s[v.f].end()){
					s[v.f].erase(s[v.f].find(v.s));
					cnt--;
				}
			}
		}
		cout << cnt << endl;
	}
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