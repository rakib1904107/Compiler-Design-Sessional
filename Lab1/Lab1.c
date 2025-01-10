#include<stdio.h>
#include<stdlib.h>

int IsSpecialCharacter(char ch)
{
	if(ch>='a'&&ch<='z')return 0;
	if(ch>='A'&&ch<='Z')return 0;
	if(ch>='0'&&ch<='9')return 0;
	return 1;
}
int main()
{
    FILE *ptr;
    ptr=fopen("input.txt","r");
    char s[100];
    int x=0,y=0,z=0;
    while(fgets(s,100,ptr)){

        //printf("%s",s);
        for(int i=0;s[i+1]!='\0';i++){
            if(s[i]==' '){
                x=1;
                continue;
            }
			if (IsSpecialCharacter(s[i])==0){
                if(x&&z==0)printf("\n");
				printf("%c",s[i]);
                x=0,y=1,z=0;
			}
			else{
                if(y)printf("\n");
				printf("%c\n",s[i]);
                x=0,y=0,z=1;
			}
		}
    }
}
