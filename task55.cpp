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

// Функция вывода матрицы
void PrintMatr(double **mas, int m) {

	for (int i = 0; i<m; i++) {
		for (int j = 0; j<m; j++)
			cout << mas[i][j] << "    ";
		cout << endl;
	}
}
// Получение матрицы без i-й строки и j-го столбца
void GetMatr(double **mas, double **p, int i, int j, int m) {
	int ki, kj, di, dj;
	di = 0;
	for (ki = 0; ki<m - 1; ki++)
	{ // проверка индекса строки
		if (ki == i) di = 1;
		dj = 0;
		for (kj = 0; kj<m - 1; kj++) 
		{ // проверка индекса столбца
			if (kj == j) dj = 1;
			p[ki][kj] = mas[ki + di][kj + dj];
		}
	}
}
// Рекурсивное вычисление определителя
double Determinant(double **mas, int m) {
	int j, k, n;
	double d;

	double **p;
	p = new double*[m];
	for (int i = 0; i < m; i++)
	{
		p[i] = new double[m];
	}

	j = 0; d = 0;
	k = 1; //(-1) в степени i
	n = m - 1;

	if (m<1) cout << "Impossible!";
	if (m == 1) {
		d = mas[0][0];
		return(d);
	}
	if (m == 2) {
		d = mas[0][0] * mas[1][1] -(mas[1][0] * mas[0][1]);
		return(d);
	}
	if (m>2) {
		for (int i = 0; i<m; i++) {
			GetMatr(mas, p, i, 0, m);
			//cout << mas[i][j] << endl;
			//PrintMatr(p, n);
			d = d + k * mas[i][0] * Determinant(p, n);
			k = -k;
		}
	}
	return(d);
}

void Solution(double **koef, double **array, double **ar, int s)
{
	double d;
	double *dn = new double[s + 1];
	
	double **mas;
	double **mas1;
	double **mas2;
	double **mas3;
	double **mas4;
	double **mas5;
	double **mas6;
	
	mas = new double*[s + 1];
	for (int i = 0; i<s+1; i++)
	{
		mas[i] = new double[s + 1];
		for (int j = 0; j<s + 1; j++) 
		{
			mas[i][j] = array[i][j] ;
		}
	}
	

	d = Determinant(mas, s+1);
	//cout << endl << "d   " << d << endl;

	mas1 = new double*[s + 1];
	for (int i = 0; i<s + 1; i++)
	{
		mas1[i] = new double[s + 1];
		for (int j = 0; j<s + 1; j++)
		{
			if(j != 0)
			mas1[i][j] = array[i][j];
			else
				mas1[i][j] = ar[i][0];
		}
	}
	cout << endl;
	//PrintMatr(mas1, s + 1);
	dn[0] = Determinant(mas1, s + 1);

	//cout << endl << "d1   " << dn[0] << endl;

	if (s>0) {
		mas2 = new double*[s + 1];
		for (int i = 0; i < s + 1; i++)
		{
			mas2[i] = new double[s + 1];
			for (int j = 0; j < s + 1; j++)
			{
				if (j != 1)
					mas2[i][j] = array[i][j];
				else
					mas2[i][j] = ar[i][0];
			}
		}
		//cout << endl;
		//PrintMatr(mas2, s + 1);
		dn[1] = Determinant(mas2, s + 1);
		//cout << endl << "d2   " << dn[1] << endl;
	}

	if (s>1) {
		mas3 = new double*[s + 1];
		for (int i = 0; i < s + 1; i++)
		{
			mas3[i] = new double[s + 1];
			for (int j = 0; j < s + 1; j++)
			{
				if (j != 2)
					mas3[i][j] = array[i][j];
				else
					mas3[i][j] = ar[i][0];
			}
		}
		//cout << endl;
		//PrintMatr(mas3, s + 1);
		dn[2] = Determinant(mas3, s + 1);
		//cout << endl << "d3   " << dn[2] << endl;
	}

	if (s>2) {
		mas4 = new double*[s + 1];
		for (int i = 0; i < s + 1; i++)
		{
			mas4[i] = new double[s + 1];
			for (int j = 0; j < s + 1; j++)
			{
				if (j != 3)
					mas4[i][j] = array[i][j];
				else
					mas4[i][j] = ar[i][0];
			}
		}
		//cout << endl;
		//PrintMatr(mas4, s + 1);
		dn[3] = Determinant(mas4, s + 1);
		//cout << endl << "d4   " << dn[3] << endl;
	}

	if (s>3) {
		mas5 = new double*[s + 1];
		for (int i = 0; i < s + 1; i++)
		{
			mas5[i] = new double[s + 1];
			for (int j = 0; j < s + 1; j++)
			{
				if (j != 4)
					mas5[i][j] = array[i][j];
				else
					mas5[i][j] = ar[i][0];
			}
		}
		//cout << endl;
		//PrintMatr(mas5, s + 1);
		dn[4] = Determinant(mas5, s + 1);
		//cout << endl << "d5   " << dn[4] << endl;
	}


	if (s>4) {
		mas6 = new double*[s + 1];
		for (int i = 0; i < s + 1; i++)
		{
			mas6[i] = new double[s + 1];
			for (int j = 0; j < s + 1; j++)
			{
				if (j != 5)
					mas6[i][j] = array[i][j];
				else
					mas6[i][j] = ar[i][0];
			}
		}
		//cout << endl;
		//PrintMatr(mas6, s + 1);
		dn[5] = Determinant(mas6, s + 1);
		//cout << endl << "d6   " << dn[5] << endl;

	}
	


	for (int i = 0; i < s+1; i++)
	{
		
		koef[i][0] = dn[i] / d;
			
	}
	
}

