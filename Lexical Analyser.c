#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
bool isValidDelimiter(char ch){
	if(ch==' '||ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch==','||ch==';'||
	ch=='>'||ch=='<'||ch=='('||ch==')'||ch=='['||ch==']'||ch=='{'
	||ch=='}')
	return true;
	return false;
}
bool isValidOperator(char ch){
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='>'||ch=='<'||ch=='=')
	return true;
	return false;
}
bool isValidIdentifier(char*str){
	if(str[0]=='0'||str[0]=='1'||str[0]=='2'||str[0]=='3'||str[0]=='4'
	||str[0]=='5'||str[0]=='6'||str[0]=='7'||str[0]=='8'||str[0]=='9'
	||isValidDelimiter(str[0])==true)
	return false;
	return true;
}
bool isValidKeyword(char*str){
	if(!strcmp(str,"if")||!strcmp(str,"else")||!strcmp(str,"do")||!strcmp
	(str,"while")||!strcmp(str,"goto")||!strcmp(str,"break")||!strcmp(str,
	"continue")||!strcmp(str,"case")||!strcmp(str,"int")||!strcmp(str,"float")||
	!strcmp(str,"long")||!strcmp(str,"double")||!strcmp(str,"return")||!strcmp
	(str,"sizeof")||!strcmp(str,"return")||!strcmp(str,"short")||!strcmp(str,"typedef")
	||!strcmp(str,"unsigned")||!strcmp(str,"void")||!strcmp(str,"static")||!strcmp
	(str,"switch")||!strcmp(str,"struct"))
	return true;
	return false;
}
bool isValidInteger(char*str){
	int i,len=strlen(str);
	if(len==0) return false;
	for(i=0;i<len;i++){
		if(str[i]!='0'&&str[i]!='1'&&str[i]!='2'&&str[i]!='3'&&str[i]!='4'&&str[i]!='5'&&
		str[i]!='6'&&str[i]!='7'&&str[i]!='8'&&str[i]!='9'||(str[i]=='-'&&i>0))
		return false;
	}
	return true;
}
bool isRealNumber(char*str){
	int i,len=strlen(str);
	bool hasDecimal=false;
	for(i=0;i<len;i++){
	if(str[i]!='0'&&str[i]!='1'&&str[i]!='2'&&str[i]!='3'&&str[i]!='4'&&str[i]!='5'&&
		str[i]!='6'&&str[i]!='7'&&str[i]!='8'&&str[i]!='9'&&str[i]=='.'||(str[i]=='-'&&i>0))
		return false;
		if(str[i]=='.')
		hasDecimal=true;	
	}
	return hasDecimal;
}
char*subString(char*str,int left,int right){
	int i;
	char*substr=(char*)malloc(sizeof(char)*(right-left+2));
	for(i=left;i<=right;i++)
	substr[i-left]=str[i];
	substr[right-left+1]='\0';
	return substr;
}
void detectTokens(char*str){
	int left=0,right=0;
	int length=strlen(str);
	while(right<=length&&left<=right){
		if(isValidDelimiter(str[right])==false)
		right++;
		if(isValidDelimiter(str[right])==true&&left==right){
			if(isValidOperator(str[right])==true)
			printf("valid operator : '%c'\n",str[right]);
			right++;
			left=right;
		}
		else if(isValidDelimiter(str[right])==true&&left!=right||(right==length&&
		left!=right)){
			char*substr=subString(str,left,right-1);
			if(isValidKeyword(substr)==true)
			printf("valid keyword : '%s'\n",substr);
			else if(isValidInteger(substr)==true)
			printf("valid Integer : '%s'\n",substr);
			else if(isRealNumber(substr)==true)
			printf("Real Number : '%s'\n",substr);
			else if(isValidIdentifier(substr)==true&&isValidDelimiter(str[right-1])==false)
			printf("valid Identifier : '%s'\n",substr);
			else if(isValidIdentifier(substr)==false&&isValidDelimiter(str[right-1])==false)
			printf("Invalid Identifier : '%s'\n",substr);
			left=right;
		}
	}
	return;
}
int main(){
	char str[100]="float x=a+1b;";
	printf("The Program is : '%s'\n",str);
	printf("All Tokens are : \n");
	detectTokens(str);
	return 0;
}
