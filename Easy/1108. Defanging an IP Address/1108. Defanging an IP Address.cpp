class Solution {
public:
    string defangIPaddr(string address) {
        string s1 ;
        s1="" ;
        int l=address.length();
        for (int i = 0 ;i<l ;i++){
            if (address[i]!='.')
                s1.append(1,address[i]) ;
            else
                s1.append("[.]") ;
        }
        return s1 ;
    }
};