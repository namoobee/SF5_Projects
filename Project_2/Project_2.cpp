// Project 2
// 타임어택 끝말잇기 게임
// 1) 제한 시간 30초 동안 플레이어는 끝말잇기 규칙에 따라 단어를 입력
// 2) 제한 시간이 종료되면 게임을 종료 시키고, 입력한 단어의 개수를 출력
// 3) 단, 한번 입력된 단어는 입력하지 못하게 하기

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime> 
#include <chrono> 
#include <unordered_set> // 중복된 단어를 처리하기 위해 사용

using namespace std;

//
// 함수 선언
//
string GetUserInput(const unordered_set<string>& userWord);
bool Input_Matching(const string& word1, const string& word2);
int PlayGame();

int main()
{
	cout << "끝말잇기 게임" << endl;
	cout << "30초안에 최대한 단어를 입력해주세요 " << endl;
	int Score = PlayGame();
	cout << "게임 종료!" << endl << "총 입력한 단어 개수: " << Score << endl;

	return 0;
}

//
// 사용자로부터 단어를 입력받는 함수
// 
string GetUserInput(const unordered_set<string>& UsedWord)
{
	string Input;
	bool Input_Check = false;

	while (!Input_Check)
	{
		cout << "다음 단어를 입력하세요: ";
		cin >> Input;

		if (UsedWord.find(Input) == UsedWord.end()) //이미 사용된 단어인지 확인
		{
			Input_Check = true;
		}
		else
		{
			cout << "중복된 단어 입니다. 다른 단어를 입력하세요." << endl;
		}
	}
	return Input;
}

//
// 이전 단어의 끝 알파벳이 새로 입력된 단어의 첫 알파벳과 일치하는지 확인 하는 함수
// 
bool Input_Matching(string& word1, string& word2)
{
	return (word1.back() == word2.front());
}

//
// 끝말잇기 게임을 실행하는 함수
// 
int PlayGame()
{
	vector<string> words = { "banaba", "watch", "cup", "chair", "airplane" };
	unordered_set<string> UsedWord;
	int Score = 0;
	srand(static_cast<unsigned int>(time(nullptr)));// 현재 시간을 시드로 사용하여 난수 발생기를 초기화
	string RanWord = words[rand()& words.size()];

	auto StartTime = chrono::steady_clock::now();// 현재 시간을 steady_clock을 사용하여 측정 (30초 기준잡기위해)

	cout << "첫 단어: " << RanWord << endl;
	while (true)
	{
		for (const string& word : UsedWord)
		{
			cout << word << " -> ";
		}
		cout << RanWord << endl;

		string UserInput = GetUserInput(UsedWord);

		if (!Input_Matching(RanWord, UserInput))
		{
			cout << "끝말이 맞지 않습니다. 다시 입력하세요." << endl;
			continue;
		}

		UsedWord.insert(RanWord);
		RanWord = UserInput;
		++Score;

		auto current_Time = chrono::steady_clock::now(); // 현재 시간을 steady_clock을 사용하여 측정 (끝나는 시간계산을 위해)
		auto elapsed_Time = chrono::duration_cast<chrono::seconds>(current_Time - StartTime).count(); // current_Time 과 StartTime사이의 시간 간격을 계산

		if (elapsed_Time >= 30)
		{
			return Score;
		}
	}
}