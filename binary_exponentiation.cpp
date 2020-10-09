#include<bits/stdc++.h>
using namespace std;

#define even(a) (!(a&1))
#define M 1000000007

typedef long long ll;

ll power(ll a, ll b) {
	ll result = 1;

	while(b!=0) {

		if(!even(b)) {
			result = ((result%M) * (a%M))%M;
		}
		a = ((a%M)*(a%M))%M;
		b = b>>1;
	}

	return result;
}

int main() {
	ll a, b;

	cin>>a>>b;

	cout<<power(a, b)<<endl; // a raised to the exponent b
	return 0;
}
