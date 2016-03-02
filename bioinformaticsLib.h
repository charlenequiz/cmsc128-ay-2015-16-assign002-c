/*	Name:		Charlene Y. Quiz
 *	Studnum:	2013-68102
 *	CMSC 128 AB-6L
 *	Simple Bioinformatics Library
 *	cmsc128-ay-2015-16-assign002-c
 */

#include<stdio.h>
#include<string.h>

int getHammingDistance(char str1[], char str2[] ){
/*	Gets the Hamming Distance
 *	The Hamming Distance of two strings is the number of characters that 
 *	differ in ith position from position 1 to the length of the string input.
 *
 *	Algorithm:
 *		Check if the strings are of equal length
 *		Traverse the two strings in one loop
 *		If they differ in the ith position, increment counter
 *		Return -1 is strings are not of equal length
 *		Otherwise, return counter
 */
	int i, counter = 0;
	
	if(strlen(str1) == strlen(str2) && strlen(str1) > 0){
		for(i = 0; i < strlen(str1); i++){
			if(str1[i] != str2[i]) counter++;
		}	
		return counter;
	}else{
		printf("Error! Strings are not equal!\n");
		return -1;
	}
}

int countSubstrPattern(char original[], char pattern[]){
/*	Counts the occurrence of the pattern in the original string
 *	
 *	Algorithm:	
 *		Traverse the original string using for loop
 *		If a character in the original string matches the first 
 *			character in the pattern, use a loop to see if the 
 *			while pattern appears in the original
 *			If it appears, increment counter
 *		Resume loop until the condition is met
 *		Return the counter
 */
	int i, j, temp, counter = 0;
	for(i = 0; i < strlen(original); i++){
		if(original[i] == pattern[0]){
			for(temp = i, j = 0; j < strlen(pattern) && temp < strlen(original); j++, temp++){
				if(original[temp] != pattern[j]) break;
			}
			if(j == strlen(pattern)) counter++;
		}
	}
	return counter;
}

int isValidString(char str[], char alphabet[]){
/*	Returns valid if all the characters in str is in the alphabet
 *
 *	Algorithm:
 *		Set valid to true
 *		Compare each character from str to each character in the
 *			alphabet
 *		If a character from str does not appear in alphabet,
 *			change valid to false
 *		Return the value of valid
 */
	int i, j, valid = 1;
	
	for(i = 0; i < strlen(str); i++){
		for(j = 0; j < strlen(alphabet); j++){
			if(str[i] == alphabet[j]) break;
		}	
		if(j == strlen(alphabet)) valid = 0;
	}
	return valid;
}

int getSkew(char str[], int n){
/*	Returns the number of 'G' minus the number of 'C' in the first
 *		n positions.
 *
 *	Algorithm;
 *		Check if the length of the string is greater than or equal
 *			to n and is greater than 0
 *		From 0 to n-1, count the number of 'G's and 'C's
 *		Return the number of 'G's minus the number of 'C's
 */
	int g_count = 0, c_count = 0, i;
	if(strlen(str) >= n && strlen(str) > 0){
		for(i = 0; i < n; i++){
			if(str[i] == 'G') g_count++;
			else if(str[i] == 'C') c_count++;
		}
	}
	return g_count - c_count;
}

int getMaxSkewN(char str[], int n){
/*	Returns the maximum value of the number of 'G' minus the number
 *		of 'C's in the first n positions
 *	
 *	Algorithm:
 *		For get the skew for every number from 1 to n-1
 *		maxSkew is initialized as the skew when n = 1
 *		If the skew (for 2 -> n-1) is greater than maxSkew
 *			we reassign the maxSkew as the skew.
 */
	int g_count = 0, c_count = 0, i, skew, maxSkew;
	if(strlen(str) >= n && strlen(str) > 0){
		for(i = 0; i < n; i++){
			if(str[i] == 'G') g_count++;
			else if(str[i] == 'C') c_count++;
			
			skew = g_count - c_count;
			if( i == 0 || skew > maxSkew) maxSkew = skew;
		}
	}
	return maxSkew;
}

int getMinSkewN(char str[], int n){
/*	Returns the minimum value of the number of 'G' minus the number
 *		of 'C's in the first n positions
 *	
 *	Algorithm:
 *		For get the skew for every number from 1 to n-1
 *		minSkew is initialized as the skew when n = 1
 *		If the skew (for 2 -> n-1) is less than minSkew
 *			we reassign the minSkew as the skew.
 */
	int g_count = 0, c_count = 0, i, skew, minSkew;
	if(strlen(str) >= n && strlen(str) > 0){
		for(i = 0; i < n; i++){
			if(str[i] == 'G') g_count++;
			else if(str[i] == 'C') c_count++;
			
			skew = g_count - c_count;
			if( i == 0 || skew < minSkew) minSkew = skew;
		}
	}
	return minSkew;
}
