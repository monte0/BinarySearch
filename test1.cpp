#include <iostream>

using namespace std;

//Purpose: Search through the array for a number that the user inputs
//Algorithm: Tree Search

// x is the key that we are looking for in array L; first and last are slot numbers
int binarySearch(int L[], int x, int first, int last)
{
	int middle;								//a variable thatr holds the middle slot within the array limits
	if (first > last)						//checks to see if the first became greater than the last
		return -1;							//then it returns -1 to signal that the client's number isn't in the array
	middle = (first + last) / 2;				//calculates the middle number using the first and last index numbers then divide by 2
	cout << "comparing against an element in index " << middle << endl;				//SLOT != INDEX
	if (x == L[middle])						//looks to see if the numer we are looking for is L[middle]
		return middle;						//if it is then return that number and end the function		
	else if (x < L[middle])					//checks to see if the number we're looking for is smaller than the middle
		last = middle - 1;					//if it is then make the array smaller by changing last
	else if (x > L[middle])					//checks to see if the number we're looking for is greater than the middle
		first = middle + 1;					//if it is then make the array smaller by changing first
	binarySearch(L, x, first, last);		//call the function with the updated first or last

}//end of function
void printArray(int arr[], int first, int last)
{
	for(int i = first; i < last; i++)
	{
		cout << arr[i] << " ";

	}
	cout << endl;
}

int main()
{
	int A[10];							//Array can hold 10 ints
	int e;								//the number the client wants to find
	int first = 0;						//first index number for the array
	int last = 9;						//last index number of the array

										// fixed elements for A				[1 3 5 7 9 11 13 15 17 19]
	A[0] = 1; A[1] = 3; A[2] = 5; A[3] = 7; A[4] = 9; A[5] = 11; A[6] = 13;
	A[7] = 15; A[8] = 17; A[9] = 19;

	printArray(A, first, last);

	cout << "What do you want to look for? ";			//ask client what number they want to find
	cin >> e;											//client's number is now e

														// Call binarySearch here to look for e in A
	int respos = binarySearch(A, e, first, last);

	if (respos == -1)									//checks to see if the value returned is -1
		cout << "The number was not found" << endl;		//then it outputs that the number is not in the array
	else
		cout << "The number was found in position " << respos + 1 << endl;	//or it outputs the number of the array

}														//end of main function