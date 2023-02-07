class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        /*method 1
            return false ;
            //because : n can never be a strict palindrome in base n - 2
        */
        //method 2
        for (int base = 2 ; base<n-1 ; base++){
            int x = n ;
            string s = "" ;
            while (x!=0){
                s.append(1,(char)x%base-(char)'0') ;
                x/=base ;
            }
            for (int i = 0 ; i<s.size()/2+1 ; i++){
                if (s[i]!=s[s.size()-1-i])
                    return false ;
            }
        }
        return true ;
    }
};