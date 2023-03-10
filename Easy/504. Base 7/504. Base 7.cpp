class Solution {
public:
    string convertToBase7(int num) {
        if (num==0)
            return "0" ;
        bool b =0 ;
        string s = "" ;
        if (num<0){
            b=1 ;
            num*=-1 ;
        }
        while (num!=0){
            s.insert(0,to_string(num%7)) ;
            num/=7 ;
        }
        if (b)
            s.insert(0,"-") ;
        return s ;
    }
};