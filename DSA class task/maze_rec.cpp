#include<iostream>
//#include<stack>
#include<string>

using namespace std;

struct location
{
	int x_index, y_index;

	location(int x = 0, int y = 0)
	{
		x_index = x, y_index = y;
	}

	bool isValidIndex()
	{
		if (x_index > -1 && x_index < 23 && y_index > -1 && y_index < 50)
			return true;

		return false;
	}
};

bool solveMaze(string mz[], location lc, bool &cont)
{
	if(cont)
	{
		if (mz[lc.x_index][lc.y_index] == 'E')
		{
			cont = false;
			return cont;
		}
		if (mz[lc.x_index][lc.y_index] != 'S')
		{
			mz[lc.x_index][lc.y_index] = '@';
		}
			
		location top = location( lc.x_index - 1, lc.y_index );
		location down = location( lc.x_index + 1, lc.y_index );
		location left = location( lc.x_index, lc.y_index - 1 );
		location right = location( lc.x_index, lc.y_index + 1 );

		if (down.isValidIndex() && (mz[down.x_index][down.y_index] == ' ' || mz[down.x_index][down.y_index] == 'E'))
			solveMaze(mz, down, cont);
		if (right.isValidIndex() && (mz[right.x_index][right.y_index] == ' ' || mz[right.x_index][right.y_index] == 'E'))
			solveMaze(mz, right, cont);
		if (left.isValidIndex() && (mz[left.x_index][left.y_index] == ' ' || mz[left.x_index][left.y_index] == 'E'))
			solveMaze(mz, left, cont);
		if (top.isValidIndex() && (mz[top.x_index][top.y_index] == ' ' || mz[top.x_index][top.y_index] == 'E'))
			solveMaze(mz, top, cont);
/*
		if (cont && mz[lc.x_index][lc.y_index] == '@')
		{
			mz[lc.x_index][lc.y_index] = ' ';
		}
*/	
	}
	return cont;
}


int main()
{
	string maze[23] = { 
		"********S*****************************************",
		"*******                              ******** ****",
		"******* ************* ************** ******** ****",
		"******* ************* ***          * ***      ****",
		"        ************* **  *******  * *** **** ****",
		"******* *** ***    ** *  ********        **** ****",
		"******* *** ****** ** *  ******************** ****",
		"******* *** ****** **    ******************** ****",
		"******* *** ****** ************************** ****",
		"******* *** **                      ********* ****",
		"***     *** ** **** **** ******************** ****",
		"*** ******* ** **** ****                ***** ****",
		"*** *******    **** ************************* ****",
		"*** ********** **** ************************* ****",
		"***            **** ************ ************ ****",
		"******** ********** ************ ************ ****",
		"******** ********** ************      ******* ****",
		"********     ****** ************ **** ******* ****",
		"*******************              **** ******* ****",
		"************************************* ******* ****",
		"************************************* ************",
		"*************************************            E",
		"**************************************************"
	};

	location var;
	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (maze[i][j] == 'S')
			{
				var = location( i, j );
			}
		}
	}
	bool moveOn = true;
	moveOn = solveMaze(maze, var, moveOn);

	cout << "Is there a solution:" << moveOn << endl;
	for (int i = 0; i < 23; i++)
	{
		cout << maze[i] << "\n";
	}
	
	return 0;
}