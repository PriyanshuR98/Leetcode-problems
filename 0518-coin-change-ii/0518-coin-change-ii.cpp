class Solution {
public:

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector <vector<int> >dp(n,vector<int>( amount+1,0));
       


       for(int val=0;val<=amount;val++)
       {
           if(val%coins[0]==0)
           {
               dp[0][val]=1;
           }
       }



       for(int index=1;index<n;index++)
       {
           for(int value=0;value<=amount;value++)
           {
                int notpick=dp[index-1][value];
                int pick=0;
                if(value >=coins[index])
                {
                    pick=dp[index][value-coins[index]];
                }

                  dp[index][value]=pick+notpick;
            }
       }

       return dp[n-1][amount];



    }
};