#include <bits/stdc++.h>
using namespace std;
//1. create a leaf node for each unique character and build a min heap of all leaf node(priority queque)
//2. extract two nodes with the min freq from the min heap
//3. create a new internal node with freq equal to the sum of the two nodes freq
//4. repeat step 2 and 3 until the heap contains only one node, the remaining node is root, the tree is complete

//a huffman tree node
struct MinHeapNode{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    
    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

//compare two heap nodes(needed in min heap
struct compare{
    bool operator()(MinHeapNode* l, MinHeapNode* r){
        return(l->freq > r->freq);
    }
};

//prints huffman codes from the root of huffman tree
void printCodes(struct MinHeapNode* root, string str){
    if(!root)
        return;
    
    if(root->data !='$')
        cout<<root->data<<": "<<str<<"\n";
    
    printCodes(root->left, str+"0");
    printCodes(root->right,str+"1");
}

//main function that builds a huffman tree and print codes by traversing the built huffman tree
void HuffmanCodes(char data[], int freq[], int size){
    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    
    for(int i=0; i<size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
        
    while(minHeap.size() !=1){
        left=minHeap.top();
        minHeap.pop();
        
        right=minHeap.top();
        minHeap.pop();
        
        top=new MinHeapNode('$', left->freq+right->freq);
        top->left = left;
        top->right=right;
        
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

int main(){
    char arr[]={'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[]={5,9,12,13,16,45};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    HuffmanCodes(arr, freq, size);
    
    return 0;
}
