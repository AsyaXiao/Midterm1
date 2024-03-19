//
// Number of lines, words, and characters
//
#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> lettersWordsLines(std::ifstream &myfile) {
    std::string word;
    std::vector<int> a;
    int countletters = 0, countpunc = 0, countspace = 0, words = 0, line = 0;
    char character, prevchar = 0;
    while (myfile.get(character) && !myfile.eof()) {
        if (isalpha(character)) {
            countletters++;
        }
        if (ispunct(character)) {
            countpunc++;
            if (isalpha(prevchar)) {
                words++;
            }
        }
        if (isspace(character)) {
            countspace++;
            if (isalpha(prevchar)) {
                words++;
            }
        }
        if (character == '\n') {
            line++;
        }
        prevchar = character;
    }
    a.push_back(countletters);
    a.push_back(words);
    a.push_back(line);
    return a;
}

int main() {
    std::ifstream myfile;
    myfile.open("input.txt");
    std::cout << "Input file contains:" << std::endl;
    std::vector<int> result = lettersWordsLines(myfile);
    std::cout << result[0] << " letters" << std::endl;
    std::cout << result[1] << " words" << std::endl;
    std::cout << result[2] << " lines" << std::endl;
    myfile.close();
    return 0;
}
