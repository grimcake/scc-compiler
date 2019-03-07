#include "Lex.h"
#include "TkWord.h"


Lex::Lex()
{
	init_lex();
	start_lex("xx.c");
}

Lex::~Lex()
{

}

void Lex::init_lex()
{	
    static TkWord keywords[] = {
    {TK_PLUS, NULL, (char *)"+"},
    {TK_MINUS, NULL, (char *)"-"},
    {TK_STAR, NULL, (char *)"*"},
    {TK_DIVIDE, NULL, (char *)"/"},
    {TK_MOD, NULL, (char *)"%"},
    {TK_ASSIGN, NULL, (char *)"="},
    {TK_EQ, NULL, (char *)"=="},
    {TK_NEQ, NULL, (char *)"!="},
    {TK_GT, NULL, (char *)">"},
    {TK_GEQ, NULL, (char *)">="},
    {TK_LT, NULL, (char *)"<"},
    {TK_LEQ, NULL, (char *)"<="},
    {TK_POINTTO, NULL, (char *)"->"},
    {TK_DOT, NULL, (char *)"."},
    {TK_AND, NULL, (char *)"&"},
    {TK_LS, NULL, (char *)"("},
    {TK_RS, NULL, (char *)")"},
    {TK_LM, NULL, (char *)"["},
    {TK_RM, NULL, (char *)"]"},
    {TK_LL, NULL, (char *)"{"},
    {TK_RL, NULL, (char *)"}"},
    {TK_SEMICOLON, NULL, (char *)";"},
    {TK_COMMA, NULL, (char *)","},

    //常量
    {TK_CINT, NULL, (char *)"CINT"},   
    {TK_CCHAR, NULL, (char *)"CCHAR"},
    {TK_CSTR, NULL, (char *)"CSTR"},

    //关键字
    {KW_CHAR, NULL, (char *)"char"},
    {KW_SHORT, NULL, (char *)"short"},
    {KW_INT, NULL, (char *)"int"},
    {KW_VOID, NULL, (char *)"void"},
    {KW_STRUCT, NULL, (char *)"struct"},
    {KW_IF, NULL, (char *)"if"},
    {KW_ELSE, NULL, (char *)"else"},
    {KW_FOR, NULL, (char *)"for"},
    {KW_CONTINUE, NULL, (char *)"continue"},
    {KW_BREAK, NULL, (char *)"break"}, 
    {KW_RETURN, NULL, (char *)"return"},
    {KW_SIZEOF, NULL, (char *)"sizeof"}};
	
	
	for(tp = &keywords[0]; tp->spelling!=NULL; tp++)
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
	}

}

void Lex::deal_token()
{
	deal_unnormal_token();
	switch(wd)
	{
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
