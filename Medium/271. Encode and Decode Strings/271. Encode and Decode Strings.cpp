class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string str ="" ;
        str.append(to_string(strs[0].size())) ;
        str.append(1,'#') ;
        str.append(strs[0]) ;
        if (strs.size()>1){
            for (int i =1; i<strs.size() ; i++){
                str.append(to_string(strs[i].size())) ;
                str.append(1,'#') ;
                str.append(strs[i]) ;

            }
        }
        return str
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string>v ;
        int l = 0 ;
        for (int i = 0 ; i<str.size() ; i++){
            if ('0'<=str[i] && str[i]<='9'){
                l= l*10 + (str[i]-'0') ;
                if ('a'<=str[i+1] && str[i+1]<='z')
                    l=0;
            }
            if (str[i]=='#' && '0'<=str[i-1] &&str[i-1]<='9'){
                v.push_back(str.substr(i+1,l)) ;
                l=0 ;
            }
        }
        return v ;
    }
};