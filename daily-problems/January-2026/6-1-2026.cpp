class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        //base condition first
        if(!root) return 0;
        
        //queue to insert the nodes at any level
        queue<TreeNode*>nodes;
        nodes.push(root);
      
        int MaxSum=INT_MIN,MaxLevel=0,LevelCount=0;

        while(!nodes.empty()) {

           int Size=nodes.size(),Sum=0;
            LevelCount++;

            //find the sum formed by all the nodes at the same level and push next
            //level nodes in the queue       
            for(int i=0;i<Size;i++) {
                  TreeNode* current=nodes.front();
                  nodes.pop();

                  Sum+=current->val;

                  if(current->left) nodes.push(current->left);
                  if(current->right) nodes.push(current->right);

            }
            
            //compare the sum at the current level with the MaxSum
            //update if turns out to be the greatest sum
            if(Sum>MaxSum) {
                MaxSum=Sum;
                MaxLevel=LevelCount;
            }
        }
        
        //finally return the level number with the MaxSum
        return MaxLevel;
    }
};
