#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int sumTo330(vector<int> nums) {
	sort(nums.begin(), nums.end()); //sorting algorithm
	int nearest = nums[0] + nums[1] + nums[2], sum, back, front; //get first value
	if(nums.size() == 3) return nearest; //if vector size is 3, return only sum
	for (int i = 0; i < nums.size() - 2; i++) { //iterate until second to last element
		back = i + 1; //back starts in front of i
		front = nums.size() - 1; //front starts at the last element
		while (front > back) { //while front is still greater than back
			sum = nums[i] + nums[back] + nums[front]; //get sum
			if(sum == 330) return 330; //if 330 return sum
			if (abs(330 - nearest) == abs(330 - sum)) { //if sum are equal but not 330
				if (nearest > sum) nearest = sum; //if nearest is bigger get smaller sum
			} else if (abs(330 - nearest) > abs(330 - sum)) { //check if sum is smaller than nearest
				nearest = sum; //set nearest to sum
			}
			if (sum < 330) { //if sum is less than 330, move back forward
				back++;
			} else { //if greater, move front back
				front--;
			}
		}
	}
	return nearest;
}

/* Read two pointer technique from https://algodaily.com/lessons/using-the-two-pointer-technique/java
   This algorithm is based on the two pointer technique where we sort the array and use two pointers at
   the same time to iterate through elements. This technique removes one loop which makes the time O(n^2)
   The algorithm also check if the magnitude of the difference is the same, it would take the smaller sum.
   If not, it would check if difference of the sum of the new elements is less than the previous nearest.
   If the back and front pointer meet, it would iterate i to get new combinations of elements
*/