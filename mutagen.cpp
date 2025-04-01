#include <iostream>
#include <string>
#include <sstream>
#include <getopt.h>

void print_help() {
    std::cout << "Usage: ./mutagen -p [PUZZLE_NUMBER] -t [THREAD_COUNT] -r [RANGE] -R [RANGE]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "-p    Puzzle number to solve (20-68)" << std::endl;
    std::cout << "-t    Number of worker threads to use" << std::endl;
    std::cout << "-r    Range of possible keys to find private keys (e.g., 0x00000000-0xFFFFFFFF)" << std::endl;
    std::cout << "-R    Alternative range option (e.g., 0x00000000-0xFFFFFFFF)" << std::endl;
    std::cout << "-h    Show help message" << std::endl;
}

int main(int argc, char *argv[]) {
    int puzzle_number = 0;
    int thread_count = 0;
    std::string range, alt_range;

    int opt;
    while ((opt = getopt(argc, argv, "p:t:r:R:h")) != -1) {
        switch (opt) {
            case 'p':
                puzzle_number = std::stoi(optarg);
                break;
            case 't':
                thread_count = std::stoi(optarg);
                break;
            case 'r':
                range = optarg;
                break;
            case 'R':
                alt_range = optarg;
                break;
            case 'h':
                print_help();
                return 0;
            default:
                print_help();
                return 1;
        }
    }

    // Validate and process the range inputs,
    if (!range.empty()) {
        std::cout << "Range specified: " << range << std::endl;
        // Add your logic to handle the range
    }

    if (!alt_range.empty()) {
        std::cout << "Alternative range specified: " << alt_range << std::endl;
        // Add your logic to handle the alternative range
    }

    // Your existing logic to solve the puzzle using puzzle_number and thread_count
    std::cout << "Puzzle number: " << puzzle_number << std::endl;
    std::cout << "Thread count: " << thread_count << std::endl;

    return 0;
}
