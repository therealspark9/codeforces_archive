//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n, k, a, b;

void input(){
	cin >> n >> k >> a >> b;
}

void solve(){
	ll d = min(a, b);
	ll D = d;
	a -= d, b -= d;
	string ans = "";
	if(a){
		while(d){
			ans += "GB";
			d--;
		}
		ans += "G";
		a--;
		if(a <= (D+1)*(k-1)){
			for(auto it:ans){
				cout << it;
				if(it == 'G'){
					ll x = min(k-1, a);
					a -= x;
					while(x){
						cout<<"G";
						x--;
					}
				}
			}
		}
		else cout << "NO";
	}
	else if(b){
		while(d){
			ans += "BG";
			d--;
		}
		ans += "B";
		b--;
		if(b <= (D+1)*(k-1)){
			for(auto it:ans){
				cout << it;
				if(it == 'B'){
					ll x = min(k-1, b);
					b -= x;
					while(x){
						cout<<"B";
						x--;
					}
				}
			}
		}
		else cout << "NO";
	}
	else{
		while(d){
			ans += "BG";
			d--;
		}
		cout << ans;
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