class Solution {
public:
    string toHex(int num) {
        int b = 0 ;
        if (num<0)
            b = 1 ;
        else if (num==0)
            return "0" ;
        string s ;
        int n =  sizeof(num)*8 - __builtin_clz(num)  , c = 0 , sum = 0;
        for (int i = 0 ; i<n ; i++){
            if (num&1)
                sum+=(1<<c) ;
            if (c==3){
                if (sum<10)
                    s.append(1,(char)(sum+48)) ;
                else
                    s.append(1,(char)(sum+87)) ;
                c=0 ;
                sum=0 ;
            }
            else
                c++ ;
            num = num>>1 ;
        }

        if (c<4 && c>0)
            if (sum<10)
                s.append(1,(char)(sum+48)) ;
             else
                s.append(1,(char)(sum+87)) ;
        if (b==1){
            for (int i = s.size() ; i<8 ; i++)
                s.append(1,'f') ;
        }
        reverse(s.begin(), s.end()); 
        
        return s ;
    }
};