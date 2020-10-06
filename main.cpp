#include <fstream> // ofstream, ifstream, fstream objects

int main() {
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

    // make sure to close a file when it is no longer being used
    inputFile.close();

    // open settings of prototypes
    ifstream(const char* filename, ios::openmode mode = ios::in);
    ofstream(const char* filename, ios::openmode mode = ios::out);
    fstream(const char* filename, ios::openmode mode = ios::in | ios::out);

    //open prototypes
    void open(const char* filename, ios::openmode mode = ios::in | ios::out);
    void open(const string& filename, ios::openmode mode = ios::in | ios::out);

    // file mode flags
    ios::app // oupput will always take place at the end of the file
    ios::ate // output will intially take place at end of file
    ios::binary // data read or written to file in binary form
    ios::in // input, fail if not existing
    ios::out // output, creates file if not existed
    ios::trunc // contents are discarded and its size is truncated to zero

    // binary operator to combine flags
    ios::in | ios::out | ios::ate

    // all on one line
    std::fstream outFile("inout.txt", ios::in | ios::app);
    outFile.close();
    outFile.open("inout.txt", ios::out | ios::app);

    // flags
    ios::eofbit // end of an input stream
    ios::failbit // operation attempted failed
    ios::hardfail // unrecoverable fail
    ios::badbit // invalid operation
    ios::goodbit // all above are not set

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
    istream& getline (istream& is, string& str, char delim = '\n');

    return 0;
} 