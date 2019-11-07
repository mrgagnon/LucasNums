/*Maylee Gagnon
* CS 2223 pro2 B'19
* Lucas Numbers
* 11.5.2019
* */

#include <iostream>
using namespace std;

// TODO printing

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
	int num;
	int i = 0;

	cout << "Enter number of terms" << endl;
	cin >> num;
	if (cin.bad()) {
		cout << "Bad input. Exiting." << endl;
		return 0;
	}

	//cout << lucas(num);

	while ( i <= num){
		cout << lucas(i) << " "; // calling recursive lucas function to calculate & print values
		i++;
	}
	cout << endl;
	return 0;
}
