//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int mod=1003;
class Solution{
public:

    int counter(int i, int j ,string s, bool isTrue, vector<vector<vector<int>>>&dp)
    
    {
        if(i>j)
        {
            return 0;
            
        }
        
        if(i==j)
        {
            if(isTrue)
            {
                return (s[i]=='T');
            }
            else
            {
                return (s[i]=='F');
            }
        }
        
        if(dp[i][j][isTrue]!=-1)
        {
            return dp[i][j][isTrue];
        }
        
        int ways=0;
        
        for(int ind=i+1;ind<=j-1;ind+=2)
        {
           int lf=counter(i,ind-1,s,0,dp);
           int lt=counter(i,ind-1,s,1,dp);
           int rf=counter(ind+1,j,s,0,dp);
           int rt=counter(ind+1,j,s,1,dp);
           
           if(s[ind]=='&')
           {
               if(isTrue)
               {
                   ways+=((lt*rt)%mod)%mod;
               }
               else
               {
                   ways+=((lt*rf+lf*rt+lf*rf)%mod)%mod;
               }
           }
           
           else if(s[ind]=='|')
           {
              if(isTrue)
               {
                   ways+=((lt*rt+lf*rt+lt*rf)%mod)%mod;
               }
               else
               {
                   ways+=((lf*rf)%mod)%mod;
               }
           }
           else  // xor
           {
                if(isTrue)
               {
                   ways+=((lf*rt+lt*rf)%mod)%mod;
               }
               else
               {
                   ways+=((lt*rt+lf*rf)%mod);
               }
           }
        }
        
        return dp[i][j][isTrue]= ways%mod;
        
    }
    
    
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(N+1,vector<int>(2,-1)));
        return counter(0,S.length()-1,S,1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends