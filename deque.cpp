#include <bits/stdc++.h>
 
using namespace std;
 
struct Node{
    int data;
    Node *prev;
    Node *next;

    static Node* GetNode(int data){
        Node* newNode = new Node;
        newNode->data = data; //newNode.data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
    }
};
 
class Deck{
    private:
        Node* head;
        Node* tail;
        int size;
 
    public:
        Deck(){
            head = NULL;
            tail = NULL;
            size = 0;
        }

        ~Deck(){
            delete head;
            delete tail;
            Erase();
            cout<<"\n------------------------------------- \n";
            cout<<"Destructor executed";
            cout<<"\n------------------------------------- \n";
        }
    
        void PushFront(int data);
        void PushBack(int data);
        void PopFront();
        void PopBack();
        int GetFront();
        int GetBack();
        int Size();
        bool IsEmpty();
        void Erase();
        void Display();
};
 
bool Deck::IsEmpty(){
    return (head == NULL);
}
 
int Deck::Size(){
    return size;
}

void Deck::PushBack(int data){
    Node* newNode = Node::GetNode(data);

    if (newNode == NULL)
        cout << "ERROR:: CAN'T CREATE NEW NODE \n";

    else{
        if (tail == NULL)
            head = tail = newNode;
 
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
 
        size++;
    }
}

void Deck::PushFront(int data){
    Node* newNode = Node::GetNode(data);

    if (newNode == NULL)
        cout << "ERROR:: CAN'T CREATE NEW NODE \n";
    else{
        if (head == NULL)
            tail = head = newNode;
 
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
 
        size++;
    }
}
 
void Deck::PopFront(){
    if (IsEmpty())
        cout << "ERROR :: DECK IS EMPTY \n";
 
    else{
        head = head->next;
 
        // If only one element is present
        if (head == NULL)   
            tail = NULL;
        else
            head->prev = NULL;
 
        size--;
    }
}
 
void Deck::PopBack(){
    if (IsEmpty())
        cout << "ERROR :: DECK IS EMPTY \n";
 
    else{
        tail = tail->prev;
 
        // If only one element is present
        if (tail == NULL)
            head = NULL;
        else
            tail->next = NULL;
 
        size--;
    }
}
 
int Deck::GetFront(){
    if (IsEmpty())
        return -1;
    return head->data;
}
 
int Deck::GetBack(){
    if (IsEmpty())
        return -1;
    return tail->data;
}
 
void Deck::Erase(){
    tail = NULL;
    while (head != NULL){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}
void Deck::Display(){
    Node *temp = head;   			
    while(temp != NULL){
        cout << temp->data << "\t"; 
        temp = temp->next; 			
    }
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
    Deck d;
    while(true){
        cout<<"\n------------------------------------- \n";
        d.Display();
        int selection;

        cout<<"\n------------------------------------- \n";
        cout<<"[0] :: exit program \n";
        cout<<"[1] :: PushBack() \n";
        cout<<"[2] :: PushFront() \n";
        cout<<"[3] :: PopFront() \n";
        cout<<"[4] :: PopBack() \n";
        cout<<"[5] :: GetFront() \n";
        cout<<"[6] :: GetBack() \n";
        cout<<"[7] :: IsEmpty() \n";
        cout<<"[8] :: Clear() \n";

        cout<<"Please select your next move: ";
        cin>>selection;
        
        switch(selection){
            int x;
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
                cout<<"First element deleted from the deck \n";
                cout<<"\n------------------------------------- \n";
                d.PopFront();
                break;
            case 4:
                cout<<"\n------------------------------------- \n";
                cout<<"Last element deleted from the deck \n";
                cout<<"\n------------------------------------- \n";
                d.PopBack();
                break;
            case 5:
                cout<<"\n------------------------------------- \n";
                cout<<"FRONT:: "<<d.GetFront();
                cout<<"\n------------------------------------- \n";
                break;
            case 6:
                cout<<"\n------------------------------------- \n";
                cout<<"BACK:: "<<d.GetBack();
                cout<<"\n------------------------------------- \n";
                break;
            case 7:
                if(d.IsEmpty()==1){
                    cout<<"\n------------------------------------- \n";
                    cout<<"--Deck is empty--\n";
                    cout<<"\n------------------------------------- \n";
                }
                else{
                    cout<<"\n------------------------------------- \n";
                    cout<<"Deck is not empty \n";
                    cout<<"Size: "<<d.Size();
                    cout<<"\n------------------------------------- \n";
                }
                break;
            case 8:
                d.Erase();
                cout<<"\n------------------------------------- \n";
                cout<<"The deck has been cleared \n";
                cout<<"\n------------------------------------- \n";
                break;
            default:
                cout<<"\n------------------------------------- \n";
                cout<<"ERROR:: Wrong option";
                cout<<"\n Program halted\n";
                cout<<"\n------------------------------------- \n";
                return 0;
                break;

        }

        Clear();
    }
    
}