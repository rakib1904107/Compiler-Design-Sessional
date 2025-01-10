#include<bits/stdc++.h>
using namespace std;

bool isFunction(char arr[],int pos){
    if(arr[pos+1]=='(')return 1;
    else return 0;
}

bool isOperator(string s)
{
    string ops[6]={"=","+","-","*","/"};
    for(auto it:ops){
        if(it==s)return 1;
    }
    return 0;
}
bool isNumber(string s)
{
    for(auto it:s){
        if((it>='0'&&it<='9')) continue;
        return false;
    }
    return true;
}

bool isVariable(string s,char arr[],int pos)
{
    string temp="";
    temp+=arr[pos];
    if(arr[pos]==')'||isOperator(temp)||arr[pos]==','||(arr[pos]==';'&&!isNumber(s)))return 1;
    else return 0;
}
bool isKeyword(string s)
{
    string keyword[4]={"int","bool","return"};
    for(auto it:keyword){
        if(it==s)return 1;
    }
    return 0;
}


bool isOther(string s){
    string others[]={"{","}",",",";"};
    for(auto it:others){
        if(it==s)return 1;
    }
    return 0;
}
int main()
{
    FILE *ptr;
    ptr=fopen("input.txt","r");

    set<string>func,op,var,key,oth;
    char arr[1000];

    while(fgets(arr,1000,ptr)){
        string curr="";
        for(int i=0;arr[i+1]!='\0';i++){
            if(arr[i]==' '||arr[i]=='('||arr[i]==')')continue;

            curr+=arr[i];

            if(isFunction(arr,i)){
                func.insert(curr);
                curr="";
            }
            else if(isOperator(curr)){
                op.insert(curr);
                curr="";
            }
            else if(isVariable(curr,arr,i+1)){
                var.insert(curr);
                curr="";
            }
            else if(isKeyword(curr)){
                key.insert(curr);
                curr="";
            }
            else if (isNumber(curr)){
                while((arr[i]!='\0')&&isNumber(curr)){
                    i++;
                    string temp = "";
                    temp+=arr[i];
                    if(isNumber(temp))curr+=arr[i];
                    else break;
                }
                i--;
                oth.insert(curr);
                curr = "";
            }
            else if(isOther(curr)){
                oth.insert(curr);
                curr="";
            }
        }
    }

    cout<<"Functions: ";
    for(auto it:func)cout<<it<<"() ";
    cout<<endl;

    cout<<"Operator:";
    for(auto it:op)cout<<it<<" ";
    cout<<endl;

    cout<<"Variable:";
    for(auto it:var)cout<<it<<" ";
    cout<<endl;

    cout<<"Keyword:";
    for(auto it:key)cout<<it<<" ";
    cout<<endl;

    cout<<"Others:";
    for(auto it:oth)cout<<it<<" ";
    cout<<endl;
}

