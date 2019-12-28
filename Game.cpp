using namespace std;

void Game::Play()
{
	while(Running)
	{
		Display();
		Input();
	}
}
void Game::Display()
{
	system("CLS");

	for(int i = 0; i < BoardSize; i++)
	{
		for(int j = 0; j < BoardSize; j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Grid[i][j] % BoardSize + color);
			cout << setw(2) << Grid[i][j] << " ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	if(Help){
		cout << "w : Move _ column up" << endl;
		cout << "s : Move _ column down" << endl;
		cout << "a : Move _ row left" << endl;
		cout << "d : Move _ row right" << endl;
		cout << "R : Randomize 10 moves" << endl;
		cout << "| : Change board size _ (1-9)" << endl;
		cout << "= : Change colors forwards" << endl;
		cout << "- : Change colors reverse" << endl;
		cout << "0 : Default colors" << endl;
		cout << "C : Quit" << endl;
		cout << "h : No help" << endl;
	}else{
		cout << "h : help" << endl;
	}
}
void Game::Input()
{
	char input;
	vector<int> row;
	input = getch();
	switch(input)
	{

		case 'w':
			cout << "Move _ column up" << endl;
			input = getch();
			if(input - '1' >= 0 && input - '1' < BoardSize)
				MoveUp(input - '1');
			break;
		case 'a':
			cout << "Move _ row left" << endl;
			input = getch();
			if(input - '1' >= 0 && input - '1' < BoardSize)
				MoveLeft(input - '1');
			break;
		case 's':
			cout << "Move _ column down" << endl;
			input = getch();
			if(input - '1' >= 0 && input - '1' < BoardSize)
				MoveDown(input - '1');
			break;
		case 'd':
			cout << "Move _ row right" << endl;
			input = getch();
			if(input - '1' >= 0 && input - '1' < BoardSize)
				MoveRight(input - '1');
			break;
		case 'C':
			Running = false;
			break;
		case 'h':
		case 'H':
			if(Help) Help = false;
			else Help = true;
			break;
		case 'R':
			Randomize(10);
			break;
		case '-':
			color--;
			break;
		case '=':
			color++;
			break;
		case '0':
			color = 1;
			break;
		case '|':
			input = getch();
			Grid.clear();
			BoardSize = input - '0';
			if(BoardSize < 1) BoardSize = 1;
			if(BoardSize > 9) BoardSize = 9;
			for(int i = 0; i < BoardSize; i++)
			{
				row.clear();
				for(int j = 0; j < BoardSize; j++)
				{
					row.push_back( i * BoardSize + j + 1);
				}
				Grid.push_back(row);
			}
			break;
		default:
			break;
	}
}

void Game::MoveUp(int n)
{
	int temp = Grid[0][n];
	for(int i = 0; i < BoardSize - 1; i++)
		Grid[i][n] = Grid[i + 1][n];
	Grid[BoardSize - 1][n] = temp;
}
void Game::MoveDown(int n)
{
	int temp = Grid[BoardSize - 1][n];
	for(int i = BoardSize - 1; i > 0; i--)
		Grid[i][n] = Grid[i - 1][n];
	Grid[0][n] = temp;
}
void Game::MoveLeft(int n)
{
	int temp = Grid[n][0];
	for(int i = 0; i < BoardSize - 1; i++)
		Grid[n][i] = Grid[n][i + 1];
	Grid[n][BoardSize - 1] = temp;
}
void Game::MoveRight(int n)
{
	int temp = Grid[n][BoardSize - 1];
	for(int i = BoardSize - 1; i > 0; i--)
		Grid[n][i] = Grid[n][i - 1];
	Grid[n][0] = temp;
}
void Game::Randomize(int n)
{
	int num, pick;
	for(int i = 0; i < n; i++)
	{
		Display();
		num = rand() % (BoardSize * BoardSize);
		pick = num % BoardSize;
		switch((num / BoardSize) % 4)
		{
			case 0:
				MoveUp(pick);
				break;
			case 1:
				MoveLeft(pick);
				break;
			case 2:
				MoveDown(pick);
				break;
			case 3:
				MoveRight(pick);
				break;
			default:
				break;
		}
	}
}