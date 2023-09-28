class Solution {
public:
    vector<int>rowcalc(int row)
    {
        vector<int>temp;
        int ans=1;
        
          temp.push_back(ans);
        
        
        for(int col=1;col<row;col++)
        {
            ans*=(row-col);
            ans=ans/col;
            
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) 
    {
     //striver approach
        // formula r-1 C c-1 for element in rth row and cth col.
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++)
        {
            ans.push_back(rowcalc(i));
        }
        
        return ans;
        
    }
};