double Polinom(double x, int s, double** koef)
{
	double y = 0.0;
	for (int i = 0; i < s+1; i++)  
		y += koef[i][0] * pow(x, i);
	return y;
}


int main()
{


	record_all(file);
	//show_all(file);



	const int ROW2 = 209;// кол-во правильных значений

	double x[ROW2];
	double y[ROW2];

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
	if (s > 3) s = 3;

	double**  ar = new double*[s + 1];
	for (int i = 0; i<s + 1; i++)
		ar[i] = new double[1];
	for (int i = 0; i<s + 1; i++)
		ar[i][0] = 0;
	for (int i = 0; i < s + 1; i++)
	{
		for (int j = 0; j < ROW2; j++)
		{
			ar[i][0] += y[j] * pow(x[j], i);
		}
	}
	//левая часть
	double** array = new double*[s + 1];
	for (int i = 0; i<s + 1; i++)
		array[i] = new double[s + 1];

	for (int i = 0; i<s + 1; i++)
	{
		for (int j = 0; j<s + 1; j++)
		{

			array[i][j] = 0;
		}
	}

	for (int i = 0; i<s + 1; i++)
	{
		for (int j = 0; j<s + 1; j++)
		{
			if (i == 0 && j == 0)
				array[i][j] = ROW2;
			else
			{
				for (int k = 0; k < ROW2; k++)
				{
					array[i][j] += pow(x[k], i + j);

				}
			}
		}
	}
	//cout << endl; cout << endl; cout << endl;

	//for (int i = 0; i<s + 1; i++)
	//{
	//	cout << ar[i][0];
	//	cout << endl;
	//}
	//cout << endl;
	//for (int i = 0; i<s + 1; i++)
	//{
	//	for (int j = 0; j < s + 1; j++)
	//	{
	//		cout << array[i][j] << "    ";
	//		
	//	}
	//	cout << endl;
	//}

	//коэф-ты
	double** koef = new double*[s+1];
	for (int i = 0; i<s+1 ; i++)
		koef[i] = new double[1];
	for (int i = 0; i<s+1; i++)
		koef[i][0] = 0.0;

	 

	Solution(koef, array, ar, s);


	//for (int i = 0; i < s + 1; i++)
	//	cout << koef[i][0] << endl;
	

	ofstream fout("file5.txt");
	ofstream fout2("file55.txt");

	
	for (double i = 1779; i<2019; i += 0.1) {
		fout << i << " " << Polinom(i, s, koef) << endl;
	}
	for (int i = 0; i<ROW2; i++) {
		fout2 << x[i] << " " << y[i] << endl;
	}







	system("pause");
	return 0;
}
