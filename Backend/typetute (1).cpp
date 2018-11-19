#include <iostream>
#include <fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include <cstring>
#include<stdio.h>
using namespace std;
int main() {
	cout<<"Content-type:text/html\n\n";
    char para_char,user_char;
	float accuracy;
	int line=1,index=1,errors=0,count=0;
	char* file=getenv("QUERY_STRING");
	string file_name=strcat(file,".txt");
    ifstream paragraph(file_name.c_str());
	ifstream userinput("input.txt");
    if (!paragraph) {
        cout << "Unable to open paragraph file";
		getchar();
        exit(1);
    }
    if (!userinput) {
        cout << "Unable to open user input file";
		getchar();
        exit(1);
    }
cout<<"<html><font size=\"4\"><br><center><h1>Paragraph<br></h1></center><hr><div style=\"background-color:orange;\"><pre>"<<endl;    
while(paragraph.get(para_char))   
	cout<<para_char;
cout<<endl<<"</div><hr><br><br><center><h1>Your Input</h1></center><br><hr><div style=\"background-color:chartreuse;\">"<<endl;



userinput.clear();
userinput.seekg(0,ios::beg);
paragraph.clear();
paragraph.seekg(0,ios::beg);
 cout<<"<pre>";
   while(paragraph.get(para_char)&&userinput.get(user_char)) 
   {    
   
        	if(user_char=='\n')
			{line++;
			userinput.get(user_char);}

	
        if(para_char=='\n')
			paragraph.get(para_char);
        	

	
       
		if(user_char!=para_char)
		{
			errors++;
		//	printf("<br><mark>%c</mark>",user_char);
		cout<<"<span style=\"background-color: #FF0000\">"<<user_char;
		//	cout<<"ERROR:"<<errors<<endl<<"	Line:"<<line<<endl<<"	Index:"<<index<<endl<<"	Should be:"<<para_char<<endl<<"	But is:"<<user_char<<endl;

		
		
		}
		else
		cout<<user_char;
		index++;
		count++;
		cout<<"</span>";

   }
   cout<<"</font></pre></div><hr>";
   cout<<"Red highlights are your errors";
   cout<<endl<<"<br><br>Total errors= "<<errors<<endl<<"Out of "<<count<<" characters"<<endl;
   accuracy=(1.0-(float)errors/(float)count)*100.0;
   cout<<"<br>Accuracy= "<<accuracy<<"%";
    cout<<"<br><h1><center>Thankyou</center></h1></html>";
    paragraph.close();
	userinput.close();
   
    getchar();
    return 0;
}












