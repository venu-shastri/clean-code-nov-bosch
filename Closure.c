// Online C compiler to run C program online
#include <stdio.h>

void (*fun(int x))() {
    int y=x+10;
		void pritFunContext(){
				printf("%d,%d",x,y);
		}
		return pritFunContext;
}
int main() {
    // Write C code here
    printf("Try programiz.pro");
    void (*callback)();
    callback=fun(10);
    callback();
    return 0;
}
