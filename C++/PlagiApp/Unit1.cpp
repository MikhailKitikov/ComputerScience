//---------------------------------------------------------------------------

#include <fstream>
#include <vector>
#include <vcl.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;

int Counter = 0, Count_Programs = 0, Current_Program = 0, Best_Coincidence[4] = {-1,-1,-1,-1};
string Obrazec_Operator = "~:;&|^.,()[]{}!=<>+-*/%"; ///Образцы операторов
string Code[2]; ///Коды программ
double ur_plagiat[4] = {0,0,0,0}; ///Уровень плагиата
vector <string> Operator_types, functions[2], h_str[2], el; ///Образцы типов функций/служебных слов(СС) и пофункциональные записи СС
vector <vector<string> > Fword_types, function_types, Variable_types, Variables;
double coincidence, total_coincidence[4]; ///Совпадение по методу токенизации
vector <int> hash_str;
int st_70[5] = {1, 70, 4900, 343000, 24010000};

String Directory;
string forms[9];
vector <string> sendings;
String FileName;

string Invert (string s)
{
    for(int i = 0; i < s.size(); i++)
        s[i]-=32;
    return s;
}

inline string Convert(int a)
{
    string s;
    while(a > 0)
    {
        s = char(a%10+48) + s;
        a/=10;
	}
    return s;
}

void Creation()
{
	forms[0] = "ИМ"; forms[1] = "М"; forms[2] = "Ф";
	forms[3] = "ФМ"; forms[4] = "БИО"; forms[5] = "ИСТ";
	forms[6] = "ФИЛ"; forms[7] = "ХБ"; forms[8] = "ХИМ";
	Form1->Series1->Clear();
	Form1->Series2->Clear();
	for(int i = 0; i < Form1->StringGrid1->ColCount; i++)
		Form1->StringGrid1->Cols[i]->Clear();
	sendings.clear();
	Count_Programs = 0;
	string temp;
	FileName = Directory + "\\Sendings.txt";
	ifstream fin(FileName.c_str());
	while(!fin.eof())
	{
		Count_Programs++;
		getline(fin, temp);
		sendings.push_back(temp.substr(0, temp.find(' ')));
	}
	Form1->StringGrid1->RowCount = Count_Programs+1;
	Form1->StringGrid1->Cells[0][0]="№";
	Form1->StringGrid1->Cells[1][0]="id";
	Form1->StringGrid1->Cells[2][0]="Класс";
	Form1->StringGrid1->Cells[3][0]="Фамилия";
	Form1->StringGrid1->Cells[4][0]="Дата";
	Form1->StringGrid1->Cells[5][0]="	%";
	Form1->StringGrid1->Cells[6][0]="id копии";
}

void Initialization()
{
	///Создание массивов образцов служебных слов
	ifstream fintp("Types.txt");
    function_types.clear();
	function_types.resize(5);
	Variable_types.clear();
	Variable_types.resize(9);
    Variables.clear();
    Variables.resize(9);
    Fword_types.clear();
    Fword_types.resize(15);
    Operator_types.clear();
    Operator_types.resize(26);
    string temp_string;
    int function_types_size[5] = {24, 3, 1, 1, 1}, variable_types_size[9] = {12, 6, 2, 3, 1, 1, 1, 2, 1};
    fintp >> temp_string;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < function_types_size[i]; j++)
        {
            fintp >> temp_string;
			function_types[i].push_back(temp_string);
        }
    fintp >> temp_string;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < variable_types_size[i]; j++)
        {
            fintp >> temp_string;
            Variable_types[i].push_back(temp_string);
        }
    fintp >> temp_string;
    for(int i = 0; i < 15; i++)
    {
        fintp >> temp_string;
        Fword_types[i].push_back(temp_string);
    }
    fintp >> temp_string;
    for(int i = 0; i < 26; i++)
		fintp >> Operator_types[i];
	Code[0] = "";
    functions[0].clear();
	h_str[0].clear();
}

