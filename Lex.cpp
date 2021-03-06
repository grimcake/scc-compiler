#include "Lex.h"
#include "myenum.h"
#include <iostream>
using namespace std;


Lex::Lex()
{
	init_lex();
	start_lex("./test.c");

    //show_tktable();
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
    {TK_REG, NULL, "reg"},
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
	/*while(wd != EOF)
	{
        tmp_wd.clear();
        deal_token();
	}*/

}

void Lex::deal_token()
{
    tmp_wd.clear();
    getword();
    int is_unormal = deal_unnormal_token();
	
    tmp_wd.clear();
    if((wd >= 'a' && wd <='z') || (wd >= 'A' && wd <= 'Z'))
    {
        tmp_wd += wd;
        deal_parse();

        TkWord *tmp_find = NULL;
        int tmp_hash = get_hash(tmp_wd); 
        tmp_find = tkword_find(tmp_wd, tmp_hash);


        if(tmp_find == NULL)
        {
            tmp_find = (TkWord *)malloc(sizeof(TkWord));
            tmp_find->tkcode = TK_REG;
            tmp_find->next = NULL;
            tmp_find->spelling = tmp_wd;
            tkword_direct_insert(tmp_find);
            tkcolor = TK_REG;
        }
        else
        {
            if(tmp_find->tkcode == TK_REG)
            {
                tkcolor = TK_REG;
            }
            else tkcolor = tmp_find->tkcode;
        }
    }

    else if(wd>='0' && wd<='9')
    {
        tkcolor = TK_CINT;
        tmp_wd += wd;
        deal_number();

    }

    else if(wd == '+')
    {
        tkcolor = TK_PLUS;
        tmp_wd += '+';
    }
    else if(wd == '=')
    {
        tkcolor = TK_ASSIGN;
        tmp_wd += '=';
    }
    else if(wd == '(')
    {
        tkcolor = TK_LS;
        tmp_wd += '(';
    }
    else if(wd == ')')
    {
        tkcolor = TK_RS;
        tmp_wd += ')';
    }
    else if(wd == ';')
    {
        tkcolor = TK_SEMICOLON;
        tmp_wd += ';';
    }
    else if(wd == '{')
    {
        tkcolor = TK_LL;
        tmp_wd += '{';
    }
    else if(wd == '}')
    {
        tkcolor = TK_RL;
        tmp_wd += '}';
    }
    lastword = tmp_wd;
    show_token();
    tmp_wd.clear();
}
int Lex::deal_unnormal_token()
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
		}
        show_token();
        return 1;
	}
    else if(wd == '\n' || wd == '\t')
    {
        //show_token();
        return 1;
    }
	else if(wd == ' ')
	{
        if(lastword != ";") tmp_wd += wd;
		deal_space();
        show_token();
        return 1;
	}
    return 0;
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
            //tmp_wd += wd;
			continue;
		}
		else
		{
			break;
		}
	}
}

void Lex::deal_parse()
{
    for(;;)
    {
        getword();
        if((wd >= 'a' && wd <= 'z') || (wd >= 'A' && wd <= 'Z') || (wd == '_'))
        {
            tmp_wd += wd;
            continue;
        }
        else 
        {
            ungetc(wd, fd);
            break;
        }
    }
}

void Lex::deal_number()
{
    for(;;)
    {
        getword();
        if(wd >= '0' && wd <= '9')
        {
            tmp_wd += wd;
            continue;
        }
        else
        {
            ungetc(wd, fd);
            break;
        }
    }
}

void Lex::show_token()
{
    if(tkcolor <= TK_COMMA) 
    {
        printf("\033[33m");
    }
    else if(tkcolor == TK_REG)
    {
        printf("\033[36m");
    }
    else if(tkcolor <= KW_KEYWORD && tkcolor >= KW_CHAR)
    {
        printf("\033[31m");
    }
    printf("%s", tmp_wd.c_str());
}
string Lex::string_from_tkcolor(int tk_color, int &color)
{
    if(tk_color == TK_PLUS)
    {   
        color = 1;
        return "+";
    }
}

void Lex::show_tktable()
{
    vector<TkWord * >::iterator it;
    for(it = tktable.data.begin(); it != tktable.data.end(); it++)
    {
        cout<<(*it)->spelling<<"  "<<(*it)->tkcode<<endl;
    }
}
