class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int MOD = 1e9 + 7;

        int n = arr.size();

        long long int ans = 0;

        for(int i = 0; i < n; i++) {

            int s = i+1;
            int e = n-1;

            while(s < e) {
                int sum = arr[i] + arr[s] + arr[e];

                if(sum == target) {
                    
                    if(arr[s] == arr[e]) {
                        int len = e - s + 1;
                        int cnt = (len*(len-1))/2;
                        ans += (cnt % MOD);
                        break;
                    }
                    else {
                        int cntL = 1;

                        while(s < e && arr[s] == arr[s+1]) {
                            s++;
                            cntL++;
                        }

                        int cntR = 1;

                        while(s < e && arr[e] == arr[e-1]) {
                            e--;
                            cntR++;
                        }

                        ans += (cntL * cntR) % MOD;
                        s++;
                        e--;

                    } 

                } else if(sum > target) e--;
                else s++;

            }
        }

        return (int)(ans % MOD);
    }
};