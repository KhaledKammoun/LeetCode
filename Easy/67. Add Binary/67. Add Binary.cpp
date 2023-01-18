class Solution {
public:
    string addBinary(string a, string b) {
        string ch = "" ;
        int na = a.size() , nb= b.size() , r = 0;
        string c = "" ;
        c.resize(max(na,nb)-min(na,nb),'0') ;
        if (na > nb) {
            b = c + b ;
        }else if (nb > na) {
            a = c + a ;
        }
        int m = max(na,nb) ;
        na=nb=m;
        for (int i = 0 ; i<na;  i++){
            int s = a[na-i-1] + b[nb-i-1] + r - 48*2 ;
            if (s==0){
                ch = '0' + ch ;
                r = 0 ;
            }
            else if (s==1){
                ch = '1' + ch ;
                r = 0 ;
            }
            else if (s==2){
                ch = '0' + ch ;
                r = 1;
            }
            else if (s==3){
                ch = '1' + ch ;
                r = 1 ;
            }
        }
        if (r==1)
            ch = '1' + ch ;
        return ch ;
    }
};