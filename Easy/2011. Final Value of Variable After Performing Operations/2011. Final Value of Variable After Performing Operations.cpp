class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int l = operations.size() ,x = 0;
        for (int i = 0 ;i<l ; i++){
            if(operations[i][0]=='+' || operations[i][2]=='+' )
                x++ ;
            else 
                x-- ;
        }
        return x ;
    }
};