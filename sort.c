#include <stdio.h>
#define ARRAY_SIZE 50 // size of the array

void shift_element(int *arr, int i);
void insertion_sort(int *arr, int len);
int main() {
  int arr[ARRAY_SIZE];  // array to store the numbers

  // Get numbers from the user and store them in the array
  //printf("Enter %d numbers: ", ARRAY_SIZE);
  for (int i = 0; i < ARRAY_SIZE; i++) {
    scanf("%d", &arr[i]);
  }

  // Sort the array
  insertion_sort(arr, ARRAY_SIZE);

  // Print the sorted array
  //printf("Sorted array: ");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d", arr[i]);
    if (i < ARRAY_SIZE - 1) {
      printf(",");  // print a comma after each number except the last one
    }
  }
  printf("\n");
  return 0;
}
/*
This function takes a pointer arr to an integer and an integer i, 
and shifts the values of the next i integers after arr one position to the right. 
The function uses a loop to iterate over the integers and swaps the values using 
a temporary variable. Note that this function does not use the array index operator [] 
to access the elements pointed by the pointer.
*/
void shift_element(int *arr, int i) {
  for (int j = 0; j < i; j++) {
    int temp = *(arr + j);
    *(arr + j) = *(arr + j + 1);
    *(arr + j + 1) = temp;
  }
}

/*
This function takes in a pointer to an array of integers arr and an integer len, 
which represents the length of the array. It performs insertion sort by iterating 
over the elements of the array, starting from the second element. 
For each element, it stores the value in a temporary variable called key. 
It then compares the key value with the elements to the left of it, 
shifting them to the right using the shift_element() function if they are greater than the key value. 
Finally, it inserts the key value into its correct position in the sorted portion of the array.
*/
void insertion_sort(int *arr, int len) 
{
  int i, j, key;

  for (i = 1; i < len; i++) {
    key = *(arr + i);
    j = i - 1;

    while (j >= 0 && *(arr + j) > key) {
      shift_element(arr + j, 1);  // shift elements to the right to make room for the key
      j--;
    }

    *(arr + j + 1) = key;
  }
}




