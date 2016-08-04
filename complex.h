/*
 * complex.h
 *
 *  Created on: Dec 27, 2015
 *      Author: Alex Cherniak
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


#define FOREVER for(;;)
#define CMDSIZE 40


typedef struct
{
	double real;
	double img;
}complex;

struct functions
{
	char *name;
	void (*func)(void);
};

typedef struct
{
	char name;
	complex *compx;
}complexes;
/*-----------------PROTOTYPES-----------------------------------------------*/
void read_comp(void);
void print_comp(void);
void add_comp(void);
void sub_comp(void);
void mult_comp_real(void);
void mult_comp_img(void);
void mult_comp_comp(void);
void abs_comp(void);
void halt(void);


#endif /* COMPLEX_H_ */
