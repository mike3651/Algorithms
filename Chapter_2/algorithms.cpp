// Michael Wilson
// ALGORITHMS IN C++
// The point of this file is to help me adapt to the C++ language more
// & solidify my knowledge of the material covered in Cormen, Leiserson,
// Rivest, & Stein's Introduction to Algorithms book 

// PROBLEMS COVERED 
	// 2.1.1
	// 2.1.2
	// 2.1.3

#include <iostream> 
#include <string.h>	// includes the strings needed for C++
#include <vector>	// to be used later down the road
using namespace std;

string response;

/** Asks the user what sort of insertion sort algorithm they would like to use */
void insertionSortInteract();

/** Method that runs a bad search */
void badSearch();

/** Method that searches for a term linearly
 * @pre Vector is valid
 * @post Index of term is returned
 * @param vect The vector to search through
 * @param v The value to search for */
int linearSearch(vector<int> vect, int v) {
	for(int i = 0; i < vect.size(); i++)
		if(vect[i] == v) return i;
	return -1;
}

/** Sorts an array with insertion sort
 * @pre Array is valid
 * @post Array is sorted
 * @param array[] The array to be sorted
 * @param size The size of the of array */
void insertionSort(int array[], int size, string choice) {
	for(int i = 1; i < size; i++) {
		int key = array[i];
		int j = i - 1;		
		bool condition = choice == "increasing" ? array[j] > key : array[j] < key;
		while(j >= 0 && condition) {
			array[j + 1] = array[j];
			j -= 1;
			condition = choice == "increasing" ? array[j] > key : array[j] < key;
		}
		array[j + 1] = key;
	}
}

/** Prints out the contents of an array
 * @pre Array is valid 
 * @param array[] The array to print
 * @param size The size of the of array */
void printArray(int array[], int size) {
	for(int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

/** Prints out the contents of an array
 * @pre Vector is valid
 * @param vect The vector to print */
void printVector(vector<int> vect) {
 	for(int i = 0; i < vect.size(); i++)
 		cout << vect[i] << " ";
 	cout << endl;
}

// WANT TO MAKE A PRINT ANY TYPE FUNCTION
// AT THE MOMENT THIS IS THE KIND OF THING THAT I WANT TO DO
// template<typename dataStruct>
// void printALL(const dataStruct &, int size){
// 	for(int i = 0; i < size; i++) {
// 		if(typeid(&) == array || typeid(&) == vector<T>)
// 			cout << &[i] << " ";
// 		else 
// 			// handle other structures
// 	}
// 	cout << endl;
// }

int main() {
	insertionSortInteract();
	// badSearch();
}

/** Method that goes through the process of asking the user for values to insert for a bad search */
void badSearch() {
	vector<int> myVector;
	int v;
	while(1) {
		cout << "What number that you would like to add to the vector? ";
		cin >> v;
		myVector.push_back(v);
		cout << "Vector so far: "; printVector(myVector); cout << endl;
		cout << "Would you like to add another number? ";
		cin >> response;
		if(response != "yes") break;
	}

	cout << "What is the number that you want to search for? ";	
	cin >> v;
	string phrase = linearSearch(myVector, v) == -1 ? "can't seem to find it" : "we found it!";
	cout << phrase << endl;
}

/** Asks the user what sort of insertion sort algorithm they would like to use */
void insertionSortInteract() {	
	cout << "Would you like to use insertion sort in increasing order "
	     << "or decreasing order?" << endl;
	cin >> response;
	int test[] = {4, 5, 0, 1};	
	int size = sizeof(test)/sizeof(test[0]);	// get the size of the array by counting 
												// the space taken by the whole array  
												// divided by the space taken by an <E>
	cout << "Array before insertion sort" << endl;
	printArray(test, size);
	
	// conditions used to handle the input response
	if(response == "increasing" || response == "decreasing") insertionSort(test, size, response);	
	else {cout << "FAILED TO COMPUTE!!!!" << endl; exit(EXIT_FAILURE); }
	
	cout << "Array after insertion sort" << endl;
	printArray(test, size);
}