#include <iostream>
#include <regex>
#include <chrono>


std::string input = "%ADD901C,0.01000*%\n%ADD23C,0.02300*%";
#define TEST_BATCH_SIZE 1000


template <typename F>
double measureExecutionTime(F func) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < TEST_BATCH_SIZE; i++) func(); 
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    return static_cast<double>(duration) / TEST_BATCH_SIZE;
}


void regex_test() {
    std::regex pattern(R"(%ADD(\d+)C,([\d.]+)\*%)");
    std::sregex_iterator it(input.begin(), input.end(), pattern);
    std::sregex_iterator end;

    while (it != end) {
        std::smatch match = *it;
        //std::cout << "Code: " << match[1] << ", Value: " << match[2] << std::endl;
        it++;
    }
}

void standard_test() {
        size_t pos = 0;

    while ((pos = input.find("%ADD", pos)) != std::string::npos) {
        pos += 4; // Move to value after "%ADD"

        // Find the 'C' and ',' pos
        size_t cPos = input.find('C', pos);
        size_t commaPos = input.find(',', pos);

        if (cPos != std::string::npos && commaPos != std::string::npos && cPos < commaPos) {
            std::string codeStr = input.substr(pos, cPos - pos);
            std::string valueStr = input.substr(commaPos + 1, input.find('*', commaPos) - commaPos - 1);
            
            // result
            int code = std::stoi(codeStr);
            double value = std::stod(valueStr);
            pos = commaPos + 1;
        } else pos++;
    }
}

int main() {
    std::cout << "regex time = " << measureExecutionTime(regex_test) << "\n";
    std::cout << "standard time = " << measureExecutionTime(standard_test) << "\n";
    return 0;
}

