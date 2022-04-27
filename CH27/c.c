#include <stdio.h>
#include <string.h>

void printout(char* p, int x){
	printf("%s",p);
	printf(" is foo and ");
	printf("%d",x);
	printf(" is 7\n");
}

int main(){

	printf("Hello World!\n");

	char begin[] = "Hello ";
	char end[] = "World!";

	strcat(begin,end);

	printf("%s",begin);
	printf("\n");

	char* c1 = "foo";
	int i1 = 7;

	printout(c1,i1);

	char* c2 = "dog";
	int i2 = 600;

	printout(c2,i2);

	char* c3 = "bmw";
	int i3 = 0;

	printout(c3,i3);
	return 0;
}