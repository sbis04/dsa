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
#define nl "\n"

void gensubarr(int *a, int n, int l, int r){
    if(r == n) return;
    else if(l > r) gensubarr(a,n,0,r+1);
    else{
        cout << "[";
        FOR(i,l,r) cout << a[i] << ",";
        cout << a[r] << "]" << nl;
        gensubarr(a,n,l+1,r);
    }
}

void itergensubarr(int *a, int n){
    FOR(i,0,n){
        FOR(j,i,n){
            cout << "[";
            FOR(k,i,j) cout << a[k] << " ";
            cout << a[j] << "]" << nl;
        }
    }
}

void ans(){
    int n;
    cin >> n;
    int a[n];
    FOR(i,0,n) cin >> a[i];
    int l = 0, r = 0;
    gensubarr(a,n,l,r);
    cout << nl;
    itergensubarr(a,n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ans();        
    }
}

/*
input
t
n
a => []

output
2 * all the subarray of the integer array
*/