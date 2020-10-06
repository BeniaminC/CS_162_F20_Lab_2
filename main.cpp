#include <fstream> // ofstream, ifstream, fstream objects
#include <iostream>
#include <string>

int main() {

    // BELOW ARE NOTES AND IS NOT INTENDED TO BE COMPILED AND RAN

    // ofstream - output file stream (creates file and writes data to it)
    // ifstream - input file stream (open existing file and reads data from it)
    // fstream - file stream (used for both reading and writing)

    // part of the standard namespace

    std::ifstream inputFile; // create an input file object called "inputFile"
    inputFile.open("test_file.txt"); // use the "open" method to open a file in current directory
    
    std::ofstream outputFile;
    outputFile.open("test_file.txt");
    // another example below
    // inputFile.open("C:\\data\\inventory.txt");

    //Think of it in the context of the program:
    //you output TO a file, and input FROM data

    // therefore...
    
    // you can think of a streaming object as a bufffer
    char buffer[256];

    outputFile << "This is a test file\n";
    inputFile >> buffer;

    //c++11 allows you to use string objects
    std::string easier_buffer;
    inputFile >> easier_buffer;

    // make sure to close a file when it is no longer being used
    inputFile.close();

    // open settings of prototypes
    std::ifstream(const char* filename, std::ios::openmode mode = std::ios::in);
    std::ofstream(const char* filename, std::ios::openmode mode = std::ios::out);
    std::fstream(const char* filename, std::ios::openmode mode = std::ios::in | std::ios::out);

    //open prototypes
    void open(const char* filename, std::ios::openmode mode = std::ios::in | std::ios::out);
    void open(const std::string& filename, std::ios::openmode mode = std::ios::in | std::ios::out);

    // file mode flags
    std::ios::app; // oupput will always take place at the end of the file
    std::ios::ate; // output will intially take place at end of file
    std::ios::binary; // data read or written to file in binary form
    std::ios::in; // input, fail if not existing
    std::ios::out; // output, creates file if not existed
    std::ios::trunc; // contents are discarded and its size is truncated to zero

    // binary operator to combine flags
    std::ios::in | std::ios::out | std::ios::ate;

    // all on one line
    std::fstream outFile("inout.txt", std::ios::in | std::ios::app);
    outFile.close();
    outFile.open("inout.txt", std::ios::out | std::ios::app);

    // flags
    std::ios::eofbit; // end of an input stream
    std::ios::failbit; // operation attempted failed
    std::ios::hardfail; // unrecoverable fail
    std::ios::badbit; // invalid operation
    std::ios::goodbit; // all above are not set

    eof() // eofbit
    fail() // failbit hardfail
    bad() // badbit
    good() // goodbit
    clear() // clear all flags

    //eg
    if (outFile.fail()) {
        cout << "we've failed, captain!" << endl
    }

    // no error flags if stream object is true
    if (dataFile) {
        cout << "still working!" << endl;
    }

    struct data {
        int id;
        std::string first_name;
        std::string last_name;
        std::string major;
    }

    data test_struct;
    int size_of_data;

    // you can use a while loop to iterate over the data set
    while (dataFile) {
        fileStream >> test_struct.id;
        fileStream >> test_struct.first_name;
        // ....
    }

    // getline
    // the getline function defaults to the newline character '\n' as the default parameter
    std::istream& getline (std::istream& is, std::string& str, char delim = '\n');

    return 0;
} 