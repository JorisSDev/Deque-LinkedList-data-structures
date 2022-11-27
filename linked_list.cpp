#include <bits/stdc++.h>
 
using namespace std;
 
struct Node{
    int data;
    Node *next;

    static Node* GetNode(int data){
        Node* newNode = new Node;
        newNode->data = data; //newNode.data = data;
        newNode->next = NULL;
        return newNode;
    }
};
 
class List{
    private:
        Node* head;
        Node* tail;
        int size;
 
    public:
        List(){
            head = NULL;
            tail = NULL;
            size = 0;
        }

        ~List(){
            Erase();
            head = NULL;
            tail = NULL;
            cout<<"\n------------------------------------- \n";
            cout<<"Destructor executed";
            cout<<"\n------------------------------------- \n";
        }
    
        int Size();
        bool IsEmpty();

        void PushFront(int data);
        void PushBack(int data);
        void Insert(char selection, int data);

        void PopFront();
        void PopBack();
        void DeleteNode(char selection);

        int Search(int nr);

        void Erase();
        void Display();
        void Reverse();
    
};
 
bool List::IsEmpty(){
    return (head == NULL);
}
 
int List::Size(){
    return size;
}

void List::Insert(char selection, int newData){
    // F - front
    // B - back
    // P - position
    if(selection == 'F'){
        PushFront(newData);
    }
    else if(selection == 'B'){
        PushBack(newData);
    }
    else if(selection == 'P'){
        cout<<"Please enter the position of insertion:: ";
        int nr; cin>>nr;

        if(nr>size){
            PushBack(newData);
        }

        else if(nr==1||IsEmpty()){
            PushFront(newData);
        }
        
        else{
            Node* newNode = Node::GetNode(newData);
            Node* cursor = head;
            Node* prev = NULL;
            int counter=1;
            for(int i=0; i<nr-1; i++){
                prev = cursor;
                cursor = cursor->next;
                counter++;
            }
            
            cout<<"CURSOR DATA:: "<<cursor->data<<endl;

            prev->next = newNode;
            newNode->next = cursor;

        }

    }
}

void List::PushBack(int data){
    Node* newNode = Node::GetNode(data);

    if (newNode == NULL)
        cout << "ERROR:: CAN'T CREATE NEW NODE \n";

    else{
        if (tail == NULL)
            head = tail = newNode;
 
        else{
            tail->next = newNode;
            tail = newNode;
        }
 
        size++;
    }
}

void List::PushFront(int data){
    Node* newNode = Node::GetNode(data);

    if (newNode == NULL)
        cout << "ERROR:: CAN'T CREATE NEW NODE \n";
    else{
        if (head == NULL)
            tail = head = newNode;
 
        else{
            newNode->next = head;
            head = newNode;
        }

        size++;
    }
}
 
void List::PopFront(){
    if (IsEmpty())
        cout << "ERROR :: List IS EMPTY \n";
 
    else{
        if(size==1){
            delete head;
            head=NULL;
            tail=NULL;
        }
        else{
            Node* temp;
            temp = head->next;
            delete head;
            head = temp;
        }
 
        size--;
    }
}
 
void List::PopBack(){
    if (IsEmpty())
        cout << "ERROR :: List IS EMPTY \n";
 
    else{
 
        if (size==1){
            delete tail;
            head=NULL;
            tail=NULL;
        }
        else{
            Node* cursor = head;
            Node* prev = NULL;

            int counter=1;
            for(int i=0; i<size-1; i++){
                prev = cursor;
                cursor = cursor->next;
                counter++;
            }
            cout<<"CURSOR DATA:: "<<cursor->data<<endl;
            prev->next = NULL;
            delete tail;
            tail = prev;
        }
 
        size--;
    }
}

void List::DeleteNode(char selection){
    // F - front
    // B - back
    // P - position

    if(selection == 'F'){
        PopFront();
    }
    else if(selection == 'B'){
        PopBack();
    }
    else if(selection == 'P'){
        cout<<"Please enter the position of deletion:: ";
        int nr; cin>>nr;
        
        if(nr>size||nr<0){
            cout<<"ERROR: NO SUCH ELEMENT EXISTS\n";
        }
        else{
            Node* cursor = head;
            Node* prev = NULL;

            int counter=1;
            for(int i=0; i<nr-1; i++){
                prev = cursor;
                cursor = cursor->next;
                counter++;
            }
            
            cout<<"CURSOR DATA:: "<<cursor->data<<endl;

            if(counter==size){
                PopBack();
            }

            else if(counter==1){
                PopFront();
            }
            else{
                prev->next = cursor->next;
                delete cursor;
            }

        }

    }

    
}

