
/* find the first occurrence of a string A in string B.
* O(n^2)
* Author: Peiwen Chen
* Date: Jan 12, 2015 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strstr(const char * string1, const char * string2) {

	int i = 0;
	int j = 0;
	int k = 0;
	int len1 = strlen(string1);
	int len2 = strlen(string2);

	while(i < len1) {
		k = i;
		j = 0;
		while ((string1[k] == string2[j]) && (j < len2) && (k < len1 )) {
			printf("i:%d, k:%d, j:%d\n",i,k,j);
			k++;
			j++;
		}
		if (j == len2) {
			printf("found the string :%d \n", i);
			return i;
		}
		i++;
	}
	/* not found */
	return 0;
}

int main(void) {
	char * string1 = "This is a string!";
	char * string2 = "string";

	int index = my_strstr(string1, string2);
	printf ("index is %d\n", index);
	return 0;
}
