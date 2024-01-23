class Solution {
public:
    int max_length = 0 ;
    bool isNotValid(vector<string>& curr_arr, string arr) {
        for (auto x : arr){
            for (auto c : curr_arr){
                size_t found = c.find(x);

                if (found != std::string::npos) 
                    return false ;
            }
        }
        int tab[26] = {0} ;
        for (auto c : arr)
            tab[c-'a']++ ;
        for (int i = 0;i <26; i++){
            if (tab[i]>1)
                return false ;
        }
        return true ;
    }

    void dfs(vector<string>& arr, vector<string>& curr_arr,int total_length, int index){
        for (int i = index; i <arr.size() ; i++){
            if (isNotValid(curr_arr, arr[i])){
                curr_arr.push_back(arr[i]) ;
                total_length+=arr[i].size() ;
                max_length = max(max_length, total_length) ;
                dfs(arr, curr_arr, total_length, i+1) ;
                total_length-=arr[i].size() ;
                curr_arr.pop_back() ;
            }
        }
        return ;
    }
    int maxLength(vector<string>& arr) {
        vector<string> curr_arr ;
        int total_length = 0 ;
        dfs(arr, curr_arr, total_length, 0) ;
        return max_length ;
    }
};