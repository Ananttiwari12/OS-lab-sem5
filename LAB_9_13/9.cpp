// LAB9
// 1 Program to translate a logical address to a physical address

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;
const int page_size = 4096;
const int page_table_size = 16;
const int logical_address_bits = 16;
map<int, int> page_table;
void createSamplePageTable(){
	for (int i = 0; i < page_table_size; i++){
		page_table[i] = rand() % 64;
	}
}
pair<int, int> translateAddress(int logical_address){
	int page_number = logical_address / page_size;
	int offset = logical_address % page_size;
	if (page_table.find(page_number) != page_table.end()) {
		int frame_number = page_table[page_number];
		int physical_address = (frame_number * page_size) + offset;
		return make_pair(physical_address, frame_number);
	}
	else{
		return make_pair(-1, -1);
	}
}
int main() {
	srand(static_cast<unsigned>(time(nullptr)));
	createSamplePageTable();
 	int num_addresses_to_generate = 10;
 	cout << "Logical Address\tPhysical Address\tFrame Number" << endl;
	for(int i = 0; i < num_addresses_to_generate; i++){
		int logical_address = rand() % (1 << logical_address_bits);
		pair<int, int> result = translateAddress(logical_address);
		int physical_address = result.first;
		int frame_number = result.second;
		cout << logical_address << "\t\t" << physical_address << "\t\t\t" <<
		frame_number << endl;
 	}
	cout << "\nPage Table Entries:" << endl;
 	for(auto it = page_table.begin(); it != page_table.end(); ++it) {
 		cout << "Page " << it->first << ": Frame"<< it->second << endl;
 	}
}


//2)Implementation of Paging Scheme

// #include <iostream>
// #include <vector>
// #include <map>
// #include <cstdlib>
// using namespace std;
// // Define the page and frame sizes
// const int PAGE_SIZE = 4096; // 4KB
// const int RAM_SIZE = 65536; // 64KB
// // Page table entry structure
// struct PageTableEntry {
//     int frame_number;
//     bool valid;
// };
// // Process structure
// struct Process {
//     int process_id;
//     int size;
//     vector<PageTableEntry> page_table;
// };
// // Function to allocate a frame to a page
// void allocateFrame(Process& process, int page, int frame, map<int, bool>& free_frames) {
//     process.page_table[page].frame_number = frame;
//     process.page_table[page].valid = true;
//     free_frames[frame] = false;
//     cout << "Allocated Frame " << frame << " to Process " << process.process_id << ", Page " << page <<endl;
// }
// int main() {
// int num_processes;
// cout << "Enter the number of processes: ";
// cin >> num_processes;
// vector<Process> processes(num_processes);
// for (int i = 0; i < num_processes; i++) {
//     cout << "Enter the size of Process " << i << " (in pages): ";
//     cin >> processes[i].size;
//     processes[i].process_id = i;
//     processes[i].page_table.resize(processes[i].size);
//     for (int j = 0; j < processes[i].size; j++) {
//         processes[i].page_table[j].valid = false;
//     }
// }
// // Create a list of free frames
// map<int, bool> free_frames;
// for (int i = 0; i < RAM_SIZE / PAGE_SIZE; i++) {
//     free_frames[i] = true;
// }
// // Allocate pages to frames until all frames are used
// while (!free_frames.empty()) {
//     for (int i = 0; i < num_processes; i++) {
//         if (processes[i].size == 0) continue;
//         int page = rand() % processes[i].size;
//         int frame;
//         for (auto& entry : free_frames) {
//             if (entry.second) {
//                 frame = entry.first;
//             break;
//             }
//         }
//         allocateFrame(processes[i], page, frame, free_frames);
//         processes[i].size--;
//     }
// }
// // Print page tables and frame allocation status
// for (int i = 0; i < num_processes; i++) {
//     cout << "Process " << processes[i].process_id << " Page Table:" << endl;
//     for (int j = 0; j < processes[i].size; j++) {
//         if (processes[i].page_table[j].valid) cout << "Page " << j << " -> Frame " << processes[i].page_table[j].frame_number << endl;
//         else cout << "Page " << j << " -> Not in RAM" << endl;
//     }
// }
// return 0;
// }
