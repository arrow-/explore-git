#include "shunting-yard.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 *	DONT EDIT THIS FILE!
 *	See the wiki, for a list of keywords that are understood by Liquid.
*/

void strip_wspace(char *ipstr, char* stripped){
	int i, j = 0;		
	for (i=0; ipstr[i] != '\0' && i<99; i++){
		if (ipstr[i] != ' ')
			stripped[j++] = ipstr[i];
	}
	stripped[j] = '\0';
	//printf("%s\n", stripped);
}

int main(int agrc, char *argv[]){
	double result;
	char input[100], stripped[100];
	int i,j;
	//Introduction 
	system("cowsay 'Welcome to the awesome calculator. Moo!'");
	printf("Liquid is a smooth CLI math expression evaluator.\nEnter expressions, you need to match all parens.\n\nSee the wiki to know the keywords understood by Liquid\nTo quit just type 'Q'\n");
	while(1)
	{
		printf("<< ");
		gets(input);
		if(strcmp(input,"Q")==0)
			break;
		strip_wspace(input, stripped);
		Status response = shunting_yard(stripped, &result);
		printf(">> %f\n", result);
	}
	return 0;
}
