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
	string a, b;
	cin >> a >> b;
	ll a_10 = 0, b_01 = 0, ab_11 = 0, ab_00 = 0; //pqrs
	for(ll i = 0; i < n; i++){
		if(a[i] == '1' and b[i] == '1')ab_11++;
		else if(a[i] == '0' and b[i] == '0')ab_00++;
		else if(a[i] == '0' and b[i] == '1')b_01++;
		else if(a[i] == '1' and b[i] == '0')a_10++;
	}
	for(ll p = 0; p <= a_10; p++){
		for(ll r = 0; r <= ab_11; r++){
			ll s = n/2 + r - ab_11 - b_01;
			ll q = n/2 - p - r - s;
			if(s >= 0 and s <= ab_00 and q >= 0 and q <= b_01){
				for(ll i = 0; i < n; i++){
					if(a[i] == '1'){
						if(b[i] == '1' and r){
							r--;
							cout<<i+1<<" ";
						}
						else if(b[i] == '0' and p){
							p--;
							cout<<i+1<<" ";
						}
					}
					else{
						if(b[i] == '0' and s){
							s--;
							cout<<i+1<<" ";
						}
						else if(b[i] == '1' and q){
							q--;
							cout<<i+1<<" ";
						}
					}
				}
				return;
			}
			else continue;
		}
	}
	cout<<-1;
	
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