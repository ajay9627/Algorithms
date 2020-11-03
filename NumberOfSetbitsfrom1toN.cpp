#include<bits/stdc++.h>
using namespace std;

int main() {
    
	long long arr[65] = {1};
	for(int i = 1; i <= 64; i++){
		arr[i] = arr[i - 1] * 2;
	}
	
	int t;
	cin >> t;
	while(t--) {
	    long long n;
	    cin >> n;
	    ++n;

	    long long number_of_set_bits = 0;
	    for(int i = 1; i <= 32; i++) {
		    number_of_set_bits += (n / arr[i]) * (arr[i] / 2);

		    long long mod = n % arr[i];
		    if(mod > (arr[i] / 2))
		 	    number_of_set_bits += mod % (arr[i] / 2);
	    }
	    cout << number_of_set_bits <<"\n";
	}
}
