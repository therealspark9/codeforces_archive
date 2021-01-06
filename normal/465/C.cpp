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
	ll n,p;
	cin >> n >> p;
	string s;
	cin >> s;
	for(ll i = sz(s)-1; i >= 0; i--){
		for(ll j = s[i] - 'a' + 1;  j < p; j++){
			char ch = j + 'a';
			char left, left2;
			if(i > 1)left = s[i-1], left2 = s[i-2];
			else if(i == 1)left = s[i-1], left2 = '%';
			else left = left2 = '%';  
			if(ch != left and ch != left2){
				s[i] = ch;
				for(ll k = i+1; k < n; k++){
					if(k > 1)left = s[k-1], left2 = s[k-2];
					else if(k == 1)left = s[k-1], left2 = '%';
					else left = left2 = '%';
					ch = 'a';
					for(ll l = 0; l < p; l++){
						if(l != left-'a' and l != left2-'a'){
							s[k] = 'a'+l;
							break;
						}
					}
				}
				cout << s;
				return;
			}
		}
	}
	cout << "NO";
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
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi