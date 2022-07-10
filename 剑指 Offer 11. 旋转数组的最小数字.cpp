#include<algorithm>
class Solution {
public:
    int minArray(vector<int>& numbers) {
        //ִ��ʱ��4ms c++�л�����86.70%   �ڴ�����11.7mb��c++�л�����90.29%��
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
