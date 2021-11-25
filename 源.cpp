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

TreeNode* CreateBiTree()//����ʱҪע��  ÿһ����ڵ����Ŀս�㶼Ҫ���� 0��������Ҷ�Ϊ�� ��Ҫ����������  ��
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
        T = (TreeNode*)malloc(sizeof(TreeNode));//ע���ǰ�ǰ�������
        T->data = a;
        T->left=CreateBiTree();
        T->right=CreateBiTree();
    }
    return T;//���ظ��ڵ�
}

//�������Ĳ������   ���Ķ��� 
vector<int> CBfun(TreeNode* root) {
    vector<int>v;
    if (root == nullptr)return v;
    queue<TreeNode*>q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* n = q.front();//�൱�ڰѶ�������Ԫ�صĵ�ַ����n  ��ôn��q��ָ����Ӧ����һ����   
        q.pop();//�˴��ǰѶ�������Ԫ�ص���
        v.push_back(n->data);//���Ǵ�ʱn����ָ����Ԫ��
        if (n->left)q.push(n->left);
        if (n->right)q.push(n->right);
        //q.pop();//���Ե�������Ҳ���Է����
    }     
    return v;
}

//�������Ĳ������   ���Ķ��� 
//�ϸ񰴲��ӡ
vector<int> CBfun2(TreeNode* root) {
    vector<int>v;
    if (root == nullptr)return v;
    queue<TreeNode*>q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        
        while (size--) {
            TreeNode* n = q.front();//�������һ��Ҫ��  
            q.pop();//�˴��ǰѶ�������Ԫ�ص���
            cout << n->data<<" ";
            v.push_back(n->data);//���Ǵ�ʱn����ָ����Ԫ��
            if (n->left)q.push(n->left);
            if (n->right)q.push(n->right);
            //q.pop();//���Ե�������Ҳ���Է����
        }
        cout << endl;
    }
    return v;
}

//ǰ�����  ���ĵݹ�
void PreOrderTraverse(TreeNode* T)
{
    if (!T)
        return;
    cout << T->data;    //��ʾ�ڵ�����
    PreOrderTraverse(T->left);
    PreOrderTraverse(T->right);
}


int main()
{
    vector<int>v;

    TreeNode* root= CreateBiTree();
    cout << "������ϣ�" << endl;
    
    
    
    PreOrderTraverse(root);//ǰ�����


    v=CBfun2(root);
    cout << "vector: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }


    return 0;
}