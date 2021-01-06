#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll m, s;
	cin >> m >> s;
	if((m > 1 and !s) or s > 9*m)cout<<"-1 -1";
	else{
		string ans;
		for(ll i = 1; i <= m; i++){
			for(ll j = 9; j >= 0; j--){
				if(s-j >= 0){
					ans += '0' + j;
					s -= j;
					break;
				}
			}
		}
		
		string t = ans;
		reverse(t.begin(), t.end());
		if(t[0] == '0'){
			for(ll i = 0; i < m; i++){
				if(t[i] != '0'){
					t[i]--,t[0]++;
					break;
				}
			}
		}
		cout << t << " " << ans;
	}
	return 0;
}