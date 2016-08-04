
/*
 * complex.c
 *
 *  Created on: Dec 19, 2015
 *      Author: Alex Cherniak
 */
#include "complex.h"
/*declare the complex variables that are used in the program*/
complex A,B,C,D,E,F;
/*define an array of complexes names and their addresses*/
complexes compxs[]=
{
		{'A',&A},
		{'B',&B},
		{'C',&C},
		{'D',&D},
		{'E',&E},
		{'F',&F},
		{'a',&A},
		{'b',&B},
		{'c',&C},
		{'d',&D},
		{'e',&E},
		{'f',&F},
		{'#',NULL}
};





/*-------------------------HALT-----------------------------------------------*/
void halt()
{
	exit(0);
}

/*---------------------------READ_COMP-----------------------------------------------*/
void read_comp()
{
	char tempcmd[CMDSIZE];
	char no_space[CMDSIZE]; /*array that will hold arguments without white spaces*/
	char* p;
	char *endptr; /*end pointer for strtod*/
	int i,j;
	double real , img;
	int bool = 0;
	complex x;

	if(fgets(tempcmd , CMDSIZE-1 , stdin) == NULL)
	{
		printf("\no legal arguments found \n");
		return;
	}

/************************************************************
Clumsy code, unflexible for changing with unnecessary rehearsal.
It was much more efficient to implement function that treat the complex 
and not special treatment in every function  (-10)
*************************************************************/
	for(i = 0 , j=0; i < CMDSIZE ; i++)
	{
		if(tempcmd[i] != ' ')/*a loop to remove spaces from command line*/
		{
			no_space[j] = tempcmd[i];
			j++;
		}
	}

	/*no_space will contain the arguments without white spaces*/
	p = no_space; /*p will point the the start of no_space array - to the first argument*/
	if(*(p+1) == ',') /*means that the first argument is single char (OK) and we should test if ots viable*/
	{
		for(i = 0; i !='#' ; i++)
			{
				if(p[0] == compxs[i].name)
					{
						x = *(compxs[i].compx); /*assign the first argument to its complex number*/
						bool = 1; /*let us know that first argument correctly found*/
						break;
					}
			}
		if(bool != 1)
		{
			printf("\n first argument is not valid or no such complex number \n");
			return;
		}
	}
	else
	{
		printf("\n first argument is not viable \n");
		return;
	}
	p+=2; /*move p pointer to start of second argument*/
	real = strtod(p , &endptr);
	if((*endptr) != ',')/*invalid argument*/
	{
		printf("\n second argument is not valid \n");
		return;
	}
	x.real = real; /*set the real value of the complex number*/
	p = endptr +1; /*p will point to the start of the third argument*/

	img = strtod(p , &endptr);
	if((*endptr) != '\n')/*at the end of our arguments we should have \n because fgets put it there*/
	{
		printf("\n third argument is not valid \n");
		return;
	}
	x.img = img;/*set the imaginary value of the complex number*/
	*(compxs[i].compx) = x;
	return;
}
/*-----------------------PRINT_COMP------------------------------------------------*/
void print_comp()
{
	char temp_cmd[CMDSIZE]; /*create an array with 40 chars to get command input*/
	char no_space[CMDSIZE]={' '}; /*array that will hold arguments without white spaces*/
	int i,j, bool =0;
	complex x;


	if(fgets(temp_cmd , CMDSIZE-1, stdin)==NULL)
	{
		printf("\n no legal arguments detected \n");
		return;
	}
	for(i = 0 , j=0 ; i < CMDSIZE ; i++)/*a loop to remove all white spaces from the command line*/
	{
		if(temp_cmd[i] != ' ')
		{
			no_space[j] = temp_cmd[i];
			j++;
		}
	}
	/*now no_space array will contain the command line characters without white spaces*/
	if(no_space[1] == '\n') /*means there is a single argument at start of no_space array*/
	{
		for(i = 0 ; i != '#'; i++)
		{
			if(no_space[0] == compxs[i].name)
			{
				x = *(compxs[i].compx); /*assign x to be the complex in the argument*/
				bool = 1; /*a flag to indicate that we found the desired argument*/
				break;
			}
		}
		if(bool != 1)/*means argument is not found*/
		{
			printf("\n no such complex number to print \n");
			return;
		}
	}
	else
	{
		printf("\n invalid complex - syntax error \n");
		return;
	}
	/*once we got here , means input was legal*/
	if(x.img >= 0)/*determine the printing style*/
	{
		printf("\n %.3f+%.3fi \n" , x.real , x.img);
	}
	else
	{
		printf("\n %.3f%.3fi \n" , x.real , x.img);
	}
}
/*--------------------------ADD_COMP------------------------------------------*/
void add_comp()
{
	int i ,j, firstbool =0 , secbool = 0;
	complex x, y , z; /* z will contain the result of x+y*/
	char temp_cmd[CMDSIZE];
	char no_space[CMDSIZE];
	char* p;

	if(fgets(temp_cmd , CMDSIZE-1 , stdin) == NULL) /*enter the characters of command line into temp_cmd*/
	{
		printf("\n no legal arguments found \n");
		return;
	}
	for(i = 0 , j=0; i < CMDSIZE ; i++)/*a loop to remove spaces from command line input*/
	{
		if(temp_cmd[i] != ' ')
		{
			no_space[j] = temp_cmd[i];
			j++;
		}
	}

	p = no_space; /*p will point the the start of no_space array - to the first argument*/
	if(*(p+1) == ',') /*means that the first argument is single char (OK) and we should test if ots viable*/
	{
		for(i = 0; i !='#' ; i++)
			{
				if(*p == compxs[i].name)
					{
						x = *(compxs[i].compx); /*assign the first argument to its complex number*/
						firstbool = 1; /*let us know that first argument correctly found*/
						break;
					}
			}
		if(firstbool != 1)
		{
			printf("\n first argument is not valid or no such complex number \n");
			return;
		}
	}
	else
	{
		printf("\n first argument is not viable \n");
		return;
	}
	p+=2; /*if first argument was found and ok , move p to second argument*/
	if(*(p+1) == '\n') /*means there is no garbage after second argument and we got to \n that fgets put there*/
	{
		for(i = 0 ; i != '#'; i++)
		{
			if(*p == compxs[i].name)
			{
				y = *(compxs[i].compx); /*assign the second argument to its complex*/
				secbool = 1; /*indicate that second argument is ok and was assigned to its complex*/
				break;
			}
		}
		if(secbool != 1) /*check the reason why loop ended*/
		{
			printf("\n second argument is not valid or no such complex number \n");
			return;
		}
	}
	else
	{
		printf("\n second argument is not viable \n");
		return;
	}
	z.real = x.real + y.real; /*set add result of complex real part into z*/
	z.img = x.img + y.img; /*set add result of complex img part into z*/
	if(z.img >= 0)
	{
		printf("\n %.3f+%.3fi \n" , z.real , z.img);
	}
	else
	{
		printf("\n %.3f%.3fi \n" , z.real , z.img);
	}
}

