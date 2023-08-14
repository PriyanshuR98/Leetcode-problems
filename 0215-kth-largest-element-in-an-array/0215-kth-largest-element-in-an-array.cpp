class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        
        multiset<int, greater<int> > ms;
 
        for(int i=0;i<nums.size();i++)
        {
            ms.insert(nums[i]);
        }
        
        int val=0;
        
        for(auto it:ms)
        {
            k--;
            if(k==0)
            {
                val=it;
                break;
            }
        }
        
        return val;
        
    }
};