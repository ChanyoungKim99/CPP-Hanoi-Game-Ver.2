#include <iostream>

int ChangeNumber(char temp)
{
	int number;
	number = (int)temp - 65;
	return number;
}

int main()
{
	char start, end;
	int number1, number2;
	static int phase{ 0 };

	int Hanoi[3][3]
	{
		{1, 0 ,0},
		{2, 0 ,0},
		{3, 0 ,0}
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << Hanoi[i][j];
		}
		std::cout << std::endl;
	}
	
	while (Hanoi[0][2] != 1 || Hanoi[1][2] != 2 || Hanoi[2][2] != 3)
	{
		std::cout << "어디에서 어디로 이동할까요?" << std::endl;
		std::cout << "A, B, C 중에서 선택하세요" << std::endl;
		std::cin >> start >> end;
		
		
		while (start == end)
		{
			std::cout << "잘못 입력하셨습니다. 다시 입력하세요." << std::endl;
			std::cin >> start >> end;
			continue;
		}

		while (start != 'A' && start != 'B' && start != 'C')
		{
			std::cout << "잘못 입력하셨습니다. 다시 입력하세요." << std::endl;
			std::cin >> start >> end;
			continue;
		}

		while (end != 'A' && end != 'B' && end != 'C')
		{
			std::cout << "잘못 입력하셨습니다. 다시 입력하세요." << std::endl;
			std::cin >> start >> end;
			continue;
		}

		number1 = ChangeNumber(start);
		number2 = ChangeNumber(end);

		if (Hanoi[0][number1] != 0)
		{
			if (Hanoi[2][number2] == 0)
			{
				Hanoi[2][number2] = Hanoi[0][number1];
				Hanoi[0][number1] = 0;
			}

			else if (Hanoi[2][number2] < Hanoi[0][number1])
			{
				std::cout << "옮길 수 없습니다." << std::endl;
			}

			else if (Hanoi[2][number2] > Hanoi[0][number1])
			{
				if (Hanoi[1][number2] == 0)
				{
					Hanoi[1][number2] = Hanoi[0][number1];
					Hanoi[0][number1] = 0;
				}
				else
				{
					Hanoi[0][number2] = Hanoi[0][number1];
					Hanoi[0][number1] = 0;
				}
			}
		}
		else if (Hanoi[1][number1] != 0)
		{
			if (Hanoi[2][number2] == 0)
			{
				Hanoi[2][number2] = Hanoi[1][number1];
				Hanoi[1][number1] = 0;
			}

			else if (Hanoi[2][number2] < Hanoi[1][number1])
			{
				std::cout << "옮길 수 없습니다." << std::endl;
			}

			else if (Hanoi[2][number2] > Hanoi[1][number1])
			{
				if (Hanoi[1][number2] == 0)
				{
					Hanoi[1][number2] = Hanoi[1][number1];
					Hanoi[1][number1] = 0;
				}
				else
				{
					Hanoi[0][number2] = Hanoi[1][number1];
					Hanoi[1][number1] = 0;
				}
			}
		}
		else if (Hanoi[2][number1] != 0)
		{
			if (Hanoi[2][number2] == 0)
			{
				Hanoi[2][number2] = Hanoi[2][number1];
				Hanoi[2][number1] = 0;
			}

			else if (Hanoi[2][number2] < Hanoi[2][number1])
			{
				std::cout << "옮길 수 없습니다." << std::endl;
			}

			else if (Hanoi[2][number2] > Hanoi[2][number1])
			{
				if (Hanoi[1][number2] == 0)
				{
					Hanoi[1][number2] = Hanoi[2][number1];
					Hanoi[2][number1] = 0;
				}
				else
				{
					Hanoi[0][number2] = Hanoi[2][number1];
					Hanoi[2][number1] = 0;
				}
			}
		}
		else
		{
			std::cout << "옮길 수 없습니다." << std::endl;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				std::cout << Hanoi[i][j];
			}
			std::cout << std::endl;
		}
		phase++;

		if (Hanoi[0][2] == 1 && Hanoi[1][2] == 2 && Hanoi[2][2] == 3)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					std::cout << Hanoi[i][j];
				}
				std::cout << std::endl;
			}
			std::cout << "축하합니다! " << phase << "번 만에 푸셨네요!" << std::endl;
			break;
		}

		continue;
	}	
}
