#include <iostream>
#include <random>

using namespace std;

void sortBubble(int* arr, const size_t size);
void arrayRandom(int* arr, const size_t size, const int min = 0, const int max = 1000);
void arrayOutput(int* arr, const size_t size);

int main()
{
	cout << "Size = ";
	size_t size;
	cin >> size;

	int* arr = new int[size];
	cout << "Array: ";
	arrayRandom(arr, size);
	cout << endl;

	int* arrB = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arrB[i] = arr[i];
	}

	cout << endl;
	cout << "Sort Bubble" << endl;
	sortBubble(arrB, size);
	arrayOutput(arrB, size);

	delete[] arrB;

	return 0;
}

void sortBubble(int* arr, const size_t size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				count++;
			}
		}
	}
	cout << "Number of iteration in bubble sort " << count << endl;
}

void arrayRandom(int* arr, const size_t size, const int min, const int max)
{
	random_device rd;
	mt19937 gen(rd());

	const uniform_int_distribution <> uniformIntDistribution(min, max);

	cout << "[ ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = uniformIntDistribution(gen);
		cout << arr[i] << "; ";
	}
	cout << "]";
}

void arrayOutput(int* arr, const size_t size)
{
	cout << "[ ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "; ";
	}
	cout << "]";
}
