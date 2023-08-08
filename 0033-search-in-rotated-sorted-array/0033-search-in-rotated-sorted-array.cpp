class Solution {
public:
    int search(vector<int>& nums, int target) {
        
       // striver explanation.. we need to eliminate the sorted half..
       int low=0;
       int high=nums.size()-1;
       while(high-low>1)
       {
           int mid=(low+high)/2;

           if(nums[low]<=nums[mid])  // means sorted left half..
           {
               if(nums[low]<=target  and target <=nums[mid])  // eliminate right half..

               {    
                   high=mid;
               }
               else // left me exist nahi karta..
               {
                   low=mid;
               }
           }

           else if(nums[mid]<=nums[high] )      // a[mid]<=a[high]  // sorted right half..
           {
               if(nums[mid]<=target and target<=nums[high])  // eliminate left half..
               {
                   low=mid;
               }
               else  // right me exist nahi krta.. 
               {
                   high=mid;
               }
           }

       }

       if(nums[high]==target)
       {
           return high;
       }

       if(nums[low]==target)
       {
           return low;
       }
       return -1;
        
    }
};