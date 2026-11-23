// week 3 searching and sorting arrays

#include <iostream>
using namespace std;


/*isSorted function
Purpose: Determines whether an array is sorted in ascending order.
• Parameters: An array of integers and the size of the array
• Returns: true if the array is sorted in ascending order and false otherwise
• Other requirements:
o Must stop checking as soon as an out-of-order pair is found.
o An empty array or an array with one element should be considered sorted.
*/

bool isSorted(int array[],int size ) {
	for (int i = 0; i < (size - 1); i++) {
		if (array[i] > array[i + 1]) {
			return false;
		}
		
	}return true;
}




/*selectionSort function
• Purpose: Sorts an array of integers into ascending order under the selection sort algorithm
• Parameters: An array of integers and the size of the array
• Returns: (We are changing the array in the function – do we need to return anything?)
• Other requirements: Do not use any built in sorting functions
*/
int* selectionSort(int array[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int smallest = i; //the smallest is now set to i

		for (int j = i + 1; j < size; j++) { //looking at the index next to it 
			if (array[j] < array[smallest]) { //this is if it is smaller
				smallest = j; //now set the smallest to j because its not i anymore
			}
		}	
		if (smallest != i) {
			swap(array[i], array[smallest]); //this performs the swapping
		}
	}
	return array;//return this array to main so it can be printed
}

/* this function helps with the swapping of the values on the actual array and moving
* the indexes without losing the actual values.
*/
void swap(int *x, int *y){ 
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* this function just displays the array to the user at the end
*/
void displayArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}




/*main function
• Purpose: Controls the overall flow of the program and interacts with the user.
• Description:
o Create an array of integers and display it to the user
o Call the isSorted function to determine if the array is sorted
▪ If the array is not sorted, ask the user whether they would like to sort it.
▪ If the array is sorted, tell the user the array is sorted
o If the user wants the array sorted, call the selectionSort function and display the
sorted array.*/
int main() {
	char userAns;
	const int size = 6;
	int array[size] = { 45,3,6,88,90,43 };


	cout << "Your array of integers is: ";
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	bool issort = isSorted(array, size); //check if its sorted
	if (issort == false) {
		cout << "\nYour array is out of order, would you like to sort your array? (y/n): " << endl;
		cin >> userAns;
		if (userAns == 'y') {
			selectionSort(array, size);
			cout << "Here is your sorted array: ";
			displayArray(array, size);
			cout << endl;

		}
		else {
			cout << "okay goodbye!" << endl;
		}
	}
	

	

	
	

		
return 0;
}