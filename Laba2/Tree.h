#include <iostream>
#include "Tmp.h"
#include "List2.h"

using namespace std;

class Tree
{
private:
    class TreeNode 
    {
    private:

    public:
        List2 data; 
        TreeNode* left; 
        TreeNode* right; 
        TreeNode(List2 intdata)
        {
            data = intdata; 
            left = NULL; 
            right = NULL;
        }
    };
    
public:
    tmp<char, List<bool>> map;
    TreeNode* root;
    Tree()
    {
        root = NULL;
    }
    List2 sortSequence(List2 list)
    {
        int sequence_size = list.get_size();
        char* arrayForFixChar = new char[sequence_size];
        int* arrayForFixInt = new int[sequence_size];
        Node2* cur = list.get_head();
        for (int i = 0; i < sequence_size; i++)
        {
            arrayForFixChar[i] = cur->key;
            arrayForFixInt[i] = cur->data;
            cur = cur->next;
        }
        
        for (int i = 0; i < sequence_size - 1; i++)
        {
            for (int j = 0; j < sequence_size - 1 - i; j++)
            {
                if (arrayForFixInt[j] > arrayForFixInt[j + 1])
                {
                    swap(arrayForFixInt[j], arrayForFixInt[j + 1]);
                    swap(arrayForFixChar[j], arrayForFixChar[j + 1]);
                }
            }
        }
        List2 list_new;
        for (int i = 0; i < sequence_size; i++)
        {
            list_new.push_front(arrayForFixChar[i], arrayForFixInt[i]);
        }
        return list_new;
    }
    List2 getSequence(string input)
    {
        List2 list; 
        for (int i = 0; i < input.length(); i++)
        {
            if (list.contains(input[i]))
            {
                list.increase_periodicity(input[i]);
            }
            else
            {
                list.push_back(input[i], 1);
            }
        }
        list = sortSequence(list);
        return list;
    }
    List2 fix_left(List2 old_list, char key)
    {
        List2 list;
        list.copy(old_list);
        Node2* cur = list.get_head();
        while (cur->key != key)
        {
            cur = cur->next;
        }
        while (cur->next != NULL)
        {
            list.pop_back();
        }
        return list;
    }
    List2 fix_right(List2 old_list, char key)
    {
        List2 right = fix_left(old_list, key);
        return right.reverse();
    }
   
    void create_tree(TreeNode* cur, List2 list, List<bool> code)
    {
        cur = new TreeNode(list);        
        if (list.get_size() > 1)
        {
            List2 left_list = list;
            List2 right_list = list.reverse();
            Node2* left = left_list.get_head();
            Node2* right = right_list.get_head();
            int left_counter = left->data;
            int right_counter = right->data;
            while (right->next->key != left->key)
            {
                while ((right_counter < left_counter) && (right->next->key != left->key))
                {
                    right = right->next;
                    right_counter = right_counter + right->data;
                }
                if (right->next->key != left->key)
                {
                    left = left->next;
                    left_counter = left_counter + left->data;
                }
            }
            List<bool> code_left;
            code_left.copy(code);
            code_left.push_back(true);
            left_list = fix_left(left_list, left->key);
            create_tree(cur->left, left_list, code_left);

            List<bool> code_right;
            code_right.copy(code);
            code_right.push_back(false);
            right_list = fix_right(right_list, right->key);
            create_tree(cur->right, right_list, code_right);
        }
        else
        {
            map.insert(list.return_char_one(), code);
        }
    }
    List<List<bool>> create_code(string input)
    {
        List<List<bool>> list;
        for (int i = 0; i < input.length(); i++)
        {
            list.push_back(map.find(input[i]));
        }
        return list;
    }
    void print_code(List<List<bool>> list)
    {
        for (int i = 0; i < list.get_size(); i++)
        {
            list.at(i).printList();
        }
    }
    int get_code_size(List<List<bool>> list)
    {
        int sum_size = 0;
        for (int i = 0; i < list.get_size(); i++)
        {
            sum_size = sum_size + list.at(i).get_size();
        }
        return sum_size;
    }
    char decode_one_char(List<bool> list)
    {
        List<char> keys = map.get_keys();
        List< List<bool>> values = map.get_values();
        for (int i = 0; i < values.get_size(); i++)
        {
            if (list.equal(values.at(i)))
            {
                return keys.at(i);
            }
        }
    }
    string decode(List<List<bool>> list)
    {
        string rez = "";
        for (int i = 0; i < list.get_size(); i++)
        {
            rez = rez + decode_one_char(list.at(i));
        }
        return rez;
    }
};