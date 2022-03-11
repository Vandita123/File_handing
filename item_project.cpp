#include <iostream>
#include <fstream>
using namespace std;

class ITEM
{
	protected:
	int code;
	char nm[20];	
	public:
		void Read() //Read() reads code and name 
		{
			cout<<endl<<"Enter Code and Name of Item:";
			cin>>code;
			cin>>nm;
		}
		
		void Show() //Show() displays code and data
		{
	//	cout<<endl<<"Code         Name of Item:";
		cout<<endl<<code<<"\t\t"<<nm;
		}
		
		
		void Update() //Update() function updates the code and name of given item
		{
			cout<<endl<<"Enter New updated Code and Name of Item:";
			cin>>code;
			cin>>nm;
		}
		
		friend int search(ITEM I[],int k,int n) //serach() function is used to search item on the basis of it's code
		{
			for(int i=0;i<n;i++)
				if (k==I[i].code)
					return i;
			return -1;		
		} 
		
		friend void Delete(ITEM I[],int k,int m,int n) //Delete() function is used to delete item on the basis of it's code
		{
			for(int i=0;i<n;i++)
				if (i==m)
				{
					for(int j=m;j<n;j++)
					{
						I[m]=I[j+1];	
					}
				}
		} 
};

static int n=0;
ITEM I,K,SR[100];

void Createfile();
void Writefile();
void Appendfile();
void Readfile();
void Updatefile();
void Deletefile();

int main()
{
	int chh;
	do
	{
		cout<<endl<<"----------------------Menu------------------------";
		cout<<endl<<"1. For Creating New Empty File : ";
		cout<<endl<<"2. Writing in New File";
		cout<<endl<<"3. Appending in Existing File";
		cout<<endl<<"4. Reading and showing records from File";
		cout<<endl<<"5. Deleting Record or Object from File";
		cout<<endl<<"6. Updating Record or Object in File";
		cout<<endl<<"7. Exit...............";
		cout<<endl<<"----------------------------------------------------";
		cout<<endl<<"Enter your choice : ";
		cin>>chh;
		cout<<endl<<"----------------------------------------------------"<<endl;
		switch(chh)
		{
			case 1:  Createfile();
					 break;
			case 2:	 Writefile();
					 break;
			case 3:  Appendfile();
					 break;
			case 4:	 Readfile();
					 break;
			case 5:  Deletefile();
					 break;
			case 6:  Updatefile();
					 break;
			case 7:  cout<<endl<<"Existing Programme...............";
		}
	} while (chh!=7);
	return 0;
	}
	
//Function Createfile used to create empty file
void Createfile() {
	ofstream F;
	F.open("D:/file_handling.txt");
	F.close();
}
		
//Function Writefile
void Writefile()
{
	fstream F;
	F.open("D:/file_handling.txt",ios::out); // opens file F
	if (F.fail()) // execute when file not found
		cout<<"Unable to open file";
		
	else {
		int k;
		cout<<endl<<"How many record you want to add:";
		cin>>k;
		n=n+k;
		for(int i=0;i<k;i++)
		{
			I.Read(); // reads the code and name 
			F.write((char *) &I, sizeof(I)); // and then write in file F
		}
		F.close(); // close file F
	}
}

//Function Appendfile
void Appendfile() {
	fstream F;
	F.open("D:/file_handling.txt",ios::app); // opens file F
	if (F.fail()) // execute when file not found
		cout<<"Unable to open file";
	
	else {
		int k;
		cout<<endl<<"How many record you want to add:";
		cin>>k;
		n=n+k;
		F.seekp(0,ios::end);
		for(int i=0;i<k;i++)
		{
			I.Read(); // reads the code and name
			F.write((char *) &I, sizeof(I)); // and then write in file F
		}
		F.close(); // close file F
	}
}

//Readfile Function
void Readfile()
{
	fstream F;
	F.open("D:/file_handling.txt",ios::in); // opens file F
	if (F.fail()) // execute when file not found
		cout<<"Unable to open file";
	else
	{
	F.seekg(0);
	cout<<endl<<"Code         Name of Item:";
	for(int i=0;i<n;i++)
	{
		F.read((char *) &K, sizeof(K));
		K.Show();
	}
	F.close(); // close file F
	}
}

//Searchfile Function
void Searchfile()
{
	int k,j=0;
	cout<<"Read Code to search:";
	cin>>k;
	fstream F;
	F.open("D:/file_handling.txt",ios::in); // opens file F
	if (F.fail()) // execute when file not found
		cout<<"Unable to open file";
	
	else {
		F.seekg(0);
		for(int i=0;i<n;i++) {
			F.read((char *) &K, sizeof(K));
			SR[j++]=K;  
		}
		int m=search(SR,k,n); // calling search() function
		if (m!=-1)
			SR[m].Show();
		else
			cout << "code not found";
	}
}

//Deletefile function
void Deletefile() {
	int k,j=0;
	cout<<"Read Code to DELETE:";
	cin>>k;
	fstream F;
	F.open("D:/file_handling.txt",ios::in); // opens file F
	if (F.fail()) // execute when file not found
		cout<<"Unable to open file"; 
	
	else {
		F.seekg(0);
		for(int i=0;i<n;i++)
		{
			F.read((char *) &K, sizeof(K));
			SR[j++]=K;  
		}
		int m=search(SR,k,n); // calling serach() function
		if (m!=-1) {
			for(int i=0;i<n;i++) {
				F.read((char *) &K, sizeof(K));
				SR[j++]=K;  
			}
			
			Delete(SR,k,m,n); // calling delete function
			n--;
			Createfile();
			F.close();
			F.open("D:/file_handling.txt",ios::out); //opens file F
			if (F.fail()) //execute when file unable to open
				cout<<"Unable to open file";
			
			else
			for(int i=0;i<n;i++)
				F.write((char *) &SR[i], sizeof(SR[i]));
			F.close();
		}
		else
			cout<<"not found";
	}
}

//Updatefile function
void Updatefile() {
	int k,j=0;
	cout<<"Read Code to Update:";
	cin>>k;
	fstream F;
	F.open("D:/file_handling.txt",ios::in); //opens file F
	if (F.fail())
		cout<<"Unable to open file";
	
	else {
		F.seekg(0);
		for(int i=0;i<n;i++) {
			F.read((char *) &K, sizeof(K));
			SR[j++]=K;  
		}
		
		int m=search(SR,k,n); //calling search() function
		if (m!=-1) {
			int cc;
			cout<<endl<<"Record Found";
			cout<<"You want to update Record yes:1 no:0:"; //conforming
			cin>>cc;
			if (cc==1)
				SR[m].Update();	//calling update function
		}
		else
			cout<<"record not found"<<endl;
	}
	Createfile();
	F.close();
	F.open("D:/file_handling.txt",ios::out); //open file F
	if (F.fail()) //execute when file unable to open
		cout<<"Unable to open file";
		
	else
	for(int i=0;i<n;i++)
		F.write((char *) &SR[i], sizeof(SR[i]));
	F.close(); // close file F
}