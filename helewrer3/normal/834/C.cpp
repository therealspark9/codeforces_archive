/*May the force be with me*/
#include <cmath>
#include <cstdio>
typedef long long ll;
using namespace std;

ll a, b;

void input(){
	scanf("%I64d %I64d", &a, &b);
}

ll cb(ll x){
	ll l = 0, r = 1000005;
	while(l <= r){
		ll mid = l + (r-l)/2;
		if(mid*mid*mid > x)r=mid-1;
		else l = mid+1;
	}
	return l-1;
}

void solve(){
	ll x = cb(a*b);
	if(x*x*x != a*b)puts("No");
	else if(a%x == 0 and b%x == 0)puts("Yes");
	else puts("No");
}

int main(){
	int t = 1;
	scanf("%d", &t);
	while(t--){
		input();
		solve();
	}
	return 0;
}