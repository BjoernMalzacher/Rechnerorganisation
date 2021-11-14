


#include <stdio.h>
int main(int argc, char* argv[])
{
const int length = 10;
const int a[10] = {1, 4, 7, 10, 11, 14, 18, 21, 25, 28};
unsigned int i;
/* Pruefe, ob das Array sortiert ist */
for (i = length - 1; i >= 1; --i) {
printf("%i \n", i);
if (a[i-1] >= a[i]) {
    
printf("Array ist nicht sortiert!\n");
return 0;
}
}
printf("Array ist sortiert!\n");
return 0;
}