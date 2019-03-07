#pragma once

#define MAXKEY 1024

class DynArray;

struct TkWord
{
    int tkcode;  //单词编码
    struct TkWord *next; //指向哈希冲突的同义词
    const char *spelling;  //单词字符串
};


enum token_code
{
    TK_PLUS,   //+
    TK_MINUS,  //-
    TK_STAR,   //*
    TK_DIVIDE, ///
    TK_MOD,    //%
    TK_ASSIGN,  //=
    TK_EQ,     //==
    TK_NEQ,    //!=
    TK_GT,     //>
    TK_GEQ,    //>=
    TK_LT,     //<
    TK_LEQ,    //<=
    TK_POINTTO, //->
    TK_DOT,    //.
    TK_AND,    //&
    TK_LS,     //(
    TK_RS,     //)
    TK_LM,     //[
    TK_RM,     //]
    TK_LL,     //{
    TK_RL,     //}
    TK_SEMICOLON, //;
    TK_COMMA,  //,

    //常量
    TK_CINT,   
    TK_CCHAR,
    TK_CSTR,

    //关键字
    KW_CHAR,
    KW_SHORT,
    KW_INT,
    KW_VOID,
    KW_STRUCT,
    KW_IF,
    KW_ELSE,
    KW_FOR,
    KW_CONTINUE,
    KW_BREAK,
    KW_RETURN,
    KW_SIZEOF,
    
    TK_REG  //??�� 


};

extern TkWord *tk_hashtable[MAXKEY];
extern DynArray tktable;

int get_hash(const char *key);
TkWord *tkword_direct_insert(TkWord *tp);
TkWord *tkword_find(const char *p, int hash_key);

