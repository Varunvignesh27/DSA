#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'

int partition(vector<int>& nums,int l,int h){
	int p = l + rand() % (h - l + 1);
	swap(nums[p],nums[h]);
	int pivot = nums[h];
	int i = l-1;

	for(int j=l;j<h;j++){
		if(nums[j] < pivot){
			i++;
			swap(nums[i],nums[j]);
		}
	}
	swap(nums[i+1],nums[h]);
	return i+1;
}

void quicksort(vector<int>& nums,int l,int h){
	
	if(l < h){
		int pi = partition(nums,l,h);

		quicksort(nums,l,pi-1);
		quicksort(nums,pi+1,h);
	}
}
 
void solve(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0;i<n;i++)
		cin >> nums[i];

	quicksort(nums,0,n-1);

	for(int i : nums){
		cout << i << " ";
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}