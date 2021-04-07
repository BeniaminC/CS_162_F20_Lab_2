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
    std::fstream io_file(argv[1], std::ios::in); // create a input file object using the constructor

    // test if we properly opened the file
    if (io_file.fail()) {
        std::cerr << "failed to open file: " << argv[1] << std::endl; // error console output
        exit(1); // will return 1 error to the terminal
    }

    int count;
    // get the number of data sets from the file.
    io_file >> count;
    std::cout << "The number of data sets are: " << count << std::endl;

    // create our struct array on the heap
    student* data_array = new student[count];

    // preemptively create the array size on the heap
    
    // it's good practice to create data on the heap in the case you have a massive file!
    
    // iterate over the data set in the file
    int idx = 0; // start at index 0

    // Error will occur if the stream type is inconsistent with the data type. i.e. int =/= string;

    for (int i = 0; i < count; i++) { // check if we are at EOF (end of file) 
        io_file >> data_array[idx].id;
        io_file >> data_array[idx].first;
        io_file >> data_array[idx].last;
        io_file >> data_array[idx].major;

        // go to next index
        ++idx;
    }
    // test if it works
    for (int i=0; i<count; i++) {
        std::cout << data_array[i].id << std::endl;
    }
    // // now we have our data, you need to implement the sorting
    // std::string getline_example;
    // // we are specifying the character delimiter (defaults to newline '\n', but we are explicitly putting it in to show)
    
    // std::getline(io_file, getline_example, '\n'); // We can parse and tokenize the line if we need.

    // while (std::getline(io_file, getline_example, '\n')) { // We can also use a while loop to ease our parsing
    //     std::cout << getline_example << std::endl;
    // }

    // Quick note: You should not have to use the getline for your first assignment!

    // clean up our heap!
    delete[] data_array;

    io_file.close(); // when you are done with the file, it is important to close it!
    io_file.clear();

    // we can use the same file stream object to open with different flags.
    // remember, fstream can do both input and output, ifstream can do input, and ofstream can do output!

    // io_file is an fstream object 
    io_file.open("outfile.txt", std::ios::out | std::ios::app); // std::ios::out = output, std::ios::app = append

    // write something to the file
    io_file << "Appending a line to the file!" << std::endl;


    // don't forget to close it!
    io_file.close();

    return 0;

}