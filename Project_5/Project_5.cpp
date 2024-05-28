// Project 5
// 야구 게임
// 사용자는 1부터 9까지 중 3개의 숫자를 뽑아 컴퓨터가 랜덤으로 뽑은 숫자 3개와 비교 (중복x)
// 1) 숫자의 자리와 값이 모두 같으면 strike
// 2) 자리는 다르지만 3개의 숫자 중 포함 되어 있으면 ball

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

//
// 함수선언
//
int GetNum(int min, int max);
vector<int> GetUserInput();
vector<int> Com_RanNum();
void Count_SnB(const vector<int>& ComputerNum, const vector<int>& UserNum, int& strikes, int& balls);

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	int strikes = 0;
	int balls = 0;
	int count = 0;
	int hint = 0;

	cout << "야구 게임을 시작합니다!" << endl;
	while (true)
	{
		vector<int> Com_Number = Com_RanNum(); // 컴퓨터의 랜덤 숫자를 생성
		
			if (count > 2)
			{
				for (int i = 2; i >= 0; i--)
				{
					cout << "--------------------------------------------------------------------------" << endl;
					cout << "맞추고 싶은 간절함에 기회가 찾아왔습니다!" << endl;
					cout << "첫번째 숫자: " << Com_Number[0] << endl << "두번째 숫자: " << Com_Number[1] << endl;
					cout << "아쉽게도 세번째 숫자는 보이지 않습니다..." << endl;
					cout << i + 1 << "번 안에 맞추지 못하면 큰일이 일어날 것같습니다." << endl;
					cout << "--------------------------------------------------------------------------" << endl;


					vector<int> User_Number = GetUserInput(); // 사용자의 숫자를 입력받기
					Count_SnB(Com_Number, User_Number, strikes, balls); // strike, ball 계산하기
					++count;

					cout << "생성된 숫자: ";
					for (int num : Com_Number)
					{
						cout << num << " ";
					}
					cout << endl;

					if (strikes == 3)
					{
						cout << count << "번 만에 맞췄습니다!" << endl;
						return 0;
					}
				}
					cout << "결국 맞추지 못했습니다." << endl;
					cout << "야구팀에서 퇴출 되었습니다....." << endl;
					return 0;
			
			}
	

		vector<int> User_Number = GetUserInput(); // 사용자의 숫자를 입력받기
		Count_SnB(Com_Number, User_Number, strikes, balls); // strike, ball 계산하기


		cout << "Strike: " << strikes << "     " << "Ball: " << balls << endl;
		++count;
	
		cout << "생성된 숫자: ";
		for (int num : Com_Number)
		{
			cout << num << " ";
		}
		cout << endl;

		if (strikes == 3)
		{
			cout << count << "번 만에 맞췄습니다!" << endl;
			break;
		}
	}
	return 0;
}

//
// 사용자로부터 1 ~ 9사이의 숫자 중 중복되지않은 3개의 숫자를 입력받는 함수 
//
vector<int> GetUserInput()
{
	vector<int> User_Input;
	int User_Num;
	

	cout << "1 ~ 9까지의 숫자 중 중복되지 않는 3개의 숫자를 입력해 주세요.(0 -> 종료)" << endl;
	
	for (int i = 0; i < 3; i++)
	{
		while (true)
		{
			cout << i + 1 << "번째 숫자: ";
			cin >> User_Num;
			if (User_Num == 0)
			{
				cout << "게임을 종료합니다." << endl;
				exit(0);
			}
			else if (User_Num < 0 || User_Num > 9)
			{
				cout << "숫자는 1부터 9 사이로 입력해 주세요." << endl;
			}
			else if (find(User_Input.begin(), User_Input.end(), User_Num) != User_Input.end())
			{
				cout << "이미 입력된 숫자입니다. 다른 숫자를 입력해 주세요." << endl;
			}
			else
			{
				User_Input.push_back(User_Num);
				break;
			}
		}
	}
	return User_Input;
}
//
// 최소값과 최대값 사이의 랜덤숫자를 생성하는 함수 
// 
int GetNum(int min, int max)
{
	return min + rand() % ((max + 1) - min);
}

//
// 랜덤숫자가 조건을 만족하는지 확인하는 함수
//
vector<int> Com_RanNum()
{
	vector<int> Number;
	while (Number.size() < 3)
	{
		int num = GetNum(1, 9);
		if (find(Number.begin(), Number.end(), num) == Number.end())
		{
			Number.push_back(num);
		}
	}
	return Number;
}

//
// 컴퓨터의 숫자와 사용자의 숫자를 비교하여 스트라이크와 볼의 개수를 계산하는 함수
//
void Count_SnB(const vector<int>& ComputerNum, const vector<int>& UserNum, int& strikes, int& balls)
{
	strikes = 0;
	balls = 0;

	for (int i = 0; i < 3; ++i)
	{
		if (UserNum[i] == ComputerNum[i])
		{
			strikes++;
		}
		else if (find(ComputerNum.begin(), ComputerNum.end(), UserNum[i]) != ComputerNum.end())
		{
			balls++;
		}
	}
}