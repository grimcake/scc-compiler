#pragma once

#include "Lex.h"

class Parse
{
public:
    Parse();
    ~Parse();
    void parse_control(); //控制程序
    void parse_declaration(int type); //解析声明
    int parse_declare_type(); //解析声明的类型 int char等
    void parse_declarator(); //解析声明符
    void parse_declarator_kind(); //解析声明的种类 比如变量还是数组还是函数
    void parse_parameter_list(); //解析函数参数列表
    void parse_function_calling(); //解析函数调用约定 _cdecl或_stdcall
    void parse_reg_assign();  //解析赋值语句

    void parse_indent(); //控制缩进
private:
    Lex *lex;
    int syn_state; //控制语法状态是否换行
    int syn_level; //控制缩进级别

};


