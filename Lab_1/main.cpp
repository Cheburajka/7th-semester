#include <iostream>
#include <random>

using namespace std;

/**
@ ������� ��� ���������� ������� ���������� �������
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
@ ������� ��� ������ �������
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
@ ������� ��� ���������� ��������� ����������� ���������� �������
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
@ ������� ��� ������ ������������ �������� � �������
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
@ ������� ��� ������ ������������� �������� � �������
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
    
    // ���� ������� �������
    cout << "Enter size of array: ";
    cin >> size;
   
    // ���� ������������ � ������������� �������� ��� ��������� ��������� �����
    cout << "\nEnter minimum number: ";
    int minNum;
    cin >> minNum;
    cout << "Enter maximum number: ";
    int maxNum;
    cin >> maxNum;

    // �������� ������� � ���������� ��� ���������� �������
    int* arr = new int[size];
    fillArrayRandom(arr, size, minNum, maxNum);
    
    // ����� �������
    cout << "\nYour array: ";
    outputArray(arr, size);
    
    // ���������� ������ � ������� ��������
    bubbleSort(arr, size);
    cout << "\nYour array sorted: ";
    outputArray(arr, size);
    
    // ���������� � ����� ������������ � ������������� �������� � �������
    int Min = findMin(arr, size);
    cout << "\nMinimum of array: " << Min << endl;
    int Max = findMax(arr, size);
    cout << "Maximum of array: " << Max << endl;

    delete[] arr;
    
    return 0;
}