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
    //��֮
    vector<int> reversePrint(ListNode* head) {
        vector<int> tmp;

        while (head)
        {
            tmp.insert(tmp.begin(), head->val);//����Ĳ�������ʱ�䣬
            head = head->next;                         //��Ϊvector�����Ĵ����ַ�������ģ����Բ�������ʱ��
        }

        return tmp;
    }

    //��ѣ���Ϊ��������o(n)�Ŀռ�����������Ҫ�Ȳ���ķ�����
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
