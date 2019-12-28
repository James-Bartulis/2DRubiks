#ifndef _Game_h_
#define _Game_h_

using namespace std;

class Game
{
public:
	Game()
	{
		Running = true;
		BoardSize = 4;
		color = 1;
		Help = false;
		vector<int> row;
		for(int i = 0; i < BoardSize; i++)
		{
			row.clear();
			for(int j = 0; j < BoardSize; j++)
			{
				row.push_back( i * BoardSize + j + 1);
			}
			Grid.push_back(row);
		}
	}

	void Play();
	void Display();
	void Input();

	void MoveUp(int n);
	void MoveDown(int n);
	void MoveLeft(int n);
	void MoveRight(int n);

	void Randomize(int n);
	
	bool Running, Help;
	int color;
	int BoardSize;
	vector<vector<int> > Grid;
};

#endif //_Game_h_