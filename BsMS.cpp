// Bookshop Management System
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
using namespace std;

class Book{

        string authorName,bookName,bookName_Buy;
        int bookNumber,bookNumber4,numCopies,numCopies_Buy,count,count1,choose,AdminChoose,ClientChoose;
        string authorName_,bookName_;
        int bookNumber_Buy,numCopies_,bookNumber_Del,bookNumber_;
        char add;
        fstream file,file1,file2,file3;                     // file handling
    public:
            void AdminBuy();                              // add books
            void AdminDelete();                           // delete books
			void AdminDisplay();                          // display books
			void AdminModify();                           // modify books
			void SoldBooks();                             // display sold books
            void ClientBuy();                             //  buy from admin books
            void ClientShow();                            //  show all boooks
            void ClientCheck();                           //  check availability
            void ClientDelete();                          //  delete books records

            void switch_();                               // switch statement for call functions
};

void Book::switch_() {                        //  run functions
        z:
        system("cls");
        cout<<"\t\tBookshop Management System\n\n";
        cout<<"1. Admin Account"<<endl;
        cout<<"2. Customer Account"<<endl;
        cout<<"choose  input: ";
        cin>>choose;
        switch(choose){
            case 1:
            x:                                                      // repeat admin functions
                system("cls");                                      // clear
                cout<<"\t\tBookshop Management System\n\n";
                cout<<"Admin Account \n"<<endl;
                cout<<"1. Add Books\n";
                cout<<"2. Display Books\n";
				cout<<"3. Delete Books\n";
                cout<<"4. Modify Books\n";
				cout<<"4. Sold Books\n\n";
                cout<<"choose input: ";
                cin>>AdminChoose;                                       // ask to input
                switch (AdminChoose) {
                case 1:
                    AdminBuy();
                    break;
                case 2:
                	AdminDisplay();
                	break;
                case 3:
                    AdminDelete();
                    break;
                case 4:
                	AdminModify();
                	break;
                case 5:
                	SoldBooks();
                	break;
                default:
                    cout<<"invalid Input\n";
                    getch();                                            // hold program
                    goto x;
                }
                break;
            case 2:
            y:
                system("cls");
                cout<<"\t\tBookshop Management System\n\n";
                cout<<"Customer Account\n"<<endl;
                cout<<"1. Buy Books"<<endl;
                cout<<"2. Display Books"<<endl;
                cout<<"3. Check Available Books"<<endl;
                cout<<"4. Delete Books"<<endl;
                cout<<"\nchoose input: ";
                cin>>ClientChoose;
                switch (ClientChoose){
                    case 1:
                        ClientBuy();
                        goto y;
                        break;
                    case 2:
                        ClientShow();
                        goto y;
						break;
                     case 3:
                        ClientCheck();
                        goto y;
						break;
                    case 4:
                        ClientDelete();
                        goto y;
						break;
                    default:
                        cout<<"invalid Input ";
                        getch();
                        goto y;
                }
            default:
                cout<<"invalid input ";
                getch();
                goto z;
        }
        
}


