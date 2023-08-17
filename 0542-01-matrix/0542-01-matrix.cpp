class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {



        int n=mat.size();
	    int m=mat[0].size();
	    
	    vector< vector<int> >visited(n, vector<int>(m,0) );
	   queue< pair< pair<int,int>, int>  >q;
	   
	    vector< vector<int> > ans(n, vector<int>(m,0) );
	   // x,y,distance
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(mat[i][j]==0)
	            {
	                q.push({{i,j},0});
	                visited[i][j]=1;
	                ans[i][j]=0;
	            }
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int x=q.front().first.first;
	        int y=q.front().first.second;
	        int distance=q.front().second;
	        q.pop();
	        
	        vector< pair<int,int> > changes={{1,0},{-1,0},{0,1},{0,-1}};
	        
	        for(auto del:changes)
	        {
	            int newx=x+del.first;
	            int newy=y+del.second;
	            
	            if(newx>=0 and newx<n and newy>=0 and newy<m and !visited[newx][newy] and mat[newx][newy]==1)
	            {
	                q.push({{newx,newy},distance+1});
	                visited[newx][newy]=1;
	                ans [newx][newy]=distance+1;
	                
	            }
	        }
	        
	        
	    }
	    return ans;


        
    }
};