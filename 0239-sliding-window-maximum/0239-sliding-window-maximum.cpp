class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // we are storing max element for every segment of length k at top of deque
        // everytime we push at back and compare from back as element at ith index > last element of dq , then we pop that last element 
        // as that element can never be the max for any window..


        deque<int>dq;
        vector<int>ans;

        //1st window
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() and nums[dq.back()] <nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        for(int i=k;i<nums.size();i++)
        {
            if(dq.front()<=i-k) // removing out of range max element
            {
                dq.pop_front();
            }

              while(!dq.empty() and nums[dq.back()] <nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);

            ans.push_back(nums[dq.front()]);


        }
        return ans;

        
    }
};