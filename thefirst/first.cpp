// lexical Analysis          //First phase

#include<bits/stdc++.h>

using namespace std;

int isconstant(char arr[]){

                     int y=0;
                   for(int k=0;k<sizeof(arr);k++){
                    if(arr[0]=='1'||arr[0]=='2'||arr[0]=='3'||arr[0]=='4'||arr[0]=='5'
                       ||arr[0]=='6'||arr[0]=='7'||arr[0]=='8'||arr[0]=='9'||arr[0]=='0'){ y=1;}
                   }
                   return y;
}


int isdecimal (char arr[]){
                   int y=0;
                   for(int k=0;k<sizeof(arr);k++){
                    if(arr[k]=='.'){ y=1; break;}
                   }
                   return y;
}

int isKeyword(char arr[]){
    char keywords[41][10] = {"iostream","include","namespace","std","using","return",
                           "auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","new","main",
                            "unsigned","void","volatile","while","int","cout","cin"};


    int i, flag = 0;

    for(i = 0; i < 41; ++i){
        if(strcmp(keywords[i], arr) == 0){
            flag = 1;
            break;
        }
    }

    return flag;
}

int main(){

vector<string>keys;
vector<string>identifiers;
vector<string>constants;
vector<char> specialcharacters;
vector<char>operators;
map<char,int>mp1;
map<string,int>mp2;

    char ch, arr[20], opt[] = "+-*/%=",numbers[]="1234567890.";
    ifstream fin("my_input.txt");
    int i,j=0;

    if(!fin.is_open()){
        cout<<"error can not open the file\n";
        exit(0);
    }

    while(!fin.eof()){
           ch = fin.get();
        for(i = 0; i < 6; ++i){
               if(ch == opt[i])
                   {if(mp1[ch]==0){
                       operators.push_back(ch);
                       mp1[ch]++;
                   }

                   }
           }


int count=0;
           if(isalnum(ch)||ch=='.'){
               arr[j++] = ch;
           }

           else if(ch==';'||ch=='#'||ch=='('||ch==')'||ch=='!'||ch=='}'||ch=='{'||ch=='<'||ch=='>')
           {
              if(mp1[ch]==0){
                 specialcharacters.push_back(ch);
                 mp1[ch]++;
              }


           }


                  else if((ch == ' ' || ch == '\n') && (j != 0)){
                   arr[j] = '\0'; count =j;
                   j = 0;

                   if(isKeyword(arr) == 1 ){ if(mp2[arr]==0){
                    keys.push_back(arr); mp2[arr]++;
                   } }

           else if(isconstant(arr)) {if(mp2[arr]==0){
            constants.push_back(arr);
           }}

                   else{
                        string id="",num=""; int c1=0,c2=0,p1=-1,p2=-1;

                   for(int o=0;o<sizeof(arr);o++){
                    if(arr[o]>='a'&&arr[o]<'z'){
                       id+=arr[o];

                    }
                    else if(arr[o]==' ' ) break;
                    else { p2=o; p1=count-o;break;}
                   }

                   if(id.size()>=1){

                    if(isKeyword(arr) == 1 )
                      {
                          if(mp2[arr]==0){
                    keys.push_back(id); mp2[id]++;
                   }
                      }

             else { if(mp2[id]==0){

                    identifiers.push_back(id); mp2[id]++;
                   }}
                   string g="";
             if(p1>0){ for(int u=p2;u<sizeof(arr);u++) { if(arr[u]=='1'||arr[u]=='2'||arr[u]=='3'
    ||arr[u]=='4'||arr[u]=='5'||arr[u]=='6'||arr[u]=='7'||arr[u]=='8'||arr[u]=='9'
    |arr[u]=='0'||arr[u]=='.'){
    g+=arr[u];
    }
    else break;
    }
if(g.size()&&mp2[g]==0){

            constants.push_back(g);
           }


                   }



                    for(int k=0;k<sizeof(arr);k++){
                    if(arr[k]=='1'||arr[k]=='2'||arr[k]=='3'||arr[k]=='4'||arr[k]=='5'
                       ||arr[k]=='6'||arr[k]=='7'||arr[k]=='8'||arr[k]=='9'||arr[k]=='0'||arr[k]=='.'){num+=arr[k];}
                       else break;
                   }

                   if(num.size()>=1){
                    {if(mp2[arr]==0){
            constants.push_back(arr);
           }
                   }

           }

    }}}}

    fin.close();
cout<<"Keywords ( ";
   for(int i=0;i<keys.size() ; i++) {if(i!=keys.size()-1)cout<<keys[i]<<" , "; else cout<<keys[i]<<" ) \n\n";}
cout<<"Identifiers ( ";
   for(int i=0;i<identifiers.size() ; i++) {if(i!=identifiers.size()-1)cout<<identifiers[i]<<" , "; else cout<<identifiers[i]<<" ) \n\n";}
cout<<"Operators ( ";
   for(int i=0;i<operators.size() ; i++) {if(i!=operators.size()-1)cout<<operators[i]<<" , "; else cout<<operators[i]<<" ) \n\n";}
cout<<"Numeric Constants ( ";
   for(int i=0;i<constants.size() ; i++) {if(i!=constants.size()-1)cout<<constants[i]<<" , "; else cout<<constants[i]<<" ) \n\n";}
cout<<"Special Characters ( ";
   for(int i=0;i<specialcharacters.size() ; i++) {if(i!=specialcharacters.size()-1)cout<<specialcharacters[i]<<" , "; else cout<<specialcharacters[i]<<" ) \n\n";}

}

