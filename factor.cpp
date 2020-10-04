#include<bits/stdc++.h>
using namespace std;
#define FOR(i,from,to) for(int i = from; i < to; i++)
#define ROF(i,from,to) for(int i = from; i > to; i--)
#define li long int
#define lli long long int
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define mp make_pair

vector<int> factors(int n) {
    vector<int> f;
    for (int x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n); // if the number is prime
    return f;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        vi ans = factors(x);
        for(auto x : ans){  
            cout << x << " ";
        }
        cout << endl;
    }
}
