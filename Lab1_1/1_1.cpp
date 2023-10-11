#include <iostream>
#include <random>

/**
 * Set numbers in a array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
void fillArrayRandom(int* arr, const size_t size, const int min, const int max);

/**
 * Get numbers of array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
void outputArray(int* arr, const size_t size);

/**
 * Get bubble sorting of array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
void bubbleSort(int* arr, const size_t size);

/**
 * Get min numbers of array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
int findMin(int* arr, const size_t size);

/**
 * Get max numbers of array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
int findMax(int* arr, const size_t size);

int main()
{
	int size;

	std::cout << "Enter size of array: ";
	std::cin >> size;

	std::cout << "\nEnter minimum number: ";
	int minNum;
	std::cin >> minNum;
	std::cout << "Enter maximum number: ";
	int maxNum;
	std::cin >> maxNum;

	int* arr = new int[size];
	fillArrayRandom(arr, size, minNum, maxNum);

	std::cout << "\nYour array: ";
	outputArray(arr, size);

	bubbleSort(arr, size);
	std::cout << "\nYour array sorted: ";
	outputArray(arr, size);

	int Min = findMin(arr, size);
	std::cout << "\nMinimum of array: " << Min << std::endl;       

	int Max = findMax(arr, size);
	std::cout << "Maximum of array: " << Max << std::endl;

	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}

	return 0;
}

void fillArrayRandom(int* arr, const size_t size, const int min, const int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uniformIntDistribution(min, max);

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = uniformIntDistribution(gen);
	}
}

void outputArray(int* arr, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void bubbleSort(int* arr, const size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int findMin(int* arr, const size_t size)
{
	int min = arr[0];

	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

int findMax(int* arr, const size_t size)
{
	int max = arr[0];

	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}