/*------------------------COMP_SUB-----------------------------------*/

void sub_comp()
{
	int i ,j, firstbool =0 , secbool = 0;
	complex x, y , z; /* z will contain the result of x-y*/
	char temp_cmd[CMDSIZE];
	char no_space[CMDSIZE];
	char* p;

	if(fgets(temp_cmd , CMDSIZE-1 , stdin) == NULL) /*enter the characters of command line into temp_cmd*/
	{
		printf("\n no legal arguments found \n");
		return;
	}
	for(i = 0 , j=0; i < CMDSIZE ; i++)
	{
		if(temp_cmd[i] != ' ')
		{
			no_space[j] = temp_cmd[i];
			j++;
		}
	}

	p = no_space; /*p will point the the start of no_space array - to the first argument*/
	if(*(p+1) == ',') /*means that the first argument is single char (OK) and we should test if ots viable*/
	{
		for(i = 0; i !='#' ; i++)
			{
				if(*p == compxs[i].name)
					{
						x = *(compxs[i].compx); /*assign the first argument to its complex number*/
						firstbool = 1; /*let us know that first argument correctly found*/
						break;
					}
			}
		if(firstbool != 1)
		{
			printf("\n first argument is not valid or no such complex number \n");
			return;
		}
	}
	else
	{
		printf("\n first argument is not viable \n");
		return;
	}
	p+=2; /*if first argument was found and OK , move p to second argument*/
	if(*(p+1) == '\n') /*means there is no garbage after second argument and we got to \n that fgets put there*/
	{
		for(i = 0 ; i != '#'; i++)
		{
			if(*p == compxs[i].name)
			{
				y = *(compxs[i].compx); /*assign the second argument to its complex*/
				secbool = 1; /*indicate that second argument is ok and was assigned to its complex*/
				break;
			}
		}
		if(secbool != 1) /*check the reason why loop ended*/
		{
			printf("\n second argument is not valid or no such complex number \n");
			return;
		}
	}
	else
	{
		printf("\n second argument is not viable \n");
		return;
	}
	z.real = x.real - y.real; /*set sub result of complex real part into z*/
	z.img = x.img - y.img; /*set sub result of complex img part into z*/
	if(z.img >= 0)
	{
		printf("\n %.3f+%.3fi \n" , z.real , z.img);
	}
	else
	{
		printf("\n %.3f%.3fi \n" , z.real , z.img);
	}
}