int List::Search(int nr){
    if(nr>size||nr<0){
        cout<<"\n------------------------------------- \n";
        cout<<"ERROR: NO SUCH ELEMENT EXISTS";
        cout<<"\n------------------------------------- \n";
        return 0;
    }
    else{
        Node* cursor = head;
        int counter=1;
        for(int i=0; i<nr-1; i++){
            cursor = cursor->next;
            counter++;
        }
        return cursor->data;
    }
}
 
void List::Erase(){
    tail = NULL;
    while (head != NULL){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

void List::Display(){
    Node *temp = head;   			
    while(temp != NULL){
        cout << temp->data << "\t"; 
        temp = temp->next; 			
    }
}

void List::Reverse(){
    if(size>1){
        tail=head;
        Node* next = NULL;
        Node* prev = NULL;
        Node* cursor = head;

        while(cursor != NULL) {
            next = cursor->next;
            cursor->next = prev;
            prev = cursor;
            cursor = next;
        }
        head = prev;
    }
        else
            cout<<"\nERROR: CAN'T REVERSE\n";
}

void Clear(){
    #if defined _WIN32
        system("cls");
        //clrscr(); // including header file : conio.h
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
        //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
    #elif defined (__APPLE__)
        system("clear");
    #endif
}
 
int main(){
    List d;
    while(true){
        cout<<"\n------------------------------------- \n";
        d.Display();
        int selection;

        cout<<"\n------------------------------------- \n";
        cout<<"[0] :: exit program \n";
        cout<<"[1] :: PushBack() \n";
        cout<<"[2] :: PushFront() \n";
        cout<<"[3] :: Insert() \n";
        cout<<"[4] :: DeleteNode() \n";
        cout<<"[5] :: Search() \n";
        cout<<"[6] :: IsEmpty() \n";
        cout<<"[7] :: Size() \n";
        cout<<"[8] :: Clear() \n";
        cout<<"[9] :: Reverse() \n";

        cout<<"Please select your next move: ";
        cin>>selection;
        
        switch(selection){
            int x;
            int methodSelect;
            
            case 0:
                cout<<"\n------------------------------------- \n";
                cout<<"\n Program halted \n";
                cout<<"\n------------------------------------- \n";
                return 0;
                break;
            case 1:
                cout<<"Enter element: ";
                cin>>x;
                d.PushBack(x);
                break;
            case 2:
                cout<<"Enter element: ";
                cin>>x;
                d.PushFront(x);
                break;
            case 3:
                cout<<"\n------------------------------------- \n";
                cout<<"Please enter the element you wish to insert:: ";
                int newData; cin>>newData;

                cout<<"F - front \n";
                cout<<"B - back \n";
                cout<<"P - position \n";
                cout<<"Please enter insertion method:: ";

                char selection2; cin>>selection2;

                d.Insert(selection2, newData);
                break; 
            case 4:
                cout<<"F - front \n";
                cout<<"B - back \n";
                cout<<"P - position \n";
                cout<<"\nPlease enter deletion method:: ";
                
                char selection1; cin>>selection1;
                d.DeleteNode(selection1);
                break;
            case 5:
                cout<<"\n------------------------------------- \n";
                cout<<"Please enter the pos of the element you want displayed:: ";
                int nr; cin>>nr;
                cout<<"THE ELEMENT: "<<d.Search(nr);
                break;
            case 6:
                if(d.IsEmpty()==1)
                    cout<<"\n----------------YES------------------\n";
                else
                    cout<<"\n-----------------NO------------------\n";
                
                break;
            case 7:
                if(d.IsEmpty()==1){
                    cout<<"\n------------------------------------- \n";
                    cout<<"--List is empty--\n";
                    cout<<"\n------------------------------------- \n";
                }
                else{
                    cout<<"\n------------------------------------- \n";
                    cout<<"Size: "<<d.Size();
                    cout<<"\n------------------------------------- \n";
                }
                break;
            case 8:
                d.Erase();
                cout<<"\n------------------------------------- \n";
                cout<<"The List has been cleared \n";
                cout<<"\n------------------------------------- \n";
                break;
            case 9:
                d.Reverse();
                break;
            default:
                cout<<"\n------------------------------------- \n";
                cout<<"ERROR:: Wrong option";
                cout<<"\n------------------------------------- \n";
                break;

        }

        //Clear();
    }
    
}