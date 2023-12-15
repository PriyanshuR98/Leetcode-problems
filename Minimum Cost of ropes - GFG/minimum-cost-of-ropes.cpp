//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        
        priority_queue<long long ,vector<long long >,greater<long long >>minh;
        
        for(int i=0;i<n;i++)  minh.push(arr[i]);
        
        long long int cost=0;
        while(minh.size()>1)
        {
            long long int top1=minh.top();
            minh.pop();
            long long int top2=minh.top();
            minh.pop();
            cost+=top1;
            cost+=top2;
            minh.push(top1+top2);
            
            
        }
        
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends