class Solution {
public:
    double myPow(double x, int n) {
        
        //binary expo
        long double res=1.0;
        long double a=x;
        long long int b=n;
        bool changed=false;
        if(b<0)
        {
            b=-b;
            changed=true;
        }

        while(b>0)
        {
            if(b&1==1) // odd
            {
                res=res*a;
            }
            a*=a;
            b>>=1;
        }

        if(changed)
        {
            res=1/res;
        }

        return res;

        
    }
};