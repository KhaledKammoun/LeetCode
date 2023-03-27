class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
       stack<pair<int,int>> s ;
       int m=0, l = v.size(),k=0;
       for (int i = 0  ;i<l ; i++){
           bool b = 1 ;
           while (!s.empty() && v[i]<s.top().first){
               m=max(m,(i-s.top().second)*s.top().first) ;
               k=s.top().second;
               s.pop() ;
               b=0 ;
           }
            if (b)
                s.push(make_pair(v[i],i)) ;
            else 
                s.push(make_pair(v[i],k)) ;
       } 
       while (!s.empty()){
           m=max(m,(l-s.top().second)*s.top().first) ;
           s.pop() ;
       }
       return m ;
    }
};