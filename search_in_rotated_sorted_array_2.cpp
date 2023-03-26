class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(nums[0] == target){
                return true;
            }
            else{
                return false;
            }
        }
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[start] == nums[mid] && nums[mid] == nums[end]){
                start++;
            }
            else if(nums[start] <= nums[mid]){  //checking array is sorted or not becuse of rotation
                if(target >=  nums[start] && target < nums[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
            else{
                if(target > nums[mid] && target <= nums[end]){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};