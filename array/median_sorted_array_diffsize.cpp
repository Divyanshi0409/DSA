#include <bits/stdc++.h>
using namespace std;

// Method to find median
double Median(vector<int>& A, vector<int>& B)
{
	int n = A.size();
	int m = B.size();
	if (n > m)
		return Median(B, A); // Swapping to make A smaller

	int lo = 0;
	int hi = n;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int cut1 = mid;
		int cut2 = (n+m+1)/2 - mid;
		int l1
			= (cut1 > 0)
				? A[cut1 - 1]
				: INT_MIN; // checking overflow of indices
		int l2
			= (cut2 > 0) ? B[cut2 - 1] : INT_MIN;
		int r1
			= (cut1 < n) ? A[cut1] : INT_MAX;
		int r2
			= (cut2 < m) ? B[cut2] : INT_MAX;

		// if correct partition is done
		if (l1 <= r2 and l2 <= r1) {
			if ((m + n) % 2 == 0)
				return (max(l1, l2)+ min(r1, r2))/ 2.0;
			return max(l1, l2);
		}
		else if (l1 > r2) {
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}
	return 0.0;
}

// Driver code
int main()
{
	vector<int> arr1 = { -5, 3, 6, 12, 15 };
	vector<int> arr2 = { -12, -10, -6, -3, 4, 10 };
	cout << "Median of the two arrays are" << endl;
	cout << Median(arr1, arr2);
	return 0;
}
