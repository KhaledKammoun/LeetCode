class Solution {
public:
    bool isAnagram(string s, string t) {
        /*with O(1) Space Complexity
        sort(s.begin(),s.end());
        sort(t.begin(),t.end()) ;
        return s== t;
        */
        int l1 = s.size() , l2 = t.size() ;
            if (l1!=l2)
                return false ;
            int tab[26]={0} ;
            for (int i = 0 ; i<l1 ; i++){
                tab[s[i]-'a']++ ;
                tab[t[i]-'a']-- ;
            }
            for (int i = 0 ; i<26 ; i++){
                if (tab[i]!=0)
                    return false ;
            }
            return true ;
    }
};