#include<bits/stdc++.h>
#include<token.hpp>

// 字句解析器を構成しているもの
struct Lexer {
    std::string input;
    int position;   // 入力における現在の位置(現在の文字を示す)
    int readPosition;   // これから読み込む位置(現在検査中の次)
    char ch;    // 現在検査中の文字
};

// 次の文字を読み込んでpositionとreadPositionを更新している
void readChar( Lexer *l )
{
    if ( l->readPosition >= l->input.size() )
    {
        l->ch = '\0';
    }
    else
    {
        l->ch = l->input[l->readPosition];
    }
    l->position = l->readPosition;
    l->readPosition += 1;
}

// 字句解析器を生成する関数
Lexer New(std::string input)
{
    Lexer *l = new Lexer();
    l -> input = input;
    readChar(l);
    return *l;
}

void skipWhiteSpace( Lexer *l )
{
    while( l->ch == ' ' || l->ch == '\t' || l->ch == '\n' || l->ch == '\r')
    {
        readChar(l);
    }
}

char peekChar(Lexer * l)
{
    if(l->readPosition >= l->input.size())
    {
        return '\0';
    }
    else
    {
        return l->input[l->readPosition];
    }
}

Token newToken(TokenType tokenType, char ch)
{
    return { tokenType, (string)ch };
}

Token NextToken( Lexer *l )
{
    Token tok;
    skipWhiteSpace(l);
    // caseとbreakは必ず対にする事
    switch(l->ch)
    {
        case '=':
            if ( peekChar(l) == '=')
            {
                char ch = l->ch;
                readChar(l);
                std::string literal = (std::string)ch + (std::string)l->ch;
                tok = { EQ, literal };
            }
            else
            {
                tok = newToken(ASSIGN, l->ch);
            }
        break;
        case '+':
            if( peekChar(l) == '=')
            {
                char ch = l->ch;
                readChar(l);
                std::string literal = (std::string)ch + (std::string)l->ch;
                tok = { PLUSEQ, literal };
            }
            else
            {
                tok = newToken(PLUS, l->ch);
            }
        break;
        case '-':
            if ( peekChar(l) == '=' )
            {
                char ch = l->ch;
                readChar(l);
                std::string literal = (std::string)ch + (std::string)l->ch;
                tok = { MINUSEQ, literal };
            }
            else
            {
                tok = newToken(MINUS, l->ch);
            }
        break;
        case '!':
            if ( peekChar(l) == '=' )
            {
                char ch = l->ch;
                readChar(l);
                std::string literal = (std::string)ch + (std::string)l->ch;
                tok = { NOT_EQ, literal};
            }
            else
            {
                tok = newToken( BANG, l->ch );
            }
        break;
        case '/':
            if ( peekChar(l) == '=')
            {
                char ch = l->ch;
                readChar(l);
                std::string literal = (std::string)ch + (std::string)l->ch;
                tok = { SLASHEQ, literal };
            }
            else
            {
                tok = newToken( SLASH, l->ch );
            }
        break;
        case '*':
            if (peekChar(l) == '=' )
            {
                char ch = l->ch;
                readChar(l);
                std::string literal = (std::string)ch + (std::string)l->ch;
                tok = { ASTERISKEQ, literal };
            }
            else
            {
                tok = newToken( ASTERISK, l->ch );
            }
        break;
        case '<':
            if ( peekChar(l) == '=' )
            {
                char ch = l->ch;
                readChar(l);
                std::string literal = (std::string)ch + (std::string)l->ch;
                tok = { LTE, literal };
            }
            else
            {
                tok = newToken( LT, l->ch );
            }
        break;
        case '>':
            if ( peekChar(l) == '=' )
            {
                char ch = l->ch;
                readChar(l);
                std::string literal = (std::string)ch + (std::string)l->ch;
                tok = { GTE, literal };
            }
            else
            {
                tok = newToken( GT, l->ch );
            }
        break;
        case ';':
            tok = newToken( SEMICOLON, l->ch );
        break;
        case ',':
            tok = newToken( COMMA, l->ch );
        break;
        case '(':
            tok = newToken( LPAREN)
    }
}

/*
int main()
{
    Lexer l = New("santa");
    std::cout << l.input << std::endl;
}
*/