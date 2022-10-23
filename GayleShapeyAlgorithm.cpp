// C++ program for stable marriage problem
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

// Number of Men or Women
#define N 4

// This function returns true if woman 'w' prefers man 'm1' over man 'm'
bool wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1)
{
	// Check if w prefers m over her current engagement m1
	for (int i = 0; i < N; i++)
	{
		// If m1 comes before m in list of w, then w prefers her
		// current engagement, don't do anything
		if (prefer[w][i] == m1)
			return true;

		// If m comes before m1 in w's list, then free her current
		// engagement and engage her with m
		if (prefer[w][i] == m)
		return false;
	}
}


void stableMarriage(int prefer[2*N][N])
{
	
	int wPartner[N];

	// An array to store availability of men. If mFree[i] is
	// false, then man 'i' is free, otherwise engaged.
	bool mFree[N];

	// Initialize all men and women as free
	memset(wPartner, -1, sizeof(wPartner));
	memset(mFree, false, sizeof(mFree));
	int freeCount = N;

	// While there are free men
	while (freeCount > 0)
	{
		// Pick the first free man (we could pick any)
		int m;
		for (m = 0; m < N; m++)
			if (mFree[m] == false)
				break;

		// One by one go to all women according to m's preferences.
		// Here m is the picked free man
		for (int i = 0; i < N && mFree[m] == false; i++)
		{
			int w = prefer[m][i];
			if (wPartner[w-N] == -1)
			{
				wPartner[w-N] = m;
				mFree[m] = true;
				freeCount--;
			}

			else // If w is not free
			{
				// Find current engagement of w
				int m1 = wPartner[w-N];
				if (wPrefersM1OverM(prefer, w, m, m1) == false)
				{
					wPartner[w-N] = m;
					mFree[m] = true;
					mFree[m1] = false;
				}
			} // End of Else
		} // End of the for loop that goes to all women in m's list
	} // End of main while loop


	// Print the solution
	cout << "Woman Man" << endl;
	for (int i = 0; i < N; i++)
	cout << " " << i+N << "\t" << wPartner[i] << endl;
}

// Driver program to test above functions
int main()
{
	int prefer[2*N][N] = { {7, 5, 6, 4},
		{5, 4, 6, 7},
		{4, 5, 6, 7},
		{4, 5, 6, 7},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
	};
	stableMarriage(prefer);

	return 0;
}
