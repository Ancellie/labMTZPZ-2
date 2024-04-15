#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "converter.hpp"

void checkArguments(int argc, char* argv[]) {
    if (argc != 2 && argc != 4 && argc != 6) {
        throw std::runtime_error("Wrong format of input arguments");
    }

    if (argc == 6 && std::string(argv[4]) != "--format") {
        throw std::runtime_error("Wrong format of input arguments");
    }
}

std::string getOutputFormat(int argc, char* argv[]) {
    if (argc == 6) {
        std::string formatArg(argv[5]);
        std::istringstream iss(formatArg);
        std::string format;
        std::getline(iss, format, '=');
        return format;
    } else if (argc == 4) {
        return "html";
    }
    return "ansi";
}

int main(int argc, char* argv[]) {
    try {
        checkArguments(argc, argv);

        std::string inputFile = argv[1];
        std::string outputFile;
        std::string outputFormat = getOutputFormat(argc, argv);

        if (argc >= 4) {
            outputFile = argv[3];
        }

        std::ifstream inputFileStream(inputFile);
        std::string markdownText((std::istreambuf_iterator<char>(inputFileStream)), std::istreambuf_iterator<char>());

        std::string htmlText = Converter::markdownToHTML(markdownText);
        if (outputFile.empty()) {
            std::cout << (outputFormat == "html" ? htmlText : Converter::formatTextWithANSI(htmlText)) << std::endl;
        } else {
            if (outputFormat == "html") {
                std::ofstream outFile(outputFile);
                outFile << htmlText;
                std::cerr << "HTML розмітка була збережена в файлі: " << outputFile << std::endl;
            } else {
                std::ofstream outFile(outputFile);
                outFile << Converter::formatTextWithANSI(htmlText);
                std::cerr << "ANSI-форматований текст був збережений в файлі: " << outputFile << std::endl;
            }
        }

    } catch (const std::exception& e) {
        std::cerr << "Помилка обробки файлу: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}


/*int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/
