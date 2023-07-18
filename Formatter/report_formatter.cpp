#include <vector> 
#include <string> 
#include <iostream>
#include <sstream>
#include <fstream>
 
// The User will either have to convert the source file format to csv, or this program will eventually be 
// able to automate this. 

class Formatter 
{
    public:
        std::string user_file; 

        struct Report
        {
            std::string buffer; 
            
            std::string amt;

            // we will need to find a way, either through user input or file name to parse
            // valid dates for the target month. 
            std::string date; 

        };
        void push_file();
        void user_prompt(); 
        void print();
        
        std::ifstream fileStream; 
       
        // sorts the report data
        std::vector<Report> setReport(std::vector<Report> r, std::string a, std::string b, std::string c); 

};

void::Formatter::push_file() {
    fileStream.open(user_file, std::ifstream::in);
    std::string line; 
    std::string buf; 
    std::string temp_amt;
    float amt;  
    std::string date;
    // dummy strings to be used as delimiters. These are essentially skipping columns in our csv
    std::string ig1,ig2,ig3,ig4,ig5,ig6,ig7,ig8;

    // We will need to add a line that skips the header row in our file. 

    while (std::getline(fileStream, line)) {
        std::stringstream ss(line); 
        std::getline(ss, ig1, ','); 
        std::getline(ss,ig2, ','); 
        std::getline(ss, ig3,','); 
        std::getline(ss,ig4,',');
        std::getline(ss,buf, ',');
        std::getline(ss, ig5, ','); 
        std::getline(ss, temp_amt, ','); 
        std::getline(ss, ig6, ','); 
        std::getline(ss, ig7, ','); 
        std::getline(ss, date, ','); 
        std::getline (ss, ig8, '\n');  
    }

    amt = std::stof(temp_amt);

    fileStream.close();
}

void::Formatter::user_prompt() {
    std::cout << "Enter file name and target month separated by a comma ',' " << "\n";

}

// void::Formatter::setReport()

