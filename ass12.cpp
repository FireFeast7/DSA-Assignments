#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Student{
    int rollno;
    string name;
    string id;

    public: Student(int rollno, string name,string id){
        this->id = id;
        this->name = name;
        this->rollno = rollno;
    }
      string toString() {
        string output ; 
        return output + " " + name + " " + to_string( rollno ) + " " + id ; 
    }
    friend class DirectAccessFile;
};

class DirectAccessFile{
    int tablesize;
    string filename;
    int *hashtable = nullptr;

    public: int hashcode(int id){
        return id%tablesize;
    }

    public: DirectAccessFile(int tablesize, string filename){
        this->filename = filename;
        this->tablesize = tablesize;
        this->hashtable = new int[this->tablesize];
        for(int i = 0; i < tablesize;i++){
            hashtable[i] = -1;
        }
    }
    public: void insert(Student s){
        ofstream fout;
        fout.open(filename,ios::app);
        int address = fout.tellp();
        int hashaddress = hashcode(s.rollno);
        hashtable[hashaddress] = address;
        fout.write(s.toString().c_str(),s.toString().length());
        fout.write("\n",1);
        fout.close();
    }
    public: void searchrecord(int id){
        int hashaddress = hashcode(id);
        int recordaddress = hashtable[hashaddress];

        if(recordaddress != -1){
            ifstream fin;
            fin.open(filename,ios::in);
            fin.seekg(recordaddress,ios::beg);
            string recordline = " ";
            char c = fin.get();
            while(c != '\n'){
                recordline += c;
                c = fin.get();
            }
            cout<<"Record Found"<<recordline<<endl;
        }
        else{
            cout<<"Record Not Found"<<endl;
        }
    }
       void printTable() {
        for( int i = 0 ; i < tablesize ; i++ ) {
            cout << i << " : " << hashtable[ i ] << "\n" ; 
        }
    }
};

int main(){
    DirectAccessFile daf(10,"abc.txt");
    daf.insert( Student( 21375, "Ameya" , "c2k211048") ) ;
    daf.insert( Student( 21377, "Tejas" , "c2k211049")) ;
    daf.searchrecord( 21375 ) ; 
    daf.searchrecord( 21377 ) ; 
}