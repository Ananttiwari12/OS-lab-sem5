// Lab 12
//  Simulation of the Banker’s Algorithm for deadlock avoidance
 // Banker's Algorithm


// #include <iostream>
// using namespace std;
// int main(){
// // P0, P1, P2, P3, P4 are the Process names here
// int n, m, i, j, k;
// n = 5; // Number of processes
// m = 3; // Number of resources
// int alloc[5][3] = { { 0, 1, 0 },
//  { 2, 0, 0 },
//  { 3, 0, 2 },
//  { 2, 1, 1 },
//  { 0, 0, 2 } };
// int max[5][3] = { { 7, 5, 3 },
//  { 3, 2, 2 },
//  { 9, 0, 2 },
//  { 2, 2, 2 },
//  { 4, 3, 3 } };
// int avail[3] = { 3, 3, 2 };
// int f[n], ans[n], ind = 0;
// for (k = 0; k < n; k++) {
//     f[k] = 0;
// }
// int need[n][m];
// for (i = 0; i < n; i++) {
//  for (j = 0; j < m; j++)
//  need[i][j] = max[i][j] - alloc[i][j];
// }
// int y = 0;
// for (k = 0; k < 5; k++) {
//  for (i = 0; i < n; i++) {
//  if (f[i] == 0) {
//  int flag = 0;
//  for (j = 0; j < m; j++) {
//  if (need[i][j] > avail[j]){
//  flag = 1;
//  break;
//  }
//  }
// if (flag == 0) {
//     ans[ind++] = i;
//     for (y = 0; y < m; y++)
//         avail[y] += alloc[i][y];
//         f[i] = 1;
//     }
// }
// }
// }
// int flag = 1;
// for(int i = 0;i<n;i++){
//  if(f[i]==0){
//  flag = 0;
//  cout << "The given sequence is not safe";
//  break;
//  }
// }
// if(flag==1){
//  cout << "Following is the SAFE Sequence" << endl;
//  for (i = 0; i < n - 1; i++)
//  cout << " P" << ans[i] << " ->";
//  cout << " P" << ans[n - 1] <<endl;
// }
//  return (0);
// }

// 2.
// Simulation of producer consumer problem
#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty = 10, x = 0;
void producer () {
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nProducer produces item %d", x);
    ++mutex;
}

void consumer () {
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes item %d", x);
    x--;
    ++mutex;
}
int main () {
    int n, i;
    printf("\n1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 3 fort");
    for (i = 1; i > 0; i++) {
    printf("\nEnter your choice:");
    scanf("%d", &n);
    switch (n) {
    case 1: if ( (mutex == 1) && (empty != 0)) {
    producer ();
    } else {
    printf("Buffer is full!");
    }
    break;
    case 2: if ( (mutex == 1) && (full != 0)) {
    consumer ();
    } else {
    printf("Buffer is empty!");
    }
    break;
    case 3: exit(0);
    break;
    }
    }
}
