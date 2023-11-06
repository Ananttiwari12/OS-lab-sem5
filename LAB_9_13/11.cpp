// Lab 11
// 1)	Implementation of memory placement schemes (Variable Partitioning)


#include <iostream>
#include <vector>
using namespace std;
// Structure to represent a memory partition
struct Partition {
int id;
int size;
bool allocated;
};
// Structure to represent a process
struct Process {
int id;
int size;
};
// Function to allocate a process using First Fit
void firstFit(vector<Partition>& partitions, Process& process) {
for (Partition& partition : partitions) {
if (!partition.allocated && partition.size >= process.size) {
partition.allocated = true;
cout << "Allocated Process " << process.id << " to Partition " << partition.id << endl;
return;
}
}
cout << "No suitable partition found for Process " << process.id << endl;
}
// Function to allocate a process using Best Fit
void bestFit(vector<Partition>& partitions, Process& process) {
int bestFitIdx = -1;
int minSizeDiff = INT_MAX;
for (int i = 0; i < partitions.size(); i++) {
if (!partitions[i].allocated && partitions[i].size >= process.size) {
int sizeDiff = partitions[i].size - process.size;
if (sizeDiff < minSizeDiff) {
bestFitIdx = i;
minSizeDiff = sizeDiff;
}
}
}
if (bestFitIdx != -1) {
partitions[bestFitIdx].allocated = true;
cout << "Allocated Process " << process.id << " to Partition " << partitions[bestFitIdx].id <<
endl;
} else {
cout << "No suitable partition found for Process " << process.id << endl;
}
}
int main() {
int numPartitions;
cout << "Enter the number of memory partitions: ";
cin >> numPartitions;
vector<Partition> partitions(numPartitions);
for (int i = 0; i < numPartitions; i++) {
partitions[i].id = i;
cout << "Enter the size of Partition " << i << ": ";
cin >> partitions[i].size;
partitions[i].allocated = false;
}
int numProcesses;
cout << "Enter the number of processes: ";
cin >> numProcesses;
vector<Process> processes(numProcesses);
for (int i = 0; i < numProcesses; i++) {
processes[i].id = i;
cout << "Enter the size of Process " << i << ": ";
cin >> processes[i].size;
}
cout << "\nFirst Fit Memory Allocation:\n";
for (Process& process : processes) {
firstFit(partitions, process);
}
cout << "\nBest Fit Memory Allocation:\n";
for (Partition& partition : partitions) {
partition.allocated = false;
}
for (Process& process : processes) {
bestFit(partitions, process);
}
return 0;
}
