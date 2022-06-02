#include <iostream>
using namespace std;

template <class T>
class Node {
private:

public:
    T data; 
    Node* next; 
    Node(T intdata)
    {
        data = intdata; 
        next = NULL;
    }
    T getData() 
    {
        return data;
    }
    Node* getNext() 
    {
        return next;
    }
    void setData(T newData)
    {
        data = newData;
    }
    void setNext(Node* newNext) 
    {
        next = newNext;
    }
};

template <class T>
class List
{
private:
    Node<T>* head; 
    Node<T>* search(size_t index) 
    {
        Node<T>* cur = head; 
        size_t counter = 0;
        while (counter < index)
        {
            cur = cur->getNext();
            counter++;
        }
        return cur;
    }
    void insert_first(T newData) 
    {
        Node<T>* newNode = new Node<T>(newData);
        head = newNode;
    }
    void delete_one()
    {
        Node<T>* tmp = head;
        head = NULL;
        delete tmp;
    }
public:
    List() 
    {
        head = NULL;
        
    }
    Node<T>* get_head()
    {
        return head;
    }

    void push_back(T newData) 
    {
        if (isEmpty())
        {
            insert_first(newData);
        }
        else
        {
            Node<T>* tmp = new Node<T>(newData);
            Node<T>* cur = head; 
            while (cur->getNext() != NULL) { cur = cur->getNext(); }
            cur->setNext(tmp);
        }
    }
    void push_front(T newData) 
    {
        if (isEmpty())
        {
            insert_first(newData);
        }
        else
        {
            Node<T>* tmp = new Node<T>(newData);
            tmp->setNext(head);
            head = tmp;
        }
    }
    void pop_back() 
    {
        if (isEmpty())
        {
            throw invalid_argument("nothing to pop");
        }
        else
        {
            if (head->getNext() == NULL)
            {
                delete_one();
            }
            else
            {
                Node<T>* cur = head; 
                Node<T>* tmp = cur->getNext();
                while (tmp->getNext() != NULL)
                {
                    cur = cur->getNext();
                    tmp = tmp->getNext();
                }
                cur->setNext(NULL);
                delete tmp;
            }
        }
    }
    void pop_front() 
    {
        if (isEmpty())
        {
            throw invalid_argument("nothing to pop");
        }
        else
        {
            Node<T>* tmp = head;
            head = head->getNext();
            delete tmp;
        }
    }
    void insert_Node(T newData, size_t index)
    {
        if ((isEmpty()) || (get_size() <= index))
        {
            if (get_size() == index)
            {
                push_back(newData);
            }
            else
            {
                throw invalid_argument("wrong index");
            }
        }
        else
        {
            if (index == 0)
            {
                push_front(newData);
            }
            else
            {
                Node<T>* prev = search(index - 1); 
                Node<T>* newNode = new Node<T>(newData); 
                newNode->setNext(prev->getNext());
                prev->setNext(newNode);
            }
        }
    }
    T at(size_t index) 
    {
        if ((isEmpty()) || (get_size() <= index))
        {
            throw invalid_argument("wrong index");

        }
        else
        {
            return search(index)->getData();
        }
    }
    void remove(size_t index) 
    {
        if ((isEmpty()) || (get_size() <= index))
        {
            throw invalid_argument("nothing to remove");
        }
        else
        {
            if (index != 0)
            {
                Node<T>* forDelete = search(index); 
                Node<T>* prev = search(index - 1); 
                prev->setNext(forDelete->getNext());
                delete forDelete;
            }
            else
            {
                pop_front();
            }
        }
    }
    size_t get_size() 
    {
        Node<T>* cur = head; 
        size_t counter = 0;
        while (cur != NULL)
        {
            counter++;
            cur = cur->getNext();
        }
        return counter;
    }
    void clear() 
    {
        Node<T>* cur; 
        while (head != NULL)
        {
            cur = head->getNext();
            delete head;
            head = cur;
        }
    }
    void set(size_t index, T newData) 
    {
        if ((isEmpty()) || (get_size() <= index))
        {
            throw invalid_argument("wrong index");
        }
        else
        {
            search(index)->setData(newData);
        }
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    void insert_List(List* newList, size_t index)
    {
        if (newList->head != NULL)
        {
            if ((isEmpty()) || (get_size() < index))
            {
                if (index == 0)
                {
                    head = newList->head;
                }
                else
                {
                    throw invalid_argument("wrong index");
                }
            }
            else
            {
                if (index == 0)
                {
                    Node<T>* tmp = newList->head;
                    while (tmp->getNext() != NULL)
                    {
                        tmp = tmp->getNext();
                    }
                    tmp->setNext(head->getNext());
                    head->setNext(tmp);
                }
                else
                {
                    Node<T>* prev = search(index - 1); 
                    Node<T>* newList_cur = newList->head; 
                    while (newList_cur->getNext() != NULL)
                    {
                        newList_cur = newList_cur->getNext();
                    }
                    newList_cur->setNext(prev->getNext());
                    prev->setNext(newList->head);
                }
            }
        }
    }
    void printList()
    {
        Node<T>* cur = head;
        while (cur != NULL)
        {
            cout << cur->data;
            cur = cur->next;
        }
        cout << "  ";
    }
    void copy(List<T> listNew)
    {
        Node<T>* curNew = listNew.get_head();
       
        while (curNew != NULL)
        {
            push_back(curNew->data);
            curNew = curNew->next;
        }
    }
    bool equal(List<T> listNew)
    {
        if (listNew.get_size() != get_size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < get_size(); i++)
            {
                if (listNew.at(i) != at(i))
                {
                    return false;
                }
            }
            return true;
        }
    }
};

