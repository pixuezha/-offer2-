#include <iostream>
#include<stack>
using namespace std;

/*思路
* 用两个栈模拟一个队列，首先我们要知道栈和队列最明显的区别：
* 栈：先进后出   队列：先进先出
* 那我们用两个栈模拟的时候，我们要将一个栈作为初始的存储栈，先存入信息，另一个栈是用来弹出的
* 模拟过成stack1进栈1，2，3，此时我们要弹出的话想要弹出1，但只有一个栈stack1只能弹出3
* 所以我们用stack2先将stack1里面的信息从顶部到底部存储到stack2中，这样stack2存储的信息就是3，2，1
* 这样用stack2弹出就是队列中的头部
*/
//执行用时：236 ms, 在所有 C++ 提交中击败了93.00 %的用户
//内存消耗：101 MB, 在所有 C++ 提交中击败了84.18 %的用户
class CQueue {
public:
    stack<int> stack1;
    stack<int>stack2;
        CQueue() {

    }

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if (stack1.empty()&& stack2.empty())//只有当两个栈都没有存储的情况下才能返回-1
            return -1;
        if (!stack2.empty())//当队列序列stack2中有元素，只需要存储顶端，再弹出操作即可
        {
            int tmp = stack2.top();
            stack2.pop();
            return tmp;
        }
        else//这里就只有一种情况，stack1有元素，stack2没有元素，所以要进行上面思路的先把stack1的元素转移到stack2中
        {
            int length = stack1.size();//这里要先记录stack1的长度，因为for循环里面要进行pop操作
            for (int i = 0; i < length; i++)
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            int tmp = stack2.top();
            stack2.pop();
            return tmp;
        }
    }
};

//根据下面的解释，我们可以不用在构造函数写东西，我们只需要完成要求的函数方法即可
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{
    
}


