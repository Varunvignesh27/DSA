#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'

//Kadane's Algorithm
/*
	Kadane's Algorithm is used to find the maximum subarray sum for array(contains positive and negative).
	(it optimized version of DP)

	Choices :
		1 : Extend the subarray sum if previous sum(curr + nums[i]) is positive 
		2 : Start subarray sum if the previous sum(curr + nums[i]) is negative
*/

void solve(vector<int> nums,int n){
	int curr = nums[0];
	int res = nums[0];
	
	for(int i=1;i<n;i++){
		curr = max(nums[i],curr + nums[i]);
		res = max(res,curr);
	}

	cout << res;
	return ;
}
 
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve({1,2,3,4,5},5);
	
	return 0;
}