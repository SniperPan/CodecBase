#include "SortAlgo.h"


CSortAlgo::CSortAlgo()
{
}


CSortAlgo::~CSortAlgo()
{
}

void CSortAlgo::SelectionSort(int* pnArr, int nLen)
{
	int j = 0;
	int tmp = 0;
	for (int i = 0; i < nLen; i++)
	{
		j = i;
		for (int k = i; k<nLen; k++)
		{
			if (pnArr[j]>pnArr[k])
			{
				j = k;
			}
		}
		tmp = pnArr[i];
		pnArr[i] = pnArr[j];
		pnArr[j] = tmp;
	}
}

void CSortAlgo::InsertionSort(int *pnArr, int nLen)
{
	int key = 0;
	int i = 0;
	for (int j = 1; j<nLen; j++)
	{
		key = pnArr[j];
		i = j - 1;
		while (i >= 0 && pnArr[i]>key)
		{
			pnArr[i + 1] = pnArr[i];
			i = i - 1;
			pnArr[i + 1] = key;
		}
	}
}

void CSortAlgo::BubbleSort(int *pnArr, int nLen)
{
	int tmp = 0;
	for (int i = 0; i < nLen; i++)
	{
		for (int j = (nLen - 1); j >= (i + 1); j--)
		{
			if (pnArr[j] < pnArr[j - 1])
			{
				tmp = pnArr[j];
				pnArr[j] = pnArr[j - 1];
				pnArr[j - 1] = tmp;
			}
		}
	}
}

void CSortAlgo::QuickSort(int *pnArr, int const nLen)
{
	int const lenD = nLen;
	int pivot = 0;
	int ind = lenD / 2;
	int i, j = 0, k = 0;
	if (lenD > 1)
	{
		int* L = new int[lenD];
		int* R = new int[lenD];
		pivot = pnArr[ind];
		for (i = 0; i < lenD; i++)
		{
			if (i != ind)
			{
				if (pnArr[i] < pivot)
				{
					L[j] = pnArr[i];
					j++;
				}
				else
				{
					R[k] = pnArr[i];
					k++;
				}
			}
		}
		QuickSort(L, j);
		QuickSort(R, k);
		for (int cnt = 0; cnt < lenD; cnt++)
		{
			if (cnt < j)
			{
				pnArr[cnt] = L[cnt];;
			}
			else if (cnt == j)
			{
				pnArr[cnt] = pivot;
			}
			else
			{
				pnArr[cnt] = R[cnt - (j + 1)];
			}
		}
	}
}

void CSortAlgo::MergeSort(int *pnArr, int nLen)
{
	if (nLen > 1)
	{
		int middle = nLen / 2;
		int rem = nLen - middle;
		int* L = new int[middle];
		int* R = new int[rem];
		for (int i = 0; i < nLen; i++)
		{
			if (i < middle)
			{
				L[i] = pnArr[i];
			}
			else
			{
				R[i - middle] = pnArr[i];
			}
		}
		MergeSort(L, middle);
		MergeSort(R, rem);
		Merge(pnArr, nLen, L, middle, R, rem);
	}
}

void CSortAlgo::Merge(int *pnArr, int nLen, int *pnArrL, int nLenL, int *pnArrR, int nLenR)
{
	int i = 0;
	int j = 0;
	while (i < nLenL || j < nLenR)
	{
		if ((i < nLenL) & (j < nLenL))
		{
			if (pnArrL[i] <= pnArrR[j])
			{
				pnArr[i + j] = pnArrL[i];
				i++;
			}
			else
			{
				pnArr[i + j] = pnArrR[j];
				j++;
			}
		}
		else if (i < nLenL)
		{
			pnArr[i + j] = pnArrL[i];
			i++;
		}
		else if (j < nLenR)
		{
			pnArr[i + j] = pnArrR[j];
			j++;
		}
	}
}

void CSortAlgo::ShellSort(int *pnArr, int nLen)
{
	int inc = nLen / 2;
	while (inc > 0)
	{
		for (int i = inc; i<nLen; i++)
		{
			int tmp = pnArr[i];
			int j = i;
			while (j >= inc && pnArr[j - inc]>tmp)
			{
				pnArr[j] = pnArr[j - inc];
				j = j - inc;
			}
			pnArr[j] = tmp;
		}
		inc = (inc / 2);
	}
}