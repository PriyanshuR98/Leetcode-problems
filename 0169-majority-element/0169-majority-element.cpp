class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        // for(auto it:nums)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<=(n/2);i++)
        {
            // cout<<"i->"<<i<<"   ";
            if(nums[i]==nums[i+(n/2)])
            {
                return nums[i];
            }
        }
        
        return 0;
    }
};