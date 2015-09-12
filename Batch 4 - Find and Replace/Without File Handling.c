#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
main()
{
	int i,j,k=0,x,y,z; 
	char input[100],find[100],replace[100] ;
	int yn , temp=0 , loc[100] , temploc=0 ;	
	printf("Enter the String:");
	gets(input);
	printf("\nEnter the find string:");
	gets(find);
	printf("\n enter the replace string: ");
	gets(replace);
	x=strlen(input);
	y=strlen(find);
    z=strlen(replace);
    
    
	// the part for finding the string
	
	for(i=0;i<x;i++)
	{  if(input[i]==find[k]) // checking for equality of input and find
		{    if(k==0)
		     j=i;
			 if(k==y-1)
			 {printf("Found at %d\n",j+1); // if condition met displaying position
		      loc[temploc] = j ;
		      temploc++ ;}
		      
			 k++;      }
		else
		k=0;}
			printf("%d,%d,%d",x,y,z);
	// the part for replacing the string 
	
	printf("\ndo you want to replace \n enter 1 for yes \n enter 2 for no \n");
	scanf("%d",&yn);
  
	if(yn==1)                 // for executing replace
	{   
	for(i=0;i<temploc;i++)    // for loop for replacing n times
	{   
	if(z>y)                   // if replace string is greater than find string
	{
		loc[i]= loc[i] + i*(z-y);
	for(j=x-1;j>=loc[i];j--)   // for creating space for the replace characters
	input[j+z-y]=input[j]	;
	for(j=loc[i];j<loc[i]+z;j++) // replacing the characters
	{input[j]=replace[temp] ;
	temp++;}
	 x=(x+z-y);
	}
    else if (z<y)                    // replace string is small or equal than find string
    {
    	loc[i]= loc[i] - i*(y-z);
	for(j=loc[i];j<loc[i]+z;j++)  // replacing the characters
	{input[j]=replace[temp] ; 
	temp++;
    }
    for(j=loc[i]+z;j<x+z-y;j++)  // removing the remenent of unwanted find string
	{input[j]=input[j+y-z]	;
	input[j+y-z]='\0';}
	
	x=x+y-z;
	}
    else                        // replace string is small or equal than find string
    {
    	loc[i]= loc[i] - i*(y-z);
	for(j=loc[i];j<loc[i]+z;j++)  // replacing the characters
	{input[j]=replace[temp] ; 
	temp++;
    }
    for(j=loc[i]+z;j<x+z-y;j++)  // removing the remenent of unwanted find string
	input[j]=input[j+y-z]	;
	
	x=x+y-z;
	}
	temp=0;
	}}
	else                          // if input is no
	printf("thanks for using");
	
	printf("\n%s",input);     // printing the replaced string
		getch();
}

