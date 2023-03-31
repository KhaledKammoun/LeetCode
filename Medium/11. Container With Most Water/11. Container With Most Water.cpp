class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0,i=0,n=height.size() ;
        int j = n-1;
        while (i <j){
            maxArea=max(maxArea,min(height[i],height[j])*(j-i)) ;
            if (height[i]>height[j])
                j--;
            else 
                i++;
        }
        return maxArea;
    }
};