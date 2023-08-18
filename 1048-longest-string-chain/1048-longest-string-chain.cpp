bool comp(string s1, string s2)
{
    return s1.length()<s2.length();
}


 bool compare(string s1, string s2)
    {
       //s1 bada wla hai
       int i=0;
       int j=0;
     int cnt=0;
    //    int extra=0;
       while(i<s1.size())
       {
           if(j<s2.size() and s1[i]==s2[j])
           {
               i++;
               j++;
           }
           else
           {
               i++;
               cnt++;
               
           }
       }
     
     if(cnt==1 and j==s2.length())
     {
         return 1;
     }
     return 0;

      
        
        
    }




class Solution {
public:
    
   
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),comp);
        
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        
        for(int ind=0;ind<n;ind++)
        {
            for(int prev=0;prev<ind;prev++)
            {
                if(compare(words[ind],words[prev])  and 1+dp[prev]>dp[ind])
                {
                    dp[ind]=1+dp[prev];
                }

            }
            maxi=max(maxi,dp[ind]);
        }
                             
        
    return maxi;
        
            
        
        
        
    }
};