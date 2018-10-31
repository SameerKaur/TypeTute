#include <fstream>
#include <string.h>
using namespace std;
int main() {



    
    char para_char,user_char;
	float accuracy;
	int line=1,index=1,errors=0,count=0;
    ifstream paragraph("para.txt");
	ifstream userinput("input.txt");
    if (!paragraph) {
        cout << "Unable to open file";
		getchar();
        exit(1);
    }
cout<<"-------------------------------Paragraph--------------------------------------"<<endl;    
while(paragraph.get(para_char))   
	cout<<para_char;
cout<<endl<<"-------------------------------Your Input--------------------------------------"<<endl;
while(userinput.get(user_char))   
	cout<<user_char;
cout<<endl<<"--------------------------------------------------------------------------------"<<endl;


userinput.clear();
userinput.seekg(0,ios::beg);
paragraph.clear();
paragraph.seekg(0,ios::beg);

   while(paragraph.get(para_char)&&userinput.get(user_char)) 
   {    if(user_char=='\n')
	{	index++;line++;continue;}
       
        if(user_char!=para_char)
		{
			errors++;
			
			cout<<"ERROR:"<<errors<<endl<<"	Line:"<<line<<endl<<"	Index:"<<index<<endl<<"	Should be:"<<para_char<<endl<<"	But is:"<<user_char<<endl;
		cout<<endl<<endl;
		
		}

		count++;

   }
   cout<<endl<<"Total errors= "<<errors<<endl<<"Out of "<<count<<" characters"<<endl;
   accuracy=(1.0-(float)errors/(float)count)*100.0;
   cout<<"Accuracy= "<<accuracy<<"%";
    
    paragraph.close();
	userinput.close();
   
    getchar();
    return 0;
}













