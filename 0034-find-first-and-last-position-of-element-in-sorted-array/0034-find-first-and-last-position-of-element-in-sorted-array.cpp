class Solution {
public:

    int bsearch(int low,int high, vector<int>nums,int target, bool leftselena)
    {
        int index=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;

            if(nums[mid]==target)
            {
                index=mid;
                if(leftselena)
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else if(nums[mid]>target)
            {
                high--;
            }
            else
            {
                low++;
            }

        }

        return index;

    }
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int leftind=bsearch(0,nums.size()-1,nums,target,true);
        int rightind=bsearch(0,nums.size()-1,nums,target,false);
        if(leftind<=rightind and leftind!=-1 and rightind!=-1)  return {leftind,rightind};

        return {-1,-1};
        
    }
};