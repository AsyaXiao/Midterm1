#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    {
        std::ofstream myfile;//поток вывода файла
        myfile.open("../data/input.txt");
        if (myfile.is_open()) {
            myfile << "4 3" << "\n";
            myfile << "sweden 4 6 3" << "\n";
            myfile << "queen 0 2 2 \n";
            myfile << "norway 4 7 5 \n";
            myfile << "king -1 3 2 \n";
        }

        myfile.close();
    }
    std::ifstream myfile("../data/input.txt");
    int N, M;
    if (myfile.is_open()) {
        myfile >> M >> N;
        std::vector<std::string> words;
        std::vector<int> summa;
        std::vector<int> for_1;
        std::string word1;
        myfile >> word1;
        for (size_t i = 0; i < N; ++i) {
            int a;
            myfile >> a;
            for_1.push_back(a);
        }
        for (size_t m = 0; m < M - 1; ++m) {
            std::string a;
            myfile >> a;
            words.push_back(a);
            int summa1 = 0;
            for (size_t n = 0; n < N; ++n) {
                int b;
                myfile >> b;
                summa1 += b * for_1[n];
            }
            summa.push_back(summa1);
        }
        int closest;
        closest = *std::max_element(summa.begin(), summa.end());
        for (size_t k = 0; k < summa.size(); ++k) {
            if (summa[k] == closest) {
                std::cout << words[k] << std::endl;
            }
        }

    }
}