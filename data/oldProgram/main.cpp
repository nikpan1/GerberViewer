#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>


int main(int argc, char **argv) {
  if(argc != 2) std::cerr << "Wrong input amount\n";
  std::ifstream input;
  input.open(argv[1]);
  if(!input.is_open()) std::cerr << "File doesn't exist.\n";


  std::string newName(argv[1]); newName += ".new";
  std::ofstream output(newName);
  if(!output.is_open()) std::cerr << "(output) File doesn't exist.\n";


  std::string line;
  // copy until the Origin starts
  while(std::getline(input, line) && line[0] != 'O') output << line <<std::endl;
  
  // just take the first two lines of Origin
  output << line <<std::endl;
  std::getline(input, line);
  output << line <<std::endl;

  // we don't care about the start 
  while(std::getline(input, line) && line[0] == 'O');

  // get the i0 and I0 
  std::ostringstream mountStream;
  mountStream << line <<std::endl;
  std::getline(input, line);
  mountStream << line <<std::endl;

  std::string empty = "O   ";
  std::string ends = "      10";
  std::string m_empty = "M    ";
  int OriginCounter = 2; // O2 .. On
  int MountCounter = 0;
  while(std::getline(input, line) && line.size() > 5) {
    line.replace(0, m_empty.size(), m_empty);
    std::string newVal = std::to_string(MountCounter);
    line.replace(1, newVal.size(), newVal);


    // check if there is an copy of it 
    
    mountStream << line <<std::endl;
    
    std::string numb = std::to_string(OriginCounter);
    line.replace(0, empty.size(), empty);
    line.replace(1, numb.size(), numb);
    line.replace(line.size() - ends.size() - 1, ends.size(), ends);
    output << line <<std::endl;
    OriginCounter ++;
    MountCounter ++;
  }
  output << mountStream.str();
  
  input.close();
  output.close();
  return 0;
}
