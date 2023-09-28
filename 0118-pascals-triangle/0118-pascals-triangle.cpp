class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
          vector<vector<int>>finalx;
        vector<int>temp;
        temp.push_back(1);
        finalx.push_back(temp);
        if(numRows==1)
        {
            return finalx;
        }
        temp.push_back(1);
        finalx.push_back(temp);
        if(numRows==2)
        {
            return finalx;
        }
        
        
        for(int i=2;i<numRows;i++)
        {
            vector<int>temp;
            temp.push_back(1);
            vector<int>upper=finalx[i-1];
            for(int j=0;j<=upper.size()-2;j++)
            {
                temp.push_back(upper[j]+upper[j+1]);
            }
            
            temp.push_back(1);
            finalx.push_back(temp);    
  
        }
        return finalx;
    }
};