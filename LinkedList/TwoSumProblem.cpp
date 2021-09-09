//LEETCODE
//TWo sum problem using hashing
//TC- O(N)
//SC - O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int len = nums.size();
        int i;
        for(i=0;i<len;i++) {
            int compliment = target - nums[i];
            if(mp.find(compliment)!=mp.end()) {
                return {i,mp[compliment]};
            } 
            else {
                mp[nums[i]]=i;
            }
        }
         return {};
    }
   
};
