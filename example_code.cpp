#include <fstream> // ofstream, ifstream, fstream objects
#include <iostream>
#include <string>

struct student {
    int id;
    std::string first;
    std::string last;
    std::string major;
};

int main(int argc, char** argv) {


    if (argc != 2) {
        std::cerr << "Requires a file name: test <file name>" << std::endl;
        exit(1);
    }
    // pass in the first argument as the file name
    std::fstream inputFile(argv[1], std::ios::in); // create a input file object using the constructor

    // test if we properly opened the file
    if (inputFile.fail()) {
        std::cerr << "failed to open file: " << argv[1] << std::endl; // error console output
        exit(1); // will return 1 error to the terminal
    }

    int count;
    // get the number of data sets from the file.
    inputFile >> count;
    std::cout << "The number of data sets are: " << count << std::endl;

    // create our struct array on the heap

    // preemptively create the array size on the heap
    
    // it's good practice to create data on the heap in the case you have a massive file!
    student* data_array = new student[count];
    
    // iterate over the data set in the file
    int idx = 0; // start at index 0

    // Error will occur if the stream type is inconsistent with the data type. i.e. int =/= string;

    while (inputFile) { // check if we are at EOF (end of file) 
        inputFile >> data_array[idx].id;
        inputFile >> data_array[idx].first;
        inputFile >> data_array[idx].last;
        inputFile >> data_array[idx].major;

        // go to next index
        ++idx;
    }

    // test if it works
    for (int i=0; i<count; i++) {
        std::cout << data_array[i].id << std::endl;
    }

    // now we have our data, you need to implement the sorting
    // std::string getline_example;
    // // we are specifying the character delimiter (defaults to newline '\n', but we are explicitly putting it in to show)
    // std::getline(inputFile, getline_example, '\n');

    // //test if it worked
    // std::cout << getline_example << std::endl;

    // clean up our heap!
    delete[] data_array;

    // don't forget to close it!
    inputFile.close();

    return 0;

}