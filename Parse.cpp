#include "Parse.h"
#include "myenum.h"
Parse::Parse()
{
    lex = new Lex();
    parse_control();
}

Parse::~Parse()
{
    delete(lex);
}

void Parse::parse_control()
{
    while(lex->wd != EOF)
    {
        syn_state = SYN_NULL;
        lex->deal_token();
        parse_declaration(S_CGF); //每次解析一条语句
        parse_indent();
    }
}

void Parse::parse_declaration(int type)
{
    parse_declare_type();
    if(lex->tkcolor == TK_SEMICOLON)
    {
        return;
    }
    for(;;)
    {
        parse_declarator(); //完成int a  int a()  int a(int, int) int a =
        if(lex->tkcolor == TK_ASSIGN)
        {
            lex->deal_token();
            parse_reg_assign(); 
        }
        else if(lex->tkcolor == TK_COMMA)
        {
            lex->deal_token();
        }
        else if(lex->tkcolor == TK_SEMICOLON)
        {
            syn_state = SYN_DELAY;
            syn_level = syn_level;
            break;
        }
        else if(lex->tkcolor == TK_LL)
        {
            syn_state = SYN_NL_ID;
            syn_level += 2;
            break;
        }
        else if(lex->tkcolor == TK_RL)
        {
            syn_state = SYN_NL_ID;
            syn_level = 0;
            break;
        }
    }

}

void Parse::parse_reg_assign()
{

}

int Parse::parse_declare_type()
{
    int type = 0;
    switch(lex->tkcolor)
    {
    case KW_CHAR:
        type = 1;
        syn_state = SYN_SP;
        lex->deal_token();
        break;
    case KW_INT:
        type = 1;
        syn_state = SYN_SP;
        lex->deal_token();
        break;
    case KW_SHORT:
        type = 1;
        syn_state = SYN_SP;
        lex->deal_token();
        break;
    case KW_VOID:
        type = 1;
        syn_state = SYN_SP;
        lex->deal_token();
        break;
    default:
        break;
    }
    return type;
}

void Parse::parse_declarator()
{
    //parse_function_calling();
    parse_declarator_kind();

}

void Parse::parse_function_calling()
{
    if(lex->tkcolor == KW_CDECL || lex->tkcolor == KW_STDCALL)
    {
        syn_state = SYN_SP;
        lex->deal_token();
    }
}

void Parse::parse_declarator_kind()
{
    if(lex->tkcolor == TK_LS)  //含‘（’ 是函数的声明
    {
        parse_parameter_list(); //解析参数列表
        lex->deal_token();  //应该得到'{'或';'
    }
    else if(lex->tkcolor == TK_LM) // 含'['是数组的声明
    {
        lex->deal_token();
        if(lex->tkcolor == TK_CINT)
        {
            lex->deal_token(); //读取数组的右中括号
        }
        lex->deal_token(); //应该读一个等号或者逗号或者分号，然后回到parse_declaration

    }
    else
    {
        lex->deal_token();
    }
}

void Parse::parse_parameter_list()
{
    lex->deal_token();
    while(lex->tkcolor != TK_RS)
    {
        parse_declare_type(); //解析函数参数的类型
        parse_declarator();  //解析函数参数的声明 递归调用
            
    }

}

void Parse::parse_indent()
{
    switch(syn_state)
    {
    case SYN_NULL:
        break;
    case SYN_SP:
        printf("  ");
        break;
    case SYN_NL_ID:
        printf("\n");
        for(int i = 1; i<=syn_level; i++)
        {
            printf("  ");
        }
        break;
    case SYN_DELAY:
        printf("\n");
        lex->getword();
        while(lex->wd == '\n')
        {
            lex->getword();
        }
        if(lex->wd != '}')
        {
            for(int i = 1; i<=syn_level; i++)
            {
                printf("  ");
            }
        }
        ungetc(lex->wd, lex->fd);
        break;
    }

}
