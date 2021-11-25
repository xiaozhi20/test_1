#include<iostream>
#include<queue>
#include<vector>
#include<malloc.h>

using namespace std;
struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		data(x), left(NULL), right(NULL) {
	}
};

TreeNode* CreateBiTree()//创建时要注意  每一层根节点其后的空结点都要输入 0（如果左右都为空 需要输入两个零  ）
{
    int a;
    TreeNode* T;
    cin>>a;
    if (a == 0)
    {
        T = NULL;
        

    }
    else
    {
        T = (TreeNode*)malloc(sizeof(TreeNode));//注意是按前序输入的
        T->data = a;
        T->left=CreateBiTree();
        T->right=CreateBiTree();
    }
    return T;//返回根节点
}

//二叉树的层序遍历   核心队列 
vector<int> CBfun(TreeNode* root) {
    vector<int>v;
    if (root == nullptr)return v;
    queue<TreeNode*>q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* n = q.front();//相当于把队列中首元素的地址赋给n  那么n与q所指内容应该是一样的   
        q.pop();//此处是把队列中首元素弹出
        v.push_back(n->data);//但是此时n依旧指向首元素
        if (n->left)q.push(n->left);
        if (n->right)q.push(n->right);
        //q.pop();//所以弹出操作也可以放最后
    }     
    return v;
}

//二叉树的层序遍历   核心队列 
//严格按层打印
vector<int> CBfun2(TreeNode* root) {
    vector<int>v;
    if (root == nullptr)return v;
    queue<TreeNode*>q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        
        while (size--) {
            TreeNode* n = q.front();//辅助结点一定要有  
            q.pop();//此处是把队列中首元素弹出
            cout << n->data<<" ";
            v.push_back(n->data);//但是此时n依旧指向首元素
            if (n->left)q.push(n->left);
            if (n->right)q.push(n->right);
            //q.pop();//所以弹出操作也可以放最后
        }
        cout << endl;
    }
    return v;
}

//前序遍历  核心递归
void PreOrderTraverse(TreeNode* T)
{
    if (!T)
        return;
    cout << T->data;    //显示节点数据
    PreOrderTraverse(T->left);
    PreOrderTraverse(T->right);
}


int main()
{
    vector<int>v;

    TreeNode* root= CreateBiTree();
    cout << "创建完毕！" << endl;
    
    
    
    PreOrderTraverse(root);//前序遍历


    v=CBfun2(root);
    cout << "vector: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }


    return 0;
}