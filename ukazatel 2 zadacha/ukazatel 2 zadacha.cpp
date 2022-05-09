/* Даны два массива : А[M] и B[N](M и N вводятся с клавиатуры).Необходимо создать третий массив
минимально возможного размера, в котором нужно собрать
элементы массивов A и B, не являющиеся общими для них, без
повторений.*/

#include <iostream>
using namespace std;

void show(int* parr, int size)
{
	for (int i = 0; i < size; i++)
		cout << parr[i] << "\t";
	cout << "\n\n";
}


void Array_rand(int* parr, int size)
{
	for (int i = 0; i < size; i++)
		parr[i] = rand() % 30;

}


void Element_new(int*& arr, int& size)  
{
	int* arr1 = new int[size + 1];
	arr1[size] = 0;

	for (int i = 0; i < size; i++)
		arr1[i] = arr[i];

	delete[] arr;
	size++;
	arr = arr1;
}

int* copy_shared_items(int* arr1, int size1, int* arr2, int size2, int& size3) 
{
	int* arr3 = new int[size3];

	for (int i = 0; i < size1; i++)
	{
		bool availability = false;   

		for (int j = 0; j < size2; j++)
			if (arr2[i] == arr1[j]) availability = true;

		if (!availability)
			for (int k = 0; k < size3; k++)
				if (arr2[i] == arr3[k]) availability = true;

		if (!availability)
		{
			Element_new(arr3, size3);
			arr3[size3 - 1] = arr2[i];
		}

	}

	return arr3;
}

int main()
{
	srand(time(0));

	int size1;
	cout << "Enter the number of elements of the 1st array: ";
	cin >> size1;

	int size2;
	cout << "Enter the number of elements of the 2st array : ";
	cin >> size2;

	int* parr1 = new int[size1];

	int* parr2 = new int[size2];

	Array_rand(parr1, size1);
	Array_rand(parr2, size2);

	int size3 = 0;

	int* parr3 = copy_shared_items(parr1, size1, parr2, size2, size3);

	cout << "One array : \n";
	show(parr1, size1);

	cout << "2st array : \n";
	show(parr2, size2);

	cout << "3 st array : \n";
	show(parr3, size3);

	delete[] parr1;
	delete[] parr2;
	delete[] parr3;
}



