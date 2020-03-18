#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;

const int ROW = 241;
const int COL = 14;
const int C = 1; // выбранный столбец
double file[ROW][COL];// кол-во строк и столбцов в файле


void record_all(double file[ROW][COL])
{

	string line;
	string word;
	int row = 0;
	ifstream fin("09_Москва.csv");

	getline(fin, line);
	for (int i = 0; i < ROW; i++)
	{
		getline(fin, line);
		stringstream s(line);

		for (int j = 0; j < COL; j++)
		{
			getline(s, word, ',');
			file[i][j] = stod(word);
		}
		row++;
	}

}
void show_all(double file[ROW][COL])
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

double Polinom(double x, int s, double** koef)
{
	double y = 0.0;
	for (int i = 0; i <= s; i++)  y += koef[i][0] * pow(x, i);
	return y;
}


void Invers(double **A, int N)
{
	double temp;
	double **E = new double *[N];
	for (int i = 0; i < N; i++)
		E[i] = new double[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			E[i][j] = 0.0;
			if (i == j)
				E[i][j] = 1.0;
		}
	for (int k = 0; k < N; k++)
	{
		temp = A[k][k];
		for (int j = 0; j < N; j++)
		{
			A[k][j] /= temp;
			E[k][j] /= temp;
		}
		for (int i = k + 1; i < N; i++)
		{
			temp = A[i][k];
			for (int j = 0; j < N; j++)
			{
				A[i][j] -= A[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	for (int k = N - 1; k > 0; k--)
	{
		for (int i = k - 1; i >= 0; i--)
		{
			temp = A[i][k];
			for (int j = 0; j < N; j++)
			{
				A[i][j] -= A[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A[i][j] = E[i][j];
	for (int i = 0; i < N; i++)
		delete[] E[i];

	delete[] E;
}

void Multip(double**A, double**B, double**C, int c, int d, int f)
{
	for (int i = 0; i<c; i++)
	{
		for (int j = 0; j<f; j++)
		{
			for (int r = 0; r<d; r++)
				C[i][j] += A[i][r] * B[r][j];
		}
	}
}








int main()
{


	record_all(file);
	//show_all(file);


	

	
	double x[ROW];
	double y[ROW];
	
	int k = 0;
	

	for (int m = 0; m < ROW; m++)
	{
		if (file[m][C] != 999.9)
		{
			y[k] = file[m][C];
			x[k] = file[m][0];
			k++;
		}
	}



	int s;
	cout << "Enter stepen polinoma (to 5): ";
	cin >> s;

	

	//правая часть
	int n1 = ROW;
	double**  ar = new double*[s + 1];
	for (int i = 0; i<s + 1; i++)
		ar[i] = new double[1];
	for (int i = 0; i<s + 1; i++)
		ar[i][0] = 0;
	for (int i = 0; i<s + 1; i++)
	{
		for (int j = 0; j<n1; j++)
			ar[i][0] += y[j] * pow(x[j], i);
	}
	//левая часть
	double** array = new double*[s + 1];
	for (int i = 0; i<s + 1; i++)
		array[i] = new double[s + 1];
	for (int i = 0; i<s + 1; i++)
	{
		for (int j = 0; j<s + 1; j++)
		{
			if (i == 0 && j == 0)
				array[i][j] = n1;
			else
			{
				for (int k = 0; k<n1; k++)
					array[i][j] += pow(x[k], i + j);
			}
		}
	}


	//коэф-ты
	double** koef = new double*[s + 1];
	for (int i = 0; i<s + 1; i++)
		koef[i] = new double[1];
	for (int i = 0; i<s + 1; i++)
		koef[i][0] = 0.0;

	Invers(array, s + 1);

	Multip(array, ar, koef, s + 1, s + 1, 1);



	ofstream fout("file5.txt");
	ofstream fout2("file55.txt");


	for (double i = 1779; i<2019; i += 0.1) {
		fout << i << " " << Polinom(i, s, koef) << endl;
	}
	for (int i = 0; i<209; i++) {
		fout2 << x[i] << " " << y[i] << endl;
	}
	
	system("pause");
	return 0;
}
