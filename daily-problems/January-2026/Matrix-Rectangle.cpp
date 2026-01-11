class Solution {
private:

   void convertToHistogram(vector<vector<char>>&matrix, vector<vector<int>>&heights, int n, int m) {
      
      //convert depending upon the value in the matrix cell just above the current cell 
      for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
           if(i-1<0) heights[i][j]=(matrix[i][j]=='0')?0:1;
           else heights[i][j]=(matrix[i][j]=='0')?0:heights[i-1][j]+1;
        }
      }
   }
   
   //the function finds out the area by taking the current height and how much is it able to span on left and right side.
   int PerformOperations(vector<vector<int>>&heights, int index, int row, int col,stack<int>&indexes) {
       int height=heights[row][index];
       int width=(indexes.empty())?col:col-indexes.top()-1;
       int area=height*width;
       return area;
   }
   
   //the function traverses through the matrix to find the max area covered by height at each of the cell.
   int findMaxRectangle(vector<vector<int>>&heights, int n, int m) {
      
        int maxRectangle=0;
        
        for(int i=0;i<n;i++) {    

          //monotonic increasing stack
          stack<int>indexes;
          
          for(int j=0;j<m;j++) {
             int current=heights[i][j];
             
             //pop from the stack until the stack is not empty or the value at index of the top of stack is lesser than the current 
             //so that would become the rightmost boundary..
             while(!indexes.empty() && current<heights[i][indexes.top()] ){
                
                int index=indexes.top(); indexes.pop();
                int area=PerformOperations(heights,index,i,j,indexes);
                maxRectangle=max(maxRectangle,area);
             }

             indexes.push(j);
          }
          
          //check at the end for the cell values left in the stack. 
          while(!indexes.empty()) {
             
             int index=indexes.top(); indexes.pop();
             int area=PerformOperations(heights,index,i,m,indexes);
             maxRectangle=max(maxRectangle,area);
          }
        }

        return maxRectangle;
   }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n=matrix.size(),m=matrix[0].size();

        //create a new vector for storing the histogram
        vector<vector<int>>heights(n,vector<int>(m,0));
  
        convertToHistogram(matrix,heights,n,m);

        return findMaxRectangle(heights,n,m);
    }
};

//time complexity- O(n*m)
//space complexity-O(n*m)
