/*
Given 4 strings, write a fucntion to get smallest string that consists all four strings. 
In Case of Multiple strings with smallest length,
Return the string which occurs alphabetically first .

Ex : (acat, tiger, silica, licaria) O/P: "silicariacatiger"
Ex : (def,abc,ghi,jkl)   O/P : “abcdefghijkl” (Alphabetically first )
Ex : (apple,pp,pineapple,nea) O/P: "pineapple";
Ex : (zzzabc,abcdef,yyyzzz,cabyyy) O/P: "cabyyyzzzabcdef" (Order Swapped )

Note : Each string given as input ,should be in the same format in the output string. 
Ie if input string is abcd ,it cannot be modified as bdca in the final string .

The Order of Strings in the Final string ,maynot be in the same order 
given in which they are given
Function Signatue : char * smallestword(char *s1,char *s2,char *s3,char *s4);

Note : You can use String.h functions .

Constraints : 
Length of each String will be less than 100 .

Difficulty : Hard
*/

#include <stdlib.h>
#include <string.h>


char * concat_4strings(char *s1, char *s2, char *s3, char *s4){
	if (s1 == NULL&&s2 == NULL&&s3 == NULL&&s4 == NULL)
		return NULL;
	int len1 = 0, len2 = 0, len3 = 0, len4 = 0;
	len1 = strlen(s1); 
	len2 = strlen(s2);
	len3 = strlen(s3);
	len4 = strlen(s4);
	struct test
	{
		int len;
		char *str;
	};
	struct test temp[4];
	temp[0].len = len1;
	temp[0].str = s1;
	temp[1].len = len1;
	temp[1].str = s1;
	temp[2].len = len1;
	temp[2].str = s1;
	temp[3].len = len1;
	temp[3].str = s1;
	int temp2 = len1 + len2 + len3 + len4;
	char *res = (char *)malloc(temp2*sizeof(char *));
	res = NULL;
	
	struct test tempo;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (temp[i].len>temp[j].len)
			{
				 tempo = temp[i];
				temp[i] = temp[j];
				temp[j] = tempo;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (temp[i].len != temp[i + 1].len)
		{
			res = strcat(temp[i].str, res);
		}
		else if (temp[i].len == temp[i + 1].len)
		{
			if (temp[i].str[0] < temp[i + 1].str[0])
			{
				res = strcat(temp[i].str, res);
			}
		}

	}
	return res;
}