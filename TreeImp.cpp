#include<stdio.h>
#include<iostream>
#include<list>
#include<string>
using namespace std;

/**
 * A class to represent binary tree. 
 * The follwoing operations are implemented: 
 * - add a new noe into a tree
 * - delete a node from tree 
 * - print nodes from the given tree 
 * - print leaves of the given tree 
 * - count number of nodes in the tree
 * - find the path of the given node in the tree
 * - swap given tree 
 * - find the depth of the tree
 * - Check if given tree is a binary tree or not 
 * - Check if given tree is balanced or not 
 */

class Tree 
{
    private:
    int data;
    Tree *head, *next; 
    Tree *left,*right,*root;


    public:
    Tree* getRoot()
    {
        return this->root;
    }

Tree* getRight()
{
    return right;
}

Tree* getLeft()
{
    return left;
}

int getData()
{
    return data;
}

/**
 * Counting the number of nodes in the given tree
 * @param t given tree 
 * @return total number of nodes 
 */
int countNodes(Tree *t)
{
    if (t == nullptr)
        return 0;
    else 
        return (1+ countNodes(t->left) + countNodes(t->right));
}



/**
 * Deleting a node which has a max data in given tree  
 * @param t given tree 
 */
void deleteMax(Tree *t)
{    
   Tree *h = t->root;
   Tree *parent = h;
   while (h->right != nullptr){
         parent =h;   
         h=h->right;
   }  
  parent->right =h->left; 
}
/**
 * Find the depth of the given tree  
 * @param t a tree to be tested
 * @return the depth of the given tree
 */
int findDepth(Tree *t)
{  
    if (t == nullptr)
	    return 0;

    int lDepth = findDepth(t->left);
    int rDepth = findDepth(t->right);
	if( lDepth > rDepth  )
          return (1+lDepth);
        else
		  return (1+rDepth);
}

/**
 * To find the path for given node from the given tree 
 * @param node a node to be searched 
 * @param t a tree to be tested 
 * @return path 
 */
list<Tree*> findPath(int  node, Tree *t)
{  
    list<Tree*> l;
    if (t == nullptr)
	    return l;
    Tree *h = t->root;
    bool pathFound = false; 
    list<Tree*> path ; 
   // list<Tree*> Emptypath = new list(); 
    while (h->data != node && h!=nullptr)
    {  
        path.push_back(h);   
        if(h->data < node)
    	    h=h->right; 
        else
    	    h=h->left; 
    }
    if (h == nullptr) // node was not found 
       path.clear();
    return path;
}



/** 
 * Test given Tree if it is a balanced Tree or not (each node has equal left and right nodes)
 * @param t
 * @return
 */

bool isBalanceBTree(Tree *t) 
{
    if(t == nullptr)
	   return true; 
    else 
	    if (findDepth(t->left) == findDepth(t->right))
	        return isBalanceBTree(t->left) &&
			    isBalanceBTree(t->right);
        else 
			return false;

 
}

/**
 * Deleting a node with a minimum data in given tree 
 * @param t given tree 
 */

void deleteMin(Tree *t)
{    
   Tree *h = t->root;
   Tree *parent = h;
   while (h->left != nullptr){
         parent = h;   
         h=h->left;
   }  
  parent->left =h->right; 
}

/** 
 * Finding the node with minimum data in given tree 
 * @param t given tree 
 * @return a node with minimum data 
 */
int min(Tree *t)
{
    Tree *h = t->root;
    if (h == nullptr)
        return -1;
    while (h->left != nullptr)          
        h=h->left;
    return h->data;
}

/** 
 * Finding the node with maximum data in given tree 
 * @param t given tree 
 * @return a node with maximum data 
 */
int max(Tree *t)
{
    Tree *h = t->root;
    if (h == nullptr)
        return -1;
    while (h->right != nullptr)          
        h=h->right;
    return h->data;
}

/**
 * Checking if given tree is a binary or not 
 * @param t given tree 
 * @return true if t is a binary tree, false otherwise 
 */

bool IsBtree(Tree *t)
{
    
    if (t == nullptr ) 
        return true;
    else if(t->left == nullptr && t->right == nullptr )
        return true;
    else if(t->left == nullptr && t->right != nullptr )
        return (t->data < min(t->right)) && IsBtree(t->right); 
    else if(t->right == nullptr && t->left != nullptr )
        return (t->data > max(t->left)) && IsBtree(t->left);                     
    else  if (t->data > max(t->left) && t->data < min(t->right))
        return IsBtree(t->left) && IsBtree(t->right); 
    else         
        return false;        
}
/**
 * Swamping given tree (left <--> right)
 * @param t tree to be swapped 
 */
void swap(Tree *t)
{
    if (t != nullptr)
    {
        Tree *temp = t->left; 
        t->left = t->right;
        t->right = temp;
        swap(t->left);
        swap(t->right);
   } 
}

/**
 * Inserting a new node into given tree 
 * @param t Given tree before insertion
 * @param d a new node to be inserted
 * @return a new tree with node d 
 */
Tree* insertTree(Tree *t,int d)
{  
    Tree *parent = nullptr;
    Tree *r = t->root;
    Tree *node = new Tree();
    node->left = nullptr;
    node->right =nullptr;
    node->data = d;    
    if (r == nullptr)
        t->root = node; 
    else 
    { 
        r = t->root;
        while (r != nullptr)
        {
            parent = r ;
            if (d > r->data )
                r =r->right;
            else 
                r=r->left;
        }
        if (parent->data > d)
            parent->left = node;
        else 
            parent->right = node;
    }
    return t;
}

/**
 * Printing leaf nodes in the given tree 
 * @param t given tree 
 */

void printLeaves(Tree *t)
{
    Tree *r = t;
    if(r != nullptr)
    {
        if (r->left == nullptr && r->right == nullptr)
            cout<<"LEAF :"+to_string(r->data)<<endl;
        printLeaves(r->left);
        printLeaves(r->right);
    
    }
}
/**
 * To test if given tree is leaf (both left and right is nullptr)
 * @param t
 * @return
 */
 bool  isleafNode(Tree *t)
{
      return (t->left == nullptr && t->right == nullptr );
}

/** 
 * Checking if given tree has only one child 
 * @param t given tree 
 * @return true if given tree has only one child, false otherwise 
 */
bool isOneChildNode(Tree *t)
{
   if (t->left == nullptr && t->right !=nullptr )
        return true; 
    else if (t->left != nullptr && t->right == nullptr )
        return true; 
    else 
        return false;    
}
/**
 * Help functions for deleting leaves 
 * @param r node which will be deleted 
 * @param parent parent of r 
 * @param t the tree which r is belong to 
 */


void deleteleaf(Tree *r, Tree *parent,Tree *t)
{
    if(r->data > parent->data)
        parent->right = nullptr;
    else 
        parent->left = nullptr;
}


void deleteOneChildNode(Tree *r, Tree *parent,Tree *t){
    if ( parent->data > r->data )
    {
        if (r->left == nullptr)
            parent->left = r->right; 
        else
            parent->left = r->left; 
    }
    else
    {  
        if(r->left == nullptr)
            parent->right = r->right;
        else
            parent->right = r->left;
    }
}

void deleteTwoChildNode(Tree *r, Tree *parent,Tree *t)
{
    
    Tree *h;
    if ( parent->data > r->data )
    { 
        parent->left = r->right; 
        h =r->left;
        while (h->right != nullptr)
            h=h->right;
        
        h->right = r->right; 
    }
    else
    {  
        parent->right = r->right;
        h = r->right;
        while (h->left != nullptr )
            h=h->left;
        h->left = r->left;
    }
}

void deleteRoot(Tree *r, Tree *parent,Tree *t)
{
    
    Tree *h;
    h = r->left; 
    while (h->right != nullptr)
        h=h->right;   
    h->right = r->right; 
    t->root = h;
}


/**
 * Deleting node in the given tree. all help functions above are used 
 * @param t tree where given node will be deleted 
 * @param node a node which will be deleted from tree t
 */


void deleteChild(Tree *t, int node)
{
    Tree *r = t->root;
    Tree *parent;
    bool found = false;
    int changed = 0;
    while ((found == false) && (r != nullptr))
    {       
        if (r->data == node) // is this node exist in the tree ? 
            found = true; 
        else 
        {  
            parent  = r; //keep parent of the current node 
            changed = 1;
            if ( node > r->data)
                r=r->right;
            else 
                r=r->left;         
        }
    }
 
// if node was found then delete this node based on its children (leaf, node with one child and node with two 
// children)
    if (found == true)
    {
        cout<<("deleting Child: "+to_string(r->data)+" its parent is : "+to_string(parent->data))<<endl;
        if(changed == 0) // deleting root of the tree
            deleteRoot(r,parent,t);
        else if( isleafNode(r)) // deleting leaf node
            deleteleaf(r,parent,t);
        else if (isOneChildNode(r)) // deleting a node with one child 
            deleteOneChildNode(r,parent,t);
        else
            deleteTwoChildNode(r,parent,t);            
    }
    else 
        cout<<("Error: node "+to_string(node)+" is not exist in the tree")<<endl;
}

/**
 * Printing nodes in the given tree in pre-order 
 * @param bt tree where nodes will be printed 
 */
void preorder(Tree *bt)
{
    if (bt!= nullptr)
    {  // data left right 
        cout<<(bt->data)<<endl;
        preorder(bt->left);  
        preorder(bt->right);
    }
}

/**
* Printing nodes on the given tree in in-order
* @param bt tree where nodes will be printed 
*/
void inorder(Tree *bt)
{
    if (bt!= nullptr)
    {
        inorder(bt->left);  
        cout<<(bt->data)<<endl;
        inorder(bt->right);
    }
}


/**
* Printing nodes on the given tree in post-order
* @param bt tree where nodes will be printed 
*/
void postorder(Tree *bt)
{
    if (bt!= nullptr)
    {     
        postorder(bt->right);      
        cout<<(bt->data)<<endl;
        postorder(bt->left);
    }
}

/**
 * Counting number of nodes in the given tree 
 * @param t tree where nodes will be counted 
 * @return number of nodes in the tree t
 */
int countlength(Tree *t)
{
    Tree *h = t->head; 
    int s = 0; 
    while (h != nullptr) 
    {
        h = h->next;
        s++;
    }
    return s;    
}


/**
 * Inserting a new node into given tree at the position i
 * @param n a new node which will be inserted 
 * @param i a position where a new node a will be inserted 
 * @param t a tree where node a will be inserted 
 */

void insert(int n,int i, Tree *t)
{   
    Tree *node;
    node->data = n;
    node->next = nullptr;    
    Tree *h = t->head;
    if (i> countlength(t))
    {
       cout<<("invalid index, abort... ")<<endl;
        return;
    }
    
    if (h == nullptr)
        t->head = node; 
    else 
        if (i == 0)
        {
            node->next = t->head;
            t->head = node;
        }
    else 
    {
        h = t->head;
        for (int j=1; j<i; j++)
            h = h->next; 
        node->next = h->next;
        h->next = node;       
    }
}
    
    
/**
 * Deleting a node at position i     
 * @param i position where node will be deleted 
 * @param t tree where node will be deleted 
 */
void deleteNode(int i, Tree *t)
{    
    Tree *h = t->head;
    if (i> countlength(t))
    {
        cout<<("invalid index, abort ")<<endl;
         
    }   
    else if (i == 0)
        {
            t->head = h->next;
           // delete(h);
        }
    else 
    {
        h=t->head;
        for (int j=1; j<i; j++)
            h = h->next; 
        Tree *x = h->next;
        h->next = x->next;       
    }
}

    
Tree* reverseList(Tree *t)            
{
    Tree *h;
    Tree *revTree;
    int s = countlength(t);
       
    for (int i=0; i<s; i++)
    {  
        h= t->head;
        int c = 0;
        for (int j=1;j<s-i; j++)
        {
            c++;
            h= h->next;        
        }            
        insert(h->data,s-c-1,revTree);             
    }
    cout<<endl;
    return revTree;
}

};
   
