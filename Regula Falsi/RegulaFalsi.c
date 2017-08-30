#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) ((x*x)-36)
int main(){
float a=0,b=0,error=0,c,c_old,tol_error;
int i=0;
printf("Error limit: ");
scanf("%f",&tol_error);
printf("Input Interval (Base): ");
scanf("%f",&a);
printf("Input Interval (Upper): ");
scanf("%f",&b);

if((f(a)*f(b))>0){
        printf("Oops! The root doesn't lie in this interval.");
        exit(1);
}

else if(f(a)==0 || f(b)==0){
        printf("Haha! That was easy! One of the bound is Root: %f\n",f(a)==0?a:b);
        exit(0);
}

printf("i\ta\t\tb\t\tc\t\tf(c)\t\terror\n");
do{
        c_old=c;
        c=(((a*f(b))-(b*f(a)))/(f(b)-f(a)));
        printf("%2d\t%4.6f\t%4.6f\t%4.6f\t%4.6f\t",i++,a,b,c,f(c));
        if(f(c)==0){
                break;
        }else if(f(a)*f(c)<0){
                b=c;
        }else a=c;
                error=fabs(c-c_old);
        if(i==1){
                printf("----\n");
        }else printf("%4.6f\n",error);
}while(error>tol_error);

printf(" Yay! I got it. The Root is %4.6f \n",c);
return 0;
}