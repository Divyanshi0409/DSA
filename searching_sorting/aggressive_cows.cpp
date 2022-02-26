// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

#include <stdio.h>
#include <iostream>
using namespace std;

bool canplace(int arr[], int n, int value, int cows)
{
    int co_ord = arr[0];
    int cnt = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - co_ord >= value)
        {
            co_ord = arr[i];
            cnt++;
        }

        if (cnt == cows)
            return true;
    }

    return false;
}

int main()
{
    cout << "Aggressive cows\n";
    int n, c;
    cout << "Enter no. of elements: ";
    cin >> n;

    cout << "\n";

    cout << "Enter number of cows: ";
    cin >> c;

    cout << "Enter elements: ";
    int arr[n], i;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\n";

    int lo = 1, high = arr[n - 1] - arr[0], res;

    while (lo <= high)
    {
        int mid = (lo + high) / 2;

        if (canplace(arr, n, mid, c))
        {
            lo = mid + 1;
            res = mid;
        }

        else
        {
            high = mid - 1;
        }
    }
    cout << "Largest minimum distance is " << res;
    return 0;
}
