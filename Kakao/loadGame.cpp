//
// Created by 양시연 on 2019/11/08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> post;
vector <int> pre;

bool compare(const vector<int> &v1, const vector<int> &v2){
    if(v1[1] > v2[1])
        return true;
    else if(v1[1] == v2[1])
        return v1[0] < v2[0];
    else
        return false;
}

class Node{
public:
    int data;
    int x;
    Node *left;
    Node *right;

    Node(int _data, int _x, Node* _left =NULL , Node* _right =NULL){
        data = _data;
        x = _x;
        left = _left;
        right = _right;
    }
};

class Tree{
public:
    Node* root;
    Tree(int data, int x){
        root = new Node(data, x);
    }

    void insert(Node *&node, int data, int x){
        if(node == NULL){
            node = new Node(data, x);
        }else if(x > node->x) {
            insert(node->right, data, x);
        }else if (x < node->x){
            insert(node->left, data, x);
        }
    }

    Node* getRoot(){
        return root;
    }

    int visit(Node *current) {
        return current->data;
    }

    // 전위 순회 Current - Left - Right
   void preorder(Node *current) {
        if (current != NULL) {
            if(visit(current) != NULL)
                pre.push_back(visit(current));
            preorder(current->left);
            preorder(current->right);
        }
    }

    // 중위 순회 Left - Current - Right
    void inorder(Node *current) {
        if (current != NULL) {
            inorder(current->left);
            visit(current);
            inorder(current->right);
        }
    }

    // 후위 순회 Left - Right - Current
    void postorder(Node *current) {
        if (current != NULL) {
            postorder(current->left);
            postorder(current->right);
            if(visit(current) != NULL)
                post.push_back(visit(current));
        }
    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    for(int i = 0 ; i < nodeinfo.size(); i++){
        nodeinfo[i].push_back(i+1);
    }
    sort(nodeinfo.begin(), nodeinfo.end(), compare);
    Tree tree(nodeinfo[0][2], nodeinfo[0][0]);
    Node *root = tree.getRoot();
    for(int i = 1; i < nodeinfo.size(); i++){
        tree.insert(root, nodeinfo[i][2], nodeinfo[i][0]);
    }

    tree.preorder(root);
    tree.postorder(root);

    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}

int main(){

    vector<vector<int>> result = solution({{5,3}, {11,5}, {13,3}, {3,5}, {6,1}, {1,3}, {8,6}, {7,2}, {2,2}});

    for(int i = 0; i <result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] <<" ";
        }
        cout << endl;
    }

    return 0;


}