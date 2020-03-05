/*+ Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass?
+*/

#include <iostream>
#include <unordered_set>

using namespace std;

bool IsSumPossible(const vector<int> &viInput, const int &iSize, const int &iSum);
void GetInput(vector<int> &viInput, int &iSize, int &iSum);

void main()
{
    int iSize, iSum;
    vector<int> viInput;
    getInput(viInput, iSize, iSum);
    cout << (isSumPossible(viInput, iSize, iSum) ? "True" : "False");
}

void getInput(vector<int> &viInput, int &iSize, int &iSum)
{
    cout << "Enter the number of elements:: ";
    cin >> iSize;
    viInput.reserve(iSize);
    cout << "Enter the array:: ";
    for (int i = 0; i < iSize; i++)
    {
        cin >> viInput[i];
    }
    cout << "Enter the sum:: ";
    cin >> iSum;
}

bool isSumPossible(const vector<int> &viInput, const int &iSize, const int &iSum)
{
    int iDiff;
    unordered_set<int> usiDifference;
    for (int i = 0; i < iSize; i++)
    {
        iDiff = iSum - viInput[i];
        if (iDiff >= 0 && usiDifference.count(iDiff) != 0)
        {
            return true;
        }
        usiDifference.insert(viInput[i]);
    }
    return false;
}