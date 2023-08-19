//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int counter(int i, int j, int arr[], vector<vector<int>>&dp)
    {   //base case
        if(i==j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mini=1e9;
        for(int par=i;par<=j-1;par++)
        {
            int steps=counter(i,par,arr,dp)+counter(par+1,j,arr,dp)+arr[i-1]*arr[par]*arr[j];
            mini=min(mini,steps);
        }
        
        return dp[i][j]=mini;
        
        
        
        
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        // lfg..
        vector<vector<int>>dp(N,vector<int>(N,-1));
        
        return counter(1,N-1,arr,dp);
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends