// Project 3
// 랜덤 숫자 맞추기
// 1) 컴퓨터가 1 ~ 25까지의 수중 랜덤으로 6개의 수 지정 (중복x)
// 2) 사용자도 1 ~ 25까지의 수 중 원하는 숫자 6개 입력 (중복x)
// 3) 한 개도 맞추지 못하면 7등, 1개 -> 6등, 2개 -> 5등... 6개 -> 1등 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <set>
#include <thread>

using namespace std;
using namespace chrono;

//
// 함수 선언
//
vector<int> Com_RanNum(int min, int max, int count);
vector<int> User_RanNum(int min, int max, int count);
int GetMatchCount(const vector<int>& Com_RanNum, const vector<int>& User_RanNum);
void PrintRank(int MatchCount);



int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	int min = 1;
	int max = 25;
	int count = 6;

	cout << "랜덤 숫자 맞추기" << endl;
	cout << "숫자는 1 ~ 25까지의 숫자만 입력할 수 있습니다." << endl;

	vector<int> Com_Ran = Com_RanNum(min, max, count);
	vector<int> User_Ran = User_RanNum(min, max, count);
	int matchCount = GetMatchCount(Com_Ran, User_Ran);
	
	
	cout << "------------------------" << endl;
	cout << "추첨중..." << endl;
	for (int i = 3; i > 0; i--)
	{
		cout << i << endl;
		this_thread::sleep_for(seconds(1)); // 1초 대기
	}
	cout << endl;
	
	cout << "==* 당첨번호 공개 *==" << endl;
	for (int num : Com_Ran)
	{
		cout << num << " ";
		this_thread::sleep_for(milliseconds(700)); // 0.7초 대기
	}
	cout << endl;

	cout << "==* 사용자의 번호 *==" << endl;
	for (int num : User_Ran)
	{
		cout << num << " ";
	}
	cout << endl;

	this_thread::sleep_for(milliseconds(1500));
	cout << "==== 당첨 결과 ====" << endl;
	this_thread::sleep_for(seconds(2));
	PrintRank(matchCount);

	return 0;
}
//
// 컴퓨터의 무작위 숫자 생성 함수 (1~25 / 6, 중복 x)
//
vector<int> Com_RanNum(int min, int max, int count)
{
	vector<int> Numbers; // 무작위 숫자를 저장
	set<int> UniqueNumbers; // 중복을 허용하지 않는 숫자들을 저장

	while (UniqueNumbers.size() < count)
	{
		int num = min + rand() % (max - min + 1); // min ~ max까지 무작위 숫자 생성
		UniqueNumbers.insert(num); // 생성된 숫자를 set에 추가 (중복x)
	}
	Numbers.assign(UniqueNumbers.begin(), UniqueNumbers.end()); // 세트의 숫자를 벡터로 변환
	
	return Numbers;
}

//
// 사용자의 무작위 숫자 입력 함수 (1~25 / 6, 중복 x)
// 
vector<int> User_RanNum(int min, int max, int count)
{
	vector<int> Numbers;
	set<int> UniqueNumbers;
	int num;

	for (int i = 0; i < count;)
	{
		cout << i + 1 << "번째 번호를 입력하세요: ";
		cin >> num;
		
		if (num < min || num > max)
		{
			cout << "잘못된 숫자입니다. 다시 입력해주세요," << endl;
		}
		else if (UniqueNumbers.find(num) != UniqueNumbers.end())
		{
			cout << "이미 입력된 숫자입니다." << endl;
		}
		else
		{
			UniqueNumbers.insert(num);
			++i;
		}
	}
	Numbers.assign(UniqueNumbers.begin(), UniqueNumbers.end());

	return Numbers;
}

//
// 컴퓨터와 사용자의 번호가 몇개가 맞았는지 확인하는 함수
//
int GetMatchCount(const vector<int>& Com_RanNum, const vector<int>& User_RanNum)
{
	int MatchCount = 0;
	for (int num : User_RanNum)
	{
		if (find(Com_RanNum.begin(), Com_RanNum.end(), num) != Com_RanNum.end())
		{
			MatchCount++;
		}
	}
	return MatchCount;
 }

//
// 몇등인지 확인하는 함수
//
void PrintRank(int MatchCount)
{
	switch (MatchCount)
	{
	case 6:
		cout << "*****@ <<1등 당첨>> @*****" << endl;
		cout << "6개의 숫자를 모두 맞췄습니다!" << endl;
		break;
	case 5:
		cout << "***** <2등 당첨> *****" << endl;
		cout << "5개의 숫자를 맞췄습니다!" << endl;
		break;
	case 4:
		cout << "**** <3등 당첨> ****" << endl;
		cout << "4개의 숫자를 맞췄습니다!" << endl;
		break;
	case 3:
		cout << "* <4등 당첨> *" << endl;
		cout << "3개의 숫자를 맞췄습니다!" << endl;
		break;
	case 2:
		cout << "* <5등 당첨> *" << endl;
		cout << "2개의 숫자를 맞췄습니다!" << endl;
		break;
	case 1:
		cout << "<6등 당첨>" << endl;
		cout << "1개의 숫자를 맞췄습니다!" << endl;
		break;
	default:
		cout << "<꽝>" << endl;
		cout << "0개의 숫자를 맞췄습니다." << endl;
		break;
	}
}