/*Maylee Gagnon
* CS 2223 pro2 B'19
* Lucas Numbers
* 11.5.2019
* */

#include <iostream>
#include <time.h>
using namespace std;


/* Recursive function to calculate the Nth term of Lucas numbers
 * @param n Nth term to be calculated
 * @return value of the Nth term
 */
int lucas(int n) {
	if (n == 0){ // hard code, initial condition L(0) = 2
		return 2;
	}
	else if (n == 1) { // hard code, initial condition L(1) = 1
		return 1;
	}
	return lucas(n-1) + lucas(n-2); //L(n-1)+L(n-2) for n>1
}

/* gathers user input,
 * calls recursive function to calculate
 * prints numbers
 */
int main() {
	clock_t t;
	int num;
	int i = 0;
	float ratioArr[num] = {};

	cout << "Enter number of terms" << endl;
	cin >> num;
	if (cin.bad()) {
		cout << "Bad input. Exiting." << endl;
		return 0;
	}

	clock_t tprev = 1; //TODO starting number
	while ( i <= num){
		t = clock(); // starting time;
		cout << lucas(i) << "("; // calling recursive lucas function to calculate & print values
		t = clock()-t; // ending time;
		cout << (float)t/CLOCKS_PER_SEC << "s) ";

		float curRatio = ((float)t/CLOCKS_PER_SEC)/((float)tprev/CLOCKS_PER_SEC);
		ratioArr[i] = curRatio;
		cout << "ratio: " << curRatio << endl;
		tprev = t;
		i++;
	}
	cout << endl;

	float ratioTotal = 0;
	for (int i = 0; i < num; i++){
		ratioTotal = ratioTotal + ratioArr[i];
	}
	cout << "average ratio: " << ratioTotal/num << endl;

	return 0;
}
