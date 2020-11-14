class Solution {
public:
    vector<vector<int> > ans;
    
    
    void subsetsWithDupUtils(vector<int> &nums, int curr, int index, int len, vector<int> subset){
        if(curr == len) {
          ans.push_back(subset);
          return;
        }

        if(index >= nums.size()) {
          return;
        }

        subset.push_back(nums[index]);
        subsetsWithDupUtils(nums, curr + 1, index + 1, len, subset);
        subset.pop_back();
        
        while(index + 1 < nums.size() && nums[index] == nums[index + 1]){
          ++index;
        }
        
        subsetsWithDupUtils(nums,curr, index + 1, len, subset);
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        int n = nums.size();
        vector<int> subset;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= n; i++){
            subsetsWithDupUtils(nums, 0, 0, i, subset);
        }
        return ans;
    }
};
