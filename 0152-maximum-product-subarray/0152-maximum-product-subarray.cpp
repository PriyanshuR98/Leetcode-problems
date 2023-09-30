class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n=nums.size();
        int pref=1;    
        int suff=1;    
        int maxprod=-1e5;
        
        for(int i=0;i<n;i++)
        {
            if(pref ==0)
            {
                pref=1;
            }
            
            if(suff ==0)
            {
                suff=1;
            }

            pref*=nums[i];
            suff*=nums[n-i-1];
            maxprod=max(maxprod,max(pref,suff));
            
        }

        return maxprod;
    }
};