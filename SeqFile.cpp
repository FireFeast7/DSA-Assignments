#include <iostream>
#include <fstream>
#include <string>
#include <cstring> 
using namespace std;

class Student {
    string Name;
    string rollNo;
    string div;
    string address;

public:
    string toString() {
        string output;
        return output + "Roll Number: " + rollNo +"\nName: " + Name +  "\nDivision: " + div + "\nAddress: " + address + "\n-------------------------------" + "\n";
    }

    void getData() {
        cout << "Enter the Name of Student: ";
        cin >> Name;
        cout << "Enter the roll number of Student: ";
        cin >> rollNo;
        cout << "Enter the division of Student: ";
        cin >> div;
        cout << "Enter the Address of Student: ";
        cin >> address;
    }

    const string& getRollNo() const {
        return rollNo;
    }

    friend class SeqFile;
};

class SeqFile {
public:
    void insert() {
        Student s;
        s.getData();
        ofstream fout;
        fout.open("StudentInfo.txt", ios::app);
        fout.write(s.toString().c_str(), s.toString().length());
        fout.close();
    }

	    void del(const string& rollNo) {
	        ifstream fin("StudentInfo.txt");
	        if (!fin) {
	            cout << "Unable to open file." << endl;
	            return;
	        }
	
	        ofstream tempFile("temp.txt");
	        if (!tempFile) {
	            cout << "Unable to create temporary file." << endl;
	            fin.close();
	            return;
	        }
	
	        string line;
	        bool found = false;
			int count = 0;
	        while (getline(fin, line)) {
	            if ((line.find("Roll Number: " + rollNo) != string::npos) || (count != 5 && count !=0 )) {
	                count++;
	                found = true;
	                continue;
	            }
				found = false;
	            tempFile << line << endl;
	        }
	
	        fin.close();
	        tempFile.close();
	
	        if (found) {
	            remove("StudentInfo.txt");
	            rename("temp.txt", "StudentInfo.txt");
	            cout << "Student record deleted successfully." << endl;
	        } else {
	            remove("temp.txt");
	            cout << "Student record with Roll Number " << rollNo << " not found." << endl;
	        }
	    }
	    public:void display_record(const string& rollNo){
	    	ifstream fin("StudentInfo.txt");
	    	if(!fin){
	    		cout<<"Unable to Open the File "<<endl;
	    		return ;
			}
			string line;
			int count = 0;
			bool found = false;
			while(getline(fin,line)){
				if((line.find("Roll Number: "+ rollNo) != string::npos)||(count!=5 && count!=0) ){
					count++;
					cout<<line<<endl;
					found = true;
				}
			}
			 if (!found) {
	            cout << "Student record with Roll Number " << rollNo << " not found." << endl; 
	        }
			count = 0;
			fin.close();
		}
};

int main() {
    int Choice;
	string R;
	SeqFile sf;

	do {
	cout<<"\n1: Add a record\n2: Display Database\n3: Delete a record\n\nEnter your choice: ";
		cin>>Choice;

		switch( Choice ) {
				
		case 1:
			sf.insert();
			break;
				
		case 2:  
		cout<<"\nEnter Roll No to see that record :";
			cin>>R;             		                
			sf.display_record(R);
			break;
		case 3:
			cout<<"\nEnter Roll No to delete :";
			cin>>R;
			sf.del( R );
			break;
    }
   	
}while(Choice<5);
	{
		cout<<"\n";
	}
}



