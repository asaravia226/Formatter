#include <vector> 
#include <string> 
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm> 
#include <iterator> 
 
// The User will either have to convert the source file format to csv, or this program will eventually be 
// able to automate this. 

// Given that metrics are due every month, as of now this program will only handle one month reports. 
// Adjustments will need to be made to handle reports for multiple months. 

class Formatter 
{
    public:
        std::ifstream fileStream;
        std::string month; 
        std::string user_file = "request_report_20230501_20230731.csv"; 

        struct Report
        {
            // we will need to find a way, either through user input or file name to parse
            // valid dates for the target month. 
            std::string date;
            std::string name; 
            // int count;
            float amt;
            // float total_vol;   

        };

        struct newReport {
            std::string name; 
            float count;
            float total_vol;  
        };

        struct Source {
            std::string item; 
            int count; 
        };

        // Creates the data structure necessary to perform search/ summations on. 
        void push_file();

        // This function reads a text file and inserts each line into a vector. 
        void push_source();
        
        void date_parser(); 

        void user_prompt();
        
        // A search algorithm summing total Liters for each type of Buffer in our report. 
        void vol_total();

        // A simple algorithm summing all occurences of each buffer in our report.  
        void req_total();
 
        void print();
        
        void newList();
        
        // This vector contains structs that have taken in original data from our csv. 
        std::vector<Report> report;
        
        // This list does not include any duplicates. 
        std::vector<newReport> nr;

        // This vector will contain the source list, which mirrors the program's desired output. 
        std::vector<Source> source_list; 


        // sorts the report data
        std::vector<Report> setReport(std::vector<Report> r, std::string a, float b, std::string c); 

        std::vector<newReport> setNewReport(std::vector<newReport> nr, std::string a); 

};

void::Formatter::push_source() {
    fileStream.open("teams_buffer_list.txt", std::ifstream::in); 
    std::string line, buf; 

    while (std::getline(fileStream, line)) {
        std::stringstream ss(line); 
        std::getline(ss, buf, '\n'); 
    }

    // newReport = setNewReport()


}
void::Formatter::push_file() {
    fileStream.open(user_file, std::ifstream::in);

    std::string line, buf, temp_amt, date; 
    float amt;  

    // dummy strings to be used as delimiters. These are essentially skipping columns in our csv
    std::string header, ig1,ig2,ig3,ig4,ig5,ig6,ig7,ig8;

    // We will need to add a line that skips the header row in our file. 

    while (std::getline(fileStream, line)) {
        std::stringstream ss(line); 
        std::getline(ss, header, '\n'); 
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

void::Formatter::newList() {
    // create a copy of report
    // std::copy(report.begin(), report.end(), back_inserter(nr));
    
    // Erase Duplicates
    // std::sort(newReport.begin(), newReport.end()); 
    // newReport.erase(unique(newReport.begin(), newReport.end()), newReport.end()); 
}

void::Formatter::date_parser() {
    // Take user input from user propmt function 
    // e.g. enter month using a digit (1-12) 
    // for loop to delete all instances that do not contain month digit in report[i].date.

    for (int i = 0; i < report.size(); i++) {
        if (report[i].date.substr(5,2) != month) {
            report.push_back(report[i]);
            report.pop_back();
        }
    }

    // we can now make a new list for items falling in the target month
    newList(); 
}

void::Formatter::user_prompt() {
    // std::cout << "Enter the full file name"; 
    // std::cin >>  user_file; 
    std::cout << "Enter the target month for your report using a digit (1-12)"; 
    std::cin >> month; 

    if (month.size() == 1)
        month = "0" + month; 
    
    push_file();
    date_parser();
    vol_total(); 
    req_total(); 

}

void::Formatter::vol_total() {
    // Count all repeats in list. 
    for (int i = 0; i < nr.size(); i++) {
        for (int j = 0; j < report.size(); j++) {
            if (nr[i].name == report[j].name) {
                nr[i].total_vol = nr[i].total_vol + report[j].amt;
            } 
        }
    }
}

void::Formatter::req_total() {
    // Count all repeats in list. 
    for (int i = 0; i < nr.size(); i++) {
        for (int j = 0; j < report.size(); j++) {
            if (nr[i].name == report[j].name) {
                nr[i].count++;
                continue;  
            }
        }
    }
}

std::vector<Formatter::Report> Formatter::setReport(std::vector<Report> r, std::string a, float b, std::string c) {
    Report myReport; 
    myReport.name = a; 
    myReport.amt = b; 
    myReport.date = c; 
    r.push_back(myReport); 
    return r; 
}

std::vector<newReport> setNewReport(std::vector<newReport> nr, std::string a) {
    newReport newrep; 
}

void::Formatter::print() {
    for (int i = 0; i < report.size() - 1; i++ ) {
        std::cout << report[i].name << " [" << i << "]" << "\n"; 
        std::cout << "Amount: " << report[i].amt << ", " << "Date: " << report[i].date << "\n";
    }   
}

int main() {
    Formatter form; 
    form.user_prompt(); 

    return 0; 
}

