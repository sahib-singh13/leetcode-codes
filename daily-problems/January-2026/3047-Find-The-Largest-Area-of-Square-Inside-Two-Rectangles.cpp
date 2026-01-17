class Solution {
private:
    long long FindMaxArea(vector<int>&bottom1, vector<int>&top1, vector<int>&bottom2, vector<int>&top2) {
        long long width=min<long long>(top1[0],top2[0])-max<long long>(bottom1[0],bottom2[0]);
        long long height=min<long long>(top1[1],top2[1])-max<long long>(bottom1[1],bottom2[1]);

        if(width<0 || height<0) return 0LL;

        long long length=min<long long>(width,height);
        return 1LL*length*length;
    }

public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        
        long long largestArea=0LL;

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
               largestArea=max<long long>(largestArea,FindMaxArea(bottomLeft[i],topRight[i],bottomLeft[j],topRight[j]));
            }
            
        }

        return largestArea;
    }
};