inline void Proverka (int in) ///Проверка по методу токенизации
{
	if (in <= 1)
    {
		if ((total_coincidence[in]*100)/functions[0].size() > ur_plagiat[in])
		{
			ur_plagiat[in] = (total_coincidence[in]*100)/functions[0].size();
			Best_Coincidence[in] = Current_Program;
        }
    }
    else
        if ((total_coincidence[in]*100)/h_str[0].size() > ur_plagiat[in])
        {
            ur_plagiat[in] = (total_coincidence[in]*100)/h_str[0].size();
            Best_Coincidence[in] = Current_Program;
        }
}

inline double Compare (string smax, string smin, int var)
{
    int i, j, p, n, kod = smax.size();
    coincidence = 0;
    double kol, Max_kol;
    if(smax.size() < smin.size())
        swap(smax,smin);
    smax+=smax;
    n = smin.size();
	if(var == 0)
		for(i = 0; i < (smax.size())/2; i++)
        {
            kol = 0;
            for(j = 0; j < n; j++)
                if(smin[j] == smax[j+i])
                    kol++;
            if (kol/kod > coincidence)
                coincidence = kol/kod;
        }
    else
        for(i = 0; i < (smax.size())/2; i++)
        {
            kol = 0;
            p = 0;
            Max_kol = 0;
            for(j = 0; j < n; j++)
                if(smin[j] == smax[j+i])
                {
                    kol++;
                    p = 1;
                }
                else if(p == 1)
                {
                    p = 0;
                    if(kol > Max_kol)
                        Max_kol = kol;
                    kol = 0;
                }
			if(p == 1)
                if(kol > Max_kol)
					Max_kol = kol;
			if (Max_kol/kod > coincidence)
                coincidence = Max_kol/kod;
		}
	return coincidence;
}

inline void Rabota_Functions (int var) ///Сравнение программ
{
    int i, j;
	double coin, Max;
    coincidence = 0;
    total_coincidence[var] = 0;
    for (i = 0; i < functions[0].size(); i++)
    {
		Max = 0;
        for (j = 0; j < functions[1].size(); j++)
        {
			if (functions[0][i][0] == functions[1][j][0])
            {
				if (var <= 1)
                    coin = Compare(functions[0][i],functions[1][j],var);
                else
                    coin = Compare(h_str[0][i],h_str[1][j],var);
                if(coin > Max)
                    Max = coin;
            }
        }
        total_coincidence[var] += Max;
    }
	Proverka(var);
}

inline int Baza_Hash (char c)
{
	if ((c>64)&&(c<91))
		return c-64;
	else if((c>96)&&(c<123))
		return c-96+24;
	else
		return Obrazec_Operator.find(c)+51;
}

inline string Winnowing ()
{
    int w = 2, sign, last;
    string marks;
    for(int i = w - 1; i < hash_str.size(); i++)
    {
        if(hash_str[i] <= hash_str[i-1])
			sign = i;
        else
            sign = i-1;
        if(sign != last)
            marks += el[sign];
        last = sign;
	}
    return marks;
}

inline void Hash (string str)
{
    int i, j, x, n = str.size()-2, rezultat;
	hash_str.clear();
    el.clear();
	for (i = 0; i < n; i++)
    {
		el.push_back(str.substr(i, 3));
        rezultat = 0;
        for (j = 0; j < 3; j++)
		{
            x = Baza_Hash(el[i][j]);
            rezultat += x*st_70[j];
        }
        hash_str.push_back(rezultat);
	}
    h_str[0].push_back(Winnowing());
}

inline void Hashing ()
{
	for (int i = 0; i < functions[0].size(); i++)
        Hash(functions[0][i]);
}

inline bool Check(string st)
{
    if(st.find(')') == string::npos)
        return true;
    if(st.find(';') == string::npos)
        return false;
    if(st.find(';') < st.find(')'))
        return true;
	else
        return false;
}

