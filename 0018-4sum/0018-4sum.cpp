class Solution {
public:
    vector<vector< int>> fourSum(vector<int>& nums, int target) 
    {
        
        int n=nums.size();
        long long int tar=target;
        set<vector<int>>st;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                set<long long int>s;
                for(int k=j+1;k<n;k++)
                {
                    long long int sum=nums[i]+nums[j];
                    sum+=nums[k];
                    
                      long long int req=tar-(sum);
                    if(s.find(req)!=s.end())
                    {
                        vector<int>temp={nums[i],nums[j],nums[k],(int)req};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    
                    s.insert(nums[k]);
                }
            }
        }
        
        vector<vector< int>>ans(st.begin(),st.end());
        return ans;
        
        
        
    }
};