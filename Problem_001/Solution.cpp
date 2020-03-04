#include <iostream>
#include <unordered_set>

using namespace std;

bool isSumPossible(const vector<int> &arr, const int &size, const int &sum);
void getInput(vector<int> &arr, int &size, int &sum);

void main()
{
    int size, sum;
    vector<int> array;
    getInput(array, size, sum);
    cout << (isSumPossible(array, size, sum) ? "True" : "False");
}

void getInput(vector<int> &arr, int &size, int &sum)
{
    cout << "Enter the number of elements:: ";
    cin >> size;
    arr.reserve(size);
    cout << "Enter the array:: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the sum:: ";
    cin >> sum;
}

bool isSumPossible(const vector<int> &arr, const int &size, const int &sum)
{
    int temp;
    unordered_set<int> arr_set;
    for (int i = 0; i < size; i++)
    {
        temp = sum - arr[i];
        if (temp >= 0 && arr_set.count(temp) != 0)
        {
            return true;
        }
        arr_set.insert(arr[i]);
    }
    return false;
}