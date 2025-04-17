#include <stdio.h>

void add(int ra, int ca, int a[ra][ca], int b[ra][ca]);
void sub(int ra, int ca, int a[ra][ca], int b[ra][ca]);
void multi(int ra, int ca, int rb, int cb, int a[ra][ca], int b[rb][cb]);

int main() {
//	int a[3][3]={{10,5,11},{22,3,2},{5,0,2}};
//	int b[3][3]={{9,3,2},{0,5,1},{3,0,1}};
    int ra,ca,rb,cb;
    printf("Enter row of A matrix:");
    scanf("%d",&ra);
    printf("Enter column of A matrix:");
    scanf("%d",&ca);
    printf("Enter row of B matrix:");
    scanf("%d",&rb);
    printf("Enter column of B matrix:");
    scanf("%d",&cb);


	int a[ra][ca], b[rb][cb];

	printf("Enter the value of A matrix(%d*%d).\n",ra,ca);

	for(int i=0;i<ra;i++){
        for(int j=0;j<ca;j++){
            printf("Enter [%d][%d] :",i,j);
            scanf("%d",&a[i][j]);
        }
	}
	printf("Enter the value of B matrix(%d*%d).\n",rb,cb);

	for(int i=0;i<rb;i++){
        for(int j=0;j<cb;j++){
            printf("Enter [%d][%d] :",i,j);
            scanf("%d",&b[i][j]);
        }
	}

	printf("\n1.Addition.\n2.Substraction.\n3.Multiplication.\n4.Exit.\n");


while(1){
        int n;
    printf("Choose operation :");

	scanf("%d",&n);
    switch(n){
    case 1:
        if(ra==rb && ca==cb){
        add(ra,ca,a,b);
        }else{
            printf("\nAddition is not possible.\n Please try again.\n");

        }
	break;

	case 2:
	    if(ra==rb && ca==cb){
       sub(ra, ca, a, b);

	    }else{
	        printf("\nSubstruction is not possible .\nPlease try again.\n");
	    }

	break;

	case 3:
    if(ca == rb){
        multi(ra,ca,rb,cb,a,b);

    } else {
        printf("\nMultiplication is not possible.\nPlease try again.\n");
    }
    break;

    case 4:
        printf("\nThanks for using the program.\n");
        return 0;

    default:

        printf("\nInvalid choice, please try again.\n");


    }

}


}

void add(int ra, int ca, int a[ra][ca], int b[ra][ca]){
    printf("A+B\n\n");
	for(int i=0;i<ra;i++){
        for(int j=0;j<ca;j++){
            printf("%d ",a[i][j] + b[i][j]);
        }printf("\n");
	}
}
void sub(int ra, int ca, int a[ra][ca], int b[ra][ca]) {
    printf("\nA - B\n\n");
    for(int i = 0; i < ra; i++) {
        for(int j = 0; j < ca; j++) {
            printf("%d ", a[i][j] - b[i][j]);
        }
        printf("\n");
    }
}

void multi(int ra, int ca, int rb, int cb, int a[ra][ca], int b[rb][cb]){
    printf("\nA * B\n\n");

        int result[ra][cb];


        for(int i = 0; i < ra; i++){
            for(int j = 0; j < cb; j++){
                result[i][j] = 0;
            }
        }


        for(int i = 0; i < ra; i++){
            for(int j = 0; j < cb; j++){
                for(int k = 0; k < ca; k++){
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }


        for(int i = 0; i < ra; i++){
            for(int j = 0; j < cb; j++){
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
}


