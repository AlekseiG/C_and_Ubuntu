#include "stdio.h"
#include "stdlib.h"
#include "time.h"
//#include <vector>

int main () {
	//printf ("Hello world");
	int *a, *b, *c;
	int n = 1000000;
	clock_t time;
	time = clock();
	a = (int*) malloc (sizeof(int) * n);
	b = (int*) malloc (sizeof(int) * n);
	c = (int*) malloc (sizeof(int) * n);
	for (int i = 0; i < n; i++) a[i]=i;	
	for (int i = 0; i < n; i++) b[i]=i;
	for (int i = 0; i < n; i++) c[i]=a[i]+b[i];
	printf("%.3f sec malloc \n",(float) (clock()-time)/CLOCKS_PER_SEC);
	//for (int i = 0; i < n; i++) printf ("%d ",c[i]);
	free (a);
	free (b);
	free (c);
//--------------------------------------------------------------------------
	time = clock();
	a =	(int*) calloc (n, sizeof(int));
	b = (int*) calloc (n, sizeof(int));
	c = (int*) calloc (n, sizeof(int));
	for (int i = 0; i < n; i++) a[i]=i;	
	for (int i = 0; i < n; i++) b[i]=i;
	for (int i = 0; i < n; i++) c[i]=a[i]+b[i];
	printf("%.3f sec calloc \n",(float) (clock()-time)/CLOCKS_PER_SEC);
	free (a);
	free (b);
	free (c);
//--------------------------------------------------------------------------
	int* temp;
	temp = (int*) calloc (n/100,sizeof(int));

time = clock();

	a =	(int*) realloc (temp, n * sizeof(int));
	b = (int*) realloc (temp, n * sizeof(int));
	c = (int*) realloc (temp, n * sizeof(int));
	for (int i = 0; i < n; i++) a[i]=i;	
	for (int i = 0; i < n; i++) b[i]=i;
	for (int i = 0; i < n; i++) c[i]=a[i]+b[i];
	printf("%.3f sec realloc \n",(float) (clock()-time)/CLOCKS_PER_SEC);
	free (a);
	free (b);
	free (c);
	free (temp);
//--------------------------------------------------------------------------
/*	time = clock();
	
	vector vect1 (n, 0), vect2 (n, 0), vect3 (n, 0)		
	
	for (int i = 0; i < n; i++) vect1[i]=i;	
	for (int i = 0; i < n; i++) vect2[i]=i;
	for (int i = 0; i < n; i++) vect3[i]=vect1[i]+vect2[i];
	printf("%.3f sec vector",(float) (clock()-time)/CLOCKS_PER_SEC);
*/	
return 1;
}