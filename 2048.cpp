#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>

main()
{

char location[4][4];
char move;
char entershit;

int row,column,random,temp;

time_t t;
srand( time(&t));

printf("*****  *****     *   *****\n");
printf("    *  *   *    **   *   *\n");
printf("*****  *   *   * *   *****\n");
printf("*      *   *  *****  *   *\n");
printf("*****  *****     *   *****\n");

printf("\nUSE W,A,S,D  for keys\n");

for(row=0;row<4;row++)
  for(column=0;column<4;column++)
    location[row][column]=0;

for(row=0;row<4;row++)
{
  for(column=0;column<4;column++)
  {
    random=rand()%2;
    if(random==1)
      location[row][column]=random*2;
  }
}	

for(row=0;row<4;row++)
{
  for(column=0;column<4;column++)
    printf("    %d    ",location[row][column]);
  printf("\n\n\n\n");
}

while(1)
{
  scanf("%c%c",&move,&entershit);
	
	for(temp=0;temp<10;temp++)
	   printf("\n");
	
  if(move='w');
  { 
    for(column=0;column<4;column++)
    {
      for(row=0;row<3;row++)
      {
        if(location[row][column]==location[row+1][column] && location[row][column]!= 0)
        {
          location[row][column]=location[row+1][column]*2 ;
          location[row+1][column]=0;
        }
        if(location[row][column]==0)
        {
          location[row][column]=location[row+1][column];
          location[row+1][column]=0;
        }
      }
    }
  }
    
  /*if (move='s')
  {
    for(column=0;column<4;column++)
    {
      for(row=3;row>0;row--)
      {
        if(location[row][column]==location[row-1][column] && location[row][column]!=0)
        {
          location[row][column]=location[row][column]*2 ;
          location[row-1][column]=0;
        }
        if(location[row][column]==0)
        {
          location[row][column]=location[row-1][column];
          location[row-1][column]=0;
        }
      }
    }
  }
  
  if (move='d')
  {
    for(column=0;column<3;column++)
    {
      for(row=0;row<4;row++)
      {
        if(location[row][column]==location[row][column+1] && location[row][column]!=0)
        {
          location[row][column]=location[row][column]*2 ;
          location[row][column+1]=0;
        }
        if(location[row][column]==0)
        {
          location[row][column]=location[row][column+1];
          location[row][column+1]=0;
        }
      }
    }
  }
  
  if (move='a')
	{
    for(column=3;column<0;column++)
    {
      for(row=0;row<4;row++)
      {
        if(location[row][column]==location[row][column-1] && location[row][column]!=0)
        {
          location[row][column]=location[row][column]*2 ;
          location[row][column-1]=0;
        }
        if(location[row][column]==0)
        {
          location[row][column]=location[row][column-1];
          location[row][column-1]=0;
        }
      }
    }
  }
	
  srand( time(&t));

 for(row=0;row<4;row++)
  {
    for(column=0;column<4;column++)
    {
      if(location[row][column]==0)
      {
        random=rand()%2;
        if(random==1)
        {
          location[row][column]=random*2;
          break;
        }
      }
    }
    if(random==1)
    break;
  }*/

  for(row=0;row<4;row++)
  {
    for(column=0;column<4;column++)
      printf("    %d    ",location[row][column]);
    printf("\n\n\n\n");
  }

  for(row=0;row<4;row++)
  {
    for(column=0;column<4;column++)
    {
      if(location[row][column]==2048)
      {
        printf("\n you have won the game \n");
        break;
      }
    }
  }
}

getch();
}