/*---------------------------MULT_COMP_COMP-----------------------------*/
void mult_comp_comp()
{
	int i ,j, firstbool =0 , secbool = 0;
	complex x, y , z; /* z will contain the result of x*y*/
	char temp_cmd[CMDSIZE];
	char no_space[CMDSIZE];
	char* p;

	if(fgets(temp_cmd , CMDSIZE-1 , stdin) == NULL) /*enter the characters of command line into temp_cmd*/
	{
		printf("\n no legal arguments found \n");
		return;
	}
	for(i = 0 , j=0; i < CMDSIZE ; i++)
	{
		if(temp_cmd[i] != ' ')
		{
			no_space[j] = temp_cmd[i];
			j++;
		}
	}

	p = no_space; /*p will point the the start of no_space array - to the first argument*/
	if(*(p+1) == ',') /*means that the first argument is single char (OK) and we should test if ots viable*/
	{
		for(i = 0; i !='#' ; i++)
			{
				if(*p == compxs[i].name)
					{
						x = *(compxs[i].compx); /*assign the first argument to its complex number*/
						firstbool = 1; /*let us know that first argument correctly found*/
						break;
					}
			}
		if(firstbool != 1)
		{
			printf("\n first argument is not valid or no such complex number \n");
			return;
		}
	}
	else
	{
		printf("\n first argument is not viable \n");
		return;
	}
	p+=2; /*if first argument was found and OK , move p to second argument*/
	if(*(p+1) == '\n') /*means there is no garbage after second argument and we got to \n that fgets put there*/
	{
		for(i = 0 ; i != '#'; i++)
		{
			if(*p == compxs[i].name)
			{
				y = *(compxs[i].compx); /*assign the second argument to its complex*/
				secbool = 1; /*indicate that second argument is ok and was assigned to its complex*/
				break;
			}
		}
		if(secbool != 1) /*check the reason why loop ended*/
		{
			printf("\n second argument is not valid or no such complex number \n");
			return;
		}
	}
	else
	{
		printf("\n second argument is not viable \n");
		return;
	}
	z.real = (x.real*y.real)-(x.img*y.img); /*set mult result of complex real part into z*/
	z.img = (x.real*y.img)+(x.img*y.real); /*set mult result of complex img part into z*/
	if(z.img >= 0)
	{
		printf("\n %.3f+%.3fi \n" , z.real , z.img);
	}
	else
	{
		printf("\n %.3f%.3fi \n" , z.real , z.img);
	}
}
/*------------MULT_COMP_REAL------------------------------------------------------*/
void mult_comp_real()
{
	int i , j , bool =0;
	char temp_cmd[CMDSIZE];
	char no_space[CMDSIZE];/*array that will contain arguments without white spaces*/
	complex x , y; /* y will be the result of x*real*/
	double real; /*will get the real number to be multiplied by the complex*/
	char* p; /*endptr is a pointer for strtod*/
	char* endptr;

	if(fgets(temp_cmd , CMDSIZE-1 , stdin) == NULL) /*enter the characters of command line into temp_cmd*/
	{
		printf("\n no legal arguments found \n");
		return;
	}
	for(i = 0 , j=0; i < CMDSIZE ; i++) /*removing all white spaces from cmd line*/
	{
		if(temp_cmd[i] != ' ')
		{
			no_space[j] = temp_cmd[i];
			j++;
		}
	}
	/*now no_space array will contain the command line without spaces*/
	p = no_space; /*p will point to the start of no_space array - to the first argument*/
	if(*(p+1) == ',') /*means that the first argument is single char (OK) and we should test if its viable*/
		{
			for(i = 0; i !='#' ; i++)
				{
					if(*p == compxs[i].name)
						{
							x = *(compxs[i].compx); /*assign the first argument to its complex number*/
							bool = 1; /*let us know that first argument correctly found*/
							break;
						}
				}
			if(bool != 1)/* test to determine why loop ended - argument found or not*/
			{
				printf("\n first argument is not valid or no such complex number \n");
				return;
			}
		}
	else /* the first argument is not correctly inserted*/
	{
		printf("\n first argument is not viable \n");
		return;
	}
	p+=2; /*if everything is OK , move p to the start of the second argument*/
	/*second argument should be a real number and in the end of the number should be \n from fgets*/
	real = strtod(p , &endptr); /* assign real as the number that's inserted as second argument*/
	if(*(endptr) != '\n')
	{
		printf("\n syntax error at second argument \n");
		return;
	}
	y.real = x.real * real; /* y.real gets the result of the real part after mult*/
	y.img = x.img * real; /* y.img gets the result of the img part after mult*/

	if(y.img >= 0) /*test if imaginary part is positive or negative to determine the print*/
	{
		printf("\n %.3f+%.3fi \n" , y.real , y.img);
	}
	else
	{
		printf("\n %.3f%.3fi \n" , y.real , y.img);
	}
	return;
}
/*-------------------MULT_COMP_IMG--------------------------------------------*/
void mult_comp_img()
{
	int i , j , bool =0;
	char temp_cmd[CMDSIZE];
	char no_space[CMDSIZE];/*array that will contain arguments without white spaces*/
	complex x , y; /* y will be the result of x*img*/
	double img; /*will get the imaginary(real) number to be multiplied by the complex*/
	char* p; /*endptr is a pointer for strtod*/
	char* endptr;


	if(fgets(temp_cmd , CMDSIZE-1 , stdin) == NULL) /*enter the characters of command line into temp_cmd*/
	{
		printf("\n no legal arguments found \n");
		return;
	}
	for(i = 0 , j=0; i < CMDSIZE ; i++) /*removing all white spaces from cmd line*/
	{
		if(temp_cmd[i] != ' ')
		{
			no_space[j] = temp_cmd[i];
			j++;
		}
	}
	/*now no_space array will contain the command line without spaces*/
	p = no_space; /*p will point to the start of no_space array - to the first argument*/
	if(*(p+1) == ',') /*means that the first argument is single char (OK) and we should test if its viable*/
		{
			for(i = 0; i !='#' ; i++)
				{
					if(*p == compxs[i].name)
						{
							x = *(compxs[i].compx); /*assign the first argument to its complex number*/
							bool = 1; /*let us know that first argument correctly found*/
							break;
						}
				}
			if(bool != 1)/* test to determine why loop ended - argument found or not*/
			{
				printf("\n first argument is not valid or no such complex number \n");
				return;
			}
		}
	else /* the first argument is not correctly inserted*/
	{
		printf("\n first argument is not viable \n");
		return;
	}
	p+=2; /*if everything is OK , move p to the start of the second argument*/
	/*second argument should be a real number and in the end of the number should be \n from fgets*/
	img = strtod(p , &endptr); /* assign img as the number that's inserted as second argument*/
	if((*endptr) != '\n')
	{
		printf("\n syntax error at second argument \n");
		return;
	}

	y.real = x.img * img*(-1); /* y.real gets the result of the real part after mult*/
	y.img = x.real * img; /* y.img gets the result of the img part after mult*/

	if(y.img >= 0) /*test if imaginary part is positive or negative to determine the print*/
	{
		printf("\n %.3f+%.3fi\n" , y.real , y.img);
	}
	else
	{
		printf("\n %.3f%.3fi \n" , y.real , y.img);
	}
	return;
}

