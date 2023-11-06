//  1)Implementation of Semaphore

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <semaphore.h>
// sem_t semaphore;
// void *thread_function(void *arg){
//     sem_wait(&semaphore);
//     printf("Thread %d entered critical section.\n", *(int *)arg);
//     _sleep(2);
//     printf("Thread %d exited critical section.\n", *(int *)arg);
//     sem_post(&semaphore);
//     return NULL;
// }
// int main(){
//     sem_init(&semaphore, 0, 1);
//     pthread_t thread1, thread2;
//     int thread1_id = 1, thread2_id = 2;
//     pthread_create(&thread1, NULL, thread_function, &thread1_id);
//     pthread_create(&thread2, NULL, thread_function, &thread2_id);
//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);
//     sem_destroy(&semaphore);
//     return 0;
// }

// 2)Implement of Resource Allocation graph

#include <bits/stdc++.h>
using namespace std;
bool isCyclic(int V,vector<int>adj []) {
    vector<int> inDegree(V,0); // stores in-degree of each vertex
    queue<int> q; // queue to store vertices with 0 in-degree
    int visited = 0; // count of visited vertices
    // calculate in-degree of each vertex
    for (int u = 0; u < V; u++) {
        for (auto v : adj[u]) {
            inDegree[v]++;
        }
    }
    // enqueue vertices with 0 in-degree
    for (int i = 0; i < V; i++){
        if (inDegree[i]== 0) {
            q.push(inDegree[i]);
        }
    }
// BFS traversal
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited++;
        // reduce in-degree of adjacent vertices
        for (auto v : adj[u]) {
            inDegree[v]--;
            // if in-degree becomes 0, enqueue the vertex
            if (inDegree[v] == 0) {
            q.push(v);
            }
        }
    }
return visited == V;
}
int main(){
    int n, m, i, j, k=0;
    cout << "Enter no of processes\n";
    cin >> n;
    cout << "Enter no of Resources\n";
    cin >> m;
    for (i = 0; i < n;i++){
        cout << "Process " << i + 1 << " is denoted by " << i<<"\n";
    }
    k = i;
    for (j=0; j < m;j++,k++){
        cout << "Resource " << j+ 1 << " is denoted by " << k<<"\n";
    }
    vector<int> adj[n+m];
    cout << "Allocate resources to process\n";
    while(true){
        int process, resource;
        cout << "Process ";
        cin >> process;
        cout << "Resource ";
        cin>> resource;
        if(process==-1 && resource==-1){
        break;
    }
        adj[resource].push_back(process);
    }
    cout << "Needed resources by process\n";
    while(true){
        int process, resource;
        cout << "Process ";
        cin >> process;
        cout << "Resource ";
        cin>> resource;
        if(process==-1 && resource==-1){
            break;
        }
        adj[process].push_back(resource);
    }
    if(isCyclic(n+m,adj)) cout << "No Deadlock\n";
    else cout << "Deadlock present\n";
    return (0);
}
