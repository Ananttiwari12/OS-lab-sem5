
// LAB 10
//  Implementation of memory placement schemes (Fixed Partitioning)

#include <iostream>
#include <iostream>
#include <vector>
using namespace std;
void firstFit( int m, int processSize[], int n) {
    int allocation[n];
    int blockSize[] = {128,256,150};
    for(int i=0;i<n;i++) allocation[i]=-1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (blockSize[j] >= processSize[i]){
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1){
            cout << allocation[i] + 1;
        }
    else cout << "Not Allocated";
    cout << endl;
    }
}
void bestFit(int m, int processSize[], int n) {
    int allocation[n];
    int blockSize[] = {128,256,150};
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++){
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]){
                if (bestIdx == -1)bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j]) bestIdx = j;
            }
        }
        if (bestIdx != -1){
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1) cout << allocation[i] + 1;
        else cout << "Not Allocated";
        cout << endl;
    }
}
void worstFit(int m, int processSize[],int n){
    int allocation[n];
    int blockSize[] = {128,256,150};
    for (int i = 0; i < n; i++){
        allocation[i] = -1;
    }
    for (int i=0; i<n; i++){
        int wstIdx = -1;
        for(int j=0; j<m; j++){
            if (blockSize[j] >= processSize[i]){
                if (wstIdx == -1) wstIdx = j;
                else if (blockSize[wstIdx] < blockSize[j]) wstIdx = j;
            }
        }
        if (wstIdx != -1){
            allocation[i] = wstIdx;
            blockSize[wstIdx] -= processSize[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++){
        cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1) cout << allocation[i] + 1;
        else cout << "Not Allocated";
        cout << endl;
    }
}
int main(){
    int processSize[] = {100,150,200};
    int blockSize[] = {128,256,150};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
    cout << "Best fit :";
    bestFit(m, processSize, n);
    cout << "First fit :";
    firstFit(m,processSize,n);
    cout << "Worst fit :";
    worstFit(m, processSize, n); 
}
