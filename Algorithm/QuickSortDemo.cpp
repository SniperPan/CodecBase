#include<iostream>  
#include "SortAlgo.h"
using namespace std;

int main()
{
	int array[] = { 34, 65, 12, 43, 67, 5, 78, 10, 3, 70 }, k;
	int len = sizeof(array) / sizeof(int);
	cout << "The orginal arrayare:" << endl;
	for (k = 0; k < len; k++)
		cout << array[k] << ",";
	cout << endl;
	
	CSortAlgo *sortAlgo = new CSortAlgo();
	sortAlgo->QuickSort(array, len);
	
	cout << "The sorted arrayare:" << endl;
	for (k = 0; k < len; k++)
		cout << array[k] << ",";
	cout << endl;
	system("pause");
	return 0;
}

