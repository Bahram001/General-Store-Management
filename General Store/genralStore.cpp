#include<iostream>
#include<fstream>
using namespace std;

class temp{
        string itemID,itemName;
        int itemQuantity,itemPrice;
        fstream file,file1;
        int totalAmount,quantity,itemRate;
        string search;
        char _choice;
    public:
    void addProduct(void);
    void viewProduct(void);
    void buyProduct(void);
}obj;

int main(){
    char choice;

    cout<<"press 1 --> Start Shoping"<<endl;
    cout<<"press 0 --> Exit"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 'A':
       obj.addProduct();
    break;
    case '1':
        obj.viewProduct();
        obj.buyProduct();
    break;
    case '0':
        system("exit");
    break; 
    default:
        cout<<"Invalid Selection...!";
        break;
    }

    return 0;
}
void temp :: addProduct(){
        cout<<"Enter Product ID :: ";
        cin>>itemID;
        cout<<"Enter Product Name :: ";
        cin>>itemName;
        cout<<"Enter Product Quantity :: ";
        cin>>itemQuantity;
        cout<<"Enter Product Price :: ";
        cin>>itemPrice;

        file.open("data.txt",ios :: out | ios :: app );
        file<<itemID<<"\t"<<itemName<<"\t"<<itemQuantity<<"\t"<<itemPrice<<endl;
        file.close();
}
void temp :: viewProduct(){
    file.open("data.txt",ios :: in);
        file>>itemID>>itemName>>itemQuantity>>itemPrice;
        while(!file.eof()){
            cout<<"--------------------------"<<endl;
            cout<<"Product Id\t\tProduct Name\t\tQuantity\t\tproduct Price"<<endl;
            cout<<itemID<<"\t\t\t"<<itemName<<"\t\t\t"<<itemQuantity<<"\t\t\t"<<itemPrice<<endl;
            cout<<"--------------------------"<<endl;
        file>>itemID>>itemName>>itemQuantity>>itemPrice;
        }
    file.close();
}
void temp :: buyProduct(){
    _choice = 'y';

    while(_choice == 'y'){

    file.open("data.txt",ios :: in);
    file1.open("temp.txt",ios :: out | ios :: app);
    file>>itemID>>itemName>>itemQuantity>>itemPrice;

    cout<<"Enter Product ID :: ";
    cin>>search;
    cout<<"Enter Quantity";
    cin>>quantity;

    while(!file.eof()){
        if(itemID ==  search){
            itemQuantity = itemQuantity - quantity;
            file1<<itemID<<"\t"<<itemName<<"\t"<<itemQuantity<<"\t"<<itemPrice<<endl;

            itemRate = quantity * itemPrice;
            totalAmount = totalAmount + itemRate;
            cout<<"------Payment Bill------"<<endl;
            cout<<"Total Purchase Amount :: "<<totalAmount<<endl;
            cout<<"------------------------"<<endl;

        }else{
            file1<<itemID<<"\t"<<itemName<<"\t"<<itemQuantity<<"\t"<<itemPrice<<endl;
        }
        file>>itemID>>itemName>>itemQuantity>>itemPrice;
    }
    file.close();
    file1.close();
    remove("data.txt");
    rename("temp.txt","data.txt");
  
    cout<<"\n Continue Shoping ? (Y / N) ";
    cin>>_choice;
    }
}