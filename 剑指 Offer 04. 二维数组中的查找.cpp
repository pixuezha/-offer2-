#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int l = matrix.size();
        int r = matrix[0].size();
        for (int i = r - 1; i >= 0; i--)
        {
            for (int k = 0; k < l; k++)
            {
                if (matrix[k][i] > target)
                {
                    break;
                }
                else if (matrix[k][i] < target)
                {
                    continue;
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}



