#include "Util.h"

int getNumber(const char *str)
{
    int num;

    cout << str;
    cin >> num;
    // �߸��� �Է��� �޾��� ���
    if (!cin)
    {
        cout << "���ڸ� �Է����ּ���" << endl; // ���� �޽��� ���
        cin.clear(); // ������Ʈ���� �ʱ�ȭ
        cin.ignore(INT_MAX, '\n'); // �Է¹��۸� ���
        num = 0;
        getNumber(str); // �Լ��� ��ȣ���Ѵ�
    }
    else
    {
        cout << cin.fail() << num;
         return (num);
    }
}