#include <iostream>
using namespace std;

class Board
{
	//Declaring class variables
	char b[9];
		
	//Member functions
	public :
		Board ();
		void drawboard ();
		void mark (int , int);
		int check ();
		int isempty (int);
};

Board :: Board()
{
	for (int i=0 ; i<9 ; i++)
		b[i] = i+49;
}

void Board :: drawboard()
{
	cout << "\t     |     |     " << endl;
	cout << "\t  " << b[0] << "  |  " << b[1] << "  |  " << b[2] << "  " << endl;
	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;
	cout << "\t  " << b[3] << "  |  " << b[4] << "  |  " << b[5] << "  " << endl;
	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;
	cout << "\t  " << b[6] << "  |  " << b[7] << "  |  " << b[8] << "  " << endl;
	cout << "\t     |     |     " << endl;
}

void Board :: mark (int p , int i)	//Put players mark on index i
{
	char mark;
	if (p == 1)
		mark = 'X';
	else 
		mark = 'O';
	b[i] = mark;
}

int Board :: check ()
{
	int f=0;	//to check draw
		
	//Conditions for a player to win
	if (b[0] == b[4] && b[4] == b[8])	//L-R diagonal
		return 1;
	if (b[2] == b[4] && b[4] == b[6])	//R-L diagonal
		return 1;
	if (b[0] == b[3] && b[3] == b[6])	//Left vertical
		return 1;
	if (b[1] == b[4] && b[4] == b[7])	//MIDDLE vertical
		return 1;
	if (b[2] == b[5] && b[5] == b[8])	//Right vertical
		return 1;
	if (b[0] == b[1] && b[1] == b[2])	//Top horizontal
		return 1;
	if (b[3] == b[4] && b[4] == b[5])	//Middle horizontal
		return 1;
	if (b[6] == b[7] && b[7] == b[8])	//Bottom horizontal
		return 1;
		
		//In case of draw
	for (int i=0 ; i<9 ; i++)
		if(b[i] == i+49)
		{
			f=1;
			break;
		}
	if(!f)
		return -1;
	
	//Board incomplete
	return 0;	
}

int Board :: isempty (int p)
{
	if (b[p] == p+49)
		return 1;
	return 0;
}

main ()
{
	Board b;
	int pl = 1 , pos;	
	int res;	
	
	do 			//Loop until a player wins
	{
		system ("cls");
		//Display board
		cout << "\t ** TIC-TAC-TOE **" << endl;
		cout << "--------------------------------------"<< endl << endl;
		b.drawboard ();
		cout << endl << endl;
		
		//Enter user's choice
		do
		{
			cout << "Player " << pl << " : ";
			cin >> pos;
			if (pos < 1 || pos > 9)
				cout << "INVALID CHOICE!! ENTER AGAIN!!" << endl;
				
		}while (pos < 1 || pos > 9);		
		
		//change value in board if not already marked and also change player for next turn
		if (b.isempty(pos-1))
		{
			b.mark( pl , pos-1);
			pl = (pl%2) + 1;
		}
		else
			cout << "INVALID CHOICE!! ENTER AGAIN!!" << endl;
		
		res = b.check();
	}while (res == 0);		//until no player wins
	 
	system ("cls");
		//Display board
	cout << "\t ** TIC-TAC-TOE **" << endl;
	cout << "--------------------------------------"<< endl << endl;
	b.drawboard ();;
	cout << endl << endl;
	
	 //player who played last was the winner. so change it to last player
	 pl = (pl%2) + 1;
	 
	//in case of draw
	if (res == -1)
		cout << "MATCH DRAW!!";
	else
		cout << "PLAYER " << pl << " WINS!!";
	return 0;
}
