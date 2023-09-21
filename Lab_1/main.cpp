#include <iostream>
#include <random>

using namespace std;

/**
@ Функция для заполнения массива случайными числами
*/
void fillArrayRandom(int* arr, int size, int min, int max) 
{
    random_device rd;
    mt19937 gen(rd());
    const uniform_int_distribution<int> uniformIntDistribution(min, max);

    for (int i = 0; i < size; i++)
    {
        arr[i] = uniformIntDistribution(gen);
    }
}

/**
@ Функция для вывода массива
*/
void outputArray(const int* arr, int size)
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
@ Функция для выполнения алгоритма пузырьковой сортировки массива
*/
void bubbleSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
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

/** 
@ Функция для поиска минимального значения в массиве
*/
int findMin(const int* arr, int size) 
{
    if (size <= 0)
    {
        cout << ("Array size must be greater than 0");
    }

    int min = arr[0];

    for (int i = 1; i < size; i++) 
    {
        if (arr[i] < min) 
        {
            min = arr[i];
        }
    }
    return min;
}

/** 
@ Функция для поиска максимального значения в массиве
*/
int findMax(const int* arr, int size)
{
    if (size <= 0) 
    {
        cout << ("Array size must be greater than 0");
    }

    int max = arr[0];
    
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int size;
    
    // Ввод размера массива
    cout << "Enter size of array: ";
    cin >> size;
   
    // Ввод минимального и максимального значения для генерации случайных чисел
    cout << "\nEnter minimum number: ";
    int minNum;
    cin >> minNum;
    cout << "Enter maximum number: ";
    int maxNum;
    cin >> maxNum;

    // Создание массива и заполнение его случайными числами
    int* arr = new int[size];
    fillArrayRandom(arr, size, minNum, maxNum);
    
    // Вывод массива
    cout << "\nYour array: ";
    outputArray(arr, size);
    
    // Сортировка массив с помощью пузырька
    bubbleSort(arr, size);
    cout << "\nYour array sorted: ";
    outputArray(arr, size);
    
    // Нахождение и вывод минимального и максимального значения в массиве
    int Min = findMin(arr, size);
    cout << "\nMinimum of array: " << Min << endl;
    int Max = findMax(arr, size);
    cout << "Maximum of array: " << Max << endl;

    delete[] arr;
    
    return 0;
}