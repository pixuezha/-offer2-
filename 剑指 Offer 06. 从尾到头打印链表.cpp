#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

class Solution {
public:
    //次之
    vector<int> reversePrint(ListNode* head) {
        vector<int> tmp;

        while (head)
        {
            tmp.insert(tmp.begin(), head->val);//这里的插入消耗时间，
            head = head->next;                         //因为vector容器的储存地址是连续的，所以插入消耗时间
        }

        return tmp;
    }

    //最佳，因为都是消耗o(n)的空间容量，所以要比插入的方法好
    vector<int> reversePrint(ListNode* head) {
        vector<int> tmp;
        stack<int> nums;
        while (head != nullptr)
        {
            nums.push(head->val);
            head = head->next;
        }

        while (!nums.empty())
        {
            tmp.push_back(nums.top());
            nums.pop();
        }
        return tmp;
    }
};

int main()
{

}
