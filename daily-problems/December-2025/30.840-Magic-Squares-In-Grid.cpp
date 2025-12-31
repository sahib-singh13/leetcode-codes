class Solution {

private:
    
    bool CheckAllInRange(vector<vector<int>>&grid,int x, int y) {
       vector<int>Count(10,0);
       
       for(int i=x;i<x+3;i++) {
         for(int j=y;j<y+3;j++) {
            if(grid[i][j]==0 || grid[i][j]>9) return false;
            if(Count[grid[i][j]]==1) return false;
            Count[grid[i][j]]=1;
         }
       }

       return true;
    }

    bool AllSumsEqual(vector<vector<int>>&grid, int x, int y) {
        int row_sum1=0,row_sum2=0,row_sum3=0;

        for(int j=y;j<y+3;j++) {
            row_sum1+=grid[x][j]; row_sum2+=grid[x+1][j]; row_sum3+=grid[x+2][j];
        }

        if(row_sum1!=row_sum2 || row_sum2!=row_sum3) return false;

        int col_sum1=0,col_sum2=0,col_sum3=0;

        for(int i=x;i<x+3;i++) {
            col_sum1+=grid[i][y]; col_sum2+=grid[i][y+1]; col_sum3+=grid[i][y+2];
        }

        if(col_sum1!=col_sum2 || col_sum2!=col_sum3) return false;

        int diag1_sum=0,diag2_sum=0;

        diag1_sum=grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2];
        diag2_sum=grid[x][y+2]+grid[x+1][y+1]+grid[x+2][y];

        if(diag1_sum!=diag2_sum) return false;

        return true; 
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),count=0;

        for(int i=0;n-i>=3;i++) {
            for(int j=0;m-j>=3;j++) {
              if(!CheckAllInRange(grid,i,j)) continue;
              if(!AllSumsEqual(grid,i,j)) continue;
              count++;
            }
        }

        return count;
    }
};

//time complexity of this code-O(n*m*9) // can it optimised?
