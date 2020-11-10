// v is parent of node u
//dp[][] table stores the 2^i ancestor from node u.
void preprocess(int u, int v) {
        dp[u][0] = v;
        for(int i = 1 ; i <= 17; i++) {
            dp[u][i] = dp[dp[u][i - 1]][i - 1];
            if(dp[u][i] == -1)
                return;
        }
}
TreeAncestor(int n, vector<int>& parent) {
        memset(dp, -1, sizeof(dp));
        int MAX = (int)ceil(log2(50001));
        // for each node, we maintain 2^k ancestor from node u.
        for(int i = 1; i < n; i++) {
            preprocess(i, parent[i]);
   }
}

int getKthAncestor(int node, int k) {
        for(int i = 0 ; i < 32; i++) {
            if(k & (1 << i)) {
                node = dp[node][i];
                if(node == -1)
                    return -1;
            }
        }
        return node;
    }
