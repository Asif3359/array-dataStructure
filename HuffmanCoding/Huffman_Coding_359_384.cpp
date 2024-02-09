#include <iostream> 
#include <cstdlib> 

using namespace std; 

class HuffmanTreeNode // Define a class for Huffman tree nodes
{
public:
    char charac ; // The character stored in the node
    int freq ; // The frequency of the character
    HuffmanTreeNode* left; // The pointer to the left child
    HuffmanTreeNode* right; // The pointer to the right child

    HuffmanTreeNode(char character , int freque) // The constructor of the node
    {
        charac = character; // Assign the character
        freq = freque; // Assign the frequency
        left = right = nullptr; // Initialize the children to null
    }
};

class priorityQueue // Define a class for priority queue
{
public :
    HuffmanTreeNode* heap[100]; // An array of pointers to Huffman tree nodes
    int Size ; // The size of the priority queue
    priorityQueue() // The constructor of the priority queue
    {
        Size = 0 ; // Initialize the size to zero
    }

    int parent(int i) // A function to get the parent index of a given index
    {
        return (i-1)/2 ; // Return the floor of (i-1)/2 (parent)
    }

    int leftChild(int i ) // A function to get the left child index of a given index
    {
        return 2* i + 1; // Return 2*i + 1 (leftChild)
    }
    int rightChild(int i ) // A function to get the right child index of a given index
    {
        return 2* i + 2; // Return 2*i + 2 (rightChild)
    }
    bool Empty() // A function to check if the priority queue is empty
    {
        return Size == 0; // Return true if size is zero, false otherwise
    }

    void push(HuffmanTreeNode* Node) // A function to insert a node into the priority queue
    {
        if(Size >= 100) // Check if the priority queue is full
        {
            cout << "Priority Queue id Overflow \n" ; // Print an error message
            return ; // Return without inserting
        }
         heap[Size++]= Node; // Insert the node at the end of the array and increment the size
        int index = Size-1 ; // Get the index of the inserted node
        while(index > 0 && heap[parent(index)]->freq > heap[index]->freq) // Loop until the node reaches the root or its parent has a smaller frequency
        {
            swap(heap[parent(index)], heap[index]); // Swap the node with its parent
            index= parent(index); // Update the index to the parent index
        }
    }
    HuffmanTreeNode* pop() // A function to remove and return the node with the smallest frequency from the priority queue
    {
        if(Size== 0) // Check if the priority queue is empty
        {
            return nullptr; // Return null
        }
        HuffmanTreeNode* top = heap[0]; // Get the node at the top of the heap
        heap[0]= heap[--Size]; // Replace the top node with the last node and decrement the size
        heapify(0); // Heapify the heap from the root
        return top; // Return the removed node
    }
    void heapify(int index) // A function to maintain the heap property of the priority queue
    {
        int lf_child = leftChild(index); // Get the left child index of the given index
        int ri_child = rightChild(index); // Get the right child index of the given index
        int smallest = index ; // Assume the given index is the smallest

        if(lf_child < Size && heap[lf_child]->freq < heap[smallest]->freq) // Check if the left child exists and has a smaller frequency than the current smallest
        {
            smallest = lf_child; // Update the smallest to the left child index
        }
        if(ri_child < Size && heap[ri_child]->freq < heap[smallest]->freq) // Check if the right child exists and has a smaller frequency than the current smallest
        {
            smallest = ri_child; // Update the smallest to the right child index
        }
        if(smallest != index) // Check if the smallest is not the given index
        {
            swap(heap[index], heap[smallest]); // Swap the node at the given index with the node at the smallest index
            heapify(smallest); // Heapify the heap from the smallest index
        }
    }
};

HuffmanTreeNode* generateTree(priorityQueue& priQue ) // A function to generate a Huffman tree from a priority queue of nodes
{
    while(priQue.Size != 1) // Loop until there is only one node left in the priority queue
    {
        HuffmanTreeNode* left = priQue.pop(); // Pop the node with the smallest frequency and assign it to the left child
        HuffmanTreeNode* right = priQue.pop(); // Pop the node with the next smallest frequency and assign it to the right child

        HuffmanTreeNode* node = new HuffmanTreeNode('$', left->freq+right->freq); // Create a new node with a dummy character and the sum of the frequencies of the children
        node->left = left; // Set the left child of the new node
        node->right =right; // Set the right child of the new node

        priQue.push(node); // Push the new node into the priority queue

    }
    return priQue.heap[0]; // Return the root of the Huffman tree
}

void printCodes(HuffmanTreeNode* root , int arr[], int top) // A function to print the Huffman codes of the characters in the tree
{
    if(root->left) // Check if the node has a left child
    {
        arr[top]=0; // Append a zero to the array
        printCodes(root->left, arr, top+1); // Recursively print the codes of the left subtree
    }
    if(root->right) // Check if the node has a right child
    {
        arr[top]=1; // Append a one to the array
         printCodes(root->right, arr, top+1); // Recursively print the codes of the right subtree
    }
    if(! root->left && ! root->right) // Check if the node is a leaf
    {
        cout << root->charac << " "; // Print the character of the node
        for(int i = 0 ; i<top ; i++) // Loop through the array
        {
            cout << arr[i]; // Print the array element
        }
        cout<< endl; // Print a new line
    }
}

void huffmancode (char charac[], int frequency[], int Size) // A function to perform Huffman coding on a given array of characters and frequencies
{
    priorityQueue  priQue ; // Create a priority queue object
    for(int i = 0 ; i< Size ; i++) // Loop through the array
    {
        HuffmanTreeNode * NewNode = new HuffmanTreeNode(charac[i], frequency[i]); // Create a new node for each character and frequency
        priQue.push(NewNode); // Push the node into the priority queue
    }
    HuffmanTreeNode * root = generateTree(priQue); // Generate the Huffman tree from the priority queue

    int arr[100] , top = 0 ; // Declare an array and a variable to store the top index
    printCodes(root , arr, top); // Print the codes of the characters in the tree

}

int main() // The main function
{
    cout << "Huff Man coding" << endl; // Print a message

    char charac[] ={'a' , 'b', 'c' , 'd', 'e', 'f' }; // Declare an array of characters
    int frequency [] = {5, 9, 12, 13, 16, 45}; // Declare an array of frequencies
    int Size = sizeof(charac) / sizeof(charac[0]); // Calculate the size of the array

    huffmancode(charac, frequency, Size); // Call the Huffman coding function
    return 0; // Return zero
}
