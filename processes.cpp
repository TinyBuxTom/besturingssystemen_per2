#include "tinbes.h"

#define TABLE_SIZE 25
#define RUNNING 'r'
#define PAUSED 'p'

// Process table: arrays of names, ids, states and addresses
string processName[TABLE_SIZE];
int id[TABLE_SIZE];
char state[TABLE_SIZE];
long addr[TABLE_SIZE];
int noOfProcesses = 0;
int idCounter = 0;

// Add new entry to end of process table with state 'RUNNING'
int newProcess(string name, long address) {

  // TO DO
  
  noOfProcesses++;
  return idCounter++;
}

// Remove entry from process table
void removeProcess(int i) {
  noOfProcesses--;
  for (int j = i; j < noOfProcesses; j++) {
    processName[j] = processName[j + 1];
    id[j] = id[j + 1];
    state[j] = state[j + 1];
    addr[j] = addr[j + 1];
  }
}

// Loop through process table and execute one instruction for each process
void executeProcesses() {
  long newAddr;
  for (int i = 0; i < noOfProcesses; i++) {
    if (state[i] == RUNNING) { // call execute function with correct address
      
      // TO DO

      if (newAddr == -1) {
        cout << "Process \"" << processName[i] << "\" has terminated." << endl;
        removeProcess(i--);
      } else {
        addr[i] = newAddr;
      }
    }
  }
}

void listProcesses() {
  for (int i = 0; i < noOfProcesses; i++) {
    cout << id[i] << ' ' << processName[i] << ' ' << state[i] << endl;
  }
}

int findProcess(int i) {
  for (int j = 0; j < noOfProcesses; j++) {
    if (id[j] == i) return j;
  }
  return -1;
}

void suspendProcess(int i) {
  int j = findProcess(i);
  if (j == -1) {
    cout << "Process does not exist." << endl;
    return;
  }
  if (state[j] == PAUSED) {
    cout << "Process already paused." << endl;
  }
  else { // set state to 'PAUSED'

    // TO DO

  }
}

void resumeProcess(int i) {
  int j = findProcess(i);
  if (j == -1) {
    cout << "Process does not exist." << endl;
    return;
  }
  if (state[j] == RUNNING) {
    cout << "Process already running." << endl;
  }
  else { // set state to 'RUNNING'

    // TO DO

  }
}

void killProcess(int i) {
  int j = findProcess(i);
  if (j == -1) {
    cout << "Process does not exist." << endl;
  } else { // remove process from process table
    
    // TO DO
    
  }
}

int main() {
  unblockCin();
  string command;
  while (true) {
    if (charactersAvailable()) {
      command = readLine();
      if (command == "RUN") {
        string name = readLine();
        long address = stoi(readLine());
        cout << newProcess(name, address) << endl;
      }
      if (command == "LIST") {
        listProcesses();
      }
      if (command == "SUSPEND") {
        int i = stoi(readLine());
        suspendProcess(i);
      }
      if (command == "RESUME") {
        int i = stoi(readLine());
        resumeProcess(i);
      }
      if (command == "KILL") {
        int i = stoi(readLine());
        killProcess(i);
      }
    }
    else {
      executeProcesses();
    }
  }
}
