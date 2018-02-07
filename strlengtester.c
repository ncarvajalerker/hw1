#include<stdio.h>

size_t mystrlen1(const char *str){
   size_t i;
   for (i = 0; str[i] != '\0'; i++);
   return i;


}

int main(int argc, char const *argv[])
{
	printf("%lu\n", mystrlen1("helllllooo hi hello"));
	return 0;
}


