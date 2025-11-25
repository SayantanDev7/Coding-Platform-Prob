#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
    };
class Solution {
public:
    vector<int> findCommon(Node *r1, Node *r2) {

        stack<Node*> s1, s2;
        vector<int> common;

        // push all left of r1
        while (r1) {
            s1.push(r1);
            r1 = r1->left;
        }

        // push all left of r2
        while (r2) {
            s2.push(r2);
            r2 = r2->left;
        }

        while (!s1.empty() && !s2.empty()) {

            Node* a = s1.top();   // always compare stack top
            Node* b = s2.top();

            if (a->data == b->data) {
                common.push_back(a->data);

                // move a to its right subtree
                s1.pop();
                a = a->right;
                while (a) {
                    s1.push(a);
                    a = a->left;
                }

                // move b to its right subtree
                s2.pop();
                b = b->right;
                while (b) {
                    s2.push(b);
                    b = b->left;
                }
            }
            else if (a->data < b->data) {

                // pop a and move to its right subtree
                s1.pop();
                a = a->right;
                while (a) {
                    s1.push(a);
                    a = a->left;
                }
            }
            else {

                // pop b and move to its right subtree
                s2.pop();
                b = b->right;
                while (b) {
                    s2.push(b);
                    b = b->left;
                }
            }
        }
        return common;
    }
};
