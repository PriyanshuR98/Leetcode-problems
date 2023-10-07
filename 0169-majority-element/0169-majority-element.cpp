class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int n=nums.size();
        int cnt=0;
        int val=-1;
        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                val=nums[i];
            }
            if(nums[i]==val)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
           
        }
        
        return val;
        
    }
};