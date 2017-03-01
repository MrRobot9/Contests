#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int find(vector<int>& nums){
    int n = nums.size();
        // Keeps track of all the intervals that after right-shifting index.
        vector<int> shifts(n,0);
        for(int i=0; i < n; i++) {
            // If the current number is negative or larger than the biggest index, it won't affect the final result.
            if(nums[i] >= n || nums[i] <= 0) continue;

            if(nums[i] > i) {
                // Right shift index i + 1 --> the current index would be n-1 after shifting
                shifts[i + 1] += 1;
                if(nums[i] > i + 1) shifts[i + 1 + n - nums[i]] -= 1;
            } else {
                // There would be two intervals for each nums[i] <= i. 
                shifts[0] += 1;
                shifts[i - nums[i] + 1] -= 1;

                if(i != n - 1) shifts[i + 1] += 1;
            }
        }

        int sum = 0, max = 0, index = 0;
        for(int i=0; i < shifts.size(); i++) {
            sum += shifts[i];
            if(sum > max) {
                max = sum;
                index = i;
            }
        }

        return index;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> table(n);
    for (int i=0; i<n; i++) {
        cin >> table[i];
    }
    int index = find(table);
    
    cout << index+1 << endl;
    return 0;
}