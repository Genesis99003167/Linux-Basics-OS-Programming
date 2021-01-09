#include<stdio.h>
#include "fun.h"

int sub(int num1,int num2)
{
	int result1;
	if(num1>num2){
	result1=num1-num2;
	return result1;
	}
	else{
	return 0;
	}
}
int cube(int num)
{
	int result2;
	result2=num*num*num;
	return result2;
}
