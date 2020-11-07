#include<bits/stdc++.h>
using namespace std;
 
void func(vector<int> &arr) {
	
	// create vector of unorded_set of length n. 
	//store sum of subset of every length x say(1, 2, 3, ....n)
	int n = arr.size();
	vector<unordered_set<int> > s(n + 1);
	
	s[0].insert(0); // insert sum of empty subset i.e 0

	for(int a : arr) { // consider each element of array
		for(int i = n; i >= 1; i--) { // consider length of each subset
			for(int b : s[i - 1]) { 
				s[i].insert(a + b); // add current element to subset of length (i - 1).
			}
		}
	}

	for(int i = 0 ; i <= n; i++) {
		cout<<"length "<< i <<" --> ";
		for(int x : s[i]) {
			cout<<x<<" ";
		}
		cout<<"\n";
	}


}

int main() {
	vector<int> arr({1, 2, 3, 4, 5, 6, 7, 8, 9});
	func(arr);
}
