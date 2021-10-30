#include <stdio.h>
#include <stdlib.h>
// declare structure 's node
typedef struct node
{
    int data;    // data in 1 node
    node *pNext; // link nodes

} NODE;
//DECLARE single list of nodes
typedef struct list
{
    NODE *pHead;
    NODE *pTail;
} LIST;
void create(LIST &input);
NODE *createNode(int input);
void printList(LIST output);
void addFirst(LIST &input, NODE *p);
void addLast(LIST &input, NODE *p);
int findMax(LIST source);
int findMin(LIST source);
void addNodeQ_toP(LIST &input, NODE *p);
void addNodeQ_firstP(LIST &input, NODE *p);
void addNodeInSingleList(LIST &source, NODE *p, int position);
void delete_first_Node(LIST &source);
void delete_last_Node(LIST &source);
void deleteNodeP_AfterQ(LIST &source);
void deleteNode_random(LIST &source);
void free_pace(LIST &sources);
int main()
{
    LIST list;
    int position;
    create(list); // declare NODE list
    int n;
    printf("enter the number: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        printf("x%d: ", i);
        scanf("%d", &x);
        NODE *p = createNode(x); // khoi tao mot cai node so nguyen
        addLast(list, p);        // them node p vao dau danh sach
    }
    printList(list);
    printf("\nThe max number is %d", findMax(list));
    printf("\nThe min number is %d", findMin(list));
    // int y;
    // printf("\nenter the value p: ");
    // scanf("%d",&y);
    // NODE *f = createNode(y);
    // addNodeQ_toP(list,f);
    // printList(list);
    // // them o phai truoc Q
    // int z;
    // printf("\nenter the value p: ");
    // scanf("%d",&z);
    // NODE *h = createNode(z);
    // addNodeQ_firstP(list,h);
    // printList(list);
    // add random position
    int m;
    printf("\nEnter the value which you want to add: ");
    scanf("%d", &m);
    NODE *k = createNode(m);
    do
    {
        printf("\nEnter position (1->n+1): ");
        scanf("%d", &position);
    } while (position < 1 || position > n + 1);
    addNodeInSingleList(list, k, position);
    printList(list);
    //delete_first_node
    printf("\nThe list number after deleting first NODE: ");
    delete_first_Node(list);
    printList(list);
    //delete_last_node
    printf("\nThe list number after deleting last NODE: ");
    delete_last_Node(list);
    printList(list);
    //delete after NODE Q
    deleteNodeP_AfterQ(list);
    printList(list);
    //delete random node
    deleteNode_random(list);
    printList(list);
    free_space(list);
    return 0;
}
//HAM XUAT DANH SACH LIEN KET DON
void printList(LIST output)
{
    printf("\nyour number: ");
    for (NODE *k = output.pHead; k != NULL; k = k->pNext)
    {
        printf("%4d", k->data);
    }
}
//HAM KHOI TAO NODE
void create(LIST &input)
{
    input.pHead = NULL;
    input.pTail = NULL;
}
NODE *createNode(int input)
{
    // NODE *p = new NODE; //allocation memory
    NODE *p = (NODE *)malloc(sizeof(NODE));
    if (p == NULL)
    {
        printf("\nError.");
        return NULL;
    }
    p->data = input;
    p->pNext = NULL;
    return p;
    // return value of Node p just appear
}
// THEM NODE VAO DAU DANH SACH LIEN LietKeSNT
void addFirst(LIST &input, NODE *p)
{
    if (input.pHead == NULL)
    {                                  // DANH SACH DANG RONG
        input.pHead = input.pTail = p; // node dau cung la node cuoi node
    }
    else
    {
        p->pNext = input.pHead;
        input.pHead = p; // cap nhat lai pHead
    }
}
void addLast(LIST &input, NODE *p)
{
    if (input.pHead == NULL)
    {                                  // DANH SACH DANG RONG
        input.pHead = input.pTail = p; // node dau cung la node cuoi node
    }
    else
    {
        input.pTail->pNext = p; // cho con cua pTail lien ket voi NODE p
        input.pTail = p;        // cap nhat lai pTail
    }
}
int findMax(LIST source)
{
    int max = source.pHead->data;
    for (NODE *k = source.pHead; k != NULL; k = k->pNext)
    {
        if (max < k->data)
        {
            max = k->data;
        }
    }
    return max;
}
int findMin(LIST source)
{
    int min = source.pHead->data;
    for (NODE *k = source.pHead; k != NULL; k = k->pNext)
    {
        if (min > k->data)
        {
            min = k->data;
        }
    }
    return min;
}
void addNodeQ_toP(LIST &input, NODE *p)
{
    int x;
    printf("\nEnter the value of Q: ");
    scanf("%d", &x);
    NODE *q = createNode(x);
    if (q->data == input.pHead->data && input.pHead->pNext == NULL)
    {
        addLast(input, p);
    }
    else
    {
        //duyet tu dau toi cuoi de tim Q
        for (NODE *k = input.pHead; k != NULL; k = k->pNext)
        {
            //neu node Q co ton tai
            if (q->data == k->data)
            {
                NODE *h = createNode(p->data); //khoi tao node H moi de them vao sau node Q
                NODE *g = k->pNext;            //  cho node g tro den node nam sau node q
                h->pNext = g;                  // b1: tao moi lien ket tu node p den node g <=> tao moi lien ket tao moi lien ket tu node p cho den node q
                k->pNext = h;                  // b2: tao moi lien ket tu node q den node p <=> chinh la node k den node p
            }
        }
    }
}
void addNodeQ_firstP(LIST &input, NODE *p)
{
    int x;
    printf("enter value of Q: ");
    scanf("%d", &x);
    NODE *q = createNode(x);
    if (q->data == input.pHead->data && input.pHead->pNext == NULL)
    {
        addFirst(input, p);
    }
    else
    {
        NODE *g = new NODE;
        for (NODE *k = input.pHead; k != NULL; k = k->pNext)
        {
            if (q->data == k->data)
            {
                NODE *h = createNode(p->data);
                h->pNext = k; // b1: cho phep NODD P cho lien ket toi NODE K => P-> Q
                g->pNext = h; //b2: cho NODE G tro den NODE Q trong danh sach
            }
            g = k;
        }
    }
}
void addNodeInSingleList(LIST &source, NODE *p, int position)
{
    //loop to get the number of node in list
    int n = 0;
    for (NODE *k = source.pHead; k != NULL; k = k->pNext)
    {
        n++;
    }
    if (source.pHead == NULL || position == 1)
    {
        //add Node at first list
        addFirst(source, p);
    }
    else if (position == n + 1)
    {
        // add Node P at the end of LIST
        addLast(source, p);
    }
    else
    {
        int count = 0; // find the position to add
        // find Node Q exist in List then add NODE P before NODE Q
        NODE *g = new NODE; // chính là node giữ liên kết với cái node nằm trước node Q trong danh sách
        for (NODE *k = source.pHead; k != NULL; k = k->pNext)
        {
            count++;
            if (count == position)
            {
                NODE *h = createNode(p->data); // mỗi lần phát hiện ra node Q thì ta khởi tạo một node P mới <=> Khỏi tạo node H
                h->pNext = k;                  // b1: cho phep NODE H cho lien ket toi NODE K => Thêm node P vào trước node Q
                g->pNext = h;                  //b2: cho node G trỏ đến node H trong ds
                break;
            }
            g = k;
        }
    }
}
void delete_first_Node(LIST &source)
{
    if (source.pHead == NULL)
    {
        return;
    }
    NODE *p = source.pHead;             // NODE P is deleted
    source.pHead = source.pHead->pNext; // update sourcE.pHead is the next NODE
    delete p;
}
void delete_last_Node(LIST &source)
{
    if (source.pHead == NULL)
    {
        return;
    }
    // case : the lisst has one NODE
    if (source.pHead->pNext == NULL)
    {
        delete_first_Node(source);
        return;
    }
    for (NODE *k = source.pHead; k != NULL; k = k->pNext)
    {
        if (k->pNext == source.pTail)
        {
            delete source.pTail;
            k->pNext = NULL;
            source.pTail = k; // update again
            return;
        }
    }
}
void deleteNodeP_AfterQ(LIST &source)
{
    int x;
    printf("\nenter the value Q:");
    scanf("%d", &x);
    NODE *q = createNode(x);
    for (NODE *k = source.pHead; k != NULL; k = k->pNext)
    {
        if (k->data == q->data)
        {
            NODE *g = k->pNext;
            k->pNext = g->pNext;
            delete g; // free space
        }
    }
}
void deleteNode_random(LIST &source)
{
    int x; 
    printf("\nenter the value of x: ");
    scanf("%d", &x);
    if(source.pHead == NULL) {
        return;
    }
    if (source.pHead->data == x)
    {
        delete_first_Node(source);
    }
    if (source.pTail->data >= x)
    {
        delete_last_Node(source);
    }
    // check k from 1 to N
    NODE *g = new NODE; // node G point to node is deleted
    for (NODE *k = source.pHead; k != NULL; k = k->pNext)
    {
        if (k->data == x)
        {
            g->pNext = k->pNext;
            delete k; // free space
            return;
        }
        g = k;
    }
}
// free space for single list
void free_pace(LIST &sources)
{
    NODE *k;
    while(source.pHead != NULL)
    {
        k = sources.pHead;
        source.pHead = source.pHead->pNext;
        delete k;
    }  
}