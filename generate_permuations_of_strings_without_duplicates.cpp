
bool couldSwap(string s, int l, int curr) {
	for(int i = l; i < curr; i++) {
		if(s[i] == s[curr])
			return false;
	}
	return true;
}
void permute(string s, int l, int r) {
	if(l == r) {
		cout << s;
		return ;
	} 

	for(int i = l; i <= r; i++) {
		bool check = couldSwap(s, l, i);
		if(check) {
			swap(s[l], s[i]);
			permute(s, l + 1, r);
			swap(s[i], s[l]);
		}
	}
}
