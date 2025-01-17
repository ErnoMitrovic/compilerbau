#include "../src/lexer/lexer.hpp"
#include <iostream>

// TODO: Implement testing structure as unit tests
int main() {
    Lexer lexer;
    std::string code = R"(
        int x = 42;
        float y = 3.14;
        if (x > y) {
            return x;
        }
    )";

    auto tokens = lexer.tokenize(code);

    for (const auto& token : tokens) {
        std::cout << "Type: " << tokenTypeToString(token.type)
                  << ", Value: " << token.value << std::endl;
    }

    return 0;
}