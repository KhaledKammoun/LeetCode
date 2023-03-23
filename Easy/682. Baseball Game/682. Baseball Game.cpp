class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s ;
        int som = 0 ;
        for (int i = 0 ; i<ops.size() ; i++){
            if (ops[i]=="C")
                s.pop() ;
            else if (ops[i]=="D")
                s.push(s.top()*2) ;
            else if (ops[i]=="+"){
                int x = s.top() ;
                s.pop() ;
                int x1 = x+s.top() ;
                s.push(x) ;
                s.push(x1) ;
            }
            else 
                s.push(stoi(ops[i])) ;
        }
        while (!s.empty()){
            som+=s.top() ;
            s.pop() ;
        }
        return som ;
    }
};