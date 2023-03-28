#include<iostream>
#include<iomanip>
using namespace std;

#define size 10

class Item
{
    long int ph;
    string name;
    
    public:
    Item()
    {
        ph = -1;
        name = "-";
    };
    friend class Hash;
};


class Hash
{
    Item hashtable[size];
    
    public:
    int hashcode(long int key);
    void insert1();  //without replacement
    void insert2();  //with replacement
    void display();
    void search();
    void delet();
};



int Hash::hashcode(long int key)
{
    return key%size;
}


void Hash::insert1()  
{   
    Item i1;
    int index;
    
    cout<<"\nEnter the Name: ";
    cin>>i1.name;
    cout<<"Enter the Phone Number: ";
    cin>>i1.ph;
    
    index = hashcode(i1.ph);
    
    if (hashtable[index].ph == -1)  
    {  
        hashtable[index] = i1;  
        cout<<"Inserted!"<<endl;
    }
    else   
    {
        while (hashtable[index].ph != -1)
        {
            index = (index+1)%size;
        }
        hashtable[index] = i1;

    }
}


void Hash::insert2()  
{
    Item i1, temp;
    int index;
    
    cout<<"\nEnter the Name: ";
    cin>>i1.name;
    cout<<"Enter the Phone Number: ";
    cin>>i1.ph;
    
    index = hashcode(i1.ph);
    
    if (hashtable[index].ph == -1)  
    {  
       hashtable[index] = i1;  
        cout<<"Inserted!"<<endl;
    }
    else  
    {
        temp = hashtable[index];  
        if (hashcode(temp.ph) == index)  
        {   
            while (hashtable[index].ph != -1)
            {
                index = (index+1)%size;
            }
            hashtable[index] = i1;
        }
        else 
        {
            hashtable[index] = i1;
            while (hashtable[index].ph != -1)
            {
                index = (index+1)%size;
            }
            hashtable[index] = temp;
        }
    }
}


void Hash::search()
{
    int index;
    int a = 0;
    bool found = false;
    long int phone;
    int count = 1;
    cout<<"Enter phone no. to search for: "<<endl;
    cin>>phone;
    
    index = hashcode(phone);
    
    while(a!=9)
    {
        if(hashtable[index].ph == phone) {
            cout<<"Found at index="<<index<<endl;
            found = true;
            break;
        }
        else {
            index = (index+1)%size;
        }
        a++;
        count++;
    }
    if (found == false)
    {
        cout<<"Not found!"<<endl;
    }
    cout<<"The Number of Comparisons it did to find the element "<<count<<endl;
}

void Hash::delet()
{
    bool found = false;
    long int phone;
    
    cout<<"Enter phone no. to be deleted : "<<endl;
    cin>>phone;
    
    for(int i=0; i<size; i++)
    {
        if (hashtable[i].ph == phone) {
            cout<<"Deleted!"<<endl;
            found = true;
            hashtable[i].ph = -1;
        }
    }
    if(found == false)
    {
        cout<<"Not found!"<<endl;
    }
}


void Hash::display()
{
    cout << "\n----------------------------------------------------------------------";
    cout << "\nSr.No" << setw(25) << "Name" << setw(30) << "Telephone";
    cout << "\n----------------------------------------------------------------------";
    for (int i = 0; i < size; i++)
    {
        cout << endl;
        cout << i << setw(30) << hashtable[i].name << setw(30) << hashtable[i].ph<<endl;
    }
}


int main()
{
    Hash h1, h2;
    int ch;
    char ans = 'y';
    long int num;
    
    do
    {
        cout<<"\n\n*** Telephone Directory ***\n1. Insert\n2. Display\n3. Search\n4. Delete";
        
        cout<<"\nEnter choice: ";
        cin>>ch;
        
        switch (ch)
        {
            case 1:
            h1.insert1();
            h2.insert2();
            break;
            
            case 2:
            h1.display();
            cout<<endl;
            h2.display();
            break;
            
            case 3:
            h1.search();
            h2.search();
            break;
            
            case 4:
            h1.delet();
            break;
        }

        cout<<"\nContinue? (y/n): ";
        cin>>ans;
        
    } while (ans == 'y' || ans == 'Y');
}