/****************************************** Main function ***************************************\
* Main function where all operations are starting 
*/
int  main() 
{
   
    Tree *bt = new Tree();    // creating a new Binary tree 
   // add some nodes into a binary tree and then print it using inorder, pre order and postorder.
    bt->insertTree(bt,50);
    bt->insertTree(bt,3);
    bt->insertTree(bt,5);
    bt->insertTree(bt,90);
    bt->insertTree(bt,7); 
    bt->insertTree(bt,4); 
    bt->insertTree(bt,2); 
    bt->insertTree(bt,70); 
    bt->insertTree(bt,100); 
    bt->insertTree(bt,6);
    bt->insertTree(bt,8);
    bt->insertTree(bt,10);

    cout<<("printing given binary tree (inorder:)")<<endl;
    bt->inorder(bt->getRoot());
    cout<<("printing binary tree (pre order:)")<<endl;
    bt->preorder(bt->getRoot()); 
    cout<<("printing binary tree post order:")<<endl;
    bt->postorder(bt->getRoot());
    
    // printing leaves from the given binary tree 
    cout<<("printing  leaves of given binary tree:")<<endl;
    bt->printLeaves(bt->getRoot());

    // to cheack if given tree is a binary tree or not ? 
    if (bt->IsBtree(bt->getRoot()))
            cout<<("This tree is abinary  tree : ")<<endl; 
        else
            cout<<("This tree is NOT a binary tree : ")<<endl; 
    
    // more operations 
    cout<<("Max node in the tree is "+to_string(bt->max(bt)))<<endl;  
    cout<<("Min node in tree is "+to_string(bt->min(bt)))<<endl;  

    // counting the nodes in the given tree 
    cout<<("Total number of nodes in the tree is: "+ to_string(bt->countNodes(bt->getRoot())))<<endl;   


    cout<<("Finding the depth of the given tree")<<endl;
    // finding the depth of the given tree 
    int treeDepth = bt->findDepth(bt->getRoot());
    cout<<("Depth of the tree =: "+ to_string(treeDepth))<<endl;
    
    // find the depth of the tree from given node  
    int node = 180; // find a path from root to this node 

    list<Tree*> path = bt->findPath(node,bt);
    cout<<" size:"<<path.size()<<endl;
    if (path.size() == 0)
    {
        cout<<"No path for node "<<node<<endl;
    }
    else
    {   
         cout<<"Path for the node "<<node<<endl;
        for(list<Tree*> ::iterator it = path.begin(); it != path.end(); it++)
        {
            Tree* d = *it; 
            cout<<d->getData()<<"-->";
        }
         cout<<node<<endl;  
         
    }
    

    
      
// Checking if given tree is a balanced binary tree not not. 
if (bt->isBalanceBTree(bt->getRoot()))
        cout<<("This tree is a balanced binary tree")<<endl;
    else
        cout<<("This tree is a balanced binary tree")<<endl;
    
  
    // swaping a given binary tree and then print it.
    cout<<("Swaping a binary tree")<<endl;
    bt->swap(bt->getRoot());
    bt->inorder(bt->getRoot());
    bt->swap(bt->getRoot()); // to reverse it again to get the same tree 
    bt->inorder(bt->getRoot());
        
   
    //deleting a max node in the tree    
    cout<<("Deleting a max node in the given binary tree ")<<endl; 
    bt->deleteMax(bt);
    bt->inorder(bt->getRoot());

    cout<<("Deleting a min node in the given binary tree ")<<endl;
    bt->deleteMin(bt);
    bt->inorder(bt->getRoot()); 

     cout<<("Deleting a random node in given binary tree ")<<endl;
    // deleting nodes from given binary tree  
    int child = 90; // node to be deleted 
        
    cout<<("Deleting child "+ child)<<endl;
    bt->deleteChild(bt,child);
    cout<<("Printing a binary tree after deleting a node: "+child)<<endl;
    bt->inorder(bt->getRoot());
    
    
cout<<("******************************************* End of the test********************************************************")<<endl;
return 0;
}

