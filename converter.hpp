#include <regex>
#include <string>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <string_view>

class Converter {
public:
    static std::string markdownToHTML(std::string markdownText);
    static std::string formatTextWithANSI(const std::string& text);
    static void _checkCoherence(const std::string& markdownText);
    static void _checkOpenedTags(const std::string& markdownText);
private:
    static std::vector<std::string> splitParagraphs(const std::string& markdownText);
};
