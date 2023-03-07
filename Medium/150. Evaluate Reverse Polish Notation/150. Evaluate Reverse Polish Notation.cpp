class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s ;
        for (int i = 0 ; i<tokens.size() ; i++){
            if (tokens[i]!="*" && tokens[i]!="/" && tokens[i]!="-" && tokens[i]!="+")
                s.push(stoi(tokens[i])) ;
            else {
                int som = s.top() ;
                s.pop() ;
                if (tokens[i]=="*")
                    som = s.top() * som;
                else if (tokens[i]=="/")
                    som = s.top() / som;
                else if (tokens[i]=="+")
                    som = s.top() + som;
                else 
                    som = s.top() - som;
                s.pop() ;
                s.push(som) ;
            }
        }
        return s.top() ;
    }
};