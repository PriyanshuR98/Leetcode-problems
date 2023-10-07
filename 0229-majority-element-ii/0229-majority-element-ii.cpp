class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
     {

         int n=nums.size();
         //moores voting algo
         // [n/k] atmost k-1 possible soln so for k=3 ,2possible soln atmost..
         int cnt1=0;
         int cnt2=0;
         long long int val1=-1e10;
         long long int val2=-1e10;

         for(int i=0;i<n;i++)
         {
             if(cnt1==0 and val2!=nums[i])
             {
                 cnt1++;
                 val1=nums[i];
             }
             else if(cnt2==0 and val1!=nums[i])
             {
                 cnt2++;
                 val2=nums[i];
             }
             else if(nums[i]==val1)
             {
                 cnt1++;
             }
             else if(nums[i]==val2)
             {
                 cnt2++;
             }
             else
             {
                 cnt1--;
                 cnt2--;
             }
         }
         vector<int>ans;
         cnt1=0;
         cnt2=0;

         for(int i=0;i<n;i++)
         {
             if(nums[i]==val1)
             {
                 cnt1++;
             }
         }
         if(cnt1>n/3) ans.push_back(val1);

        cnt2=0;
         for(int i=0;i<n;i++)
         {
             if(nums[i]==val2)
             {
                 cnt2++;
             }
         }
         if(cnt2>n/3) ans.push_back(val2);

         return ans;

       
    }
};