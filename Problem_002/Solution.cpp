/*+ Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
+*/

#include <iostream>
#include <vector>

using namespace std;

void GetInput(vector<int> &viInput, int &iSize, int &o_iProduct);
vector<int> GetProducts(const vector<int> &viInput, const int &iProduct);

void main()
{
    int iSize, iProduct = 1;
    vector<int> viInput, viResult;
    GetInput(viInput, iSize, iProduct);
    viResult = GetProducts(viInput, iProduct);
    cout << "Output vector:: ";
    for (int i = 0; i < iSize; i++)
    {
        cout << viResult[i] << " ";
    }
}

void GetInput(vector<int> &viInput, int &iSize, int &o_iProduct)
{
    int iTemp;
    cout << "Enter the number of elements:: ";
    cin >> iSize;
    viInput.reserve(iSize);
    cout << "Enter the array:: ";
    for (int i = 0; i < iSize; i++)
    {
        cin >> iTemp;
        o_iProduct *= iTemp;
        viInput.push_back(iTemp);
    }
}
vector<int> GetProducts(const vector<int> &viInput, const int &iProduct)
{
    float fProductLog;
    vector<int> viResult(viInput.size());
    fProductLog = log(iProduct);
    for (int i = 0; i < viInput.size(); i++)
    {
        viResult[i] = exp(fProductLog - log(viInput[i]));
    }
    return viResult;
}