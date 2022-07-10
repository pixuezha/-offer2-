#include<algorithm>
class Solution {
public:
    int minArray(vector<int>& numbers) {
        //执行时间4ms c++中击败了86.70%   内存消耗11.7mb，c++中击败了90.29%；
       sort(numbers.begin(),numbers.end());
       return numbers[0];

    }

    int minArray(vector<int>& numbers) {
       int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (numbers[pivot] < numbers[high]) {
                high = pivot;
            }
            else if (numbers[pivot] > numbers[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;
            }
        }
        return numbers[low];
    }
};
