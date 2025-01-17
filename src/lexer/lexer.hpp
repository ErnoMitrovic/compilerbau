#ifndef LEXER_HPP
#define LEXER_HPP

#include "tokens.hpp"
#include <string>
#include <vector>

class Lexer {
public:
    /**
     * Tokenizes the given code
     * 
     * @param code The code to tokenize
     * @return The tokens
     */
    std::vector<Token> tokenize(const std::string& code);
};

#endif 