/* 
* Reverse a C-style string("abcd" is reprensted as 5 chars, including '/0'
* Author: Peiwen Chen
* Date: Oct 19th, 2014 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Analysis:
 * C-style string: use char * as pt to the string
 * in-place exchange
 * O(n) 
 */

void reverse_string(char *string) {

	char *s = string;
    char *e = string;		//pt to start
	char tmp;
	while(*e != '\0') {
		e++;
	}

	e--;
	
	while (s < e) {
		tmp = *s;
		*s = *e;
		*e = tmp;
		e --;
		s ++;
	}

}

int main(void){
	char string[128] = "This is a string\0";
	printf("string :%s\n", string);
	reverse_string(string);
	printf("reversed string: %s\n",string);
	return 0;
}
	
