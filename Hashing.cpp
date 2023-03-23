#include<iostream>
#include<iomanip>
using namespace std;
#define size 10

int hashIndex=0;

class DataItem
{
    long int data;
    string name;
    public: DataItem()
    {
        data=-1;
        name = "--";
    };
        friend class hashTable;
};


class hashTable
{
public: void insert();
        void insertR();
        void del();
        void search();
        void display();
        DataItem hashArray[size];
};


int hashCode(long int key)
{
    return key%size;
}


void hashTable::insert()
{   
    DataItem d;
    int pos;
    cout<<"Enter the Phone Number : "<<endl;
    cin>>d.data;
    pos = hashCode(d.data);
    cout<<"Enter the Name"<<endl;
    cin>>d.name;
    if(hashArray[pos].data == -1){
        hashArray[pos] = d;
        cout<<"Successfully Added"<<endl;
    }
    else{
        for(int i = pos+1; i%size!=pos;i++){
            cout<<"Successfully Added"<<endl;
            hashArray[i] = d;
            break;
        }
    }
}
void hashTable::insertR(){
    DataItem d,d1;
    int pos;

    cout<<"Enter The Name : "<<endl;
    cin>>d.name;
    cout<<"Enter the Phone Number : "<<endl;
    cin>>d.data;
    pos = hashCode(d.data);
    if(hashArray[pos].data == -1){
        hashArray[pos] = d;
        cout<<"Successfully Added "<<endl;
    }
    else{
        d1 = hashArray[pos];
        if(hashCode(d1.data == -1)){
            for(int i = pos+1 ; i%size!=0;i++){
                if(hashArray[i].data == -1){
                    hashArray[i] = d;
                    break;
                }       
            }
        }
        else {
                hashArray[pos] = d;
                for (int i = pos + 1; i % size != 0; i++)
                {
                    if (hashArray[i].data == 0)
                    {
                        hashArray[i] = d1;
                        break;
                    }
                }
            }
    }
}

void hashTable::search(){
    int count = 0;
    long int phno;
    cout<<"Enter The phone number to be searched "<<endl;
    cin>>phno;
    int hashIndex = hashCode(phno);
    int a = 0;
    bool found = false;
    while(a!=9){
        if(hashArray[hashIndex].data == phno){
            cout<<"Found At"<<hashIndex;
            found = true;
            break;
        }
        else{
            ++hashIndex;
            hashIndex = hashIndex%size;
        }
        a++;
        count++;
    }
    if(found == false){
        cout<<"Not Found in Hash Table"<<endl;
    }
    cout<<count+1;
}

void hashTable::del()
{
    bool found = false;
    long int phno;
    cout<<"Enter the phone number to be deleted : "<<endl;
    cin>>phno;
    for(int i =0;i<size;i++){
        if(hashArray[i].data == phno){
            cout<<"Successfully deleted"<<endl;
            found = true;
            hashArray[i].data = -1;
        }
    }
    if(found == false){
        cout<<"Element not Found"<<endl;
    }
}

void hashTable::display()
{
    cout << "\n----------------------------------------------------------------------";
    cout << "\nSr.No" << setw(25) << "Name" << setw(30) << "Telephone";
    cout << "\n----------------------------------------------------------------------";
    for (int i = 0; i < size; i++)
    {
        cout << endl;
        cout << i << setw(30) << hashArray[i].name << setw(30) << hashArray[i].data<<endl;
    }
}

int main()
{
    hashTable h;
    hashTable hR;
    char ans;
    long int num;
    do
    {
        cout << "\n1.Insert\n2,Display\n3.Search\n4.Delete";
        int ch;
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            h.insert();
            hR.insertR();
            break;
        case 2:
            h.display();
            hR.display();
            break;
        case 3:
            h.search();
            break;
        case 4:
            h.del();
            break;
        }

        cout << "\nDo you want to continue: ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}