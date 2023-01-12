class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.size() ;
        int i = l-1,ind = 0 ;
        while (i>=0){
            if (s[i]==' '){
                if (ind !=0)
                    break ;
            }
            else {
                ind++;
            }
            i--;
        }
        return ind ;
    }
};