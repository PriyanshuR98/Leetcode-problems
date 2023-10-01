class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //first find transpose 
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }

        }

        // swap col now.. ie reverse transposed martix column wise
        for(int j=0;j<n/2;j++)
        {
            for(int i=0;i<n;i++ )
            {
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }

        
    }
};