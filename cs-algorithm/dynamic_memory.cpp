#include "pch.h"
#include "iostream"
#include "string"
#include "math.h"
#include "vector"
using namespace std;

class Box {
public:
	Box() {
		cout << "yes" << endl;
	}
	~Box() {
		cout << "no" << endl;
	}
};

int main() {

	Box *x;
	x = new Box[4];
	delete[] x;
	/*
	//
	double *pvalue = NULL;
	pvalue = new double;
	*pvalue = 3.154;
	cout << *pvalue << endl;
	delete pvalue;
	//
	int *pint = new int[5];
	for (int i = 0; i < 5; i++) {
		pint[i] = i;
	}

	for (int i = 0; i < 5; i++) {
		cout << pint[i] << endl;
	}
	delete [] pint;
	//
	int **y;
	y = new int *[5];
	for (int i = 0; i < 5; i++) {
		y[i] = new int[6];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			y[i][j] = i * j;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			cout << y[i][j] << endl;
		}
	}

	for (int i = 0; i < 5; i++) {
		delete[] y[i];
	}
	delete[] y;

	//
	*/

	/*
	int ***z;
	z = new int **[1];
	for (int i = 0; i < 1; i++) {
		z[i] = new int*[2];
		for (int j = 0; j < 2; j++) {
			z[i][j] = new int[3];
			for (int k = 0; k < 3; k++) {
				z[i][j][k] = k;
				cout << z[i][j][k] << endl;
			}
		}
	}
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 2; j++)
			delete[] z[i][j];
		delete[] z[i];
	}
	delete[] z;
	*/

	



	return 0;
}
