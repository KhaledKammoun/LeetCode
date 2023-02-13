class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>v ;
        for (int i =left ; i<right+1 ;i++){
            if (i<10 && i!=10)
                v.push_back(i) ;
            else {
                int x = i ,b=1;
                while (x>0 && b==1){
                    int y= x%10 ;
                    if (y==0 || (i%y)!=0){
                        b=0 ;
                        break ;
                        }
                     x/=10 ;    
                }
                if (b==1 && i%10!=0)
                    v.push_back(i) ;
            }
        }
        return v ;
    }
};