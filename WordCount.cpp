#include <iostream>
#include<string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int getChar(FILE *F)
{
	char ch;
	int num=0;
	while((ch=fgetc(F))!=EOF)
	{
		num++;
	}
	rewind(F);
	return num;
}

int getWord(FILE *F)
{
	int num=0;
	int a=0,b=0;
	int flag=0;  
	char word;
	word = fgetc(F);
	
	while(feof(F)==0)
    {
        if(flag == 0 && (word == ' ' || word == ','))
		{
			 num++;
             flag = 1;
             a++;
        }
        else if(flag == 1 && (word == ' ' || word == ','))
        {
        	
		}
		else if(flag == 1 && (word != ' ' && word != ','))
		{
			flag=0;
		}
		word = fgetc(F);
    }
    if(flag==1){
    	num=num;
	}else{
		num=num+1;
	}
	rewind(F);
	return num;
}

int main(int argc, char** argv) {
	FILE *F;
	int num;
	
	if(argc==3){
    	
		F = fopen(argv[2],"r");        
		  
	       if(!strcmp(argv[1],"-c"))	
			{
		        num = getChar(F);
		     	printf("Number of letters:%d\n",num);
		    }
		
		   else if(!strcmp(argv[1],"-w"))
			{
			    num = getWord(F);
			    printf("Number of words:%d\n",num); 
			}
           
	}
	return 0;
}
