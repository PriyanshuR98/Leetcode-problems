class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        //tc is o(2n)
        int n=s.length();
        set<char>pres;
        int l=0;
        int maxlen=0;
        for(int r=0;r<n;r++)
        {
            if(pres.find(s[r])==pres.end())  // not found
            {
                // add
                pres.insert(s[r]);
                maxlen=max(maxlen,r-l+1);

                
            }
            else  // already exists
            {
                while(pres.find(s[r])!=pres.end())
                {
                    pres.erase(s[l]);
                    l++;
                }
                
                pres.insert(s[r]);
                maxlen=max(maxlen,r-l+1);
            }
        }

        return maxlen;

    }
};