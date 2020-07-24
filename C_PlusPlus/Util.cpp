#include "Util.h"

using namespace std; 
  
int getNumber(const char* str)
{
    int value;
    string checkint;

    cout << str;
    cin >> checkint;
    for (int i = 0; i < (int)checkint.length(); i++)
    {
        if (isdigit(checkint[i]) == false)
        {
            cout << "숫자만 입력해주세요";
            return getNumber(str);
        }
    }
    value = std::stoi(checkint);
    return value;
}