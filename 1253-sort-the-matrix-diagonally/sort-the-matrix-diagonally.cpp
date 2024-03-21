class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> umap;
        
        // Fill the map with diagonals
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                umap[i - j].push(mat[i][j]);
            }
        }
        
        // Update the matrix with sorted values
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = umap[i - j].top();
                umap[i - j].pop();
            }
        }
        
        return mat;
    }
};