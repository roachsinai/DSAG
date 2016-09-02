# include<iostream>
using namespace std;

// 二叉树结点的定义
template<class T>
struct TreeNode
{
    T data;
    TreeNode<T> *lChild, *rChild;
    
    TreeNode(T value) : data(value), lChild(NULL), rChild(NULL) {}
};

// 二叉树的建立，先序建立
template <class T>
void createBinaryTree(TreeNode<T>* &root)
{
    TreeNode<T>* p = root;
    T value;
    cin >> value;
    
    // 如果 value 值为 -1，说明当前是一个空节点
    if (value == -1)
        root = NULL;
    else
    {
        root = new TreeNode<T>(value);
        
        createBinaryTree(root->lChild);
        createBinaryTree(root->rChild);
    }
}

// 遍历

// 先序遍历
template <class T>
void preOrder(TreeNode<T>* &p)
{
    if (p)
    {
        cout << p->data << "  ";
        
        preOrder(p->lChild);
        preOrder(p->rChild);
    }
}

// 中序遍历
template <class T>
void inOrder(TreeNode<T>* &p)
{
    if (p)
    {
        inOrder(p->lChild);
        
        cout << p->data << "  ";
        
        inOrder(p->rChild);
    }
}

// 后序遍历
template <class T>
void postOrder(TreeNode<T>* &p)
{
    if (p)
    {
        postOrder(p->lChild);
        postOrder(p->rChild);
        
        cout << p->data << "  ";
    }
}

// 统计二叉树中节点的个数
template <class T>
int countNode(TreeNode<T>* p)
{
    if (p == NULL)
        return 0;
        
    return 1 + countNode(p->lChild) + countNode(p->rChild);
}

// 得到二叉树的深度
template <class T>
int getDepth(TreeNode<T>* &p)
{
    if (p == NULL)
        return 0;
        
    int left = getDepth(p->lChild);
    int right = getDepth(p->rChild);
    
    return left > right ? left + 1 : right + 1;
}

// 二叉树的销毁
template <class T>
void destroyTree(TreeNode<T>* &p)
{
    if (p)
    {
        destroyTree(p->lChild);
        destroyTree(p->rChild);
        
        delete p;
        
        p = NULL; // 如果传进的参数不是引用，这一步无效，这样树的所有节点指针都将是野指针
                  // 野指针指向一个已删除的对象或未申请访问受限内存区域的指针
    }
}

// 一个可行的二叉树创建顺序：8 7 5 1 –1 –1 –1 4 –1 –1 6 3 –1 –1 2 –1 -1
// 除了-1节点之外的就是实际创建的二叉树
// -1不是实际的节点、输入-1仅表示子节点为空返回继续创建其他节点

int main()
{
    TreeNode<int> * rootNode = NULL;
    int choiced = 0;
    while(true)
    {
        system("cls"); //清屏
        cout<<"\n\n\n                              ---主界面---\n\n\n";
        cout<<"                     1、创建二叉树                2、先序遍历二叉树\n";
        cout<<"                     3、中序遍历二叉树            4、后序遍历二叉树\n";
        cout<<"                     5、统计结点总数              6、查看树深度    \n";
        cout<<"                     7、消毁二叉树                0、退出\n\n";
        cout<<"             请选择操作：";
        cin>>choiced;
        if(choiced == 0)
            return 0;
        else if(choiced == 1)
        {
            system("cls");
            cout<<"请输入每个结点，回车确认，并以-1结束：\n";
            createBinaryTree(rootNode );
        }
        else if(choiced == 2)
        {
            system("cls");
            cout<<"先序遍历二叉树结果：\n";
            preOrder(rootNode);
            cout<<endl;
            system("pause"); //暂停屏幕
        }
        else if(choiced == 3)
        {
            system("cls");
            cout<<"中序遍历二叉树结果：\n";
            inOrder(rootNode);
            cout<<endl;
            system("pause");
        }
        else if(choiced == 4)
        {
            system("cls");
            cout<<"后序遍历二叉树结果：\n";
            postOrder(rootNode);
            cout<<endl;
            system("pause");
        }
        else if(choiced == 5)
        {
            system("cls");
            int count = countNode(rootNode);
            cout<<"二叉树中结点总数为"<<count<<endl;
            system("pause");
        }
        else if(choiced == 6)
        {
            system("cls");
            int dep = getDepth(rootNode);
            cout<<"此二叉树的深度为"<<dep<<endl;
            system("pause");
        }
        else if(choiced == 7)
        {
            system("cls");
            cout<<"二叉树已被消毁！\n";
            destroyTree(rootNode);
            cout<<endl;
            system("pause");
        }
        else
        {
            system("cls");
            cout<<"\n\n\n\n\n\t错误选择！\n";
        } 
    }
    
    return 0;
}

// References:
// http://www.cnblogs.com/charley_yang/archive/2010/12/08/1900256.html