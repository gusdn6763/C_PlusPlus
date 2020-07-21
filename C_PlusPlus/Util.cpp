#include "Util.h"

int getNumber(const char *str)
{
    int num;

    cout << str;
    cin >> num;
    // 잘못된 입력을 받았을 경우
    if (!cin)
    {
        cout << "숫자만 입력해주세요" << endl; // 에러 메시지 출력
        cin.clear(); // 오류스트림을 초기화
        cin.ignore(INT_MAX, '\n'); // 입력버퍼를 비움
        num = 0;
        getNumber(str); // 함수를 재호출한다
    }
    else
    {
        cout << cin.fail() << num;
         return (num);
    }
}