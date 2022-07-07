#include <iostream>
#include<vector>
using namespace std;

class Function {
public:
    int chongfu(vector<int>& nums)
    {
        
		int a[100000] = { 0 };
		for (int i = 0; i < nums.size(); i++)
		{
			if (a[nums[i]] == 0)
			{
				a[nums[i]] = 1;
			}
			else
			{
				return nums[i];
			}
		}
		return -1;
    }
};


int main()
{
	vector<int> nums = { 3, 4, 2, 0, 0, 1 };
	Function f;
	int num=f.chongfu(nums);
	cout << num;
}



