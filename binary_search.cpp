#include<bits/stdc++.h>
using namespace std;
#define FOR(i,from,to) for(int i = from; i < to; i++)
#define ROF(i,from,to) for(int i = from; i > to; i--)
#define li long int
#define lli long long int
#define MOD 1e9+7
typedef vector<int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define mp make_pair

int binary_search(vector<int> &v, int low, int high, int target){
    if(low > high) return -1;
    int mid = low + (high-low)/2;
    if(v[mid] == target) return mid;
    else if(v[mid] > target) return binary_search(v,low,mid-1,target);
    else return binary_search(v,mid+1,high,target);
}

int iter_bs(vector<int> &v, int low, int high, int target){
    while(low <= high){
        int mid = low + (high-low)/2;
        if(v[mid] == target) return mid;
        else if(v[mid] > target) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        vector<int> v;
        int n;
        cin >> n;
        v.resize(n);
        FOR(i,0,n) cin >> v[i];
        int target;
        cin >> target;
        cout << binary_search(v,0,n-1,target) << endl;
        cout << iter_bs(v,0,n-1,target) << endl;
    }
}

// input 
// t
// n
// v[]
// target