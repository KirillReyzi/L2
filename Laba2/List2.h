#include <iostream>
using namespace std;

class Node2
{
private:

public:
    int data;
    char key;
    Node2* next;
    Node2(char initkey, int intdata)
    {
        key = initkey;
        data = intdata;
        next = NULL;
    }
    Node2* getNext()
    {
        return next;
    }
    void setData(char newKey, int newData)
    {
        data = newData;
        key = newKey;
    }
    void setNext(Node2* newNext)
    {
        next = newNext;
    }
};

class List2
{
private:
    Node2* head;
    unsigned int error;
    Node2* search(size_t index)
    {
        Node2* cur = head;
        size_t counter = 0;
        while (counter < index)
        {
            cur = cur->getNext();
            counter++;
        }
        return cur;
    }
    void insert_first(char newKey, int newData)
    {
        Node2* newNode2 = new Node2(newKey, newData);
        head = newNode2;
    }
    void delete_one()
    {
        Node2* tmp = head;
        head = NULL;
        delete tmp;
    }
public:
    List2()
    {
        head = NULL;
        error = 0;
    }
    Node2* get_head()
    {
        return head;
    }
    void reset_error()
    {
        error = 0;
    }
    unsigned int get_error()
    {
        return error;
    }

    void push_back(char newKey, int newData)
    {
        if (isEmpty())
        {
            insert_first(newKey, newData);
        }
        else
        {
            Node2* tmp = new Node2(newKey, newData);
            Node2* cur = head;
            while (cur->getNext() != NULL) { cur = cur->getNext(); }
            cur->setNext(tmp);
        }
    }
    void push_front(char newKey, int newData)
    {
        if (isEmpty())
        {
            insert_first(newKey, newData);
        }
        else
        {
            Node2* tmp = new Node2(newKey, newData);
            tmp->setNext(head);
            head = tmp;
        }
    }
    void pop_back()
    {
        if (isEmpty())
        {
            error = 1;
        }
        else
        {
            if (head->getNext() == NULL)
            {
                delete_one();
            }
            else
            {
                Node2* cur = head;
                Node2* tmp = cur->getNext();
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
            error = 1;
        }
        else
        {
            Node2* tmp = head;
            head = head->getNext();
            delete tmp;
        }
    }
    void insert_Node2(char newKey, int newData, size_t index)
    {
        if ((isEmpty()) || (get_size() <= index))
        {
            if (get_size() == index)
            {
                push_back(newKey, newData);
            }
            else
            {
                error = 1;
            }
        }
        else
        {
            if (index == 0)
            {
                push_front(newKey, newData);
            }
            else
            {
                Node2* prev = search(index - 1);
                Node2* newNode2 = new Node2(newKey, newData);
                newNode2->setNext(prev->getNext());
                prev->setNext(newNode2);
            }
        }
    }
    void remove(size_t index)
    {
        if ((isEmpty()) || (get_size() <= index))
        {
            error = 1;
        }
        else
        {
            if (index != 0)
            {
                Node2* forDelete = search(index);
                Node2* prev = search(index - 1);
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
        Node2* cur = head;
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
        Node2* cur;
        while (head != NULL)
        {
            cur = head->getNext();
            delete head;
            head = cur;
        }
    }
    void set(size_t index, char newKey, int newData)
    {
        if ((isEmpty()) || (get_size() <= index))
        {
            error = 1;
        }
        else
        {
            search(index)->setData(newKey, newData);
        }
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    void insert_List2(List2* newList2, size_t index)
    {
        if (newList2->head != NULL)
        {
            if ((isEmpty()) || (get_size() < index))
            {
                if (index == 0)
                {
                    head = newList2->head;
                }
                else
                {
                    error = 1;
                }
            }
            else
            {
                if (index == 0)
                {
                    Node2* tmp = newList2->head;
                    while (tmp->getNext() != NULL)
                    {
                        tmp = tmp->getNext();
                    }
                    tmp->setNext(head->getNext());
                    head->setNext(tmp);
                }
                else
                {
                    Node2* prev = search(index - 1);
                    Node2* newList2_cur = newList2->head;
                    while (newList2_cur->getNext() != NULL)
                    {
                        newList2_cur = newList2_cur->getNext();
                    }
                    newList2_cur->setNext(prev->getNext());
                    prev->setNext(newList2->head);
                }
            }
        }
    }
    void printList2()
    {
        Node2* cur = head;
        while (cur != NULL)
        {
            cout << cur->key << ", " << cur->data << "->";
            cur = cur->next;
        }
        cout << "XXX\n";
    }
    List2 reverse()
    {
        Node2* cur = head;
        List2 reverce_list;
        while (cur != NULL)
        {
            reverce_list.push_front(cur->key, cur->data);
            cur = cur->next;
        }
        return reverce_list;
    }
    bool contains(char x)
    {
        Node2* cur = head;
        while (cur != NULL)
        {
            if (cur->key == x)
            {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
    void increase_periodicity(char x)
    {
        Node2* cur = head;
        while (cur->key != x)
        {
            cur = cur->next;
        }
        cur->data++;
    }
    int return_data(char x)
    {
        {
            Node2* cur = head;
            while (cur->key != x)
            {
                cur = cur->next;
            }
            return cur->data;
        }
    }
    char return_char_one()
    {
        return head->key;
    }
    void copy(List2 listNew)
    {
        Node2* curNew = listNew.get_head();
        while (curNew != NULL)
        {
            push_back(curNew->key, curNew->data);
            curNew = curNew->next;
        }
    }
};