class Solution {
public:
    bool search(vector<int>& nums, int target) {


        
       // striver explanation.. we need to eliminate the sorted half..

       // if a[mid]==a[low] and a[mid]==a[high]
       // stink it as we dont know how to compare as both conditions are true..
       int low=0;
       int high=nums.size()-1;
       while(high-low>1)
       {
           int mid=(low+high)/2;

           if(nums[low]==nums[mid] and nums[mid]==nums[high])
           {    
               low=low+1;
               high=high-1;
               continue;

           } 

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
           return 1;
       }

       if(nums[low]==target)
       {
           return 1;
       }
       return  0;
        
   
    }
};