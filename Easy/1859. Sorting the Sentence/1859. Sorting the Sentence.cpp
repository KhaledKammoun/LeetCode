class Solution {
public:
    string sortSentence(string s) {
        int ind = 0 ,l = s.length() ;
        vector <char> v ;
        for (int i=0;i<l;i++)
            v.push_back(s[i]) ;
        string t[9]={"None"} ;
        int j = 0,m=0 ;
        for(int i = 0 ;i< l ;i++){
            j=((int)v[i])-48 ;
            if (j>0 && j<10){
                t[j-1]={v.begin()+ind,v.begin()+i} ;
                ind = i+2 ;
                if (j>m)
                    m=j ;
            }
        }
        string str="" ;
        j=0 ;
        for (int i = 0 ;i< m ;i++){
            str+=(t[i]) ;
            if (i<(m-1))
                str+=(" ") ;
        }
        return str ;
    }
}; 