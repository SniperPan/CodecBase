#ifndef SORTALGO_H
#define SORTALGO_H

#pragma once
class CSortAlgo
{
public:
	CSortAlgo();
	~CSortAlgo();

	void SelectionSort(int *pnArr, int nLen);
	void InsertionSort(int *pnArr, int nLen);
	void BubbleSort(int *pnArr, int nLen);
	void QuickSort(int *pnArr, int const nLen);
	void MergeSort(int *pnArr, int nLen);
	void ShellSort(int *pnArr, int nLen);

private:
	void Merge(int *pnArr, int nLen, int *pnLArr, int nLenL, int *pnArrR, int nLenR);
};

#endif //SORTALGO_H


