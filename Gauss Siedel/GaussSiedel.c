#include <stdio.h>

int main(void){

	float a[100][100], b[100], y[100];
	float x[100];
	int n,i,j,p,sum=0;
	printf("Enter the size of 2D array:");
	scanf("%d",&n);
	printf("%d\n", n);

	for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter values no :( %d , %d )\n", i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }

    //diagonally dominant
    for(i=0;i<n;i++){
    	sum=0;
    	for(j=0;j<n;j++){
    		if(i==j)
    			continue;
    		sum+=a[i][j];
    	}
    	if(a[i][i]<sum){
    		printf("Ye Gauss-Seidel se na ho payega!\n");
    		return 0;
    	}
    }

    printf("\nEnter Values to the right side of equation\n");
    for (i = 0; i < n; i++)
    {
    	printf("Enter values no :( %d , %d )\n",i+1,j);
        scanf("%f",&b[i]);
    }

    printf("\nEnter initial values of x\n");
    for (i = 0; i < n; i++)
    {
    	printf("Enter values no. %d :", i+1);
    	scanf("%f",&x[i]);
    }

    printf("Enter the no of iterations0n");
    scanf("%d",&p);
    while(p>0){
    	for (i = 0; i < n; i++)
        {
            y[i] = (b[i] / a[i][i]);
            for (j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
            }
            printf("x%d = %f    ", i + 1, y[i]);
        }
        printf("\n");
        p--;

    }

    return 0;

}