inline void Find_operators (string str, int kod) ///Запись последовательностей операторов программ
{
    string posl;
    for(int i = 0; i < str.size(); i++)
        posl += ' ';
	int position;
	/// Search for variable initialization
    for(int i = 0; i < Variable_types.size(); i++)
		for(int j = 0; j < Variable_types[i].size(); j++)
		{
			while(str.find(Variable_types[i][j])!=string::npos)
			{    //ShowMessage("ok");
                position = str.find(Variable_types[i][j]); /// Позиция типа инициализируемой переменной
                string temp_variable;
                bool ok = false;
                if(!(str[position-1]>='a' && str[position-1]<='z') && !(str[position-1]>='A' && str[position-1]<='Z'))
                {
                    int pos = position + Variable_types[i][j].size();
                    int pos1 = position;
                    bool Closed = false;
                    bool row_began = false;
                    while(pos < str.size() && !Closed)
                    {
                        if(Obrazec_Operator.find(str[pos]) != string::npos) ///Если стоит оператор
                        {
                            if(str[pos] == '(') ///Если это функция или изменение типа
                            {
                                ok = false;
                                Closed = true;
                            }
                            else
                            {
                                if(str[pos] == ',')
                                {
                                    if(ok) ///Если это ряд переменных или параметров
                                    {
                                        bool Found = false;
                                        for(int ii = 0; ii < Variables.size() && Found == false; ii++)
                                            if(count(Variables[ii].begin(), Variables[ii].end(), temp_variable))
                                            {
                                                Found = 1;
                                                break;
                                            }
                                        char tmp = 'A' + i;
                                        posl[pos1] = tmp;
                                        if(Found == false)
                                            Variables[i].push_back(temp_variable);
                                        if(row_began)
                                        {
                                            str.erase(pos1, temp_variable.size());
                                            for(int ii = 0; ii < temp_variable.size(); ii++)
                                                str.insert(pos1, " ");
                                        }
                                        else
                                        {
                                            if(Check(str.substr(pos1, str.size()-pos1)))
                                            {
                                                str.erase(pos1, Variable_types[i][j].size() + temp_variable.size());
                                                for(int ii = 0; ii < Variable_types[i][j].size() + temp_variable.size(); ii++)
                                                    str.insert(pos1, " ");
                                                pos1 +=  Variable_types[i][j].size()-1;
                                                row_began = true;
                                            }
											else
                                            {
                                                Closed = true;
                                                ok = false;
                                            }
                                        }
                                        pos1 += temp_variable.size();
                                        temp_variable = "";
                                    }
                                    else ///Если это pair <type, type>
                                    {
                                        ok = false;
                                        Closed = true;
                                    }
                                }
                                else
                                    Closed = true;
                            }
                        }
                        else
                        {
                            temp_variable += str[pos];
                            ok = true;
                        }
                        pos++;
                    }
                }
                if(ok)
                {
                    bool Found = false;
                    for(int ii = 0; ii < Variables.size() && Found == false; ii++)
                        if(count(Variables[ii].begin(), Variables[ii].end(), temp_variable))
                        {
                            Found = 1;
                            break;
                        }
                    char tmp = 'A' + i;
                    posl[position] = tmp;
                    if(Found == false)
                    {
                        Variables[i].push_back(temp_variable);
                    }
                    str.erase(position, Variable_types[i][j].size() + temp_variable.size());
                    for(int ii = 0; ii < Variable_types[i][j].size() + temp_variable.size(); ii++)
                        str.insert(position, " ");
                }
                else
                {
                    char tmp = 'A' + i;
                    posl[position] = tmp;
                    str.erase(position, Variable_types[i][j].size());
                    for(int ii = 0; ii < Variable_types[i][j].size(); ii++)
                        str.insert(position, " ");
                }
			}
		}
    /// Search for variable entry
    for(int i = 0; i < Variables.size(); i++)
        for(int j = 0; j < Variables[i].size(); j++)
        {
            while(str.find(Variables[i][j])!=string::npos)
            {
                int pos1 = str.find(Variables[i][j]);
                int pos2 = pos1 + Variables[i][j].size();
                if(!(str[pos1-1]>='a' && str[pos1-1]<='z') && !(str[pos2]>='a' && str[pos2]<='z') && str[pos1]!='_' && str[pos2]!='_')
                {
                    char tmp = 'A' + i;
                    posl[pos1] = tmp;
                    str.erase(pos1, Variables[i][j].size());
                    for(int ii = 0; ii < Variables[i][j].size(); ii++)
                        str.insert(pos1, " ");
                }
                else
                {
                    for(int ii = pos1; ii < pos1 + Variables[i][j].size(); ii++)
                        str[ii]-=32;
                }
            }
            string inv_type = Invert(Variables[i][j]);
            while(str.find(inv_type)!=string::npos)
            {
                int inv_pos = str.find(inv_type);
                for(int ii = inv_pos; ii < inv_pos + inv_type.size(); ii++)
                    str[ii]+=32;
            }
        }
    /// Search for other functional words
    for(int i = 0; i < Fword_types.size(); i++)
        for(int j = 0; j < Fword_types[i].size(); j++)
            while(str.find(Fword_types[i][j])!=string::npos)
            {
                int position = str.find(Fword_types[i][j]);
                char tmp = 'J' + i;
                posl[str.find(Fword_types[i][j])] = tmp;
                str.erase(position, Fword_types[i][j].size());
                for(int ii = 0; ii < Fword_types[i][j].size(); ii++)
                    str.insert(position, " ");
            }
    for(int i = 0; i < Operator_types.size(); i++)
    {
        while(str.find(Operator_types[i])!=string::npos)
        {
            char tmp = 'a' + i;
            posl[str.find(Operator_types[i])] = tmp;
            int position = str.find(Operator_types[i]);
            str.erase(position, Operator_types[i].size());
            for(int ii = 0; ii < Operator_types[i].size(); ii++)
                str.insert(position, " ");
        }
    }
    for(int i = 0; i < Obrazec_Operator.size(); i++)
    {
        while(str.find(Obrazec_Operator[i])!=string::npos)
        {
            position = str.find(Obrazec_Operator[i]);
            posl[position] = Obrazec_Operator[i];
            str.erase(position, 1);
            str.insert(position, " ");
        }
    }
    while(posl.find(' ') != string::npos)
        posl.erase(posl.find(' '), 1);
    functions[kod].push_back(posl);
}

