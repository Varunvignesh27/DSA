#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'

static int K = 25;
vector<vector<int>> st;

void sparse_table(vector<int>& nums){
    int n = nums.size();
    st.resize(K,vector<int>(n));

    for(int i=0;i<n;i++){
        st[0][i] = nums[i];
    }

    for(int i=1;i<K;i++){
        for(int j = 0;j + (1 << (i-1)) < n;j++){
            st[i][j] = st[i-1][j]  + st[i-1][j + (1 << (i-1))];
        }
    }
}

int rangeQuery(int l,int r){
    int ans = 0;
    for(int i = K-1;i>=0;i--){
        if(r-l+1 >= (1 << i)){
            ans += st[i][l];
            l += (1 << i);
        }
    }
    return ans;
}

void solve(){
	int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];

    sparse_table(nums);

    cout << rangeQuery(2,4);
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}