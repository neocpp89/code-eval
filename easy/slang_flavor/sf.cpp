#include <iostream>
#include <fstream>
#include <string>

const int num_phrases = 8;
const std::string phrases[num_phrases] =
{
", yeah!",
", this is crazy, I tell ya.",
", can U believe this?",
", eh?",
", aw yea.",
", yo.",
"? No way!",
". Awesome!"
};

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }

    std::ifstream f(argv[1]);
    int which_phrase = 0;
    int parity = 0;
    while (true) {
        std::string line;   
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        size_t n;
        while ((n = line.find_first_of(".!?")) != std::string::npos) {
            std::cout << line.substr(0, n);
            if (parity % 2) {
                std::cout << phrases[which_phrase];
                which_phrase = (which_phrase + 1) % num_phrases;
            } else {
                std::cout << line[n];
            }
            line = line.substr(n+1);
            parity++;
        }
        std::cout << '\n';
    }
    return 0;
}
