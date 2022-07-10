// PacMan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <windows.h> 
#include <conio.h> 


int main()
{
	HANDLE h = GetStdHandle(-11);


	const int width = 50;
	const int height = 15;
	int maze[height][width] = {};


	// заполнение массива
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			maze[y][x] = rand() % 4; // 0 1 2 3

			if (maze[y][x] == 1) // стены
			{
				int r = rand() % 2; // уменьшить количество стен в 2 раза
				if (r != 0)
				{
					maze[y][x] = 0;
				}
			}
			else if (maze[y][x] == 3) // враги
			{
				int r = rand() % 20;
				if (r != 0)
				{
					maze[y][x] = 0;
				}
			}

			if (x == 0 || y == 0 || x == width - 1 || y == height - 1)
			{
				maze[y][x] = 1;
			}
		}
	}


	// показ элементов массива
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (maze[y][x] == 0) // коридоры
			{
				SetConsoleTextAttribute(h, 0);
				std::cout << " ";
			}
			else if (maze[y][x] == 1) // стены
			{
				SetConsoleTextAttribute(h, 2);
				std::cout << (char)178;
			}
			else if (maze[y][x] == 2) // монетки
			{
				SetConsoleTextAttribute(h, 14);
				std::cout << ".";
				count++;
			}
			else if (maze[y][x] == 3) // враги
			{

				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
		}
		std::cout << "\n";
	}


	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = false;
	cursor.dwSize = 100;
	SetConsoleCursorInfo(h, &cursor);


	COORD smile;
	smile.X = 0; // поля структуры
	smile.Y = 2;
	SetConsoleCursorPosition(h, smile);
	SetConsoleTextAttribute(h, 9);
	std::cout << (char)1;


	// получаем код нажатой клавиши
	srand(time(0));
	while (true)
	{
		int code = _getch();
		if (code == 224)
		{
			code = _getch(); // если была нажата стрелка, то получаем второй код
		}


		SetConsoleCursorPosition(h, smile);
		SetConsoleTextAttribute(h, 0);
		std::cout << " ";


		prev = code;
		if (code == 77 && maze[smile.Y][smile.X + 1] != 1)
		{
			smile.X++;
		}
		else if (code == 80 && maze[smile.Y + 1][smile.X] != 1)
		{
			smile.Y++;
		}
		else if (code == 75 && maze[smile.Y][smile.X - 1] != 1)
		{
			smile.X--;
		}
		else if (code == 72 && maze[smile.Y - 1][smile.X] != 1)
		{
			smile.Y--;
		}
		SetConsoleCursorPosition(h, smile);
		SetConsoleTextAttribute(h, 9);
		cout << (char)1;
	}
	Sleep(INFINITE);
}