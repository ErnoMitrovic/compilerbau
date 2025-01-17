/** 
 * Tokens for the lexer
 * 
*/

#ifndef TOKENS_HPP
#define TOKENS_HPP

#include <string>

enum class TokenType {
    KEYWORD,
    IDENTIFIER,
    INT_LITERAL,
    FLOAT_LITERAL,
    CHAR_LITERAL,
    STRING_LITERAL,
    OPERATOR,
    DELIMITER,
    COMMENT,
    WHITESPACE,
    UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
};

/**
 * This function converts a TokenType to a string just for debugging purposes
 * 
 * @param type The TokenType to convert
 * @return The string representation of the TokenType
 */
inline std::string tokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::KEYWORD: return "KEYWORD";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::INT_LITERAL: return "INT_LITERAL";
        case TokenType::FLOAT_LITERAL: return "FLOAT_LITERAL";
        case TokenType::CHAR_LITERAL: return "CHAR_LITERAL";
        case TokenType::STRING_LITERAL: return "STRING_LITERAL";
        case TokenType::OPERATOR: return "OPERATOR";
        case TokenType::DELIMITER: return "DELIMITER";
        case TokenType::COMMENT: return "COMMENT";
        case TokenType::WHITESPACE: return "WHITESPACE";
        default: return "UNKNOWN";
    }
}

#endif