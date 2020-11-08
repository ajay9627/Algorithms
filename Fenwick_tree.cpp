#include<bits/stdc++.h>
using namespace std;

 /**
     * To get next
     * 1) 2's complement of get minus of index
     * 2) AND this with index
     * 3) Add it to index
*/
int getNext(int index) {
	return (index + (index & -index));
}

/**
     * To get parent
     * 1) 2's complement to get minus of index
     * 2) AND this with index
     * 3) Subtract that from index
*/
int getParent(int index) {
	return (index - (index & -index));
}

void fenwick(int tree[], int arr[], int n) {
	int curr ;
	for(int i = 1; i <= n; i++) {
		curr = i;
		while(curr <= n) {
			tree[curr] += arr[i - 1];
			curr = getNext(curr);
		}
	}
}

int getSum(int tree[], int index){
	int parent = index, sum = 0;
	while(parent > 0) {
		sum += (tree[parent]);
		parent = getParent(parent);
	}
	return sum;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int tree[n + 1];
		memset(tree, 0, sizeof(tree));
		fenwick(tree, arr, n);
		int q, l, r;
		cin >> q;
		while(q--) {
			cin >> l >> r;
			if(l != 0){
				cout<<getSum(tree, r) - getSum(tree,l - 1);
			} else {
				cout<<getSum(tree,r)<<"\n";			}
		}
	}
	return 0;
}
