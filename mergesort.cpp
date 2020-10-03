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

void merge(int* A, int start, int end, int mid){
    int leftlen = mid-start+1;
    int rightlen = end-mid;
    int L[leftlen], R[rightlen];
    FOR(i,0,leftlen) L[i] = A[start+i];
    FOR(j,0,rightlen) R[j] = A[mid+1+j];

    int i = 0, j = 0;
    int k = start;
    while(i < leftlen && j < rightlen){
        if(L[i] > R[j]){
            A[k] = R[j];
            j++, k++;
        }
        else{
            A[k] = L[i];
            i++, k++;
        }
    }
    for(;i < leftlen; i++){
        A[k] = L[i];
        k++;
    }
    for(;j < rightlen; j++){
        A[k] = R[j];
        k++;
    }
}

void mergesort(int* A, int start, int end){
    if(start < end){
        int mid = start + (end-start)/2;
        mergesort(A,start,mid);
        mergesort(A,mid+1,end);
        merge(A,start,end,mid);
    }
}

void mergealgo(int* A, int n){
    int start = 0, end = n-1;
    mergesort(A,start,end);      
    FOR(i,0,n) cout << A[i] << " ";
    cout << nl;        
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
        mergealgo(A,n);
    }
}
