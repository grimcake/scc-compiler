#pragma once

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
    KW_KEYWORD, //代表所有关键字，用于染色

    TK_REG,  //reg
    TK_NOTE, // /*/
    
    //函数调用约定
    KW_CDECL,
    KW_STDCALL
};




enum store_type
{
    S_CGF //const global function
};


enum SynState
{
    SYN_NULL,  //空状态，无动作
    SYN_SP,  //空格
    SYN_NL_ID,  //换行并缩进
    SYN_DELAY  //延迟取单词

};
