#include <stdio.h>
int main(){
	float n = 3.14159;
	double area = 0;
	float raio = 0;
	scanf("%f",&raio);
	area = n*(raio*raio);
	printf("A=%2.4lf \n",area); 
	system("PAUSE");
	return 0;
}