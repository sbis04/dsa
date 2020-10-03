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

int partition(int *A, int start, int end){
    int pivot = A[end];
    int pindex = start;
    FOR(j,start,end){
        if(pivot >= A[j]){
            swap(A[pindex], A[j]);
            pindex++;
        }
    }
    swap(A[pindex],A[end]);
    return pindex;
}


void quicksort(int* A, int start, int end){
    if(start < end){
        int part = partition(A,start,end);
        quicksort(A,start,part-1);
        quicksort(A,part+1,end);
    }
}

void quick(int* A, int n){
    int start = 0, end = n-1;
    quicksort(A, start, end);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n; 
        int A[n];
        FOR(i,0,n) cin >> A[i];
        quick(A,n);
        FOR(i,0,n) cout << A[i] << " ";
        cout << nl;

    }
}

// t
// n 
// A[]

