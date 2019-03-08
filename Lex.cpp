#include "Lex.h"


Lex::Lex()
{
	init_lex();
	start_lex("./test.c");
}

Lex::~Lex()
{

}

void Lex::init_lex()
{	
    static TkWord keywords[] = {
    {TK_PLUS, NULL, "+"},
    {TK_MINUS, NULL, "-"},
    {TK_STAR, NULL, "*"},
    {TK_DIVIDE, NULL, "/"},
    {TK_MOD, NULL, "%"},
    {TK_ASSIGN, NULL, "="},
    {TK_EQ, NULL, "=="},
    {TK_NEQ, NULL, "!="},
    {TK_GT, NULL, ">"},
    {TK_GEQ, NULL, ">="},
    {TK_LT, NULL, "<"},
    {TK_LEQ, NULL, "<="},
    {TK_POINTTO, NULL, "->"},
    {TK_DOT, NULL, "."},
    {TK_AND, NULL, "&"},
    {TK_LS, NULL, "("},
    {TK_RS, NULL, ")"},
    {TK_LM, NULL, "["},
    {TK_RM, NULL, "]"},
    {TK_LL, NULL, "{"},
    {TK_RL, NULL, "}"},
    {TK_SEMICOLON, NULL, ";"},
    {TK_COMMA, NULL, ","},

    //常量
    {TK_CINT, NULL, "CINT"},   
    {TK_CCHAR, NULL, "CCHAR"},
    {TK_CSTR, NULL, "CSTR"},

    //关键字
    {KW_CHAR, NULL, "char"},
    {KW_SHORT, NULL, "short"},
    {KW_INT, NULL, "int"},
    {KW_VOID, NULL, "void"},
    {KW_STRUCT, NULL, "struct"},
    {KW_IF, NULL, "if"},
    {KW_ELSE, NULL, "else"},
    {KW_FOR, NULL, "for"},
    {KW_CONTINUE, NULL, "continue"},
    {KW_BREAK, NULL, "break"}, 
    {KW_RETURN, NULL, "return"},
    {KW_SIZEOF, NULL, "sizeof"},
    {-1, NULL, "NULL"}};
	
	
	for(tp = &keywords[0]; tp->tkcode != -1; tp++)
	{
		tkword_direct_insert(tp);
	}
}


void Lex::getword()
{	
	wd = getc(fd);
}

void Lex::start_lex(const char* filepath)
{
	fd = fopen(filepath, "rb");
	if(fd == NULL)
	{
		printf("file don't exit\n'");
		return;
	}
	while(wd != EOF)
	{
		getword();
		deal_token();
        show_token();
	}

}

void Lex::deal_token()
{
	deal_unnormal_token();
	
    if(wd == '+')
    {
        tkcolor = TK_PLUS; 
    }
}
void Lex::deal_unnormal_token()
{
	if(wd == '/')
	{
		getword();
		if(wd == '*')
		{
			deal_note();
		}
		else
		{
			ungetc(wd, fd);
			wd = '/';
			return;
		}
	}
	else if(wd == ' ')
	{
		deal_space();
	}
}

void Lex::deal_note()
{
	for(;;)
	{
		getword();
		if(wd == '*')
		{
			getword();
			if(wd == '/')
			{
				getword();
				break;
			}
			else
			{
				ungetc(wd, fd);
				continue;
			}
		}
	}
}

void Lex::deal_space()
{
	for(;;)
	{
		getword();
		if(wd == '\n' || wd == '\r' || wd == ' ')
		{
			continue;
		}
		else
		{
			break;
		}
	}
}

void Lex::show_token()
{
    string str = string_from_tkcolor(tkcolor);
    printf("%s\n", str.c_str());
}

string Lex::string_from_tkcolor(int tk_color)
{

}
