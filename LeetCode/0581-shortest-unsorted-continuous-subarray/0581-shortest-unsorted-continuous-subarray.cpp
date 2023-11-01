class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    
        if(nums.size()==0){
            return 0;
        }
        
        int idx = 0;
        int idx2 = nums.size()-1;
        int right = nums.size();
        int maxNum = nums[0];
        int left = 0;
        int minNum = nums[right-1];
        
        while(idx <= nums.size()&& idx2 >= 0){
            if(nums[idx] < maxNum){
                right = idx;
            }
            maxNum = max(maxNum, nums[idx]);
            idx++;
            
            if(nums[idx2] > minNum){
                left = idx2;
            }
            minNum = min(minNum,nums[idx2]);
            idx2--;
            
        }
        if(right == nums.size() && left == 0){
            return 0;
        }
        return right - left + 1;
    }
};