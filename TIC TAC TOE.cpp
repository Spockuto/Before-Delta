#include<stdio.h>
#include<conio.h>
char xo[3][3]={'_','_','_','_','_','_','_','_','_'};
main()
{
	
int i,j,x;
int a,b;
printf("lets play XO\n");
printf("Gaming Instruction:\n");
printf("1.Game starts with X..\n2.Enter Row(0,1,2) And Coulmn(0,1,2)\n3.Game is drawn only when all moves are done (no predictions)\nSTART\n");
for(x=0;x<9;x++)
{
	scanf("%d%d",&i,&j);
	
	if(x%2==0)
	xo[i][j]='X';
	else
	xo[i][j]='O';
	printf("\n");
	
	for(a=0;a<3;a++)
   {for(b=0;b<3;b++)
	printf(" %c ",xo[a][b]);
	printf("\n");}
      
if(xo[i%3][j%3]==xo[(i+1)%3][j%3]&&xo[i%3][j%3]==xo[(i+2)%3][j%3]) 
{printf("\nthe game has been won by %c",xo[i][j]);
break;}

else if((xo[i%3][j%3]==xo[i%3][(j+1)%3])&&(xo[i%3][j%3]==xo[i%3][(j+2)%3]))   
{printf("\nthe game has been won by %c",xo[i][j]);
break;}

else if(i==j)
{if ((xo[i%3][j%3]==xo[(i+1)%3][(j+1)%3])&&(xo[i%3][j%3]==xo[(i+2)%3][(j+2)%3])) 
{printf("\nthe game has been won by %c",xo[i][j]);
break;}} 

else if(xo[i][j]==xo[1][1]&&xo[i][j]==xo[0][2]&&xo[i][j]==xo[2][0])
{printf("\nthe game has been won by %c",xo[i][j]);
break;}

else if (x==8)
{printf("\nthe game has been drawn");}
}
printf("\nthanks for playing");
getch();

}
