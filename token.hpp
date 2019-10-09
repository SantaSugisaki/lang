#include<bits/std++.h>

typedef std::string TokenType;

struct Token {
    TokenType Type;
    std::string Literal;
};

// 識別子(変数や関数の名前) + リテラル(リテラルはキーワードでもある)
const std::string IDENT = "IDENT";
const std::string INT = "INT";
const std::string FLOAT = "FLOAT";
const std::string STRING = "STRING";
const std::string CHAR = "CHAR";
// 演算子
const std::string ASSIGN = "=";
const std::string PLUS ="+";
const std::string PLUSEQ = "+=";
const std::string MINUS = "-";
const std::string MINUSEQ = "-=";
const std::string BANG = "!";
const std::string ASTERISK = "*";
const std::string ASTERISKEQ = "*=";
const std::string SLASH = "/";
const std::string SLASHEQ = "/=";

// 比較演算子, &&,||など
const std::string LT = "<";
const std::string LTE = "<=";
const std::string GT = ">";
const std::string GTE = ">=";
const std::string EQ = "==";
const std::string NOT_EQ = "!=";
const std::string AND = "&&";
const std::string OR = "||";

// デリミタ(各項目を区切る目印として使う文字)
const std::string COMMA = ",";
const std::string SEMICOLON = ";";
const std::string LPAREN = "(";
const std::string RPAREN = ")";
const std::string LBRACE = "{";
const std::string RBRACE = "}";

// キーワード
const std::string FUNCTION = "FUNCTION";
const std::string IMPORT = "IMPORT";
const std::string TRUE = "TRUE";
const std::string FALSE = "FALSE";
const std::string IF = "IF";
const std::string ELSE = "ELSE";
const std::string FOR = "FOR";
const std::string DEFINE = "DEFINE";
const std::string RETURN = "RETURN";
const std::string IMPORT = "IMPORT";

std::map<std::string, TokenType> keywords {
    { "func", FUNCTION },
    { "import", IMPORT },
    { "int", INT },
    { "float", FLOAT },
    { "string", STRING },
    { "char", CHAR },
    { "if", IF },
    { "else", ELSE },
    { "for", FOR },
    { "#define", DEFINE },
    { "return", RETURN }
};
