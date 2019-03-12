#pragma once

#include "Lex.h"

class Parse
{
public:
    Parse();
    ~Parse();
    void parse_control(); //控制程序
    void parse_declaration(int type); //解析声明
    void parse_declarator(); //解析声明符
    void parse_function_calling(); //解析函数调用约定 _cdecl或_stdcall
private:
    Lex *lex;
    int syn_state; //控制语法状态是否换行
    int syn_level; //控制缩进级别
};


