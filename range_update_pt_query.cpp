#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set; 
#define endl "\n"
#define FILEIO freopen("test1.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define LL long long 
#define mod 1000000007LL
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pp pop_back
//#define p push
#define I insert
#define bg begin()
#define sz size()
#define all(v) v.begin(),v.end()
#define ALL(v) v.rbegin(),v.rend()
typedef vector<LL> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef map<LL ,LL > mii;
typedef priority_queue<int> pq;
typedef queue<int>que;
typedef stack<int>stk;
#define Inf 100000005LL
#define f first
#define s second
#define INF 1e5


vi arr(200005),seg_tree(600006),lazy(600006);

void builtree(int ind , int start  , int end){

    if (start == end){
        seg_tree[ind] = arr[start];
        return ;
    }

    int mid = (start+end) >> 1;

    builtree(2*ind , start , mid);
    builtree(2*ind+1, mid+1 , end);

    seg_tree[ind] = seg_tree[2*ind] + seg_tree[2*ind+1];
}

void update_range(LL ind  , LL start , LL end , LL qst , LL qed , LL val){

    if(lazy[ind]!=0){
        seg_tree[ind]+= (end - start + 1)*lazy[ind];
        if(start != end){
            lazy[2*ind]+= lazy[ind];
            lazy[2*ind+1]+=lazy[ind];
        }
        lazy[ind]=0;
    }

    if( qst > end || qed < start || start > end)
        return ;

    if(qst <= start && qed>= end){
          seg_tree[ind]+=(end - start + 1)*val;
          if(start !=end){
              lazy[2*ind]+=val;
              lazy[2*ind+1]+=val;
        }
        return ;
    } 
    LL mid = (end + start) >> 1;

    update_range(2*ind , start , mid , qst , qed , val);
    update_range(2*ind+1 , mid+1 , end , qst , qed, val);

    seg_tree[ind] = seg_tree[2*ind] + seg_tree[2*ind+1]; 

}

LL query(LL ind , LL start , LL end , LL index){

    if(lazy[ind]!=0){
        seg_tree[ind]+= (end - start + 1)*lazy[ind];
        if(start != end){
            lazy[2*ind]+= lazy[ind];
            lazy[2*ind+1]+=lazy[ind];
        }
        lazy[ind]=0;
    }

    if(start == end){
        return seg_tree[ind];
    }

    LL mid = (start + end)/2;
    
    if(mid >= index)
        query(2*ind , start , mid , index);
    else
    {
        query(2*ind+1 , mid+1 , end , index);
    }
        
}

int main()
{
    //FILEIO
    LL n , q;

    cin>>n>>q;

    for(LL i=1 ;i<=n ; i++)
        cin>>arr[i];

    builtree(1,1,n);
    
    while(q--){
        int code;
        cin>>code;
        if(code == 1){
            LL l , r , val;
            cin>>l>>r>>val;

            update_range(1 , 1, n , l , r , val);
        }
        else
        {
            LL index;
            cin>>index;
            cout<<query(1 , 1, n , index)<<endl;
        }
        // for(int i=1 ;i<=2*n ;i++)
        //   cout<<seg_tree[i]<<" ";
        // cout<<endl;

        // for(int i=1;i<=2*n;i++)
        //    cout<<lazy[i]<<" ";
        // cout<<endl;  
    }


}