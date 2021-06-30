#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Declaration of functions merge and mergesort WITH THE LENGTH OF THE MAIN ARRAY
void merge(int l[], int r[], int a[], int len);
void mergesort(int a[], int len);

int main(void)
{
    // Definition of experimental array and length of the array using sizeof in bytes
    int array[] = {5, 3, 2, 1, 4};
    int len = sizeof(array) / sizeof(int);

    // Function call for mergesort
    mergesort(array, len);

    // Simple iteration for printing the array AFTER THE MERGESORT
    for (int i = 0; i < len; i++)
    {
        printf("%i ", array[i]);
    }
}

// Definition of function merge, used in the mergesort function
void merge(int l[], int r[], int a[], int len)
{

    // Calculating the length of the left side and right side of the array
    int nl = floor(len / 2);
    int nr = len - nl;

    // Declaration of useful variables for the while loop
    int i = 0, j = 0, k = 0;

    // While loop over each SORTED half and checks which elements, IN ORDER, are smaller
    while (i < nl && j < nr)
    {
        if (l[i] <= r[j])
        {
            // Appending the smaller element to the original array in the correct place: K
            a[k] = l[i];
            i++;
        }
        else
        {
            // Same if the smaller element is in the right half
            a[k] = r[j];
            j++;
        }
        // Increasing k by one every iteration to make sure the elements are in order
        k++;
    }

    // While loop when there are only elements on the left side left
    while (i < nl)
    {
        a[k] = l[i];
        i++;
        k++;
    }
    // Same for the right side
    while (j < nr)
    {
        a[k] = r[j];
        j++;
        k++;
    }
}

// Definition of mergesort function WITH THE LENGTH of the array
void mergesort(int a[], int len)
{
    // Declaration of new length variable: n
    int n = len;

    // Control flow to exit in case there is only one number in the array - IT'S SORTED!
    if (n < 2)
    {
        return;
    }

    // Declaration of the middle point and the two arrays of equal size or the right side with 1+ element
    int mid = floor(n / 2);
    int left[mid];
    int right[n - mid];

    // For loop responsible for appending elements in the left half of the array to the new left array
    for (int i = 0; i < mid; i++)
    {
        left[i] = a[i];
    }

    // Same for the right array
    for (int i = mid; i < n; i++)
    {
        right[i - mid] = a[i];
    }

    // Calling mergesort to sort the left half WITH THE LENGTH
    mergesort(left, mid);

    // Calling mergesort to sort the right half the same way
    mergesort(right, n - mid);

    // Merging the left and the half SORTED arrays
    merge(left, right, a, n);
}