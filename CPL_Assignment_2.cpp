#include<stdio.h>
#include<string.h>
#define SIZE 310
//#define PLUSE 1
//#define MINUS -1


typedef struct bigint_tag 
{
    char digits[SIZE];
    int Sign_Bit;
    int last_digit;
    
}Big_int;

void Initialise_big_int(Big_int *num)
{
    num->digits[SIZE-1]='\0';
    num->last_digit=SIZE-1;
}

void  string_to_big_int(char no_1[], Big_int *num)
{
    int i,j,l,z=0;
    
    if(no_1[0]=='-')
    {
        num->Sign_Bit=-1;
        z=1;
    }
    else
    {
		num->Sign_Bit=1;
		
    	l=strlen(no_1);
    	
    	j=SIZE-1;
    	num->digits[SIZE-1]='\0';
    	
    	for(i=l-1;i>=z;i--)
    	{
        	j--;
        	num->digits[j]=no_1[i];
    	}
    
    	num->last_digit=j;
	}

}

void Print_Big_int(Big_int num)
{
    int i;
    int f=0;
    
    for(i=num.last_digit;i<=SIZE-2;i++)
    {
        if(num.digits[i]!='0')                  //Prints the big_int
        {
            f=1;
            break;
        }
    }
    
    if(f==0)
    {
    	num.Sign_Bit=1;
	}
    
    if(num.Sign_Bit==-1)
    {
        printf("-");
    }

    for(i=num.last_digit;i<=SIZE-2;i++)
    {
        printf("%c",num.digits[i]);
    }
}





int main()
{	
	Big_int num_1,num_2,add,sub,mult;
	char no_1[SIZE] ,no_2[SIZE];
	
	printf("\n\t\t\t----------------------------------------------------------------------------\n");
	printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############   Representation of Bigint in C                   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n\n");
    
    printf("Enter the First Number  : ");
    scanf("%s",no_1);
    

    printf("Enter the Second Number : ");
    scanf("%s",no_2);
    
    
	Initialise_big_int(&num_1);
    Initialise_big_int(&num_2);
    Initialise_big_int(&add);
    Initialise_big_int(&sub);
    Initialise_big_int(&mult);
    
    string_to_big_int(no_1,&num_1);
    string_to_big_int(no_2,&num_2);
    
    
	printf("\n\n");
    Print_Big_int(num_1);
    printf("  +  ");
    Print_Big_int(num_2);
    //ans1=Add(num1,num2);
    printf("  =  ");
    //Print_Big_int(ans1);

  	return 0;
}
