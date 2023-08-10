class Solution {
public:
        // 
    
            // binary searching on answer..
    bool checker(int possdiff,int p, vector<int>&nums)
    {
        int cnt=0;
        int i=0;
        int n=nums.size();
        
        while(i<=n-2)
        {
            if(nums[i+1]-nums[i]<=possdiff)
            {
                cnt++;
                i+=2;
            }
            else
            {
                i++;
            }
        }

        return (cnt>=p ) ? 1 : 0;
    }


    int minimizeMax(vector<int>& nums, int p) {

        sort(nums.begin(),nums.end());

        int low=0;
        int high=nums[nums.size()-1]-nums[0];

        while(high-low>1)
        {
            int mid= (low+high)/2;

            if(checker(mid,p,nums)==true)
            {
                high=mid;
            }
            else
            {
                low=mid;
            }
        }


        if(checker(low,p,nums)==true)
        {
            return low;
        }
        return high;


        
    }
};