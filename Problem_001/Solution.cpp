#include <iostream>
#include <unordered_set>

using namespace std;
bool isSumPossible(int *arr, int size, int sum);
void main()
{
    int size, sum;
    cout << "Enter the size";
    cin >> size;
    int *array = new int[size];
    cout << "Enter the array";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << "enter the sum";
    cin >> sum;
    cout << (isSumPossible(array, size, sum) ? "true" : "false");
    delete[] array;
}
bool isSumPossible(int *arr, int size, int sum)
{
    int temp;
    unordered_set<int> arr_set;
    for (int i = 0; i < size; i++)
    {
        temp = sum - arr[i];
        if (temp >= 0 && arr_set.find(temp) != arr_set.end())
        {
            return true;
        }
        arr_set.insert(arr[i]);
    }
    return false;
}