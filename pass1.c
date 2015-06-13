#include<stdio.h>
#include<string.h>
void main()
{
	FILE *fr,*fw;char input[30],output[40]="symboltable.txt";
	printf("Please enter the file name: ");
	gets(input);
	
	fr =  fopen(input,"r");
	fw = fopen (output,"w");
	char a[50];
	char ch;int line=1,i=0;
	
	while(1)
	{
		ch=fgetc(fr);
		if(ch==EOF)
			break;
		else
		{
			if(ch==10)
			{
				i=0;line++;
			}
			a[i]=ch;i++;
			if(ch==':')
			{
				i--;
				a[i]='\0';
				i=0;
				fprintf(fw,"%s %d\n",a,line);
			}
		}
	}
	fclose(fr);
	fclose(fw);
}

	
