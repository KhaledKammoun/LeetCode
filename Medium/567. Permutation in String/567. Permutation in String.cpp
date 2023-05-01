class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(),n2 = s2.size(), c = 0, i= 0,j=0 ;
        int tab_1[26]={0},tab_2[26]={0} ;
        for (int k=0 ; k<n1 ; k++){
            tab_1[s1[k]-'a']++ ;
        }

        while (j<n2){
            if (j<n1){
                tab_2[s2[j]-'a']++ ;
                if (tab_1[s2[j]-'a']==tab_2[s2[j]-'a'])
                    c+=tab_2[s2[j]-'a'] ;
                j++ ;
                if (c==n1)
                    return true ;
            }
            else {
                tab_2[s2[j]-'a']++ ;
                if (tab_1[s2[j]-'a']==tab_2[s2[j]-'a'])
                    c+=tab_2[s2[j]-'a'] ;
                j++ ;
                if (tab_1[s2[i]-'a']==tab_2[s2[i]-'a'])
                    c-=tab_2[s2[i]-'a'] ;
                tab_2[s2[i]-'a']-- ;
                i++ ;
                if (c==n1)
                    return true ;
            }
            
        }
        return c==n1 ;
    }
};