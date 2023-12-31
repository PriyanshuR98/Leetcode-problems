class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size(); 

   
    int ind = -1; 
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            
            ind = i;
            break;
        }
    }

    
    if (ind == -1) {
        // reverse the whole array:
        reverse(nums.begin(), nums.end());
        return ;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (nums[i] > nums[ind]) {
            swap(nums[i], nums[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    // reverse(nums.begin() + ind + 1, nums.end());
    sort(nums.begin() + ind + 1, nums.end());

    return ;
        
        
        
    }
};