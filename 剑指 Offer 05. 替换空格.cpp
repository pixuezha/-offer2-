#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int l = s.size();
        string tmp = "";
        for (int i = 0; i < l; i++)
        {
            if (s[i] != ' ')
            {
                tmp += s[i];
            }
            else
            {
                tmp += "%20";
            }
        }
        return tmp;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

