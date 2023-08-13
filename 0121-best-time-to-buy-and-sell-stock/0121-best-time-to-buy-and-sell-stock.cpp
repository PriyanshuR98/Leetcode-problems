class Solution {
public:
    int maxProfit(vector<int>& prices) {

        //if we need to sell stock on ith day then we should have bought on day from 0 to i-1 at lowest         price..
        
        int n=prices.size();
        int prevmini[n];
        prevmini[0]=prices[0];
        for(int i=1;i<n;i++)
        {
            prevmini[i]=min(prevmini[i-1],prices[i]);
        }
        
        int ans=0;
        
        for(int i=1;i<n;i++)
        {
            ans=max(ans,prices[i]-prevmini[i-1]);
        }
        
        return ans;
        
        
        
    }
};