inline void Find_function (int kod)    ///Пофункцинальная токенизация программ
{
	string str = Code[kod];
    for(int i = 0; i < function_types.size(); i++)
	{
        for(int j = 0; j < function_types[i].size(); j++)
        {
            while(str.find(function_types[i][j])!=string::npos)
            {
                int Fword_pos = str.find(function_types[i][j]);
                int pos, first = 0;
                for(pos = Fword_pos+1; pos < str.size(); pos++)
                    if(str[pos] == '(' && pos != (Fword_pos+function_types[i][j].size()))   ///Поиск открывающей скобки после типа функции/переменной
                    {
                        first = 1;
                        break;
                    }
                    else if(str[pos] == ';' || str[pos] == ',' || str[pos] == ')' || str[pos] == '=')  ///Поиск точки с запятой после типа функции/переменной
                        break;
                if(first == 1) ///Если это функция
                {
                    int End;
                    int p = 0;
                    for(int ii = pos+1; ii < str.size(); ii++)
                        if(str[ii] == '}')
                        {
                            p--;
                            if(p == 0)
                            {
                                End = ii;
                                break;
                            }
                        }
                        else if(str[ii] == '{')
							p++;
                    string func = str.substr(Fword_pos, End-Fword_pos+1); ///Выделение тела функции
					str.erase(Fword_pos,End-Fword_pos+1);       // ShowMessage(func.c_str());
					Find_operators(func, kod);
                }
                else
                {
                    for(int ii = Fword_pos; ii < Fword_pos + function_types[i][j].size(); ii++)
                        str[ii]-=32;
                }
            }
            string inv_type = Invert(function_types[i][j]);
            while(str.find(inv_type)!=string::npos)
            {
                int inv_pos = str.find(inv_type);
                for(int ii = inv_pos; ii < inv_pos + inv_type.size(); ii++)
                    str[ii]+=32;
            }
        }
    }
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Creation();
	Series1->Add(0,"",clAqua);
	StringGrid1->ColWidths[0] = 40;
	StringGrid1->ColWidths[1] = 90;
	StringGrid1->ColWidths[2] = 140;
	StringGrid1->ColWidths[3] = 240;
	StringGrid1->ColWidths[4] = 190;
	StringGrid1->ColWidths[5] = 100;
	StringGrid1->ColWidths[6] = 90;
	vector <int> plag_value (6, 0);
	DirectoryListBox1->Visible = false;
	FileName = Directory + "\\off.txt";
	ofstream fout (FileName.c_str());
	string Code_dop, temp_string;
	String n1, n2;
	int func_size;
	int i, j, k;
	for(Counter = 0; Counter < Count_Programs; Counter++)
	{
		Initialization();
		n1 = "\\";
		n1 += sendings[Counter].c_str();
		n1 += ".cpp";
		FileName = Directory + n1;
		ifstream fin1 (FileName.c_str());
		/// Ввод кодов программ
		while(!fin1.eof())
		{
			getline(fin1, Code_dop);
			if(Code_dop.find("//")!=string::npos)
			{
				k = Code_dop.find("//");
				Code_dop.erase(k, Code_dop.size()-k);
			}
			while(Code_dop.find('\t')!=string::npos)
			{
				Code_dop.erase(Code_dop.find('\t'),1);
			}
			while(Code_dop.find(' ')!=string::npos)
			{
				Code_dop.erase(Code_dop.find(' '),1);
			}
			while(Code_dop.find('"')!=string::npos)
			{
				k = Code_dop.find('"');
				Code_dop.erase(k, 1);
                Code_dop.erase(k, Code_dop.find('"')-k+1);
			}
			while(Code_dop.find("'")!=string::npos)
			{
				k = Code_dop.find("'");
				Code_dop.erase(k, 1);
				Code_dop.erase(k, Code_dop.find("'")-k+1);
			}
			while(Code_dop.find("using namespace std;")!=string::npos)
			{
				int k = Code_dop.find("using namespace std;");
				Code_dop.erase(k, 20);
			}
			string temp_string, definition;
			if(Code_dop.find("#define") != string::npos)
			{
                temp_string = Code_dop;
                temp_string.erase(0, 7);
                bool Closed = 0;
                for(int i = 0; i < Fword_types.size() && Closed == false; i++){
                    for(int j = 0; j < Fword_types[i].size(); j++){
                        if(temp_string.find(Fword_types[i][j]) == string::npos)
                            continue;
                        if(temp_string.find('(') != string::npos && temp_string.find('(') != temp_string.rfind('('))
                            definition = temp_string.substr(0, temp_string.find('('));
                        else
                            definition = temp_string.substr(0, temp_string.find(Fword_types[i][j]));
                        if(!count(Fword_types[i].begin(), Fword_types[i].end(), definition))
                            Fword_types[i].push_back(definition);
                        Code_dop = definition;
                        Closed = true;
                        break;
                    }
                }
			}
			else
	            while(Code_dop.find("typedef") != string::npos)
	            {
	                temp_string = Code_dop.substr(Code_dop.find("typedef"), Code_dop.find(';'));
	                Code_dop.erase(Code_dop.find("typedef"), Code_dop.find(';')+1);
	                temp_string.erase(0, 7);
	                bool Closed = 0, found = 0;
	                int pos;
	                string defined;
	                if(temp_string.find('<') != string::npos)
	                {
	                	if(temp_string.find('<') == temp_string.rfind('<'))
	                    {
	                        int open_bracket_pos = temp_string.find('<');
	                        int close_bracket_pos = temp_string.find('>');
	                        string vector_type = temp_string.substr(open_bracket_pos+1, close_bracket_pos-open_bracket_pos-1);
	                        for(int i = 0; i < function_types.size() && Closed == false; i++){
	                            for(int j = 0; j < function_types[i].size(); j++){
	                                if(function_types[i][j] != vector_type)
                                        continue;
                                    found = true;
                                    definition = temp_string.substr(close_bracket_pos+1, temp_string.size()-close_bracket_pos-1);
                                    pos = i;
                                    defined = function_types[i][j];
                                    Closed = 1;
                                    break;
	                            }
	                        }
	                    }
	                }
                    else
                    {
                        for(int i = 0; i < function_types.size() && Closed == false; i++){
                            for(int j = 0; j < function_types[i].size(); j++){
                                if(temp_string.find(function_types[i][j]) == string::npos)
                                    continue;
                                found = true;
                                int Fword_pos = temp_string.find(function_types[i][j]);
                                definition = temp_string.substr(Fword_pos+function_types[i][j].size(), temp_string.size()-Fword_pos-1);
                                pos = i;
                                defined = function_types[i][j];
                                Closed = 1;
                                break;
                            }
                        }
                    }
                    if(found){
                        Closed = 0;
                        if(!count(function_types[pos].begin(), function_types[pos].end(), definition))
                        {
                            function_types[pos].push_back(definition);
                            for(int i = 0; i < Fword_types.size() && Closed == false; i++){
                                for(int j = 0; j < Fword_types[i].size(); j++){
                                    if(Fword_types[i][j] == defined){
                                        Fword_types[i].push_back(definition);
                                        Closed = 1;
                                        break;
                                    }
                                }
                            }
                            for(int i = 0; i < Variable_types.size() && Closed == false; i++){
                                for(int j = 0; j < Variable_types[i].size(); j++){
                                    if(Variable_types[i][j] == defined){
                                        Variable_types[i].push_back(definition);
                                        Closed = 1;
                                        break;
                                    }
                                }
                            }
                        }
	                }
				}
			Code[0]+=Code_dop;
		}
		Find_function(0);
		n2 = "\\";
		n2 += sendings[Counter].c_str();
		n2 += ".txt";
		FileName = Directory + n2;
		ofstream fout2 (FileName.c_str());
		fout2 << functions[0].size() << endl;
		for(int i = 0; i < functions[0].size(); i++)
			fout2 << functions[0][i] << endl;
		Hashing();
		for(int i = 0; i < h_str[0].size(); i++)
			fout2 << h_str[0][i] << endl;
	}
	FileName = Directory + "\\Sendings.txt";
	ifstream fin(FileName.c_str());
	for(Counter = 0; Counter < Count_Programs; Counter++)
	{
		Code[0] = "";
		functions[0].clear();
		for (i = 0; i < 4; i++)
		{
			ur_plagiat[i] = 0;
		}
		h_str[0].clear();
		n1 = "\\";
		n1 += sendings[Counter].c_str();
		n1 += ".txt";
		FileName = Directory + n1;
		ifstream fin1 (FileName.c_str());
        fin1 >> func_size;
		for(i = 0; i < func_size; i++)
		{
			fin1 >> temp_string;
			functions[0].push_back(temp_string);
		}
		for(i = 0; i < func_size; i++)
		{
			fin1 >> temp_string;
			h_str[0].push_back(temp_string);
		}
		for(Current_Program = 0; Current_Program < Count_Programs; Current_Program++)
			if(Counter != Current_Program)
			{
				Code[1] = "";
				functions[1].clear();
				h_str[1].clear();
				n2 = "\\";
				n2 += sendings[Current_Program].c_str();
				n2 += ".txt";
				FileName = Directory + n2;
				ifstream fin2 (FileName.c_str());
				fin2 >> func_size;
				for(i = 0; i < func_size; i++)
				{
					fin2 >> temp_string;
					functions[1].push_back(temp_string);
				}
				for(i = 0; i < func_size; i++)
				{
					fin2 >> temp_string;
					h_str[1].push_back(temp_string);
				}
				///Сравнение программ
				for (i = 0; i < 4; i++)
					Rabota_Functions(i);
			}
		int Resultat = (int((ur_plagiat[0] * SpinEdit1->Value + ur_plagiat[1] * SpinEdit2->Value + ur_plagiat[2] * SpinEdit3->Value + ur_plagiat[3] * SpinEdit4->Value) / (SpinEdit1->Value + SpinEdit2->Value + SpinEdit3->Value + SpinEdit4->Value)));
		// reading sending's information
		int form, form_type, form_n, id;
		string name, surname, date;
		fin >> id >> form >> form_type >> form_n >> surname >> name;
		getline(fin, date);
		StringGrid1->Cells[0][Counter+1] = IntToStr(Counter+1);
		StringGrid1->Cells[1][Counter+1] = id;
		StringGrid1->Cells[2][Counter+1] = IntToStr(form) + ' ' + forms[form_type].c_str() + ' ' + IntToStr(form_n);
		StringGrid1->Cells[3][Counter+1] = (surname + ' ' + name).c_str();
		StringGrid1->Cells[4][Counter+1] = date.c_str();
		StringGrid1->Cells[5][Counter+1] = IntToStr(Resultat);
		StringGrid1->Cells[6][Counter+1] = sendings[Best_Coincidence[0]].c_str();
		fout << Counter+1 << ' ' << id << ' ' << form << ' ' << form_type << ' ' << form_n << ' ' << surname << ' ' << name << ' ' << ' ' << Resultat << ' ' << sendings[Best_Coincidence[0]] << endl;
		//
		Series1->Add(double(Resultat),"",clAqua);
		plag_value[Resultat / 20]++;
	}
	int DiagramColors[18] = {0,255,255, 102,255,0, 255,255,0, 255,153,0, 255,0,0, 102,0,0};
	string DiagramNames[6] = {"Слабый", "Умеренный", "Средний", "Выше среднего", "Сильный", "Полный плагиат"};
	for(i = 0; i <= 5; i++)
	{
		if(plag_value[i])
		{
		   Series2->Add(plag_value[i]*100., DiagramNames[i].c_str(), RGB(DiagramColors[i*3], DiagramColors[i*3+1], DiagramColors[i*3+2]));
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
	DirectoryListBox1->Visible = true;
	DirectoryListBox1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (MessageDlg("Выйти?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrNo)
	{
		CanClose = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
	if (CheckBox1->Checked)
	{
		SpinEdit1->Enabled = true;
	}
	else
	{
		SpinEdit1->Enabled = false;
		SpinEdit1->Value = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
	if (CheckBox2->Checked)
	{
		SpinEdit2->Enabled = true;
	}
	else
	{
		SpinEdit2->Enabled = false;
		SpinEdit2->Value = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox3Click(TObject *Sender)
{
	if (CheckBox3->Checked)
	{
		SpinEdit3->Enabled = true;
	}
	else
	{
		SpinEdit3->Enabled = false;
		SpinEdit3->Value = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox4Click(TObject *Sender)
{
	if (CheckBox4->Checked)
	{
		SpinEdit4->Enabled = true;
	}
	else
	{
		SpinEdit4->Enabled = false;
		SpinEdit4->Value = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
	Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
	Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DirectoryListBox1Click(TObject *Sender)
{
	Directory = DirectoryListBox1->Directory;
	Button1->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
	DirectoryListBox1->Width = 890;
}
//---------------------------------------------------------------------------

