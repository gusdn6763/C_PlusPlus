#include "0강 선택.h"

int main()
{
	int part, chapter, chapter_num;

	cout << "1.C++로의 전환" << endl;
	cout << "2.객체지향의 도입" << endl;
	cout << endl << "파트 선택 : ";
	cin >> part;
	system("cls");
	if (part == 1)
	{
		cout << "챕터1 : C 언어 기반의 C++" << endl;
		cout << "챕터2 : C 언어 기반의 C++" << endl;
		cout << endl << "챕터 선택 : ";
		cin >> chapter;
		system("cls");
		if (chapter == 1)
		{
			system("cls");
			cout << "1. printf와 scanf를 대신하는 입출력 방식" << endl;
			cout << "2. 함수 오버로딩" << endl;
			cout << "3. 매개변수 디폴드 값" << endl;
			cout << "4. 인라인 함수" << endl;
			cout << "5. 이름공간과 using" << endl;
			cout << endl << "챕터 내용선택";
			cin >> chapter_num;
			if (chapter_num == 1)
				main111();
			else if (chapter_num == 2)
				main112();
			else if (chapter_num == 3)
				main113();
			else if (chapter_num == 4)
				main114();
			else if (chapter_num == 5)
				main115();
			else if (chapter_num == 6)
			{
				main116();
			}
				
		}
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
