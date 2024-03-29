#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define N_MAX 1000001

using namespace std;

typedef struct Node* treePointer;

typedef struct Node {
    int data;
    pair<int,int> location;
    treePointer left;
    treePointer right;
} Node;

Node tree[N_MAX];
vector<int> pre;
vector<int> post;

int get_root(vector<int> nodes) {
    int root = -1;
    int rootY = -1;
    for (int i : nodes) {
        Node node = tree[i];
        int y = node.location.second;
        if (y > rootY) {
            rootY = y;
            root = i;
        }
    }
    
    return root;
}

void build(vector<int> nodes, int root) {
    if (nodes.empty() || root < 0) return;
    
    int rootX = tree[root].location.first;
    
    vector<int> leftnodes;
    vector<int> rightnodes;
    
    for (int i : nodes) {
        Node node = tree[i];
        int x = node.location.first;
        if (x < rootX) leftnodes.push_back(i);
        else if (x > rootX) rightnodes.push_back(i);
    }
    
    int leftRoot = get_root(leftnodes);
    int rightRoot = get_root(rightnodes);
    
    if (leftRoot  != -1) tree[root].left  = &tree[leftRoot];
    if (rightRoot != -1) tree[root].right = &tree[rightRoot];
    
    build(leftnodes , leftRoot );
    build(rightnodes, rightRoot);
}

void preorder(treePointer node) {
    if (!node) return;
    
    pre.push_back(node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(treePointer node) {
    if (!node) return;
    
    postorder(node->left);
    postorder(node->right);
    post.push_back(node->data);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    const int E = nodeinfo.size();
    vector<int> allinfo;
    for (int i = 0; i < E; i++) {
        Node node;
        node.data = i+1;
        node.location = { nodeinfo[i][0], nodeinfo[i][1] };
        node.left = node.right = nullptr;
        tree[i+1] = node;
        allinfo.push_back(i+1);
    }
    
    int root = get_root(allinfo);
    build(allinfo, root);
    
    preorder (&tree[root]);
    postorder(&tree[root]);
    
    vector<vector<int>> answer;
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}