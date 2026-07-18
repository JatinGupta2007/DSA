#include<iostream>
#include<queue>
using namespace std;

class Solution {
	public:
	int startStation(vector<int> &gas, vector<int> &cost) {
		int n = gas.size();

		// Agar pehle par hi cost zyada hai gas se , not possible
		for (int i = 0; i < n; i++) {
			if (cost[i] > gas[i]) {
				continue;
			}
			
			int sum = gas[i] - cost[i];
			int j = i + 1;
			bool failed = false;
			
		// Agar pehle ok hai then check for every element till same element come again
			while (j % n != i) {

				sum = sum + gas[j%n] - cost[j%n];

				// Agar sum negative huya tau answer nhi ho sakta , and sum  jis j par  negative huya hai , i and j ke beech saare
				// elements bhi answer nhi ho sakte
				if (sum < 0) {
					failed = true;
					break;
				}

				j++;
			}
			
			if (!failed) {
				return i;
			}

			// Between i and j koi bhi answer nhi hoga agar yaha tak aagye , therefore i ko j kardiya
			i = j;
			
		}
		return - 1;
	}
};

// Optimised approach
class Solution {
public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int deficit = 0;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            balance += gas[i] - cost[i];

            if (balance < 0) {
                // Can't reach station i+1 from current start
                deficit += balance;   // accumulate the shortfall
                start = i + 1;        // move start to next station
                balance = 0;          // reset balance
            }
        }

        // If total gas >= total cost, return start; otherwise impossible
        return (balance + deficit >= 0) ? start : -1;
    }
};

