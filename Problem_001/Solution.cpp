/*+ Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
+*/

#include <iostream>
#include <unordered_set>

using namespace std;

void GetInput(vector<int> &viInput, int &iSize, int &iSum);
bool IsSumPossible(const vector<int> &viInput, const int &iSize, const int &iSum);

void main()
{
    int iSize, iSum;
    vector<int> viInput;
    GetInput(viInput, iSize, iSum);
    cout << (IsSumPossible(viInput, iSize, iSum) ? "True" : "False");
}

void GetInput(vector<int> &viInput, int &iSize, int &iSum)
{
    int iTemp;
    cout << "Enter the number of elements:: ";
    cin >> iSize;
    viInput.reserve(iSize);
    cout << "Enter the array:: ";
    for (int i = 0; i < iSize; i++)
    {
        cin >> iTemp;
        viInput.push_back(iTemp);
    }
    cout << "Enter the sum:: ";
    cin >> iSum;
}

bool IsSumPossible(const vector<int> &viInput, const int &iSize, const int &iSum)
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