#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Usage: checker <input> <output> <answer>" << endl;
        return 2;
    }
    ifstream fin(argv[1]);
    ifstream fout(argv[2]);
    ifstream fans(argv[3]);
    long long val_in, val_out, val_ans;
    if (!(fin >> val_in)) return 2;
    if (!(fout >> val_out)) return 1;
    if (!(fans >> val_ans)) return 2;
    
    if (val_out == val_in * 2) {
        return 0; // AC
    } else {
        return 1; // WA
    }
}