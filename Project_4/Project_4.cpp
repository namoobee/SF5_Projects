// Project 4
// 마방진 만들기
// 사용자로부터 홀수 n을 입력 받아 n * n의 마방진 만들기
// 마방진 => 1 ~ n제곱까지의 수를 정사각형으로 배열해 가로, 세로, 대각의 합계가 모두 같도록 만든 것
// 
// 1) 1은 첫 행의 가운데에 위치한다.
// 2) 우상단으로 갈 수록 숫자가 1씩 늘어난다.
// 3) 우상단으로 이동하는 도중 이미 칸이 채워져 있으면 바로 아래 칸에 다음 숫자가 채워진다.
// 4) 첫번째 행에서 우상단으로 이동할 때는 마지막 행의 다음 열로 이동한다.
// 5) 마지막 열에서 우상단으로 이동할 때는 첫번째 열의 이전 행으로 이동한다.
// 6) 첫번째 행의 마지막 열에서는 우상단으로 이동하는 것이 아니라 바로 아래칸으로 이동

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//
// 함수선언
//
int Num_Check();
vector<vector<int>> CreatSquare(int n);
void Print_Square(const vector<vector<int>>& Square);

int main()
{
	int size = Num_Check();
	if (size == 0)
	{
		return 0;
	}

	vector<vector<int>> Square = CreatSquare(size);
	Print_Square(Square);

	return 0;
}

//
// 입력받은 숫자가 옳은 값인지 확인하는 함수
//
int Num_Check()
{
	int User_num;

	while (true)
	{
		cout << "생성 할 마방진의 크기를 홀수로 입력해주세요(0 => 종료): ";
		cin >> User_num;

		if (User_num == 0)
		{
			return 0;
		}
		else if (User_num < 0)
		{
			cout << "입력한 숫자는 음수입니다. 다시 입력해주세요." << endl;
			continue;
		}
		else if (User_num % 2 == 1)
		{
			cout << "크기가 " << User_num << " * " << User_num << "인 마방진을 생성합니다." << endl;
			return User_num;
		}
		else
		{
			cout << "입력한 숫자는 홀수가 아닙니다. 다시 입력해주세요." << endl;
			continue;
		}
	}
}
//
// n * n 의 마방진을 만들기 위한 함수
//
vector<vector<int>> CreatSquare(int n)
{
	vector<vector<int>>Square(n, vector<int>(n, 0));

	int number = 1; // 마방진의 첫 번째 숫자
	int i = 0; // i = 행 인덱스
	int j = n / 2;// j = 열 인덱스

	while (number <= n * n)
	{
		Square[i][j] = number;
		number++;
		int next_i = (i - 1 + n) % n;
		int next_j = (j + 1) % n;

		if (Square[next_i][next_j] != 0)
		{
			i = (i + 1) % n;
		}
		else
		{
			i = next_i;
			j = next_j;
		}
	}
	return Square;
}

//
// 마방진을 출력하는 함수
//
void Print_Square(const vector<vector<int>>& Square)
{
	for (const auto& Square_num : Square)
	{
		for (int cell : Square_num)
		{
			cout << setw(2) << setfill('0') << cell << " ";
		}
		cout << endl;
	}
}