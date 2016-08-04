
/*
 * main.c
 *
 *  Created on: Dec 19, 2015
 *      Author: Alex Cherniak
 *
 * this is a complex calculator(made on ANSI C) , query's to run in are:
 * read_comp A, 5.1, 6.2 - represents A = 5.1+(6.2)i , reads a number into A
 * add_comp A , B - adds 2 complex numbers A and B
 * sub_comp A , B - substructs B from A when A,B are Complex
 * mult_comp_real A , x - multiply complex A by real number x(x can be inserted directly through the terminal)
 * mult_comp_img A , x - multiply complex A by imaginary x(x can be inserted directly through the terminal)
 * mult_comp_comp A , B - multiply 2 complex numbers
 * abs_comp A - calculates the absolute value of complex number A
 * halt - stops the program
 */

#include "complex.h"

/* a struct that contains the function's names and their pointers*/
struct functions cmd[] =
{
		{"read_comp", read_comp},
		{"print_comp", print_comp},
		{"add_comp", add_comp},
		{"sub_comp", sub_comp},
		{"mult_comp_real", mult_comp_real},
		{"mult_comp_img", mult_comp_img},
		{"mult_comp_comp", mult_comp_comp},
		{"abs_comp", abs_comp},
		{"halt", halt},
		{"not valid" , NULL}
};

/*===================MAIN==============================================*/


int main()
{
	int i;
	char command[CMDSIZE]; /*declare an array to get the command line - assuming its no more than 40 chars*/
	FOREVER
	{
/***************************************************
missing user interface (-5)
*****************************************************/
		printf("\n Please enter a viable command: \n");
		if (scanf("%s",command)==1) /*scan the command name to the command array*/
		{
			for(i=0;cmd[i].func != NULL ; i++)
				if(strcmp(command , cmd[i].name) == 0)/*check if user inserted one of the functions on the list*/
					break;
			if(cmd[i].func == NULL)/*if function doesn't exist*/
			{
				fprintf(stderr  , "Command does'nt Exist: %s\n", command);
				if(fgets(command , CMDSIZE-1 , stdin)== NULL)/*to empty the input till the end of the line*/
				{
					return 0;
				}
			}
			else
				(*(cmd[i].func))(); /*a pointer to a function that is found in the functions array*/
		}
	}
	return 0;

}

