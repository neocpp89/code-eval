#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

int main()
{
    std::string message = "012222 1114142503 0313012513 03141418192102 0113 2419182119021713 06131715070119";
    std::string keyed_alphabet = "BHISOECRTMGWYVALUZDNFJKPQX";
    std::vector<char> decoded_message;
    std::istringstream iss(message);
    int w = 0;
    while (true) {
        std::string word;
        iss >> word;
        if (iss.fail()) {
            break;
        }
        int idx = 0;
        for (size_t i = 0; i < word.size(); i += 2) {
            idx = atoi(word.substr(i, 2).c_str());
            char c = 'A' + static_cast<char>(keyed_alphabet.find('A' + static_cast<char>(idx)));
            decoded_message.push_back(c);
        }
        decoded_message.push_back(' ');
        w++;
    }
    for (size_t i = 0; i < decoded_message.size(); i++) {
        std::cout << decoded_message[i];
    }
    std::cout << '\n';
    return 0;
}
