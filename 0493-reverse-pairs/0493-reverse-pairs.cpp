class Solution {
public:
    //global variable.
    int cnt=0;

    void counter(vector<int>&a, int low,int mid,int high)
    {
        // before merging count reverse pairs.
        int j=mid+1;
        for(int i=low;i<=mid;i++)
        {
            while (j <= high && a[i] > 2 * (long long)a[j])
            {
                j++;
            }
            cnt+=j-(mid+1);
        }
    }

    
    void merge(vector<int>&a, int low,int mid, int high)
    {

        

        vector<int>temp;

        int i=low;
         int j=mid+1;
        while(i<=mid and j<=high)
        {
            if(a[i]<=a[j])
            {
             

                temp.push_back(a[i]);
                i++;

            }
            else
            {
                temp.push_back(a[j]);
                j++;
               
            }
        }

        while(i<=mid)
        {
            temp.push_back(a[i]);
            i++;
        }

                while(j<=high)
        {
            temp.push_back(a[j]);
            j++;
        }

        // change
        int k=0;
        for(int i=low;i<=high;i++)
        {
            a[i]=temp[k];
            k++;
        }



    }



    void mergesort(vector<int>&a,int low,int high)
    {
        if(low>=high)  return ;

        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        counter(a,low,mid,high);
        merge(a,low,mid,high);
    
    }   


    int reversePairs(vector<int>& nums) 
    {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return cnt;
    }
};