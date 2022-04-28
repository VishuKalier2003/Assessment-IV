// Assessment 5...
/*Using Stack data structure check if the entered word is a Palindrome or Not...*/
#include <iostream>
using namespace std;
class Node             // Node class for defining Node attributes
{
    public:    // Data members
        char character;
        Node* next;
        Node(char ch)    // Parametrized Constructor
        {
            character = ch;
            next = NULL;
        }
};
class Stack     // class Stack to Implement Stack Data Structure
{
    public:     // Top Pointer as data member
        Node* top;
        Stack()       // Default Constructor
        {
            top = NULL;
        }
        void Push(char value)      // Push Operation O(1) time...
        {
            Node* n = new Node(value);
            if(top == NULL)     // If Stack is Empty 
            {
                top = n;
                return;
            }
            n -> next = top;      // Otherwise
            top = n;
        }
        void Pop()      // Pop Operation O(1) time...
        {
            if(top == NULL)     // Stack Underflow Condition
            {
                cout << "Since the Stack is empty nothing can be popped out !!" << endl;
                return;
            }
            Node* temp = top;    // Otherwise
            top = temp -> next;
            delete temp;
        }
        void PrintStack()    // Printing Stack Operation O(n) time...
        {
            Node* temp = top;
            if(temp != NULL)
            {
                cout << " Top <--- \t";
                cout << temp -> character << "\t";
                temp = temp -> next;
            }
            for(; temp != NULL; temp = temp -> next)
            {
                cout << temp -> character << "\t";
            }
            cout << endl;
        }
        bool IsEmpty()    // Stack Empty Operation O(1) time...
        {
            if(top == NULL)    // If top points to Null
                return true;      // Stack is Empty
            return false;     // Otherwise Stack is not EMpty
        }
};
int main()
{
    string str;
    int s = 0;
    Stack stack1, stack2;    // Creating Two Stacks
    cout << "Enter a String or a word : ";
    cin >> str;
    for(int i = 0; i < str.length(); i++)    // Loop for Entering String characters in reverse order
    {
        stack1.Push(str[i]);
    }
    for(int i = 0; i < str.length(); i++)   // Loop for Entering String characters in normal order
    {
        stack2.Push(str[str.length() - (i+1)]);
    }
    cout << "The First Stack : " << endl;   // Printing Stack
    stack1.PrintStack();     
    cout << "The Second Stack : " << endl;  // Printing Stack
    stack2.PrintStack();
    while(!stack1.IsEmpty() && s == 0)
    {
        if(stack1.top -> character == stack2.top -> character)
        {     // If the top pointer points to the same character in both Stacks
            stack1.Pop();    // Pop top of Stack1
            stack2.Pop();    // Pop top of Stack2
        }
        else   // Otherwise
        {
            cout << "The Entered Word is not a Palindrome !!" << endl;
            s = 1;
        }
    }
    if(stack1.IsEmpty() == true && stack2.IsEmpty() == true)    // If both Stacks are empty
        cout << "The Entered Word is a Palindrome !!" << endl;
    return 0;    // End of the program
}