#include "Parse.h"
#include "myenum.h"
Parse::Parse()
{
    lex = new Lex();    
}

Parse::~Parse()
{
    delete(lex);
}

void Parse::parse_control()
{
    while(lex->wd != EOF)
    {
        parse_declaration(S_CGF);
    }
}

void Parse::parse_declaration(int type)
{
    if(lex->wd == TK_SEMICOLON)
    {
        lex->deal_token();
        return;
    }
    for(;;)
    {
        parse_declarator();
    }

}

void Parse::parse_declarator()
{
    parse_function_calling();
    
}

void Parse::parse_function_calling()
{
    if(lex->wd == KW_CDECL || lex->wd == KW_STDCALL)
    {
        syn_state = SYN_SP;
        lex->deal_token();
    }
}