/*-----------------------ABS_COMP----------------------------------*/
void abs_comp()
{
	int i,j,bool=0;
	complex x;
	double res; /*will hold the absolute value of the complex number that will be asked by user*/
	char temp_cmd[CMDSIZE];
	char no_space[CMDSIZE];

	if(fgets(temp_cmd , CMDSIZE-1 , stdin)==NULL)/*ensure that fgets gets anything from stdin*/
	{
		printf("\n no viable arguments found \n"); /* error message if fgets failed*/
		return;/* end function if error*/
	}
	for(i=0 , j=0 ; i < CMDSIZE ; i++)/* a loop to remove white spaces*/
	{
		if(temp_cmd[i] != ' ')
		{
			no_space[j] = temp_cmd[i];
			j++;
		}
	}
	/*now no_space array has the command line without any spaces in it and has \n in the end from the fgets*/
	if(no_space[1]== '\n') /*means there is a single argument at the start of the array and no garbage after the argument*/
	{
		for(i=0 ; i != '#' ; i++)
		{
			if(no_space[0] == compxs[i].name) /*if argument is found to be one of the complexes defined in the program*/
			{
				x = *(compxs[i].compx); /*assign the argument inserted to the x complex*/
				bool = 1; /*indicate that the argument found and OK*/
				break;
			}
		}
		if(bool != 1)
		{
			printf("\n no such complex number \n");
			return;
		}
	}
	else
	{
		printf("\n syntax error at first argument \n");
		return;
	}
	/*if we got here , means everything is OK and argument found as a defined complex*/
	res = sqrt((x.real*x.real)+(x.img*x.img)); /*calculate the absolute value of desired complex*/
	printf("\n %.3f\n", res); /*print the result*/
	return;
}









