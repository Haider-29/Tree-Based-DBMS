#pragma once
#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include <string>
#include <cctype>
using namespace std;

template <class R>
class Node {

public:
    R data;
    LinkedList<string> location;
    string filename;
    Node* parent;
    Node* left;
    Node* right;
    bool color;     //0 pink - 1 purple

    Node()
    {
        parent = NULL;
        left = right = NULL;
        color = 0;
    }
};

template <class T>
class PinkPurpleTree {
private:
    Node<T>* root;
    Node<T>* tempN;

public:


    PinkPurpleTree() {
        tempN = new Node<T>;
        tempN->color = 0;
        tempN->left = nullptr;
        tempN->right = nullptr;
        root = tempN;
    }
    //----------------------------------------------------------------
    //----------------------------------------------------------------
    //-------------------------- SEARCHING ---------------------------

    Node<T>* getTempN() {

        return tempN;

    }

    Node<T>* searchForNode(Node<T>* node, T val)
    {
        if (node == tempN || val == node->data)
        {
            return node;
        }

        else if (val < node->data)
        {
            return searchForNode(node->left, val);
        }

        else if (val > node->data)
        {
            return searchForNode(node->right, val);
        }

    }

    Node<T>* search(T k)
    {
        Node<T>* nn = searchForNode(this->root, k);
        return nn;
    }


    //----------------------------------------------------------------
    //----------------------------------------------------------------
    //-------------------------- SEARCHING ---------------------------


    //----------------------------------------------------------------
    //----------------------------------------------------------------
    //-------------------------- INSERTING ---------------------------
    Node<T>* insert(T val)
    {
        Node<T>* node = new Node<T>;
        node->parent = NULL;
        node->data = val;
        node->left = tempN;
        node->right = tempN;
        node->color = 1;


        Node<T>* temp1 = this->root;
        Node<T>* temp2 = NULL;

        while (temp1 != tempN) {
            temp2 = temp1;
            if (node->data < temp1->data) {
                temp1 = temp1->left;
            }
            else {
                temp1 = temp1->right;
            }
        }

        node->parent = temp2;

        if (temp2 == NULL)
        {
            root = node;
        }
        else if (node->data < temp2->data)
        {
            temp2->left = node;
        }
        else
        {
            temp2->right = node;
        }

        if (node->parent == NULL)
        {
            node->color = 0;
            return node;
        }

        if (node->parent->parent == NULL)
        {
            return node;
        }

        insertrotation(node);

        return node;
    }

    // For balancing the tree after insertion

    void insertrotation(Node<T>* insertednode)
    {
        Node<T>* temp;
        while (insertednode->parent->color == 1)
        {
            if (insertednode->parent == insertednode->parent->parent->right)
            {
                temp = insertednode->parent->parent->left;
                if (temp->color == 1)
                {
                    temp->color = 0;
                    insertednode->parent->color = 0;
                    insertednode->parent->parent->color = 1;
                    insertednode = insertednode->parent->parent;
                }
                else
                {
                    if (insertednode == insertednode->parent->left)
                    {
                        insertednode = insertednode->parent;
                        rightRotate(insertednode);
                    }
                    insertednode->parent->color = 0;
                    insertednode->parent->parent->color = 1;
                    leftRotate(insertednode->parent->parent);
                }
            }
            else
            {
                temp = insertednode->parent->parent->right;

                if (temp->color == 1)
                {
                    temp->color = 0;
                    insertednode->parent->color = 0;
                    insertednode->parent->parent->color = 1;
                    insertednode = insertednode->parent->parent;
                }
                else
                {
                    if (insertednode == insertednode->parent->right)
                    {
                        insertednode = insertednode->parent;
                        leftRotate(insertednode);
                    }
                    insertednode->parent->color = 0;
                    insertednode->parent->parent->color = 1;
                    rightRotate(insertednode->parent->parent);
                }
            }

            if (insertednode == root)
            {
                break;
            }
        }

        root->color = 0;
    }


    //----------------------------------------------------------------
    //----------------------------------------------------------------
    //-------------------------- INSERTING ---------------------------


     //----------------------------------------------------------------
    //-----------------------------------------------------------------
    //-------------------------- DELETING -----------------------------

    void deleteNode(T data)
    {
        deleteNodetwo(this->root, data);
    }



    void deleteNodetwo(Node<T>* node, T key)
    {
        Node<T>* z = tempN;
        Node<T>* x, * y;
        while (node != tempN)
        {
            if (node->data == key)
            {
                z = node;
            }

            else if (node->data < key)
            {
                node = node->right;
            }

            else
            {
                node = node->left;
            }
        }

        if (z == tempN) {
            cout << "Key not found in the tree" << endl;
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == tempN) {
            x = z->right;
            ppTransplant(z, z->right);
        }
        else if (z->right == tempN) {
            x = z->left;
            ppTransplant(z, z->left);
        }
        else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            }
            else {
                ppTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            ppTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        delete z;

        if (y_original_color == 0)
        {
            deleteFix(x);
        }
    }

