#include "balancedDivide.h"
#include <iostream>
#include <cmath> //abs()
#include <algorithm> //sort()
using namespace std;

Assignment balancedDivide(std::vector<int> const &birthdays) {
	
	//Variable Declaration
	int diff, suma, sumb = 0;
	vector<int> temp; //temporary storage of vector
	vector<int> a;
	vector<int> b;
	
	for(int i = 0; i < birthdays.size(); i++) //store birthdays in temp
		temp.push_back(birthdays[i]);
	
	//Sort vector in descending order and store first in vector a
	sort(temp.begin(), temp.end(), greater<int>());
	a.push_back(temp[0]);
	suma = a[0];
	
	//Sort numbers in each vector based on the sum of each vector
	for (int i = 1; i < temp.size(); i++) {
		if (suma < sumb) { //if sum of vector a is less than b
			a.push_back(temp[i]); //store in a
			suma += temp[i]; //add date to sum
		} else { //if sum of vector a is greater than b
			b.push_back(temp[i]); //store in b
			sumb += temp[i]; //add date to sum
		}
	}
	diff = abs(suma - sumb); //store magnitude of difference in diff
	return Assignment(diff, a, b); //return assignment
}

/* What this algorithm does is sort the vector in decreasing order then puts the first variable in a.
   Then it checks the sum of each vector then puts the next integer in the vector with less sum.
   It will keep repeating until it reaches the last element of the vector.
   Afterwards it will get the absolute value of the difference of the sum of each vectors (we do not want negatives)
   It then returns an Assignment with the difference and both vectors (groups of integers).
*/