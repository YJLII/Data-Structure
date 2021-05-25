#include <stdio.h>
#include <time.h>
#include <malloc.h>
#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif
#define N 100000
#define M 1000
struct BinarySearchTreeNode {
    int data;
    struct BinarySearchTreeNode* left;
    struct BinarySearchTreeNode* right;
}BST;

struct AVLTreeNode {
    int data;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
    int height;
}AVL;

struct BinarySearchTreeNode* BSTFind(struct BinarySearchTreeNode* root, int data) {
    if (root == NULL)
        return NULL;
    if (data < root->data)
        return BSTFind(root->left, data);
    else if (data > root->data)
        return BSTFind(root->right, data);
    return root;
}
struct AVLTreeNode* AVLFind(struct AVLTreeNode* root, int data) {
    if (root == NULL)
        return NULL;
    if (data < root->data)
        return AVLFind(root->left, data);
    else if (data > root->data)
        return AVLFind(root->right, data);
    return root;
}

struct AVLTreeNode* AVLFindMin(struct AVLTreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    else if (root->left == NULL)
        return root;
    else
        return AVLFindMin(root->left);
}
struct BinarySearchTreeNode* BSTFindMin(struct BinarySearchTreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    else if (root->left == NULL)
        return root;
    else
        return BSTFindMin(root->left);
}
struct BinarySearchTreeNode* BSTInsert(struct BinarySearchTreeNode* root, int data) {
    if (root == NULL) {
        root = (struct BinarySearchTreeNode*)malloc(sizeof(struct BinarySearchTreeNode));
        if (root == NULL) {
            printf("Memory Error");
            return NULL;
        }
        else {
            root->data = data;
            root->left = root->right = NULL;
        }
    }
    else {
        if (data < root->data)   root->left = BSTInsert(root->left, data);
        else if (data > root->data)   root->right = BSTInsert(root->right, data);
    }
    return root;
}//For Number 1
int Height(struct AVLTreeNode* root) {
    if (!root) return -1;
    else return root->height;
}

struct AVLTreeNode* SingleRotateLeft(struct AVLTreeNode* X) {
    struct AVLTreeNode* W = X->left;
    X->left = W->right;
    W->right = X;
    X->height = max(Height(X->left), Height(X->right)) + 1;
    W->height = max(Height(W->left), X->height) + 1;
    return W; //새 루트 노드
}
struct AVLTreeNode* SingleRotateRight(struct AVLTreeNode* W) {
    struct AVLTreeNode* X = W->right;
    W->right = X->left;
    X->left = W;
    W->height = max(Height(W->left), Height(W->right)) + 1;
    X->height = max(W->height, Height(X->right)) + 1;
    return X;
}
struct AVLTreeNode* DoubleRotatewithLeft(struct AVLTreeNode* Z) {
    Z->left = SingleRotateRight(Z->left);
    return  SingleRotateLeft(Z);
}
struct AVLTreeNode* DoubleRotatewithRight(struct AVLTreeNode* X) {
    X->right = SingleRotateLeft(X->right);
    return  SingleRotateRight(X);
}

struct AVLTreeNode* AVLInsert(struct AVLTreeNode* root, int data) {
    if (!root) {
        root = (struct AVLTreeNode*)malloc(sizeof(struct AVLTreeNode*));
        if (!root) {
            printf("Memory Error");
            return NULL;
        }
        else {
            root->data = data;
            root->height = 0;
            root->left = root->right = NULL;
        }
    }
    else if (data < root->data) {  // 왼쪽으로
        root->left = AVLInsert(root->left, data);
        if ((Height(root->left) - Height(root->right)) == 2) {
            if (data < root->left->data)    // LeftLeft
                root = SingleRotateLeft(root);
            else root = DoubleRotatewithLeft(root);   // LeftRight
        }
    }
    else if (data > root->data) {  // 오른쪽으로
        root->right = AVLInsert(root->right, data);
        if ((Height(root->right) - Height(root->left)) == 2) {
            if (data > root->right->data)    // RightRight
                root = SingleRotateRight(root);
            else root = DoubleRotatewithRight(root);   // RightLeft
        }
    }
    // 데이터가 트리 안에 이미 있다면 아무것도 안 한다
    root->height = max(Height(root->left), Height(root->right)) + 1;
    return root;
}


void forQuestion01(){
    clock_t start;
    clock_t end;
    srand(time(NULL));
    int RandomNumber;
    
    struct BinarySearchTreeNode* BST = NULL;
    start = clock();
    for (int i = 0;i < N;i++)
    { 
        RandomNumber = (rand() * 3) % 100001;
        //printf("Random Number = %d\n", RandomNumber);
        BST=BSTInsert(BST, RandomNumber);
    }
    end = clock();//시간 측정 종료
    printf("BST Time: %ld millisec\n\n", end - start);

    //printf("Minimum : %d\n",BSTFindMin(BST)->data);
    
    struct AVLTreeNode* AVL = NULL;
    start = clock();
    for (int i = 0;i < N;i++)
    {
        RandomNumber = (rand() * 3) % 100001;
        //printf("Random Number = %d\n", RandomNumber);
        AVL = AVLInsert(AVL, RandomNumber);
    }
    end = clock();//시간 측정 종료
    printf("AVL Time: %ld millisec\n\n", end - start);

    //printf("Minimum : %d\n", AVLFindMin(AVL)->data);

    start = clock();
    for (int i = 0;i < N;i++)
    {
        RandomNumber = (rand() * 3) % 100001;
        BSTFind(BST, RandomNumber);
    }
    end = clock();//시간 측정 종료
    printf("BST Search Time: %ld millisec\n\n", end - start);

    start = clock();
    for (int i = 0;i < N;i++)
    {
        RandomNumber = (rand() * 3) % 100001;
        AVLFind(AVL, RandomNumber);
    }
    end = clock();//시간 측정 종료
    printf("AVL Search Time: %ld millisec\n\n", end - start);

    //AVL에서 Find 이렇게 하는게 맞는지 꼭 검색해보기.
}

void forQuestion02()
{
    clock_t start;
    clock_t end;
    srand(time(NULL));
    int RandomNumber;
    srand(time(NULL));
    struct BinarySearchTreeNode* BST = NULL;
    start = clock();
    for (int i = 1;i <= M;i++)
    {
        BST = BSTInsert(BST, i);
    }
    end = clock();//시간 측정 종료
    printf("BST 1~%d Insert Time: %ld millisec\n\n",M ,end - start);

    struct AVLTreeNode* AVL = NULL;
    start = clock();
    for (int i = 1;i <= M;i++)
    {
        AVL = AVLInsert(AVL, i);
    }
    end = clock();//시간 측정 종료
    printf("AVL 1~%d Insert Time: %ld millisec\n\n", M,end - start);
    
    
    start = clock();
    for (int i = 1;i <= M;i++)
    {
        RandomNumber = rand() % (M+1);
        BSTFind(BST, RandomNumber);
    }
    end = clock();//시간 측정 종료
    printf("BST Search Time: %ld millisec\n\n", end - start);

    start = clock();
    for (int i = 1;i <= M;i++)
    {
        RandomNumber = rand() % (M+1);
        AVLFind(AVL, RandomNumber);
    }
    end = clock();//시간 측정 종료
    printf("AVL Search Time: %ld millisec\n\n", end - start);


}
int main(void)
{
    forQuestion01();
    forQuestion02();
}