    void deleteFix(Node<T>* x)
    {
        Node<T>* s;
        while (x != root && x->color == 0) {
            if (x == x->parent->left) {
                s = x->parent->right;
                if (s->color == 1) {
                    s->color = 0;
                    x->parent->color = 1;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == 0 && s->right->color == 0) {
                    s->color = 1;
                    x = x->parent;
                }
                else {
                    if (s->right->color == 0) {
                        s->left->color = 0;
                        s->color = 1;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->right->color = 0;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else {
                s = x->parent->left;
                if (s->color == 1) {
                    s->color = 0;
                    x->parent->color = 1;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == 0 && s->right->color == 0) {
                    s->color = 1;
                    x = x->parent;
                }
                else {
                    if (s->left->color == 0) {
                        s->right->color = 0;
                        s->color = 1;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->left->color = 0;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = 0;
    }

    void ppTransplant(Node<T>* u, Node<T>* v)
    {
        if (u->parent == nullptr)
        {
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }


    void printHelper(Node<T>* root, string indent, bool last) {
        if (root != tempN) {
            cout << indent;
            if (last) {
                cout << "R----";
                indent += "   ";
            }
            else {
                cout << "L----";
                indent += "|  ";
            }

            string sColor = root->color ? "RED" : "BLACK";
            cout << root->data << "(" << sColor << ")" << endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

    void preorder() {
        preOrderHelper(this->root);
    }

    void inorder() {
        inOrderHelper(this->root);
    }

    void postorder(T num1, T num2) {
        postOrderHelper(this->root, num1, num2);
    }



    Node<T>* minimum(Node<T>* node) {
        while (node->left != tempN) {
            node = node->left;
        }
        return node;
    }

    Node<T>* maximum(Node<T>* node) {
        while (node->right != tempN) {
            node = node->right;
        }
        return node;
    }

    Node<T>* successor(Node<T>* x) {
        if (x->right != tempN) {
            return minimum(x->right);
        }

        Node<T>* y = x->parent;
        while (y != tempN && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }

    Node<T>* predecessor(Node<T>* x) {
        if (x->left != tempN) {
            return maximum(x->left);
        }

        Node<T>* y = x->parent;
        while (y != tempN && x == y->left) {
            x = y;
            y = y->parent;
        }

        return y;
    }

    void leftRotate(Node<T>* x) {
        Node<T>* y = x->right;
        x->right = y->left;
        if (y->left != tempN) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node<T>* x) {
        Node<T>* y = x->left;
        x->left = y->right;
        if (y->right != tempN) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }



    Node<T>* getRoot() {
        return this->root;
    }

    // Preorder
    void preOrderHelper(Node<T>* node) {
        if (node != tempN) {
            ofstream fout(node->filename);
            
            fout << node->left->filename << endl << node->right->filename << endl;

            LNode<string>* temp= new LNode<string>();
            temp = node->location.getHead();

            for (int i = 0; i < node->location.getSize(); i++) {

                fout << temp->getData() << endl;

                temp = temp->getNext();
                
            }

            //cout << node->location << "*" << node->left->filename << "*" << node->right->filename << endl;
            //cout << node->filename << endl;
            fout.close();
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }

    // Inorder
    void inOrderHelper(Node<T>* node) {
        if (node != tempN) {
            inOrderHelper(node->left);
            cout << node->data << " ";
            inOrderHelper(node->right);
        }
    }

    // Post order
    void postOrderHelper(Node<T>* node, T num1, T num2) {

        LinkedList<string> l = node->location;
        LNode<string>* lol = l.getHead();
        string location = "";
        string filename = "";
        int lineNum = -1;
        string temp = "";
        int countedStuff = 0;
        string data = "";
        
        if (node != tempN) {

            for(int i = 0; i < l.getSize(); i++){

                if (node->data >= num1 && node->data <= num2) {

                    location = lol->getData();

                    //cout << location << endl;

                    countedStuff = 0;

                    for (int j = 0; j < location.length(); j++) {

                        if (location[j] != ',') {

                            temp += location[j];

                        }

                        else {

                            if (countedStuff == 0) {

                                filename = temp;
                                temp = "";
                                countedStuff++;

                            }

                        }

                    }

                    lineNum = stoi(temp);

                    temp = "";

                    lol = lol->getNext();

                    ifstream fin(filename);

                    for (int i = 0; i < lineNum; i++) {

                        getline(fin, data);

                    }

                    cout << data << endl;

                    fin.close();

                }

            }

            postOrderHelper(node->left, num1, num2);
            postOrderHelper(node->right, num1, num2);
        }
    }

    void printTree() 
    {
        if (root) 
        {
            printHelper(this->root, "", true);
        }
    }

};