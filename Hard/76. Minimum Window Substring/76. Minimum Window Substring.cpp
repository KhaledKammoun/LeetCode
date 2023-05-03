class Solution {
public:
    string minWindow(string s, string t) {
        int n_s = s.size(), n_t = t.size() ;
        if (n_s<n_t)
            return "" ;
        else {
            
            int tab_s[100]={0}, tab_t[100]={0} ;
            for (int i = 0 ; i<n_t ; i++)
                tab_t[t[i]-'A']++ ;

            string s_min = "",s_var="" ;
            s_var.append(1,s[0]) ;
            
            int i = 0, j = 0, c = 0 ;
            tab_s[s[0]-'A']++ ;
            if (tab_s[s[0]-'A']==tab_t[s[0]-'A']){
                c+=tab_s[s[0]-'A'] ;
            }
            while (i<n_s){
                if (c>=n_t || j==n_s-1){
                    if ((s_min=="" && c>=n_t) || (c>=n_t && s_min.size()>s_var.size())){
                        s_min = s_var ;
                    }
                    if (tab_s[s[i]-'A']==tab_t[s[i]-'A'])
                        c-=tab_s[s[i]-'A'] ;
                    tab_s[s[i]-'A']-- ;
                    s_var.erase(s_var.begin()) ;
                    i++ ;
                }else {
                    j++ ;
                    tab_s[s[j]-'A']++ ;
                    if (tab_s[s[j]-'A']==tab_t[s[j]-'A']){
                        c+=tab_s[s[j]-'A'] ;
                    }
                    s_var.append(1,s[j]) ;
                }
                
            }
            if (n_t==1 && t[0]!=s[0] && n_s==1)
                return "" ;
            return s_min ;
        }
       
        
    }
};