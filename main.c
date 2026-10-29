#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main (void)
{
	char	*p;
	char	*sn;
	char	*pn;
	int		pfimm;
	int		pfc;

	p = "pointer";
	sn = NULL;
	pn = NULL;
	ft_printf("BASIC CASES::::\n");
	ft_printf("My print_ft: %c %s \n", 'x', "string");
	printf("Real printf: %c %s \n", 'x', "string");
	ft_printf("My print_ft: %d %i %u\n", -3436755, 3436755, 534231);
	printf("Real printf: %d %i %u\n", -3436755, 3436755, 534231);
	ft_printf("My print_ft: %x %X %p\n", 8729569, 8729569, p);
	printf("Real printf: %x %X %p\n", 8729569, 8729569, p);
	// PUSHING CASES ::::
	ft_printf("PUSHING CASES::::\n");
	ft_printf("prinft - percentage: %%d\n");
	printf("realprinf - percentage: %%d\n");
	pfimm = ft_printf("My print_ft: %d %i %u\n", -3436755, 3436755, 534231);
	pfc = printf("Real printf: %d %i %u\n", -3436755, 3436755, 534231);
	printf(":::: :::: ::::\n");
	// EDGE CASES ::::
	ft_printf("My print_ft edge putnbr ddd: %d %d %d %d\n", -1, 0, INT_MAX, INT_MIN);
	printf("Real printf edge ccases ddd: %d %d %d %d\n", -1, 0, INT_MAX, INT_MIN);
	ft_printf("My print_ft edge putnbr iii: %i %i %i %i\n", -1, 0, INT_MAX, INT_MIN);
	printf("Real printf edge ccases iii: %i %i %i %i\n", -1, 0, INT_MAX, INT_MIN);
	ft_printf("My print_ft edge putnbr uuu: %u %u %u\n", -1, 0, UINT_MAX);
	printf("Real printf edge ccases uuu: %u %u %u\n", -1, 0, UINT_MAX);
	printf("::::\ncounts:\n%d\n%d\n", pfimm, pfc);
	ft_printf("this is a %%%%%% so what up\n");
	printf("this is a %%%%%% so what up\n");
	ft_printf("this is a %%%%%%d so what up\n");
	printf("this is a %%%%%%d so what up\n");
	// NULL CASES::::
	ft_printf("My print_ft: %s\n", sn);
	printf("Real printf: %s\n", sn);
	ft_printf("My print_ft: %p\n", pn);
	printf("Real printf: %p\n", pn);
	
}
