#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <locale> 
using namespace std;
const int ROW = 242;
const int COL = 14;
const int C = 1;
string file[ROW][COL];// кол-во строк и столбцов в файле


void record_all(string file[ROW][COL])
{

	string line;
	string word;
	int row = 0;
	ifstream fin("09_Москва.csv");


	for (int i = 0; i < ROW; i++)
	{
		getline(fin, line);
		stringstream s(line);

		for (int j = 0; j < COL; j++)
		{
			getline(s, word, ',');
			file[i][j] = word;
		}
		row++;
	}

}
void show_all(string file[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{


		for (int j = 0; j < COL; j++)
		{
			cout << file[i][j] << "    ";
		}
		cout << endl;
	}
}




double dy0(int i)
{
	
	double y0 = stod(file[43][C]), y1 = stod(file[44][C]), y2 = stod(file[45][C]), y3 = stod(file[46][C]), y4 = stod(file[47][C]), y5 = stod(file[48][C]);

	double dy0 = y1 - y0;
	double dy1 = y2 - y1;
	double dy2 = y3 - y2;
	double dy3 = y4 - y3;
	double dy4 = y5 - y4;

	double ddy0 = dy1 - dy0;
	double ddy1 = dy2 - dy1;
	double ddy2 = dy3 - dy2;
	double ddy3 = dy4 - dy3;
	
	double dddy0 = ddy1 - ddy0;
	double dddy1 = ddy2 - ddy1;
	double dddy2 = ddy3 - ddy2;

	double ddddy0 = dddy1 - dddy0;
	double ddddy1 = dddy2 - dddy1;
	
	double dddddy0 = ddddy1 - ddddy0;


	switch (i)
	{
	case 0:
		return y0;
	case 1:
		return dy0;
	case 2:
		return ddy0;
	case 3:
		return dddy0;
	case 4:
		return ddddy0;
	case 5:
		return dddddy0;
	}

}
double a(int i)
{
	double h = 1;


	switch(i)
	{
		case 0:
			return dy0(0) / ( (1)*(1) );
		case 1:
			return dy0(1) / ((1)*(h));
		case 2:
			return dy0(2) / ((1*2)*(h*h));
		case 3:
			return dy0(3) / ((1 * 2 * 3)*(h*h*h));
		case 4:
			return dy0(4) / ((1 * 2 * 3 * 4)*(h*h*h*h));
		case 5:
			return dy0(5) / ((1 * 2 * 3 * 4 * 5)*(h*h*h*h*h));

	}
}
double p(int i, double x)
{
	
	double x0 = stod(file[43][0]), x1 = stod(file[44][0]), x2 = stod(file[45][0]), x3 = stod(file[46][0]), x4 = stod(file[47][0]);

	switch (i)
	{
		case 0:
			return 1;
		case 1:
			return (x - x0);
		case 2:
			return (x - x0)*(x - x1);
		case 3:
			return (x - x0)*(x - x1)*(x - x2);
		case 4:
			return (x - x0)*(x - x1)*(x - x2)*(x - x3);
		case 5:
			return (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x4);

	}
}
double newton1(double x)
{
	return a(0) + a(1)*p(1, x) + a(2)*p(2, x) + a(3)*p(3, x) + a(4)*p(4, x) + a(5)*p(5, x);
}
int main() {

	ofstream fout("file3.txt");
	ofstream fout2("file33.txt");
	record_all(file);
	//show_all(file);
	




	for (int k = 43; k < 55; k++)
		cout << file[k][0] << "    " << file[k][C] << endl;


	cout << endl << newton1(1821.1) << endl;

	for (int k = 43; k < 49; k++)
	{
		fout << stod(file[k][0]) << "    " << stod(file[k][C]) << endl;
		if (k == 48)
			break;
		for (double l = 0.1; l <= 0.9; l += 0.1)
		{
			fout << (stod(file[k][0]) + l) << "    " << newton1((stod(file[k][0]) + l)) << endl;
		}
	}
	for (int k = 43; k < 49; k++)
	{
		fout2 << stod(file[k][0]) << "    " << stod(file[k][C]) << endl;
		
	}

	system("pause");
	return 0;
}
