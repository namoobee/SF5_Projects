// Project 1
// 배스킨라빈스 31 게임
// 서로 최소 1개에서 최대 3개의 연속된 숫자를 말하고 31이라는 숫자를 말하는 사람이 지는 게임
// 1) 사용자는 본인이 입력한 숫자만큼 입력
// 2) 컴퓨터는 랜덤 숫자로 입력
// 3) 단 사용자, 컴퓨터 모두 1 ~ 3 사이의 개수만 가능

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0))); // 고정된 시드 값(3) 설정
	int Input = 0;
	int Total = 0;

	cout << "배스킨라빈스 31 게임" << endl << endl;

	while (Total < 31)
	{
		cout << "현재 숫자: " << Total << endl;
		cout << "1에서 3 사이의 숫자를 입력하세요 (종료 -> 0): ";
		cin >> Input;

		if (Input == 0)
		{
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
		if (Input < 1 || Input > 3)
		{
			cout << "잘못된 입력입니다. 1에서 3 사이의 숫자를 입력하세요." << endl;
			continue;
		}
		
		cout << "-----사용자가 입력한 숫자!-----" << endl;
		Total += Input;
		for (int i = 0; i < Input; ++i)
		{
			cout << (Total - Input + 1 + i) << endl;
		}
		if (Total >= 31)
		{
			cout << "사용자의 입력으로 숫자가 31을 넘었습니다." << endl << "*** 컴퓨터 승리! ***" << endl;
			break;
		}
		
		// 컴퓨터의 랜덤 입력
		cout << "-----컴퓨터가 입력한 숫자!-----" << endl;
		Input = rand() % 3 + 1;
		
		Total += Input;
		for (int i = 0; i < Input; ++i)
		{
			cout << (Total - Input + 1 + i) << endl;
		}
		if (Total >= 31)
		{
			cout << "컴퓨터의 입력으로 숫자가 31을 넘었습니다." << endl << "*** 사용자 승리! ***" << endl;
			break;
		}
	}
	
	return 0;
}