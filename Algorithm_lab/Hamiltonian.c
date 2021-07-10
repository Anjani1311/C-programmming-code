#include<stdio.h>
#include<stdlib.h>

int numNodes;

int **problemGraph;
int hamPathsolutions[100][10];
int hamCycleSolutions[100][10];
int* visitedNodes;
int lastVisitedNodeIndex = -1, lastHamSolutionIndex = -1, lastHamCycleSolutionIndex = -1;


void pushNode(int);
int popNode();
int isVisited(int);
int haveWeVisitedAllNodes();

void hamiltonianPath(int, int, int);
void storeResult();
void printSolutions();
void printVisitedNodes();



void hamiltonianPath(int startNode, int currentNode, int prevNode){

    //printf("\nham(%d, %d, %d)\n",startNode, currentNode, prevNode);

    int nextNode;
    
    pushNode(currentNode);

    //printVisitedNodes();

    //if we have visited all the vertices, then it is a hamiltonian path 
    if(haveWeVisitedAllNodes() == 1){
        
        if(problemGraph[currentNode][startNode] == 1){
            //if we can traverse from current node to start node then it will also form a hamiltonian cycle or hamiltonian circuit
            storeResult(1);
        }else{
            storeResult(0);
        }

     
        popNode();
        return; 
        
    }

    
    //trying to traverse all nodes one by one from the current node
    for(nextNode = 0; nextNode < numNodes; nextNode++){
        
        //checking whether there is an edge from current node and next node
        if( problemGraph[currentNode][nextNode] == 1){

            if(isVisited(nextNode) == 1){//if the forthcoming node is already visited, then we will skip this node and move on to continue 
                continue;
            }else{//if the next node is not visted then we will traverse the node
                hamiltonianPath(startNode, nextNode, currentNode);
            }

        }else{
            //because there are no edge between current node and next node, we continue with another node in the succession
            continue;
        }
    }

    popNode();
    return; 
    
}

void pushNode(int node){

    if(haveWeVisitedAllNodes() == 0){
        visitedNodes[++lastVisitedNodeIndex] = node;
    }
}

int popNode(){
    return visitedNodes[lastVisitedNodeIndex--];
}

int isVisited(int node){
    int i;

    for(i = 0;i <= lastVisitedNodeIndex; i++){
        if(node == visitedNodes[i]){
            return 1;//the node is already visited
        }
    }

    return 0;//the node is not visted yet
}

int haveWeVisitedAllNodes(){
    
    if(lastVisitedNodeIndex == (numNodes - 1)){
        return 1;// 1 denotes true
    }else{
        return 0;//0 denotes false
    }

}

void printVisitedNodes(){
    int i;
    printf("lastVisitedIndex: %d\n", lastVisitedNodeIndex);
    for (i = 0; i < numNodes; i++){
        printf("index %i -- node %d \t", i, visitedNodes[i]);
    }

    printf("\n");
    
}

void storeResult(int isCycleAlso){
    int i;

    lastHamSolutionIndex++;
    
    if(isCycleAlso){
        lastHamCycleSolutionIndex++;
    }
    
    for ( i = 0; i < numNodes; i++){
        
        hamPathsolutions[lastHamSolutionIndex][i] = visitedNodes[i]; 

        if(isCycleAlso == 1){
            hamCycleSolutions[lastHamCycleSolutionIndex][i] = visitedNodes[i];
        }
    }

}

void printSolutions(){
    int i,j;
    printf("\n\n");
    if(lastHamSolutionIndex == -1){
        printf("Conclusion: There are no hamiltonian paths or circuit for the given graph.");
    }else{
        printf(":::Hamiltonian Paths:::\n\n\n");
        for(i = 0; i <= lastHamSolutionIndex; i++){
            printf("Hamiltonian Path %d: ", i+1);
            for(j = 0; j < numNodes; j++){
                printf(" => %d", hamPathsolutions[i][j]);
            }
            printf("\n");
        }
        printf("\n\n\n:::Hamiltonian Circuit:::\n\n\n");
        if(lastHamCycleSolutionIndex != -1){
            
            for(i = 0; i <= lastHamCycleSolutionIndex; i++){
                printf("Hamiltonian Circuit %d: ", i+1);
                for(j = 0; j < numNodes; j++){
                    printf(" => %d", hamCycleSolutions[i][j]);
                }
                printf("\n");
            }
        }else{
            printf("There are no hamiltonian paths or circuit for the given graph.");
        }
    }
    
}


void main(){

    int i, j;

    //input number of nodes in the problem
    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);


    //creating 2D array for problem matrix
    problemGraph = (int **)malloc(numNodes * sizeof(int *));
    for (i = 0; i < numNodes; i++){
        problemGraph[i] = (int *)malloc(numNodes * sizeof(int));
    }
    
    //initializing dynamic array for keeping record of all vertices traversed
    visitedNodes = (int *)malloc(numNodes * sizeof(int));

    //inputting problem matrix
    printf("Enter problem matrix row-wise:\n");
    for(i = 0; i < numNodes; i++){
        for(j = 0; j < numNodes; j++){
            scanf("%d", &problemGraph[i][j]);
        }
        printf("\n");
    }

    //formatted printing of problem matrix
    printf("Entered Matrix:\n");
    for(i = 0; i < numNodes; i++){
        for(j = 0; j < numNodes; j++){
            printf("%d\t", problemGraph[i][j]);
        }
        printf("\n");
    }

    hamiltonianPath(0, 0, -1);

    printSolutions();

}
