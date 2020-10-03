#include<iostream>
using namespace std;
#define nl "\n"

int max(int a, int b){
    return (a >= b) ? a : b;
}

void ans(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int maxval = a[0];
    int max_so_far = a[0];
    for(int i = 1; i < n; i++){ 
        maxval = max(maxval+a[i],a[i]);
        max_so_far = max(maxval,max_so_far);
    }
    cout << max_so_far << nl;
}

int main()
 {
    int t;
    cin >> t;
    while(t--){
        ans();
    }
	return 0;
}