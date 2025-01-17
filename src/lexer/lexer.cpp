#include "lexer.hpp"
#include <regex>
#include <unordered_map>
#include <iostream>

const std::unordered_map<TokenType, std::string> tokenDefinitions = {
    {TokenType::KEYWORD, "\\b(int|float|if|else|return|while)\\b"},
    {TokenType::IDENTIFIER, "[a-zA-Z_][a-zA-Z0-9_]*"},
    {TokenType::INT_LITERAL, "0|[1-9][0-9]*"},
    {TokenType::FLOAT_LITERAL, "[0-9]+\\.[0-9]+([eE][+-]?[0-9]+)?"},
    {TokenType::CHAR_LITERAL, "'.'"},
    {TokenType::STRING_LITERAL, "\"[^\"]*\""},
    {TokenType::OPERATOR, "\\+|\\-|\\*|/|==|!=|<|>|<=|>=|=|\\+=|-=|\\*=|/="},
    {TokenType::DELIMITER, "[;{}(),]"},
    {TokenType::COMMENT, "//.*|/\\*.*?\\*/"},
    {TokenType::WHITESPACE, "[ \\t\\n]+"}
};

std::vector<Token> Lexer::tokenize(const std::string& code) {
    std::vector<Token> tokens;
    std::string remainingCode = code;

    while (!remainingCode.empty()) {
        bool matched = false;

        for (const auto& [type, pattern] : tokenDefinitions) {
            std::regex re("^" + pattern);
            std::smatch match;

            if (std::regex_search(remainingCode, match, re)) {
                if (type != TokenType::WHITESPACE) {
                    tokens.push_back({type, match.str(0)});
                }
                remainingCode = match.suffix();
                matched = true;
                break;
            }
        }

        if (!matched) {
            std::cerr << "Unexpected token: " << remainingCode[0] << std::endl;
            remainingCode = remainingCode.substr(1);
        }
    }

    return tokens;
}