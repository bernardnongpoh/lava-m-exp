/*** Generated by CAnnotate ***/ 
// COVERAGE CRITERIA : ABS AOR COR ROR MCC 
#include<stdio.h>
#include <stdbool.h>
int foo(int i){

// ABS Label 1
if(i < 0)  { asm volatile (""::: "memory"); }
return i;
}

int main(){

int x=0;
while(1){
	
// ABS Label 2
if(x < 0)  { asm volatile (""::: "memory"); }

// ROR Label 3
if((x <= 4) != (x > 4))  { asm volatile (""::: "memory"); }
// ROR Label 4
if((x < 4) != (x > 4))  { asm volatile (""::: "memory"); }
// ROR Label 5
if((x >= 4) != (x > 4))  { asm volatile (""::: "memory"); }
if(x>4){
	break;
	}
	
	
	x++;
	

};
}
