#include <iostream>
#include<stack>
using namespace std;

/*˼·
* ������ջģ��һ�����У���������Ҫ֪��ջ�Ͷ��������Ե�����
* ջ���Ƚ����   ���У��Ƚ��ȳ�
* ������������ջģ���ʱ������Ҫ��һ��ջ��Ϊ��ʼ�Ĵ洢ջ���ȴ�����Ϣ����һ��ջ������������
* ģ�����stack1��ջ1��2��3����ʱ����Ҫ�����Ļ���Ҫ����1����ֻ��һ��ջstack1ֻ�ܵ���3
* ����������stack2�Ƚ�stack1�������Ϣ�Ӷ������ײ��洢��stack2�У�����stack2�洢����Ϣ����3��2��1
* ������stack2�������Ƕ����е�ͷ��
*/
//ִ����ʱ��236 ms, ������ C++ �ύ�л�����93.00 %���û�
//�ڴ����ģ�101 MB, ������ C++ �ύ�л�����84.18 %���û�
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
        if (stack1.empty()&& stack2.empty())//ֻ�е�����ջ��û�д洢������²��ܷ���-1
            return -1;
        if (!stack2.empty())//����������stack2����Ԫ�أ�ֻ��Ҫ�洢���ˣ��ٵ�����������
        {
            int tmp = stack2.top();
            stack2.pop();
            return tmp;
        }
        else//�����ֻ��һ�������stack1��Ԫ�أ�stack2û��Ԫ�أ�����Ҫ��������˼·���Ȱ�stack1��Ԫ��ת�Ƶ�stack2��
        {
            int length = stack1.size();//����Ҫ�ȼ�¼stack1�ĳ��ȣ���Ϊforѭ������Ҫ����pop����
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

//��������Ľ��ͣ����ǿ��Բ����ڹ��캯��д����������ֻ��Ҫ���Ҫ��ĺ�����������
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{
    
}


