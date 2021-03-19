#include <iostream>
using namespace std;

void selectionsort(int data[], size_t n);
void insertionsort(int data[], size_t n);

int main()
{
	int data[10] = { 7, 9, 6, 8, 0, 2, 4, 3, 5, 1 };
	size_t arrsize = 10;

	cout << "Original Array" << endl;
	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;

	cout << "Selection Sort" << endl;
	selectionsort(data, arrsize);
	
	cout << "Insertion Sort" << endl;
	insertionsort(data, arrsize);

	return 0;
}

void selectionsort(int data[], size_t n)
{
	int swap;
	int temp;

	//Selecting position to sort
	for (int i = 0; i < n - 1; i++) {
		swap = i;
		
		//Finding smallest value
		for (int j = i + 1; j < n; j++) {
			if (data[swap] > data[j])
				swap = j;
		}

		//Sorting
		if (swap != i) {
			temp = data[swap];
			data[swap] = data[i];
			data[i] = temp;
		}
	}

	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;
}

void insertionsort(int data[], size_t n)
{
	int temp;
	int j;

	for (int i = 1; i < n; i++) {
		temp = data[i];
		j = i - 1;

		while (j >= 0 && data[j] > temp) {
			data[j + 1] = data[j];
			j -= 1;
		}

		data[j + 1] = temp;
	}

	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;
}