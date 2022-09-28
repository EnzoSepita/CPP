#include <iostream>
#include <fstream>
#include <vector>




int main(int argc , char* argv[]) {
    if(argc != 0) {
        std::ifstream fileStream(argv[1]);
        if (fileStream.fail()) {
            //file could not be opened
            std::cout << "The file " << argv[1] << "could not be opened." << std::endl;
            return 1;
        }
        int count = 0 ;
        std::vector<std::string> words;
        std::string word;
        while (fileStream >> word) {
            words.push_back(word);
            if (word.find(argv[2]) != std::string::npos)
                count = count + 1;
        }

        std::cout << "The file " << argv[1] << " contains " << count << " words containing the motive " << argv[2] << std::endl;
        fileStream.close();
        return 0;

    }
}