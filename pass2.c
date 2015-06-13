#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void hexa2binary(char str[]);
void binary(char str[]);
main()
{ 
char operands[33][10]={"movei","move","laxi","out","in","loada","storea","sum","sumi","diff","diffi","incr",
"decr","incx","decx","anda","andi","or","ori","xor","xori","compr","compri","termt","nope","jump","jumpz","jumpnz","jumpc",
"jumpnc","call","return"};
char registers[15][5]={"a","flag","b","c","d","e","f","g","h","i","j","sp","pc","m"};
char opropcode[33][9]={"00100000","00100001","00100010","00100011","00100100","00100101","00100110","00100111","00101000","00101001","00110000","00110001","00110010","00110011","00110100",
"00110101","00110110","00110111","00111000","00111001","00111010","00111011","00111100","00111101","00111110","00111111","01000000","01000001","01000010","01000011",
"01000100","01000101"};

char regopcode[15][5]={"0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1110","1101"};
char str[16],str1[16],str2[10],str3[16],str4[16],str5[16];
FILE *fr,*fw,*fs;
int i,j,k,length,b,c,o,jum=0;
char ch;;
char a[10];
fr = fopen("code.txt","r");
fw = fopen("output.txt","w");
fs= fopen("symboltable.txt","r");
while(!(feof(fr)))
{	
	i=0;k=0;
	fscanf(fr,"%s",str);
	for(j=0;j<33;j++)
	{
		//printf("%s",operands[j]);
		if(!(strcmp(operands[j],str)))
		{
			if(!(feof(fr))){
			if(j==0||j==2||j==7||j==9||j==11||j==12||j==13||j==14||j==15||j==21)
				fprintf(fw,"0000");
			if(j==5||j==6||j==23||j==24||j==30||j==31)
				fprintf(fw,"00000000");
			if(j==25||j==26||j==27||j==28||j==29)
				jum=1;
			}
			if(!(feof(fr)))
			fprintf(fw,"%s",opropcode[j]);
			k=1;
			
			break; 
		}
	}
	for(o=0;o<15;o++)
	{
		if(!(strcmp(registers[o],str)))
		{
			if(!(feof(fr)))
			fprintf(fw,"%s",regopcode[o]);
			k=1;
			
			break;
		}
	}
	while(1)
	{
		fscanf(fs,"%s",str2);	
		fscanf(fs,"%s",str3);
		if(!strcmp(str,str2))
            	{
			binary(str3);
			if(jum==1){
			if(!(feof(fr)))
                	fprintf(fw,"%s",str3);
			k=1;jum=0;
               		 break;
			}k=1;
            	}
            	if (feof(fs))
     		{
			
			fseek(fs,0,0);
			break;
		}
	}
	if(str[4]=='h')
	{
		str[4]='\0';
		fprintf(fw,"\n");
		hexa2binary(str);
	}

	
	if(str[0]==':'||str[0]==';'||str[0]==',')
		k=1;
	
		if(k==0)
			if(!(feof(fr)))
			fprintf(fw,"%s",str);
	
	
	
	if(str[0]==';'||str[0]==':')
		fprintf(fw,"\n");
	if (feof(fr))
     			break;
}
}

void hexa2binary(char str[])
{
	char s[16];int i=0;
	strcpy(s,str);
	str[0]='\0';
	for(i=0;s[i]!='\0';i++)   
	{                 
	switch(s[i])           
	 {             
		case '0':             
		 strcat(str,"0000");              
		break;            
		 case '1':              
		strcat(str,"0001");              
		break;            
 		case '2':              
		strcat(str,"0010");             
		 break;             
		case '3':              
		strcat(str,"0011");             
		 break;            
		 case '4':              
		strcat(str,"0100");             
		 break;             
		case '5':             
 		strcat(str,"0101");              
		break;            
		 case '6':              
		strcat(str,"0110");              
		break;             
		case '7':              
		strcat(str,"0111");              
		break;             
		case '8':              
		strcat(str,"1000");             
		 break;             
		case '9':              
		strcat(str,"1001");              
		break;             
		case 'a':             
		case 'A':             
		 strcat(str,"1010");              
		break;             
		case 'b':             
		case 'B':             
		 strcat(str,"1011");              
		break;             
		case 'c':             
		case 'C':              
		strcat(str,"1100");              
		break;            
		 case 'd':            
		 case 'D':              
		strcat(str,"1101");             
		 break;             
		case 'e':             
		case 'E':             
		 strcat(str,"1110");             
		 break;            
		 case 'f':             
		case 'F':              
		strcat(str,"1111");             
		 break;             
		default:              
		printf("Entered number is not Hexadecimal.Printed value is not correct.");             
		 break;           
	}
	}
} 

void binary(char str[])
{
	int n=atoi(str); //printf("\n%d  %s",n,str);
	int c, k;
	int i=0;
  for (c = 7; c >= 0; c--)
  {
    k = n >> c;
 
    if (k & 1)
     {
	str[i]='1';i++;
	}
    else
      {
	str[i]='0';i++;	
	}
  }
 str[i]='\0';
  //printf("\n%s",str);
 

}



