#include <iostream>
#include <array>
// using namespace std;

class Stack
{
private:
    std::array<int, 20> arr;

public:
    int top;
    int size = arr.size();

    Stack() { top = -1; }

    void makeEmpty()
    {
        top = -1;
        std::cout << "Stack Emptied." << std::endl;
    }

    bool isOverFlow()
    {
        if (top > size - 1)
        {
            return 1;
        }
        return 0;
    }

    bool isUnderFlow()
    {
        if (top < 0)
        {
            return 1;
        }
        return 0;
    }

    bool isEmpty()
    {
        if (isUnderFlow())
        {
            return 1;
        }
        return 0;
    }

    int get_top()
    {
        return this->arr[top];
    }

    void push(int data)
    {
        if (!isOverFlow())
        {
            top++;
            this->arr[top] = data;
            std::cout << data << " pushed successfully!!" << std::endl;
        }
        else
        {
            std::cout << "Stack Overflow. Cannot push data\b" << std::endl;
        }
    }

    void pop()
    {
        if (!isUnderFlow())
        {
            int data = this->arr[top];
            top--;
            std::cout << data << " popped successfully!!" << std::endl;
        }
        else
        {
            std::cout << "Pop operation unsuccessful!!" << std::endl;
        }
    }

    void peakOp(int data)
    {
        if (!isEmpty())
        {
            this->arr[top] = data;
            std::cout << "Peak operation successful." << std::endl;
        }
        else
        {
            std::cout << "Peak operation unsuccessful!!" << std::endl;
        }
    }

    void stackTraversal()
    {
        std::cout << "Stack traversal from top to bottom:" << std::endl;
        int top_store = top;
        while (!isUnderFlow())
        {
            std::cout << arr[top] << " ";
            top--;
        }
        top = top_store;
    }

    void displayEmpty()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
        }
        else
        {
            std::cout << "Stack is not empty." << std::endl
                      << "Top pointer: " << top << std::endl;
        }
    }
};

int main()
{
    Stack stack;

    // test cases
    std::cout << std::endl;
    stack.displayEmpty();
    std::cout << std::endl;
    stack.push(4);
    std::cout << std::endl;
    stack.stackTraversal();
    std::cout << std::endl;
    stack.pop();
    std::cout << std::endl;
    stack.stackTraversal();
    std::cout << std::endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    std::cout << std::endl;
    stack.stackTraversal();
    std::cout << std::endl;
    stack.displayEmpty();
    std::cout << std::endl;
    std::cout << stack.get_top();
    std::cout << std::endl;
    stack.peakOp(5);
    std::cout << std::endl;
    stack.stackTraversal();
    std::cout << std::endl;
    stack.makeEmpty();
    stack.stackTraversal();

    return 0;
}
