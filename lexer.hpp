#include<bits/stdc++.h>
//#include<token.hpp>

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

int main()
{
    Lexer l = New("santa");
    std::cout << l.input << std::endl;
}
