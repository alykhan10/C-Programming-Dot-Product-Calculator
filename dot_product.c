/*****************************************************************************************************************/
/*												  Dot Product Calculator										 */
/*****************************************************************************************************************/

/*
 * Author:	Aly Khan Nuruddin
 * Date:	June 2, 2021
 *
 * Purpose: This program prompts the user for the dimension of two vectors, one consisting of odd numbers and the
 *          other consisting of even numbers, and then computes the dot product of the two vectors, for the user.
 */

/*****************************************************************************************************************/
 
 #define _CRT_SECURE_NO_WARNINGS												// Prohibit the compiler from suggesting secure versions of library functions.

 #include <stdio.h>																// Include the standard input and output library in C.
 #include <stdlib.h>															// Include the standard library in C.
 
 #define MAX_DIMENSION 20														// Initialize the maximum possible dimension of the vector space.
 
 int dotVal( int vectorOdd[], int vectorEven[], int vectorDimension);			// Define the prototype for the function "dotVal".		
 
 int main( void )																// Define the function "main".
 {   
     int dotProduct;															// Define the variable that stores the dot product of the two vectors.
     int vectorDimension;														// Define the variable that stores the dimension of the vector space specified by the user.
     
     int vectorOdd[ MAX_DIMENSION ];											// Define the array that stores odd entries of the second vector.
     int vectorEven[ MAX_DIMENSION ];											// Define the array that stores even entries of the first vector.
     
     printf( "Note: The vector space has a maximum possible dimension of %d.", MAX_DIMENSION );					// Notify the user about the maximum possible dimension of the vector space.
     printf( "\n\nEnter a value for the dimension of the vector space: " );										// Request the user to input a dimension of the vector space.
     scanf( "%d", &vectorDimension);																			// Read the value entered by the user and assign it to the variable.
     
     while( vectorDimension > MAX_DIMENSION )																	// Define the condition where the dimension entered by the user exceeds the maximum possible dimension of the vector space
     {
         printf( "\nError: The dimension of the vector space cannot exceed the maximum possible dimension." );	// Notify the user of an invalid input.
         printf( "\n\nEnter a value for the dimension of the vector space: " );									// Request the user to input a dimension of the vector space.
		 scanf("%d", &vectorDimension);																			// Read the value entered by the user and assign it to the variable.
     }
     
     for( int count = 0; count < vectorDimension; count++ )						// Initialize 'count' as 0. Increment 'count' by 1. Execute the loop while 'count' is less than the vector dimension.
     {
         vectorEven[ count ] = ( count * 2 );									// Assign an even value to each entry of the vector.
     }
     
     printf( "\nThe first vector comprises of even entries: " );				// Print the following statement for the user.
     
     printf( "[%d", vectorEven[0] );											// Print the first entry of the vector.
     
     for( int count = 1; count < vectorDimension; count++ )						// Initialize 'count' as 1. Increment 'count' by 1. Execute the loop while 'count' is less than the vector dimension.
     {   
         printf( ", " );														// Print a 'comma' on the screen.
         printf( "%d", vectorEven[count] );										// Print each entry of the vector.
     }
     
     printf( "]." );															// Print a 'closing bracket' and a 'full stop' on the screen.
     
     for( int count = 1; count <= vectorDimension; count++ )					// Initialize 'count' as 1. Increment 'count' by 1. Execute the loop while 'count' is less than the vector dimension.
     {
         vectorOdd[ count - 1 ] = -1 + ( count * 2 );							// Assign an odd value to each entry of the vector.
     }
     
     printf( "\n\nThe second vector comprises of odd entries: " );				// Print the following statement for the user.
     
     printf( "[%d", vectorOdd[0] );												// Print the first entry of the vector.
     
     for( int count = 1; count < vectorDimension; count++ )						// Initialize 'count' as 1. Increment 'count' by 1. Execute the loop while 'count' is less than the vector dimension.
     {   
         printf( ", " );														// Print a 'comma' on the screen.
         printf( "%d", vectorOdd[count] );										// Print each entry of the vector.
     }
     
     printf( "]." );															// Print a 'closing bracket' and a 'full stop' on the screen.
     
     dotProduct = dotVal( vectorOdd, vectorEven, vectorDimension );				// Call the function "dotVal".
     
     printf( "\n\nThe dot product of the two vectors is %d.\n\n", dotProduct );	// Print the value of the vector dot product on the screen.
     
     system( "PAUSE" );															// Suspend the execution of the program.
	 return 0;																	// Terminate the execution of the program.
 }
 
 int dotVal( int vectorOdd[], int vectorEven[], int vectorDimension )			// Define the function "dotVal".
 {   
     int dotProduct = 0;														// Initialize the value of the dot product as 0.
     int scalarProduct;															// Define the variable that stores the scalar product of two vector entries.
     
     for( int count = 0; count < vectorDimension; count++ )						// Initialize 'count' as 0. Increment 'count' by 1. Execute the loop while 'count' is less than the vector dimension.
     {
         scalarProduct = vectorOdd[count] * vectorEven[count];					// Compute the scalar product of two vector entries.
         dotProduct += scalarProduct;											// Compute the vector dot product.
     }
     
     return dotProduct;															// Return the value of the dot product to the "main" function.
 }