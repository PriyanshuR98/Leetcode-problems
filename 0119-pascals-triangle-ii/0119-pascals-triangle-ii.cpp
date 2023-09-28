class Solution {
public:
    
     vector<int >rowcalc(int row)
    {
        vector< int>temp;
        long long int ans=1;
        
          temp.push_back(ans);
        
        
        for(int col=1;col<row;col++)
        {
            ans*=(row-col);
            ans=ans/col;
            
            temp.push_back(ans);
        }
        return temp;
    }
    
    
    vector<int> getRow(int rowIndex) {
        
        return rowcalc(rowIndex+1);    
    }
};