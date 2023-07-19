#include <vector> 
#include <string> 
#include <iostream>
#include <sstream>
#include <fstream>
 
// The User will either have to convert the source file format to csv, or this program will eventually be 
// able to automate this. 

// Given that metrics are due every month, as of now this program will only handle one month reports. 
// Adjustments will need to be made to handle reports for multiple months. 

class Formatter 
{
    public:
        std::string user_file; 

        struct Report
        {
            std::string name; 
            std::string amt;

            // we will need to find a way, either through user input or file name to parse
            // valid dates for the target month. 
            std::string date; 

        };
        // Creates the data structure necessary to perform search/ summations on. 
        void push_file();

        void user_prompt();
        
        // A search algorithm summing total Liters for each type of Buffer in our report. 
        void vol_total();

        // A simple algorithm summing all occurences of each buffer in our report.  
        void req_total();
 
        void print();
        
        std::ifstream fileStream;
        std::vector<Report> report;  
       
        // sorts the report data
        std::vector<Report> setReport(std::vector<Report> r, std::string a, float b, std::string c); 

};

void::Formatter::push_file() {
    fileStream.open(user_file, std::ifstream::in);

    std::string line, buf, temp_amt, date; 
    float amt;  

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

        amt = std::stof(temp_amt);

        if (date == "Not Yet Completed") {
            std::cout << "one or more buffers were not recorded as 'completed', return to the excel sheet and add dates." << "\n";
            break;
        }

        report = setReport(report, buf, amt, date); 
    }
    fileStream.close();
}

void::Formatter::user_prompt() {
    std::cout << "Enter file name and target month separated by a comma ',' " << "\n";

}

void::Formatter::vol_total() {

}

void::Formatter::req_total() {
    
}

std::vector<Formatter::Report> Formatter::setReport(std::vector<Report> r, std::string a, float b, std::string c) {
    Report myReport; 
    myReport.name = a; 
    myReport.amt = b; 
    myReport.date = c; 
    r.push_back(myReport); 
    return r; 
}

void::Formatter::print() {
    for (int i = 0; i < report.size() - 1; i++ ) {
        std::cout << report[i].name << " [" << i << "]" << "\n"; 
        std::cout << "Amount: " << report[i].amt << ", " << "Date: " << report[i].date << "\n";
    }   
}