/////////////////////////////////////////////////////////////////////////////////////
void Book::AdminBuy(){
	repeat:
    file.open("AdminBook.txt",ios::out|ios::app);                       // create adminbook.txt file and append file
    cout<<"Enter the book Number: ";
    cin>>bookNumber;
    cin.ignore();                                                       // ignore invalid character
    cout<<"Enter the name of Book: ";
    cin>>bookName;
    cin.ignore();
    cout<<"Enter the Author's Name: ";
    cin>>authorName;
    cin.ignore();
    cout<<"Enter no. of copies: ";
    cin>>numCopies;
    file<<bookNumber<<" "<<bookName<<" "<<authorName<<" "<<numCopies<<"\n";         // to write in a file
    file.close();
    cout<<"Do you want to add more Books(y/n) :";
    cin>>add;
    if(add == 'y' || add == 'Y'){                                                   // to repeat program
    	goto repeat;
	}
}
/////////////////////////////////////////////////////////////////////////////////////
void Book::AdminDelete(){
	repeat:                                                                         // goto repeat here
    int count=0;
    file.open("AdminBook.txt",ios::in);                                     // read data from file
    file1.open("AdminBook1.txt",ios::out|ios::app);                         // write and append  data in file
    if(!file){
        cout<<"Error in opening a file";
    } else {
        cout<<"Enter Book id: ";
        cin>>bookNumber_;
        file>>bookNumber>>bookName>>authorName>>numCopies;                  // read data from file
        while(!file.eof()){                                                     // loop until conditon meet
            if(bookNumber == bookNumber_){
            count++;                                                              // count = count + 1;
            cout<<"book id sucessfully delete";
            } else {
                file1<<bookNumber<<" "<<bookName<<" "<<authorName<<" "<<numCopies<<endl;            // else write in file
                }
        	file>>bookNumber>>bookName>>authorName>>numCopies;                          // if not read from file
        }
    }
    if(count == 0){                                                                   // if count not increment run this 
    cout<<"Book id not Found";
    goto ext;                                                                       // goto exit
    }
    // file>>bookNumber>>bookName>>authorName>>numCopies;
    file.close();                                                                   // close file
    file1.close();                                                                  // close file
    remove("AdminBook.txt");                                                        // remove file
    rename("AdminBook1.txt","AdminBook.txt");                                       // rename file
    cout<<"\nDo you want to Delete more Books(y/n) :";
    cin>>add;
    if(add == 'y' || add == 'Y'){
    	goto repeat;                                                        // goto repeat
	}
	ext:										// to exit from program
    getch();
}
/////////////////////////////////////////////////////////////////////////////////////
void Book::ClientBuy(){
//////////// TO SHOW DATA ////////////////
    int count=0;
    file.open("AdminBook.txt",ios::in);
    if(!file){
        cout<<"error in opening a file";
    } else {
        cout<<"Book Number\tBookName\tAuthorName\tNo.ofcopies\n";
        file>>bookNumber>>bookName>>authorName>>numCopies;
        while(!file.eof()){
            cout<<bookNumber<<"\t\t"<<bookName<<"\t\t"<<authorName<<"\t\t"<<numCopies<<"\n";
            file>>bookNumber>>bookName>>authorName>>numCopies;
            count++;
        }
        file.close();
    }
///////////////////////////////////////// To write Data in client file /////////////////////////////////
    repeat:
	int count1=0;
    file.open("AdminBook.txt",ios::in);                                             // read data from file
    file2.open("AdminBook1.txt",ios::out|ios::app);                                 // to write in a file
    file1.open("ClientBook.txt",ios::out|ios::app);                                 // to write in a file
    file3.open("SoldBook.txt",ios::out|ios::app);                                   // to write in a file
    if(!file){
        cout<<"Error in opening a file";
    } else {
        cout<<"Enter Book Number: ";
        cin>>bookNumber_Buy;
        file>>bookNumber>>bookName>>authorName>>numCopies;
        while(!file.eof()){
            if(bookNumber == bookNumber_Buy){                                       // check condition
            cout<<"Enter book Number of copies you want to buy: ";
            cin>>numCopies_Buy;
            file1<<bookNumber<<" "<<bookName<<" "<<authorName<<" "<<numCopies_Buy<<endl;          //  to write in a file   
            numCopies -= numCopies_Buy;
            file2<<bookNumber<<" "<<bookName<<" "<<authorName<<" "<<numCopies<<endl;          //  to write in a file 
            file3<<bookNumber<<" "<<bookName<<" "<<authorName<<" "<<numCopies<<endl;          //  to write in a file 
            count1++;
            }
            else {
                file2<<bookNumber<<" "<<bookName<<" "<<authorName<<" "<<numCopies<<endl;            //  to write in a file 
                }
            file>>bookNumber>>bookName>>authorName>>numCopies;                                     // to read from file
        }
            if(count1 == 0){
            cout<<"Book id not Found";
            goto ext;                                                                               // goto exit
        }
    }
    file.close();
    file1.close();
    file2.close();
    remove("AdminBook.txt");
    rename("AdminBook1.txt","AdminBook.txt");
    cout<<"\nDo you want to Buy more Books(y/n) :";
    cin>>add;
    if(add == 'y' || add == 'Y'){
    	goto repeat;
	}
	ext:										                // to exit from program  // here
    getch();
}
/////////////////////////////////////////////////////////////////////////////////////
void Book:: ClientShow(){
    int count=0;
    file.open("ClientBook.txt",ios::in);
    if(!file){
        cout<<"error in opening a file";
    } else {
        cout<<"Book Number\tBookName\tAuthorName\tNo.ofcopies\n";
        file>>bookNumber>>bookName>>authorName>>numCopies;
        while(!file.eof()){
            cout<<bookNumber<<"\t\t"<<bookName<<"\t\t"<<authorName<<"\t\t"<<numCopies<<"\n";
            file>>bookNumber>>bookName>>authorName>>numCopies;
            count++;
        }
        file.close();
    }
    if(count == 0){
        system("cls");
         cout<<"\n\nClient id not Found\n\n";
    }
    getch();
}
/////////////////////////////////////////////////////////////////////////////////////
void Book:: ClientDelete(){
	repeat:
    int bookNumber_Del,count=0;
    file.open("ClientBook.txt",ios::in);
    file1.open("ClientBook1.txt",ios::out|ios::app);
    if(!file){
        cout<<"Error in opening a file";
    } else {
        cout<<"Enter Book id: ";
        cin>>bookNumber_Del;
        file>>bookNumber>>bookName>>authorName>>numCopies;
        while(!file.eof()){
            if(bookNumber == bookNumber_Del){
            count++;
            cout<<"book id sucessfully delete";
            // break;
            } else {
                file1<<bookNumber<<" "<<bookName<<" "<<authorName<<" "<<numCopies<<endl;
                }
            file>>bookNumber>>bookName>>authorName>>numCopies;
        }
            if(count == 0){
            cout<<"Book id not Found";
            goto ext;
            }
    }
//    file>>bookNumber>>bookName>>authorName>>numCopies;
    file.close();
    file1.close();
    remove("ClientBook.txt");
    rename("ClientBook1.txt","ClientBook.txt");
	cout<<"\nDo you want to Delete more Books(y/n) :";
    cin>>add;
    if(add == 'y' || add == 'Y'){
    	goto repeat;
	}
	ext:										// to exit from program
    getch();
}
/////////////////////////////////////////////////////////////////////////////////////
void Book::ClientCheck(){
	int count=0;
    file.open("AdminBook.txt",ios::in);
    if(!file){
        cout<<"error in opening a file";
    } else {
        cout<<"Book Number\tBookName\tAuthorName\tNo.ofcopies\n";
        file>>bookNumber>>bookName>>authorName>>numCopies;
        while(!file.eof()){
            cout<<bookNumber<<"\t\t"<<bookName<<"\t\t"<<authorName<<"\t\t"<<numCopies<<"\n";
            file>>bookNumber>>bookName>>authorName>>numCopies;
            count++;
        }
        file.close();
    }
     if(count == 0){
         system("cls");
         cout<<"\n\tEmpty Database\n\n";
     }
     getch();
}
/////////////////////////////////////////////////////////////////////////////////////
void Book:: AdminModify(){
    int bookNumber3,count=0;
    file.open("AdminBook.txt",ios::in);
    file1.open("AdminBook1.txt",ios::out|ios::app);
    if(!file){
        cout<<"Error in opening a file";
    } else {
        cout<<"Enter Book id: ";
        cin>>bookNumber3;
        file>>bookNumber>>bookName>>authorName>>numCopies;
        while(!file.eof()){
            if(bookNumber == bookNumber3){
            cout<<"\nPrevious Data"<<endl;
            cout<<"Book id: "<<bookNumber<<endl;
            cout<<"Book Name: "<<bookName<<endl;
            cout<<"Author Name: "<<authorName<<endl;
            cout<<"NumofCopies: "<<numCopies<<endl<<endl;
            /////////////////New Entry//////////////////////////
            cout<<"Enter New Data"<<endl;
            cout<<"Book id: ";
            cin>>bookNumber_;
            cout<<"Book Name: ";
            cin>>bookName_;
            cout<<"Author Name: ";
            cin>>authorName_;
            cout<<"NumofCopies: ";
            cin>>numCopies_;
            file1<<" "<<bookNumber_<<" "<<bookName_<<" "<<authorName_<<" "<<numCopies_<<endl;
            count++;
            // break;
            } else {
                file1<<" "<<bookNumber<<" "<<bookName<<" "<<authorName<<" "<<numCopies<<endl;
                }
            file>>bookNumber>>bookName>>authorName>>numCopies;
        }
            if(count == 0){
            cout<<"Book id not Found"; 
        	}
        
    }
    
    // file>>bookNumber>>bookName>>authorName>>numCopies;
    file.close();
    file1.close();
    remove("AdminBook.txt");
    rename("AdminBook1.txt","AdminBook.txt");
    getch();
}
///////////////////////////////////////////////////////////////////////////////////////////
void Book:: AdminDisplay(){
    int count=0;
    file.open("AdminBook.txt",ios::in);
    if(!file){
        cout<<"error in opening a file";
    } else {
        cout<<"Book Number\tBookName\tAuthorName\tNo.ofcopies\n";
        file>>bookNumber>>bookName>>authorName>>numCopies;
        while(!file.eof()){  // end of file (eof)
            cout<<bookNumber<<"\t\t"<<bookName<<"\t\t"<<authorName<<"\t\t"<<numCopies<<"\n";
            file>>bookNumber>>bookName>>authorName>>numCopies;
            count++;
        }
    	file.close();
    	if(count == 0){
		cout<<"Empty Database";
		}
	}
    getch();
}
//////////////////////////////////////////////////////////////////////////
void Book::SoldBooks(){
	int count=0;
    file.open("SoldBook.txt",ios::in);
    if(!file){
        cout<<"error in opening a file";
    } else {
        cout<<"Book Number\tBookName\tAuthorName\tNo.ofcopies\n";
        file>>bookNumber>>bookName>>authorName>>numCopies;
        while(!file.eof()){
            cout<<bookNumber<<"\t\t"<<bookName<<"\t\t"<<authorName<<"\t\t"<<numCopies<<"\n";
            file>>bookNumber>>bookName>>authorName>>numCopies;
            count++;
        }
    	file.close();
    	if(count == 0){
		cout<<"Empty Database";
		}
	}
    getch();
}
//////////////////////////////////////////////////////////////////////////
int main(void){                                                             // main function
    Book book;                                                              // create object
    while(1){                                                              // 1 == true // run infinite times
    book.switch_();                                                         // call function
    }
}
