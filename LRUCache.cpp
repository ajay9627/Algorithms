//https://www.geeksforgeeks.org/lru-cache-implementation/
#include<bits/stdc++.h>
using namespace std;


class LRUCache {
public:
	int nframes;
	list<int> dq;
	unordered_map<int, list<int>::iterator> mp;

	LRUCache(int nframes) {
		this->nframes = nframes;
	}

	void refer(int x) {
		if(mp.find(x) == mp.end()) {
			if(dq.size() == nframes) {
				int last = dq.back();
				dq.pop_back();
				mp.erase(last);
			}
		} else {
			dq.erase(mp[x]);
		}

		dq.push_front(x);
		mp[x] = dq.begin();

	}


	void display() {
		for(int a : dq) {
			cout << a << " ";
		}
		cout << "\n";
	}

};

int main() {
	LRUCache ca(4);
 
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
 
    return 0;
}
