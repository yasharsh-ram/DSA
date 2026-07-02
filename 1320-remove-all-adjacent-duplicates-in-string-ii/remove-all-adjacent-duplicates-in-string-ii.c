typedef struct{
    char ch;
    int count;
}pair;

char* removeDuplicates(char* s, int k) {
    int n=strlen(s);
    char* ans=(char*)malloc((n+1)*sizeof(char));
    int idx=0;
    pair stack[100000];
    int top=-1;
    for(int i=0;s[i]!='\0';i++){
        if(top==-1||stack[top].ch!=s[i] ){
            top++;
            stack[top].ch=s[i];
            stack[top].count=1;
        }else{
            stack[top].count++;
            if(stack[top].count==k){
                top--;
            }
        }
    }
    for(int i=0;i<=top;i++){
        for(int j=0;j<stack[i].count;j++){
        ans[idx++]=stack[i].ch;
    }
    }
    ans[idx]='\0';
    return ans;
    
}