class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
        
        // Step 1: Fix top row (r1) and bottom row (r2)
        for(int r1 = 0; r1 < m; r1++) {
            
            // Step 2: Create columnSums array for compression
            vector<int> columnSums(n, 0);
            
            for(int r2 = r1; r2 < m; r2++) {
                
                // Step 3: Add current row to columnSums (compress rows r1 to r2)
                for(int c = 0; c < n; c++) {
                    columnSums[c] += matrix[r2][c];
                }
                
                // Step 4: Solve 1D problem on columnSums array
                // Find max subarray sum <= k in O(n log n)
                int maxSum = findMaxSumSubarray(columnSums, k);
                ans = max(ans, maxSum);
            }
        }
        
        return ans;
    }
    
private:
    // Find maximum subarray sum <= k in 1D array
    int findMaxSumSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int maxSum = INT_MIN;
        
        // Set to store prefix sums in sorted order
        set<int> prefixSet;
        prefixSet.insert(0);  // For subarray starting from index 0
        
        int prefixSum = 0;
        
        for(int j = 0; j < n; j++) {
            // Calculate prefix sum up to index j
            prefixSum += arr[j];
            
            // We want: prefixSum - prefixSet[i] <= k
            // Rearranging: prefixSet[i] >= prefixSum - k
            // Find smallest prefixSet[i] that satisfies this
            
            auto it = prefixSet.lower_bound(prefixSum - k);
            
            if(it != prefixSet.end()) {
                // Found a valid prefix sum
                int subarraySum = prefixSum - *it;
                maxSum = max(maxSum, subarraySum);
            }
            
            // Add current prefix sum to set for future iterations
            prefixSet.insert(prefixSum);
        }
        
        return maxSum;
    }
};