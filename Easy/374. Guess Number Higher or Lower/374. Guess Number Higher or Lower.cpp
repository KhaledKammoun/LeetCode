/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    long long guessNumber(long long n) {
        long long s= 1 ,e = n ;
        while (s<=e){
            long long  m = (s+e)/2 ;
            long long  pick = guess(m) ;
            if (pick == 0)
                return m ;
            else if (pick==1)
                s = m+1 ;
            else 
                e = m-1 ;
        }
        return -1 ;
    }
};