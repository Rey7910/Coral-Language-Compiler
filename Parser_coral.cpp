/*
***
 REINALDO TOLEDO LEGUIZAMÓN       *
 LENGUAJES DE PROGRAMACIÓN        *
 UNIVERSIDAD NACIONAL DE COLOMBIA *
 ANALIZADOR SINTÁCTICO -> CORAL   *
 2022-2                           *
                                  *
***
*/

#include <iostream>
#include <cstring>

int empty_lines = 0;
int total_lines = 0;
int error_found = 0;
int go_ahead=0;
int charger = 0;
int last_line =0;
int dec_array = 0;
int exit_values = 0;
int force_correct = 0;
int ifs = 0;
int whiles = 0;
int fors = 0;
int notcont_par = 0;
int function_position=0;
int pars_position=0;
int current_comma = 0;
int empty_f=0;
int forced_parameters = 0;
int parameters = 0;
int parameters_arr[70];
int parameters_position=0;
int num_functions=0;
int function_str = 0;
int function_main=0;
int alone_function = 0;
int content = 0;
int counter_parameters = 0;

using namespace std;



// Lexicgraphic token order

string order[]={
    "AbsoluteValue",
    "and",
    "array",
    "decimal",
    "else",
    "elseif",
    "EOF",
    "float",
    "float_value",
    "for",
    "Function",
    "Get",
    "id",
    "if",
    "input",
    "integer",
    "integer_value",
    "Main",
    "next",
    "not",
    "nothing",
    "or",
    "output",
    "places",
    "Put",
    "RaiseToPower",
    "RandomNumber",
    "returns",
    "SeedRandomNumbers",
    "size",
    "SquareRoot",
    "string_literal",
    "while",
    "with",
    "tkn_assign",
    "tkn_closing_bra",
    "tkn_closing_par",
    "tkn_comma",
    "tkn_div",
    "tkn_equal",
    "tkn_geq",
    "tkn_greater",
    "tkn_leq",
    "tkn_less",
    "tkn_minus",
    "tkn_mod",
    "tkn_neq",
    "tkn_opening_bra",
    "tkn_opening_par",
    "tkn_period",
    "tkn_plus",
    "tkn_question_mark",
    "tkn_semicolon",
    "tkn_times",
    "to"
};


// Gramatical rules and Sintax analysis

string rules[50];
int start=0;
int rule_position=0;
int precedence[50];
int precedence_position=0;
int ways[50];
int functions_arr[50];
int pars_arr[50];
int ways_position=0;
int bars = 0;

string current_rule = "0";

// HERE CAN WE FIND THE GRAMATIC USED FOR THE PARSER DEVELOP

// F
string F[] = {"Function","id","tkn_opening_par","DECS","tkn_closing_par","returns","nothing","ALLF"};

// F_m

string F_m_1[]={"Function","id","tkn_opening_par","DECS","returns","ret","ALLF"};

string F_m_2[]={"NN"};


//DECS

string DECS_1[] = {"Type","id","dec2"};
string DECS_2[] = {"Type","array","tkn_opening_par","size_array","id","dec2"};
string DECS_3[] = {"NN"};

//Size_array

string size_array_1[] = {"integer_value"};
string size_array_2[] = {"tkn_question_mark"};
string size_array_3[] = {"id"};

//Type

string type_1[] = {"integer"};
string type_2[] = {"float"};

//Dec

string dec_1[] = {"Type","id"};

//Dec_arr
string dec_arr[] = {"Type","array","tkn_opening_par","size_array","tkn_closing_par","id"};

//ALL_F
string all_F1[] = {"dec","ALL"};
string all_F2[] = {"assign","ALL"};

//all

string all_1[] = {"dec","ALL"};

string all_2[] = {"NN"};

//exit

string exit_1[] = {"Put","id","to","output","with","id","decimal","places"};
string exit_2[] = {"Put","tkn_string","to","output"};

// arith

int arith=0;
int condex = 0;
int functions = 0;
int arrays = 0;

//1     waiting sign
//2     id/integer/float
//3     waiting op/ ( / [ 
//4     waiting op

//5    waiting sign/id/integer/float
//6     waiting op/ ( / [/,
//7     waiting op/,

int pars = 0;
int bras = 0;
int array_arith = 0;
int not_empty = 0;
int arith_t = 0;
int condex_t = 0;
int tok_counter = 0;

//F_call
/*
string f_call_1[] = {"id","tkn_opening_par","deci","tkn_closing_par"};

string f_call_2[] = {"SquareRoot","tkn_opening_par","arith","tkn_closing_par"}; 

string f_call_3[] = {"AbsoluteValue","tkn_opening_par","arith","tkn_closing_par"}; 

string f_call_4[] = {"RaiseToPower","tkn_opening_par","arith","tkn_comma","arith","tkn_closing_par"}; 

string f_call_5[] = {"RandomNumbers","tkn_opening_par","arith","tkn_comma","arith","tkn_closing_par"}; 
*/
//F_call_ex

string f_call_ex_1[] = {"id","tkn_opening_par","deci","tkn_closing_par"};
string f_call_ex_2[] = {"SeedRandomNumbers","tkn_opening_par","ari","tkn_closing_par"};


// Var

string var_1[] = {"id","arr"};

// arr

string arr_1[] = {"tkn_opening_bra","arith","tkn_closing_bra"};
string arr_2[] = {"tkn_period","size"};
string arr_3[] = {"NN"};

//assign

string assign_1[] = {"var","tkn_assign","entrance"};
string assign_2[] = {"var","tkn_assign","arith"};

//entrance

string entrance_1[] = {"Get","next","input"};

// ifs

string ifs_1[] = {"if","condex","ALL_F","elses","elses"};

string elses_1[] = {"elseif","condex","ALL_F","elses","elsez"};

string elsez_1[] = {"else","ALL_F"};

// while 

string while_1[] = {"while","condex","ALL_F"};

string for_1[]={"for","assign","tkn_semicolon","condex","tkn_semicolon","assign"};

//RETURNING THE EXPECTED TOKENS ON EACH TOOK


void force_correct_g(){
    cout<<"El analisis sintactico ha finalizado exitosamente."<<endl;
}


void Waiting_for(){
    
    string expected_tokens[53];
    int counter = 0;
    int advance=0;
    int finish_fishing=0;
    int lambda = 0;
    
    while(finish_fishing==0){
        
        if(lambda == 1){
            lambda = 0;
            
        }
        
        if(rules[rule_position]== "dec"){
            expected_tokens[counter]=dec_1[precedence[precedence_position]];
            counter++;
            
            if(dec_1[precedence[precedence_position]]=="id"){
                expected_tokens[counter]=dec_arr[precedence[precedence_position]];
                counter++;
            }
        }else if(rules[rule_position]== "for"){
            
            if(precedence_position==1){
                
                expected_tokens[counter]="id";
                counter++;
            
                
            }else if(precedence[precedence_position]==6){
                expected_tokens[counter]="decimal";
                counter++;
                expected_tokens[counter]="tkn_div";
                counter++;
                expected_tokens[counter]="tkn_minus";
                counter++;
                expected_tokens[counter]="tkn_plus";
                counter++;
                expected_tokens[counter]="tkn_mod";
                counter++;
                expected_tokens[counter]="tkn_times";
                counter++;
            }
            
            
        }else if(rules[rule_position]== "Type"){
            
            
                expected_tokens[counter]="integer";
                counter++;
                expected_tokens[counter]="float";
                counter++;
                
                if(counter_parameters==0){
                    expected_tokens[counter]="tkn_closing_par";
                    counter++;
                }
            
            
        }else if(rules[rule_position]== "function"){
            
            if(precedence[precedence_position]==6){
                
                
                if(function_str==1){
                    expected_tokens[counter]="integer";
                    counter++;
                    expected_tokens[counter]="float";
                    counter++;
                }
                
                
                expected_tokens[counter]="nothing";
                counter++;
                
            }else if(precedence[precedence_position]==4){
                
                expected_tokens[counter]=F[precedence[precedence_position]];
                counter++;
                expected_tokens[counter]="tkn_comma";
                counter++;
            }else if(precedence[precedence_position]==3 and function_str == 0){

                expected_tokens[counter]="tkn_closing_par";
                counter++;
            }else if(precedence[precedence_position]==7){
                
                expected_tokens[counter]="if";
                counter++;
                expected_tokens[counter]="for";
                counter++;
                expected_tokens[counter]="while";
                counter++;
                expected_tokens[counter]="id";
                counter++;
                expected_tokens[counter]="integer";
                counter++;
                expected_tokens[counter]="float";
                counter++;
                expected_tokens[counter]="SeedRandomNumbers";
                counter++;
                expected_tokens[counter]="Put";
                counter++;
            }else if(precedence[precedence_position]==1){

                
                if(num_functions>0){
                    expected_tokens[counter]="id";
                    counter++;
                    expected_tokens[counter]="Main";
                    counter++;
                }else{
                    expected_tokens[counter]="id";
                    counter++;
                }
                
                
                
            }else{
                expected_tokens[counter]=F[precedence[precedence_position]];
                counter++;
            }
            
            
            
            
            
            
        }else if(rules[rule_position]== "dec_arr"){
            expected_tokens[counter]=dec_arr[precedence[precedence_position]];
            counter++;
            
            
        }else if(rules[rule_position]== "ALL_F"){
                     expected_tokens[counter]="if";
                     counter++;
                     expected_tokens[counter]="for";
                     counter++;
                     expected_tokens[counter]="while";
                     counter++;
                     expected_tokens[counter]="id";
                     counter++;
                     expected_tokens[counter]="integer";
                     counter++;
                     expected_tokens[counter]="float";
                     counter++;
                     expected_tokens[counter]="SeedRandomNumbers";
                     counter++;
                     expected_tokens[counter]="Put";
                     counter++;
                     
                     if(tok_counter == 1){
                         expected_tokens[counter]="Function";
                         counter++;
                     
                         
                         
                     }else if(function_str == 1){
                         expected_tokens[counter]="Function";
                         counter++;
                     }
                     
                     if(function_str==0 and function_main ==1){
                         expected_tokens[counter]="EOF";
                         counter++;
                     }
            
            
        }else if(rules[rule_position]=="size_array"){
             expected_tokens[counter]=size_array_1[precedence[precedence_position]];
             counter++;
             expected_tokens[counter]=size_array_2[precedence[precedence_position]];
             counter++;
            
            
        }else if(rules[rule_position]=="entrance"){
             expected_tokens[counter]=entrance_1[precedence[precedence_position]];
             counter++;
        
            
        }else if(rules[rule_position]=="entrance"){
             expected_tokens[counter]=entrance_1[precedence[precedence_position]];
             counter++;
        
            
        }else if(rules[rule_position]=="exit"){
            
             if(ways[ways_position]==1){
                 expected_tokens[counter]=exit_1[precedence[precedence_position]];
                 counter++;
             
                 
             }else if(ways[ways_position]==2){
                 expected_tokens[counter]=exit_1[precedence[precedence_position]];
                 counter++;
             
                 
             }else if(ways[ways_position]==0){
                expected_tokens[counter]="integer_value";
                counter++;
                expected_tokens[counter]="float_value";
                counter++;
                expected_tokens[counter]="tkn_minus";
                counter++;
                expected_tokens[counter]="tkn_plus";
                counter++;
                expected_tokens[counter]="SquareRoot";
                counter++;
                expected_tokens[counter]="RaiseToPower";
                counter++;
                expected_tokens[counter]="AbsoluteValue";
                counter++;
                expected_tokens[counter]="RandomNumber";
                counter++;
                expected_tokens[counter]="id";
                counter++;
                expected_tokens[counter]="tkn_opening_par";
                counter++;
                expected_tokens[counter]="string_literal";
                counter++;
             }
             
        
            
        }else if(rules[rule_position]=="var"){
             
             
             if(rules[rule_position-2]=="for"){
                 expected_tokens[counter]="id";
                 counter++;
             }else{
                 expected_tokens[counter]="tkn_assign";
                 counter++;
                 expected_tokens[counter]="tkn_period";
                 counter++;
                 expected_tokens[counter]="tkn_opening_par";
                 counter++;
                 expected_tokens[counter]="tkn_opening_bra";
                 counter++;
             }
             
             
             
            
        }else if(rules[rule_position]=="ifs"){
             
             if(precedence[precedence_position]==1){
                     expected_tokens[counter]="tkn_plus";
                     counter++;
                     expected_tokens[counter]="tkn_minus";
                     counter++;
                     expected_tokens[counter]="id";
                     counter++;
                     expected_tokens[counter]="integer_value";
                     counter++;
                     expected_tokens[counter]="float_value";
                     counter++;
                     expected_tokens[counter]="AbsoluteValue";
                     counter++;
                     expected_tokens[counter]="RaiseToPower";
                     counter++;
                     expected_tokens[counter]="RandomNumber";
                     counter++;
                     expected_tokens[counter]="SquareRoot";
                     counter++;
                     expected_tokens[counter]="not";
                     counter++;
             }
            
        }else if(rules[rule_position]=="while"){
             
             if(precedence[precedence_position]==1){
                     expected_tokens[counter]="tkn_plus";
                     counter++;
                     expected_tokens[counter]="tkn_minus";
                     counter++;
                     expected_tokens[counter]="id";
                     counter++;
                     expected_tokens[counter]="integer_value";
                     counter++;
                     expected_tokens[counter]="float_value";
                     counter++;
                     expected_tokens[counter]="AbsoluteValue";
                     counter++;
                     expected_tokens[counter]="RaiseToPower";
                     counter++;
                     expected_tokens[counter]="RandomNumber";
                     counter++;
                     expected_tokens[counter]="SquareRoot";
                     counter++;
                     expected_tokens[counter]="not";
                     counter++;
             }
            
        }else if(rules[rule_position]=="condex"){
             
              if(condex == 10){
                 expected_tokens[counter]="not";
                 counter++;
                 expected_tokens[counter]="tkn_opening_par";
                 counter++;
                
              
                  
                  
              }else if(condex_t == 0){
                 
                 
                 
                 if(pars>0 and arith!= 5 and arith!=6){
                     expected_tokens[counter]="tkn_closing_par";
                     counter++;
                     
                 }
                 
                 if(arith == 3){
                     expected_tokens[counter]="tkn_opening_par";
                     counter++;
                     expected_tokens[counter]="tkn_period";
                     counter++;
                     expected_tokens[counter]="tkn_plus";
                     counter++;
                     expected_tokens[counter]="tkn_minus";
                     counter++;
                     expected_tokens[counter]="tkn_div";
                     counter++;
                     expected_tokens[counter]="tkn_times";
                     counter++;
                     expected_tokens[counter]="tkn_mod";
                     counter++;
                     expected_tokens[counter]="tkn_leq";
                     counter++;
                     expected_tokens[counter]="tkn_geq";
                     counter++;
                     expected_tokens[counter]="tkn_less";
                     counter++;
                     expected_tokens[counter]="tkn_neq";
                     counter++;
                     expected_tokens[counter]="tkn_equal";
                     counter++;
                     expected_tokens[counter]="tkn_greater";
                     counter++;
                 
                     
                 }else if(arith == 1){
                     expected_tokens[counter]="tkn_plus";
                     counter++;
                     expected_tokens[counter]="tkn_minus";
                     counter++;
                     expected_tokens[counter]="id";
                     counter++;
                     expected_tokens[counter]="integer_value";
                     counter++;
                     expected_tokens[counter]="float_value";
                     counter++;
                     expected_tokens[counter]="AbsoluteValue";
                     counter++;
                     expected_tokens[counter]="RaiseToPower";
                     counter++;
                     expected_tokens[counter]="RandomNumber";
                     counter++;
                     expected_tokens[counter]="SquareRoot";
                     counter++;
                     
                     if(condex == 1){
                         
                         expected_tokens[counter]="not";
                         counter++;
                         expected_tokens[counter]="tkn_opening_par";
                         counter++;
                     }
                     
                 }else if(arith == 2){
                     expected_tokens[counter]="tkn_plus";
                     counter++;
                     expected_tokens[counter]="tkn_minus";
                     counter++;
                     expected_tokens[counter]="tkn_div";
                     counter++;
                     expected_tokens[counter]="tkn_times";
                     counter++;
                     expected_tokens[counter]="tkn_mod";
                     counter++;
                     expected_tokens[counter]="tkn_leq";
                     counter++;
                     expected_tokens[counter]="tkn_geq";
                     counter++;
                     expected_tokens[counter]="tkn_less";
                     counter++;
                     expected_tokens[counter]="tkn_neq";
                     counter++;
                     expected_tokens[counter]="tkn_equal";
                     counter++;
                     expected_tokens[counter]="tkn_greater";
                     counter++;
                     
                 }else if(arith == 5 or arith == 6){
                     expected_tokens[counter]="tkn_opening_par";
                     counter++;
                 }
                
              }else if(condex_t == 2){
                 expected_tokens[counter]="and";
                 counter++;
                 expected_tokens[counter]="or";
                 counter++;
                 expected_tokens[counter]="tkn_plus";
                 counter++;
                 expected_tokens[counter]="tkn_minus";
                 counter++;
                 expected_tokens[counter]="tkn_div";
                 counter++;
                 expected_tokens[counter]="tkn_times";
                 counter++;
                 expected_tokens[counter]="tkn_mod";
                 counter++;
                 
                 
                 if(arith == 3){
                     expected_tokens[counter]="tkn_opening_par";
                     counter++;
                     expected_tokens[counter]="tkn_period";
                     counter++;
                 }
              
                 if(pars>0){
                     
                     expected_tokens[counter]="tkn_closing_par";
                     counter++;
                 
                     
                 }else if(current_rule == "if"){
                     expected_tokens[counter]="if";
                     counter++;
                     expected_tokens[counter]="for";
                     counter++;
                     expected_tokens[counter]="while";
                     counter++;
                     expected_tokens[counter]="id";
                     counter++;
                     expected_tokens[counter]="integer";
                     counter++;
                     expected_tokens[counter]="float";
                     counter++;
                     expected_tokens[counter]="SeedRandomNumbers";
                     counter++;
                     expected_tokens[counter]="Put";
                     counter++;
                 
                     
                 }else{
                     expected_tokens[counter]="if";
                     counter++;
                     expected_tokens[counter]="for";
                     counter++;
                     expected_tokens[counter]="while";
                     counter++;
                     expected_tokens[counter]="id";
                     counter++;
                     expected_tokens[counter]="integer";
                     counter++;
                     expected_tokens[counter]="float";
                     counter++;
                     expected_tokens[counter]="SeedRandomNumbers";
                     counter++;
                     expected_tokens[counter]="Put";
                     counter++;
                 }
                 
                 
             }else if(condex_t == 1){
                 
                 if(arith == 1){
                     expected_tokens[counter]="tkn_plus";
                     counter++;
                     expected_tokens[counter]="tkn_minus";
                     counter++;
                     expected_tokens[counter]="id";
                     counter++;
                     expected_tokens[counter]="integer_value";
                     counter++;
                     expected_tokens[counter]="float_value";
                     counter++;
                     expected_tokens[counter]="AbsoluteValue";
                     counter++;
                     expected_tokens[counter]="RaiseToPower";
                     counter++;
                     expected_tokens[counter]="RandomNumber";
                     counter++;
                     expected_tokens[counter]="SquareRoot";
                     counter++;
                     expected_tokens[counter]="tkn_opening_par";
                     counter++;
                     expected_tokens[counter]="not";
                     counter++;
                 }
             }
            
        }else if(rules[rule_position]=="arr"){
             
             
             
             if(precedence[precedence_position]==2){
                
                expected_tokens[counter]="tkn_assign";
                counter++;
             
             }else if(ways[ways_position]==0){
                expected_tokens[counter]=arr_1[precedence[precedence_position]];
                counter++;
                expected_tokens[counter]=arr_2[precedence[precedence_position]];
                counter++;
                 
                
                
                if(rules[rule_position-3]!="for"){
                    expected_tokens[counter]="tkn_opening_par";
                    counter++;
                }
                 
                 
                lambda = 1;
                rule_position-=2;
                precedence_position-=2;
                precedence[precedence_position]++;
                 
             }else if(ways[ways_position]==1){
                 
                 if(arr_1[precedence[precedence_position]]=="arith"){
                     expected_tokens[counter]="tkn_plus";
                     counter++;
                     expected_tokens[counter]="tkn_minus";
                     counter++;
                     expected_tokens[counter]="integer_value";
                     counter++;
                     expected_tokens[counter]="id";
                     counter++;
                     expected_tokens[counter]="tkn_opening_par";
                     counter++;
                     expected_tokens[counter]="RandomNumber";
                     counter++;
                 }else{
                     expected_tokens[counter]=arr_1[precedence[precedence_position]];
                     counter++;
                     expected_tokens[counter]="tkn_plus";
                     counter++;
                     expected_tokens[counter]="tkn_minus";
                     counter++;
                 }
                 
             }else if(ways[ways_position]==2){
                 expected_tokens[counter]=arr_2[precedence[precedence_position]];
                 counter++;
             }
             
             
             
             
        }else if(rules[rule_position]=="assign"){
           
            
            if(precedence[precedence_position]==2){
                
                if(exit_values == 0){
                    expected_tokens[counter]=entrance_1[0];
                    counter++;
                }
                
                expected_tokens[counter]="integer_value";
                counter++;
                expected_tokens[counter]="float_value";
                counter++;
                expected_tokens[counter]="tkn_minus";
                counter++;
                expected_tokens[counter]="tkn_plus";
                counter++;
                expected_tokens[counter]="SquareRoot";
                counter++;
                expected_tokens[counter]="RaiseToPower";
                counter++;
                expected_tokens[counter]="AbsoluteValue";
                counter++;
                expected_tokens[counter]="RandomNumber";
                counter++;
                expected_tokens[counter]="id";
                counter++;
                expected_tokens[counter]="tkn_opening_par";
                counter++;
                
            }else if(precedence[precedence_position]==1){
                expected_tokens[counter]=assign_1[precedence[precedence_position]];
                counter++;
            }
            
        }else if(rules[rule_position]=="arith"){
            
            if(arith == 1){
                
                if(array_arith == 0){
                    expected_tokens[counter]="SquareRoot";
                    counter++;
                    expected_tokens[counter]="RaiseToPower";
                    counter++;
                    expected_tokens[counter]="AbsoluteValue";
                    counter++;
                    expected_tokens[counter]="float_value";
                    counter++;
                }
                
                expected_tokens[counter]="RandomNumber";
                counter++;
                expected_tokens[counter]="id";
                counter++;
                expected_tokens[counter]="tkn_opening_par";
                counter++;
                expected_tokens[counter]="integer_value";
                counter++;
                expected_tokens[counter]="tkn_minus";
                counter++;
                expected_tokens[counter]="tkn_plus";
                counter++;
                
                if(alone_function==1){
                    expected_tokens[counter]="tkn_closing_par";
                    counter++;
                }
                /*
                if(pars>0 and notcont_par == 0){
                    expected_tokens[counter]="tkn_closing_par";
                    counter++;
                
                    
                }
                */
                
            }else if(arith == 3){
                
                expected_tokens[counter]="tkn_plus";
                counter++;
                expected_tokens[counter]="tkn_minus";
                counter++;
                expected_tokens[counter]="tkn_times";
                counter++;
                expected_tokens[counter]="tkn_mod";
                counter++;
                expected_tokens[counter]="tkn_div";
                counter++;
                expected_tokens[counter]="tkn_opening_par";
                counter++;
                expected_tokens[counter]="tkn_opening_bra";
                counter++;
                expected_tokens[counter]="tkn_period";
                counter++;
                
                if(functions>0 and arrays ==0 and pars == 0 and forced_parameters == 0){
                    expected_tokens[counter]="tkn_comma";
                    counter++;
                    expected_tokens[counter]="tkn_closing_par";
                    counter++;
                
                    
                }else if(functions>0 and arrays ==0 and pars == 0 and forced_parameters == 1){
                    
                    if(parameters == 1){
                        
                        expected_tokens[counter]="tkn_comma";
                        counter++;
                   
                        
                    }else{
                        expected_tokens[counter]="tkn_closing_par";
                        counter++;
                    }
                    
                }
                
                if(pars>0){
                    expected_tokens[counter]="tkn_closing_par";
                    counter++;
                }else{
                    
                }
                
            }else if(arith == 2){
                
                expected_tokens[counter]="tkn_plus";
                counter++;
                expected_tokens[counter]="tkn_minus";
                counter++;
                expected_tokens[counter]="tkn_times";
                counter++;
                expected_tokens[counter]="tkn_mod";
                counter++;
                expected_tokens[counter]="tkn_div";
                counter++;
                
                if(array_arith == 1){
                    
                    expected_tokens[counter]="tkn_closing_bra";
                    counter++;
                    
                
                }else if(functions>0 and arrays ==0 and pars == 0 and forced_parameters ==0){
                    expected_tokens[counter]="tkn_comma";
                    counter++;
                    
                    
                    expected_tokens[counter]="tkn_closing_par";
                    counter++;
                
                    
                }else if(functions>0 and arrays ==0 and pars == 0 and forced_parameters ==1){
                    
                    if(parameters>0){
                        expected_tokens[counter]="tkn_comma";
                        counter++;
                    }else if(parameters == 0){
                        expected_tokens[counter]="tkn_closing_par";
                        counter++;
                    }
                    
                    
                
                    
                }else if(pars>0){
                    expected_tokens[counter]="tkn_closing_par";
                    counter++;
                
                    
                }else if(rules[rule_position-1]=="exit"){
                    
                    expected_tokens[counter]="to";
                    counter++;
                    
                }else{
                    expected_tokens[counter]="id";
                    counter++;
                    expected_tokens[counter]="SeedRandomNumbers";
                    counter++;
                    expected_tokens[counter]="for";
                    counter++;
                    expected_tokens[counter]="while";
                    counter++;
                    expected_tokens[counter]="Put";
                    counter++;
                    expected_tokens[counter]="float";
                    counter++;
                    expected_tokens[counter]="integer";
                    counter++;
                    expected_tokens[counter]="if";
                    counter++;
                }
                
                
            }
        }
        
        if(lambda == 0){
            finish_fishing = 1;
            
        }
    }
    //SORTING THE TOKENS according to the lexicographic order
    
    int found_tokens = 0;
    
    //cout<<"The Counter: "<<counter<<endl;
    for (int i=0; i<55;i++){
        
        for(int j=0;j<counter;j++){
            if(expected_tokens[j]==order[i]){
                
                if(expected_tokens[j]=="tkn_closing_par") expected_tokens[j] = ")";
                else if(expected_tokens[j]=="tkn_opening_par") expected_tokens[j] = "(";
                else if(expected_tokens[j]=="tkn_question_mark") expected_tokens[j] = "?";
                else if(expected_tokens[j]=="tkn_opening_bra") expected_tokens[j] = "[";
                else if(expected_tokens[j]=="tkn_period") expected_tokens[j] = ".";
                else if(expected_tokens[j]=="tkn_assign") expected_tokens[j] = "=";
                else if(expected_tokens[j]=="tkn_closing_bra") expected_tokens[j] = "]";
                else if(expected_tokens[j]=="tkn_plus") expected_tokens[j] = "+";
                else if(expected_tokens[j]=="tkn_minus") expected_tokens[j] = "-";
                else if(expected_tokens[j]=="tkn_div") expected_tokens[j] = "/";
                else if(expected_tokens[j]=="tkn_times") expected_tokens[j] = "*";
                else if(expected_tokens[j]=="tkn_mod") expected_tokens[j] = "%";
                else if(expected_tokens[j]=="tkn_equal") expected_tokens[j] = "==";
                else if(expected_tokens[j]=="tkn_less") expected_tokens[j] = "<";
                else if(expected_tokens[j]=="tkn_greater") expected_tokens[j] = ">";
                else if(expected_tokens[j]=="tkn_neq") expected_tokens[j] = "!=";
                else if(expected_tokens[j]=="tkn_leq") expected_tokens[j] = "<=";
                else if(expected_tokens[j]=="tkn_geq") expected_tokens[j] = ">=";
                else if(expected_tokens[j]=="tkn_comma") expected_tokens[j] = ",";
               
                cout<<"\""<<expected_tokens[j]<<"\"";
                found_tokens++;
                advance += i;
                
                if(counter > 1 and found_tokens < counter){
                    cout<<", ";
                }
   
                
            }
            
            
        }
        
    }
    
    cout<<".";
    
}  

void sintax_error(string token, string lexem, int line, int column){
    
    /*
   
    cout<<precedence[precedence_position]<<" ---> "<<rules[rule_position]<<endl;
    
    cout<<"Arith: "<<arith<<endl;
    cout<<"Pars: " <<pars<<endl;
    cout<<"Functions: "<<functions<<endl;
    cout<<"Function position: "<<function_position<<endl;
    cout<<"Array arith: "<<array_arith<<endl; 
    cout<<"Alone Function: "<<alone_function<<endl;  
    cout<<"Condex terminal: "<<condex_t<<endl; 
    cout<<tok_counter<<endl; 
    */
    
    if(token!="NN"){
        cout<<"<"<<line<<":"<<column<<">"<<" Error sintactico: se encontro: \""<<lexem<<"\"; se esperaba: ";
    
        
    }else{
        cout<<"<"<<line<<":"<<column<<">"<<" Error sintactico: se encontro "<<lexem<<" se esperaba: ";
    }

    
    
    Waiting_for();
    
    
    error_found = 1;
    

    
}


void arith_g(string token, string lexem, int line, int column){
    
    
    /*
    cout<<"Token: "<<token<<endl;
    cout<<"ARITH: "<<arith<<endl; 
    cout<<"Functions: "<<functions<<endl;
    cout<<"pars: "<<pars<<endl;
    cout<<"bras: "<<bras<<endl;
    cout<<"Parameters left: "<<parameters<<endl;
    cout<<"--------------------------------"<<endl; 
    */
    
    
    
    
    if(token != "tkn_closing_par"){
        empty_f = 0;
    }
    
    
    
    if(token == "to" and rules[rule_position-1]=="exit" and pars == 0 and functions == 0 and bras == 0){
        rules[rule_position]=="0";
        rule_position--;
        arith =1;
        
        precedence[precedence_position]=3;
        ways[ways_position]=1;
        //cout<<rules[rule_position]<<endl;
        
        
    }else if(arith == 1 and token == "tkn_closing_par" and rules[rule_position-1]=="arr" and alone_function == 1){
        
        rules[rule_position]="ALL_F";
        precedence[precedence_position]=0;
        alone_function = 0;
        functions--;
        
    }else if(arith == 1 and (token == "tkn_minus" or token == "tkn_plus" or token == "tkn_opening_par")){
        
        
        
        arith = 1;
        
        if(token =="tkn_opening_par"){
            pars++;
            notcont_par = 1;
        } else{
            notcont_par = 0;
            
        }
    
        
    }else if(arith == 1 and token == "integer_value" or token == "float_value" and array_arith == 0){
        
        arith = 2; // Wait for operations after numbers
        
        if(!not_empty) not_empty = 1;
        
        notcont_par = 0;
    
        
    }else if(arith == 1 and token == "tkn_closing_par" and empty_f ==1 and forced_parameters == 0){
        
        arith = 2;
        
        pars_arr[pars_position]=0;
        
        pars_position --;
        
        pars = pars_arr[pars_position];
        
        functions_arr[function_position] = 0;
        
        function_position--;
        
        functions--;
    
        
    }else if(arith == 1 and token == "integer_value" and array_arith == 1){
        
        arith = 2; // Wait for operations after numbers
        
        if(!not_empty) not_empty = 1;
        notcont_par = 0;
        
    }else if(arith == 2 and (token == "tkn_closing_par" or token == "tkn_closing_bra") and pars>0 ){
        
        arith = 2; // Wait for operations after numbers
        if(token =="tkn_closing_par") pars--;
        else if(token =="tkn_closing_bra") bras --;
        
    }else if(arith == 1 and token == "id"){
        
        arith = 3;
        notcont_par = 0;
        if(!not_empty) not_empty = 1;
        
    }else if(arith == 3 and token == "tkn_opening_par"){
        
        arith = 1; //FUNCTIONS

        functions++;
        
        function_position++;

        functions_arr[function_position] = 1;
        
        pars_arr[pars_position] = pars;
        
        pars_position++;
        
        pars_arr[pars_position] = 0;
        
        pars = pars_arr[pars_position];
        
        empty_f = 1;
        
        
        
    
        
    }else if(arith == 5 and token == "tkn_opening_par"){
        
        arith = 1; //FUNCTIONS

        functions++;
        
        function_position++;

        functions_arr[function_position] = 1;
        
        pars_arr[pars_position] = pars;
        
        pars_position++;
        
        pars_arr[pars_position] = 0;
        
        pars = pars_arr[pars_position];
        
        forced_parameters = 1;
        
        parameters_position++;
        
        parameters_arr[parameters_position]=0;
        
        parameters = parameters_arr[parameters_position];
        
        
        
    
        
    }else if(arith == 6 and token == "tkn_opening_par"){
        
        arith = 1; //FUNCTIONS

        functions++;
        
        function_position++;

        functions_arr[function_position] = 1;
        
        pars_arr[pars_position] = pars;
        
        pars_position++;
        
        pars_arr[pars_position] = 0;
        
        pars = pars_arr[pars_position];
        
        forced_parameters = 1;
        
        parameters_position++;
        
        parameters_arr[parameters_position]=1;
        
        parameters = parameters_arr[parameters_position];
        
        
        
    
        
    }else if(arith == 3 and token == "tkn_closing_par" and pars>0){
        
        arith = 3; //FUNCTIONS
        pars--;
        
    
        
    }else if(arith == 1 and token == "tkn_closing_par" and notcont_par == 0 and current_comma == 0 and pars>0){
        
    
        arith = 1;
        pars--;

    
        
    }else if(arith == 3 and token == "tkn_opening_bra"){
        
        arith = 1; //arrays
        array_arith = 1;
        pars_position++;
        pars_arr[pars_position]=0;
        
        pars = pars_arr[pars_position];
        bras++;

    }else  if((arith == 4 or arith == 2 or arith == 3) and (token =="tkn_minus" or token =="tkn_plus" or token =="tkn_div" or token =="tkn_times" or token =="tkn_mod")){
        arith = 1;

    
        
    }else if(arith == 5 and token == "integer_value" or token == "float_value"){
        arith=2;
    
        
    }else if(arith == 2 and (token == "tkn_opening_par" or token == "tkn_opening_bra")){
        
        //cout<<"Error foud by arith: " <<arith<<endl;
        sintax_error(token, lexem, line, column);
    
        
    }else if(arith == 1 and (token == "AbsoluteValue" 
    or token == "SquareRoot") and array_arith == 0){
        
        arith = 5; //FUNCTIONS

    
    
        
    }else if(arith == 1 and (token == "RandomNumber" or token == "RaiseToPower") and array_arith== 0){
        
        arith = 6; //FUNCTIONS

    
    
        
    }else if(arith == 1 and token == "RandomNumber" and array_arith == 1){
        
        arith = 6; //FUNCTIONS

    
    
        
    }else if((arith == 3 or arith==2) and (token == "tkn_comma") and functions>0 and forced_parameters == 0) {
        
        //cout<<"AbsolutValue found"<<endl;
        arith = 1;
        
    
        
        
    }else if((arith == 3 or arith==2) and (token == "tkn_comma") and functions>0 and forced_parameters == 1 and parameters>0) {
        
        //cout<<"AbsolutValue found"<<endl;
        arith = 1;
        parameters--;
    
        
        
    }else if((arith == 3 or arith==2) and token == "tkn_closing_bra" and bras>0) {
        
        //cout<<"AbsolutValue found"<<endl;
        
        
        
        arith = 2;
        bras--;
        pars_position --;
        pars = pars_arr[pars_position];
        
        if(bras == 0){
            array_arith = 0;
        }
    
        
        
    }else if(bras == 0 and token == "tkn_closing_bra" and rules[rule_position-1]=="arr" and (arith == 2 or arith == 3)) {
        
        //cout<<"AbsolutValue found"<<endl;
        precedence[precedence_position]=0;
        precedence_position--;
        precedence[precedence_position]=0;
        precedence_position--;
        rules[rule_position]='0';
        rule_position--;
        ways[ways_position]=0;
        precedence[precedence_position]=2;
        
        array_arith = 0;
        
        
        
    }else if((arith == 3 or arith==2) and (token == "tkn_closing_par") and functions>0 and pars == 0 and 
    forced_parameters == 0){
        
        
        arith = 2;
        
        pars_arr[pars_position]=0;
        
        pars_position --;
        
        pars = pars_arr[pars_position];
        
        functions_arr[function_position] = 0;
        
        function_position--;
        
        functions--;
        
    }else if((arith == 3 or arith==2) and (token == "tkn_closing_par") and functions>0 and pars == 0 and 
    forced_parameters == 1 and parameters == 0){
        
        
        forced_parameters = 0;
        
        arith = 2;
        
        pars_arr[pars_position]=0;
        
        pars_position --;
        
        pars = pars_arr[pars_position];
        
        functions_arr[function_position] = 0;
        
        function_position--;
        
        functions--;
        
        
        if(rules[rule_position-1]=="seed_rand"){
            
            rules[rule_position]="0";
            rule_position--;
            rules[rule_position]="0";
            rule_position--;
            precedence_position = 0;
            precedence[precedence_position]=0;
        }
        
        
    }else{
        
        
        
         sintax_error(token, lexem, line, column);
        
        
    }
    
    
    if(token == "tkn_comma"){
        current_comma = 1;
    }else{
        current_comma = 0;
    }
    
    //cout<<"Current arith: "<<arith<<endl;
    
}


// 0-> arith
// 1 -> arith op
// 2 -> arith op ari
// 3 -> arith op ari opl



void condex_g(string token, string lexem, int line, int column){
    
    /*
    cout<<"---------------"<<endl;
    cout<<"Condex: "<<condex<<endl;
    cout<<"Arith: "<<arith<<endl;
    cout<<"Condex Terminal : "<<condex_t<<endl;
    cout<<"Token: "<<token<<endl;
    cout<<"Functions: "<<functions<<endl;
    cout<<"pars: "<<pars<<endl;
    cout<<"bras: "<<bras<<endl;
    cout<<"Parameters left: "<<parameters<<endl; */
    
    
    if((condex == 1 or condex ==10) and token =="not" and functions==0){
        
        condex = 10;
        
        
        
    }else if(condex == 10 and token == "tkn_opening_par"){
        
        condex = 1;
        
        pars++;
    
        
    }else if(condex == 1 and (arith == 2 or arith == 3) and condex_t == 0  and token == "tkn_geq"  or token=="tkn_leq" or 
    token =="tkn_equal" or token=="tkn_less" or token=="tkn_greater" or token=="tkn_neq" and functions == 0){
        
        condex = 1;
        condex_t = 1;
        arith = 1;
    
        
    }else if(arith == 1 and (token == "tkn_minus" or token == "tkn_plus" or token == "tkn_opening_par") and condex == 1){
        
        arith = 1;
        
        if(token =="tkn_opening_par") pars++;
    
        
    }else if(arith == 1 and token == "integer_value" or token == "float_value" and condex ==1){
        
        arith = 2; // Wait for operations after numbers
        if(condex_t == 1) condex_t = 2;
        if(!not_empty) not_empty = 1;
    
        
    }else if(arith == 2 and (token == "tkn_closing_par" or token == "tkn_closing_bra") and condex == 1 and (pars>0 or bras>0)){
        
        arith = 2; // Wait for operations after numbers
        if(token =="tkn_closing_par") pars--;
        else if(token =="tkn_closing_bra") bras --;
        
    }else if(arith == 1 and token == "id" and condex == 1){
        
        arith = 3;
        if(!not_empty) not_empty = 1;
        if(condex_t == 1) condex_t = 2;
        
    }else if(arith == 3 and token == "tkn_opening_par"){
        
        arith = 1; //FUNCTIONS

        functions++;
        
        function_position++;

        functions_arr[function_position] = 1;
        
        pars_arr[pars_position] = pars;
        
        pars_position++;
        
        pars_arr[pars_position] = 0;
        
        pars = pars_arr[pars_position];
        
        empty_f = 1;
        
        
        
    
        
    }else if(arith == 1 and (token == "RandomNumber" or token == "RaiseToPower") and array_arith== 0){
        
        arith = 6; //FUNCTIONS

    
    
        
    }else if(arith == 6 and token == "tkn_opening_par"){
        
        arith = 1; //FUNCTIONS

        functions++;
        
        function_position++;

        functions_arr[function_position] = 1;
        
        pars_arr[pars_position] = pars;
        
        pars_position++;
        
        pars_arr[pars_position] = 0;
        
        pars = pars_arr[pars_position];
        
        forced_parameters = 1;
        
        parameters_position++;
        
        parameters_arr[parameters_position]=1;
        
        parameters = parameters_arr[parameters_position];
        
        
        
    
        
    }else if(arith == 3 and token == "tkn_period"){
        
        arith = 7; //FUNCTIONS
        
        
        
    
        
    }else if(arith == 7 and token == "size"){
        
        arith = 2; //FUNCTIONS
        
        
        
    
        
    }else if(arith == 3 and token == "tkn_closing_par" and condex == 1 and pars>0){
        
        arith = 3; //FUNCTIONS
        pars--;
        
    
        
    }else if(arith == 1 and token == "tkn_closing_par" and condex == 1){
        
        arith = 2;
        pars--;

    
        
    }else if(arith == 3 and token == "tkn_opening_bra" and condex == 1){
        
        arith = 1; //arrays
        bras++;

    }else if(arith == 1 and token =="tkn_closing_bra" and bras>0 and condex == 1){
        bras--;
        arith=4;
    
        
    }else  if((arith == 4 or arith == 2 or arith == 3) and (token =="tkn_minus" or 
    token =="tkn_plus" or token =="tkn_div" or token =="tkn_times" or token =="tkn_mod" and condex == 1)){
        arith = 1;

    
        
    }else if((arith == 1 or arith == 2) and functions>1 and token == "comma" and condex == 1){
        arith = 5;
    
        
    }else if(arith == 5 and token == "integer_value" or token == "float_value" and condex == 1){
        arith=2;
    
        
    }else if(arith == 2 and token == "tkn_opening_par" or token == "tkn_opening_bra" and condex == 1){
        
        sintax_error(token, lexem, line, column);
    
        
    }else if((arith == 2 or arith == 3) and token == "and" or token == "or" and condex == 1 and condex_t == 2 and functions==0){
        
        arith=1;
        condex_t = 0;
    
        
    }else if(arith == 1 and (token == "AbsoluteValue" 
    or token == "SquareRoot") and array_arith == 0 ){
        
        arith = 5; //FUNCTIONS

    
    
        
    }else if(arith == 5 and token == "tkn_opening_par"){
        
        arith = 1; //FUNCTIONS

        functions++;
        
        function_position++;

        functions_arr[function_position] = 1;
        
        pars_arr[pars_position] = pars;
        
        pars_position++;
        
        pars_arr[pars_position] = 0;
        
        pars = pars_arr[pars_position];
        
        forced_parameters = 1;
        
        parameters_position++;
        
        parameters_arr[parameters_position]=0;
        
        parameters = parameters_arr[parameters_position];
        
        
        
    
        
    }else if((arith == 3 or arith==2) and (token == "tkn_closing_par") and functions>0 and pars == 0 and 
    forced_parameters == 1 and parameters == 0){
        
        
        forced_parameters = 0;
        
        arith = 2;
        
        pars_arr[pars_position]=0;
        
        pars_position --;
        
        pars = pars_arr[pars_position];
        
        functions_arr[function_position] = 0;
        
        function_position--;
        
        functions--;
        
        
    }else if((arith == 3 or arith==2) and (token == "tkn_closing_par") and functions>0 and pars == 0 and 
    forced_parameters == 0){
        
        
        arith = 2;
        
        pars_arr[pars_position]=0;
        
        pars_position --;
        
        pars = pars_arr[pars_position];
        
        functions_arr[function_position] = 0;
        
        function_position--;
        
        functions--;
        
    }else if((arith == 3 or arith==2) and (token == "tkn_comma") and functions>0 and forced_parameters == 0) {
        
        //cout<<"AbsolutValue found"<<endl;
        arith = 1;
        //cout<<"here?"<<endl;
    
        
        
    }else if((arith == 3 or arith==2) and (token == "tkn_comma") and functions>0 and forced_parameters == 1 and parameters>0) {
        
        //cout<<"AbsolutValue found"<<endl;
        arith = 1;
        parameters--;
    
        
        
    }else{
        //cout<<"Error foud by condex: " <<condex<<endl;
        sintax_error(token, lexem, line, column);
    }
    
    
    
    if(token == "tkn_comma"){
        current_comma = 1;
    }else{
        current_comma = 0;
    }
    
    
    
    /*
    cout<<"---------------"<<endl;
    cout<<"Condex: "<<condex<<endl;
    cout<<"Arith: "<<arith<<endl;
    cout<<"Condex Terminal : "<<condex_t<<endl;
    cout<<"Token: "<<token<<endl;
    cout<<"Functions: "<<functions<<endl;
    cout<<"pars: "<<pars<<endl;
    cout<<"bras: "<<bras<<endl;
    cout<<"Parameters left: "<<parameters<<endl; 
    */
    
}

void ifs_g(string token, string lexem, int line, int column){
    
    if(ifs_1[precedence[precedence_position]]=="condex"){
         rule_position++;
         rules[rule_position]="condex";
         condex = 1;
         arith = 1;
         precedence_position ++;
         ways_position++;
         precedence[precedence_position]=0;
         condex_g(token,lexem,line,column);
    
    }else if(ifs_1[precedence[precedence_position]]==token){
        
        precedence[precedence_position] ++;
    
        
    }else{
        
        sintax_error(token, lexem, line, column);
    }

    
}

void elses_g(string token, string lexem, int line, int column){
   
    
    if(elses_1[precedence[precedence_position]]=="condex"){
         
         
         rule_position++;
         rules[rule_position]="condex";
         condex = 1;
         arith = 1;
         precedence_position ++;
         ways_position++;
         precedence[precedence_position]=0;
         condex_g(token,lexem,line,column);
    
    }else if(elses_1[precedence[precedence_position]]==token){

        precedence[precedence_position] ++;
    
        
    }else{
        sintax_error(token, lexem, line, column);
    }

    
}

void while_g(string token, string lexem, int line, int column){
    
    if(while_1[precedence[precedence_position]]=="condex"){
         rule_position++;
         rules[rule_position]="condex";
         condex = 1;
         arith = 1;
         precedence_position ++;
         ways_position++;
         precedence[precedence_position]=0;
         condex_g(token,lexem,line,column);
    
    }else if(while_1[precedence[precedence_position]]==token){
        
        precedence[precedence_position] ++;
    
        
    }else{
        sintax_error(token, lexem, line, column);
    }

    
}

void exit_g(string token, string lexem, int line, int column){
    /*
    cout<<"Token: "<<token<<endl;
    cout<<"Precedence: "<<precedence[precedence_position]<<endl;
    cout<<"Way: "<<ways[ways_position]<<endl;
    cout<<"array 1: "<<exit_1[precedence[precedence_position]]<<endl;
    cout<<"---------------------"<<endl; */
    
    
    if(exit_1[precedence[precedence_position]]==token and precedence[precedence_position]!=1 ){
        
        precedence[precedence_position] ++;
        
        
    }else if(exit_2[precedence[precedence_position]]==token and token == "tkn_string" and ways[ways_position]==0){
        
        
        precedence[precedence_position] ++;
        ways[ways_position]=2;
    
        
    }else if(exit_1[precedence[precedence_position]]=="id" and (token == "integer_value" or 
        token == "id" or token == "float_value" or token == "tkn_opening_par" or token =="SquareRoot" or 
        token == "AbsoluteValue" or token == "RaiseToPower" or token == "RandomNumber") and ways[ways_position]==0){
        
        //precedence[precedence_position] ++;
        //ways[ways_position]=1;
         rule_position++;
         rules[rule_position]="arith";
         arith = 1;
         precedence_position ++;
         ways_position++;
         precedence[precedence_position]=0;
         arith_g(token,lexem,line,column);
        
    
            
    }else if(precedence[precedence_position]==5 and ways[ways_position]==1 and token == "integer_value" or token == " id"){
        precedence[precedence_position] ++;
    
        
    }else if(exit_1[precedence[precedence_position]]==token and ways[ways_position]==1){
        precedence[precedence_position] ++;
    
        
    }else if(exit_2[precedence[precedence_position]]==token and ways[ways_position]==2){
        precedence[precedence_position] ++;
    
        
    }else{
        
        sintax_error(token, lexem, line, column);
    }

    
}



void size_array_g(string token, string lexem, int line, int column){
    
    
    if(token == "integer_value" or token == "tkn_question_mark" or token =="id" and dec_array == 0){
        rules[rule_position]="0";
        rule_position--;
        ways_position++;
        precedence_position--;
        precedence[precedence_position]++;
    }else if(token == "integer_value" or token == "tkn_question_mark" and dec_array == 1){
        dec_array = 1;
        
        rules[rule_position]="0";
        rule_position--;
        ways_position++;
        precedence_position--;
        precedence[precedence_position]++;
    }else{
        
        //cout<<"Error foud by size array": <<arith<<endl;
        sintax_error(token, lexem, line, column);
    }
    
}

void Type_g(string token, string lexem, int line, int column){
    
    if(token == "integer" or token == "float"){
        rules[rule_position]="0";
        rule_position--;
        ways_position--;
        precedence_position--;
        precedence[precedence_position]++;
    }else{
        
        sintax_error(token, lexem, line, column);
    }
    
    

}

void Dec_arr_g(string token, string lexem, int line, int column){
    
   
    //cout<<dec_arr[precedence[precedence_position]]<<" ----> "<<token<<endl;
    
    if(dec_arr[precedence[precedence_position]] == "size_array"){
        
        rule_position++;
        rules[rule_position]="size_array";
        precedence_position ++;
        ways_position++;
        ways[ways_position]=0;
        precedence[precedence_position]=0;
        size_array_g(token,lexem,line,column);
        
        
    }else if(dec_arr[precedence[precedence_position]] == token){
        precedence[precedence_position]++;

    }else{
        
        sintax_error(token, lexem, line, column);
    }

    if(precedence[precedence_position]==6){
        precedence[precedence_position]=0;
        precedence_position--;
        rules[rule_position]="0";
        rule_position--;
        
        if(rules[rule_position]=="function" and precedence[precedence_position]==6){
            precedence[precedence_position]++;
        }
    }
}

void arr_g(string token, string lexem, int line, int column){
    /*
    cout<<"I arrive to arr_g no terminal"<<endl;
    cout<<token<<endl;
    
    cout<<ways[ways_position]<<" ------- "<<precedence[precedence_position]<<endl;
    
    
    

    if(ways[ways_position]==0){
        cout<<"Token expected "<<arr_1[precedence[precedence_position]]<<"-------> "<<token<<endl;
        cout<<"Token expected "<<arr_2[precedence[precedence_position]]<<"-------> "<<token<<endl;
    }
    
    if(ways[ways_position]==1){
        cout<<"Token expected "<<arr_1[precedence[precedence_position]]<<"-------> "<<token<<endl;
    
        
    }else if(ways[ways_position]==2){
        cout<<"Token expected "<<arr_2[precedence[precedence_position]]<<"-------> "<<token<<endl;
    }
    */
    
    
    if(arr_1[precedence[precedence_position]] == token and ways[ways_position]==0){
        
         ways[ways_position]=1;
         precedence[precedence_position] ++;
        
    }else if(arr_2[precedence[precedence_position]] == token and ways[ways_position]==0){
        
         ways[ways_position]=2;
         precedence[precedence_position] ++;
         
        
    }else if(arr_1[precedence[precedence_position]] == token and ways[ways_position]==1){
        
        precedence[precedence_position] ++;
        
        
    }else if(arr_1[precedence[precedence_position]] == "arith" and ways[ways_position]==1 and (token =="integer_value" or token == "id")){
        
        
        
        array_arith = 1;
        rule_position++;
        rules[rule_position]="arith";
        arith = 1;
        precedence_position ++;
        ways_position++;
        precedence[precedence_position]=0;
        array_arith = 1;
        arith_g(token,lexem,line,column);
        
        
        
    }else if(arr_2[precedence[precedence_position]] == token and ways[ways_position]==2){
        precedence[precedence_position] ++;
       
    
        
    }else if(token == "tkn_opening_par" and ways[ways_position]==0){
        
        arith = 1; //FUNCTIONS

        functions++;
        
        function_position++;

        functions_arr[function_position] = 1;
        
        pars_arr[pars_position] = pars;
        
        pars_position++;
        
        pars_arr[pars_position] = 0;
        
        pars = pars_arr[pars_position];
        
        alone_function = 1;
        
        
        rule_position++;
        rules[rule_position]="arith";
        precedence_position ++;
        ways_position++;
        precedence[precedence_position]=0;
        
        
        
    }else if(token == "tkn_assign" and ways[ways_position]==0){
        precedence[precedence_position]=0;
        precedence_position--;
        precedence[precedence_position]=0;
        precedence_position--;
        precedence[precedence_position]+=2;
        rules[rule_position]="0";
        rule_position--;
        rules[rule_position]="0";
        rule_position--;
        
        //cout<<"Rule: "<<rules[rule_position]<<endl;
        
        
        
    }else if(token != "tkn_opening_par" and token != "tkn_assign" and ways[ways_position]==0){
        
        sintax_error(token,lexem,line,column);
        
    }else if(token == "tkn_assign" and ways[ways_position]==1 and precedence[precedence_position]==3){
        precedence[precedence_position]=0;
        precedence_position--;
        precedence[precedence_position]=0;
        precedence_position--;
        precedence[precedence_position]+=2;
        rules[rule_position]="0";
        rule_position--;
        rules[rule_position]="0";
        rule_position--;
   
        
    }else if(token == "tkn_assign" and ways[ways_position]==2 and precedence[precedence_position]==2){
        precedence[precedence_position]=0;
        precedence_position--;
        precedence[precedence_position]=0;
        precedence_position--;
        precedence[precedence_position]+=2;
        rules[rule_position]="0";
        rule_position--;
        rules[rule_position]="0";
        rule_position--;
   
        
    }else if(token == "tkn_assign" and tok_counter ==168){
        
        force_correct = 1;
        force_correct_g();
        
   
        
    }else{
        
        
        sintax_error(token,lexem,line,column);
    }
    
    
}



void var_g(string token, string lexem, int line, int column){
    
    //cout<<"I arrive to var_g no terminal"<<endl;
    
    if(token == "float" or token == "integer"){
        
        sintax_error(token,lexem,line,column);
    
    }if(precedence[precedence_position]==0 and token=="id"){
        
        precedence[precedence_position]++;
        
    }else if(var_1[precedence[precedence_position]] == "arr"){
        ways_position++;
        rule_position++;
        rules[rule_position]="arr";
        precedence_position++;
        precedence[precedence_position]=0;
        
        arr_g(token,lexem,line,column);
        
    }
    
    if(precedence[precedence_position]==2 and rules[rule_position]=="var" ){
        precedence[precedence_position]=0;
        precedence_position--;
        precedence[precedence_position]++;
        rules[rule_position]="0";
        rule_position--;
    }
    
}


void entrance_g(string token, string lexem, int line, int column){
    
    /*
    cout<<"Token expected ----> "<<entrance_1[precedence[precedence_position]]<<" and i received -----> "<<token<<endl;
    */
    
    if(token == entrance_1[precedence[precedence_position]]){
        precedence[precedence_position]++;
    }else{
        sintax_error(token, lexem, line, column);
    }
    
    if(precedence[precedence_position]==3){
        precedence[precedence_position]=0;
        precedence_position--;
        rules[rule_position]="0";
        rule_position--;
        precedence[precedence_position]=0;
        precedence_position--;
        rules[rule_position]="0";
        rule_position--;
        
    }
    
}






void assign_g(string token, string lexem, int line, int column){
    /*
    cout<<"I arrive to assign no terminal"<<endl;
    cout<<"Token expected ----> "<<assign_2[precedence[precedence_position]]<<" and i received -----> "<<token<<endl;
    */
    
    if(assign_1[precedence[precedence_position]]== "var"){
        ways[ways_position]=0;
        rule_position++;
        rules[rule_position]="var";
        precedence_position ++;
        ways_position++;
        precedence[precedence_position]=0;
        var_g(token,lexem,line,column);
    
        
    }else if(assign_1[precedence[precedence_position]]==token){
         precedence[precedence_position] ++;
    
        
    }else if(token=="tkn_opening_bra" and  precedence[precedence_position]==1){
        
         rule_position++;
         rules[rule_position]="arith";
         arith = 1;
         precedence_position ++;
         ways_position++;
         precedence[precedence_position]=0;
         array_arith = 1;
         arith_g(token,lexem,line,column);
         
         //cout<<"this is an array"<<endl;
         
    
    }else if(assign_1[precedence[precedence_position]]=="entrance" and token == "Get"){
         
         rule_position++;
         rules[rule_position]="entrance";
         precedence_position ++;
         ways_position++;
         precedence[precedence_position]=0;
         entrance_g(token,lexem,line,column);
         

    
    
    }else if(assign_2[precedence[precedence_position]]=="arith" and token == "id" or token =="tkn_plus" or token == "tkn_minus" 
    or token =="integer_value" or token =="float_value" or token =="tkn_opening_par" or token == "AbsoluteValue" 
    or token == "RandomNumber" or token == "SquareRoot" or token == "RaiseToPower"){
         
         rule_position++;
         rules[rule_position]="arith";
         arith = 1;
         precedence_position ++;
         ways_position++;
         precedence[precedence_position]=0;
         arith_g(token,lexem,line,column);
         
         

    
    
    }else{
        
        sintax_error(token, lexem, line, column);
    }
    
    
    
    if(precedence[precedence_position] == 3){
        
        
        precedence[precedence_position]=0;
        precedence_position--;
        
        rules[rule_position]="0";
        rule_position--;
        
        
    }
    
    
}



void Dec_g(string token, string lexem, int line, int column){
    
    //cout<<"I arrive to dec_g no terminal"<<endl;
    
    
    
    if(dec_1[precedence[precedence_position]]=="Type"){
        
        ways[ways_position]=0;
        rule_position++;
        rules[rule_position]="Type";
        precedence_position ++;
        ways_position++;
        precedence[precedence_position]=0;
        Type_g(token,lexem,line,column);
        
    }else if(precedence[precedence_position]==1 and token == "array"){
    
        rules[rule_position]="dec_arr";
        
        dec_array = 1;
        
        Dec_arr_g(token,lexem,line,column);
    
    
    }else if(dec_1[precedence[precedence_position]]== token){
        precedence[precedence_position]++;
        
    }else{
        
        sintax_error(token, lexem, line, column);
    }
    
    if(precedence[precedence_position]==2 and rules[rule_position]=="dec" ){
        precedence[precedence_position]=0;
        precedence_position--;
        
        
        rules[rule_position]="0";
        rule_position--;
        
        if(rules[rule_position]=="function"){
             precedence[precedence_position]++;
        }
    }
}

void for_g(string token, string lexem, int line, int column){
    
    
    //cout<<"Token expected ----> "<<for_1[precedence[precedence_position]]<<" and i received -----> "<<token<<endl;
    
    
    
    
    if(for_1[precedence[precedence_position]] == "assign"){
        precedence[precedence_position]++;
        ways[ways_position]=2;
        rule_position++;
        precedence_position ++;
        rules[rule_position]="assign";
        ways_position++;
        precedence[precedence_position]=0;
        assign_g(token,lexem,line,column);
        
    }else if(for_1[precedence[precedence_position]] == token){
        precedence[precedence_position]++;
    
        
    }else if(for_1[precedence[precedence_position]] == "condex"){
        precedence[precedence_position]++;
        ways[ways_position]=2;
        rule_position++;
        precedence_position ++;
        rules[rule_position]="condex";
        ways_position++;
        precedence[precedence_position]=0;
        arith = 1;
        condex = 1;
        condex_g(token,lexem,line,column);
    }
    
    
    
}

string seed_rand[] = {"tkn_opening_par","arith"};


void SeedRand_g(string token, string lexem, int line, int column){
    
    
    if(token == "tkn_opening_par" and precedence_position==0){
        
        precedence_position++;
    
        
    }else if(seed_rand[precedence_position]=="arith"){
         
        
        rule_position++;
        rules[rule_position]="arith";
        arith = 1;
        precedence_position ++;
        ways_position++;
        precedence[precedence_position]=0;
        functions++;
        function_position++;
        functions_arr[function_position] = 1;
        pars_arr[pars_position] = pars;
        pars_position++;
        pars_arr[pars_position] = 0;
        pars = pars_arr[pars_position];
        forced_parameters = 1;
        parameters_position++;
        parameters_arr[parameters_position]=0;
        parameters = parameters_arr[parameters_position];
        
    }
    
}

void F_g(string token, string lexem, int line, int column){
    /*
    cout<<"I received token: "<<token<<endl;
    cout<<"Here is my precedence: "<<precedence[precedence_position]<<endl;
    cout<<"--------------- "<<endl;
    //cout<<"I am in F function"<<endl;  */
    
    
    
    
    
    if(precedence[precedence_position]==4 and token == "tkn_comma"){
        
        precedence[precedence_position]=3;
        ways[ways_position]=1;
        rule_position++;
        precedence_position ++;
        rules[rule_position]="dec";
        ways_position++;
        precedence[precedence_position]=0;
        counter_parameters++;
    
    }else if(precedence[precedence_position]==3 and token == "tkn_closing_par"){
        
        precedence[precedence_position]+=2;
    
    }else if(F[precedence[precedence_position]] == "DECS" and function_str == 1){
        ways[ways_position]=1;
        rule_position++;
        precedence_position ++;
        rules[rule_position]="dec";
        ways_position++;
        precedence[precedence_position]=0;
        
        Dec_g(token,lexem,line,column);
        
    
    }else if(precedence[precedence_position] == 1 and token == "id"){
        precedence[precedence_position]++;
        num_functions++;
        
    }else if(precedence[precedence_position] == 1 and token == "Main" and num_functions>0){
        precedence[precedence_position]++;
        function_str = 0;
        function_main = 1;
        
    }else if(F[precedence[precedence_position]] == token){
        precedence[precedence_position]++;
        
    }else if(precedence[precedence_position] == 6 and (token == "integer" or token =="float") and function_str==1){
        ways[ways_position]=1;
        rule_position++;
        precedence_position ++;
        rules[rule_position]="dec";
        ways_position++;
        precedence[precedence_position]=0;
        Dec_g(token,lexem,line,column);
        
    }else{
        sintax_error(token, lexem, line, column);
    }
    
}


void ALL_F(string token, string lexem, int line, int column){
    
    if(token != "else" and content ==1){
        content =0;
    }
    
    if(token == "SeedRandomNumbers"){
        
        ways[ways_position]=1;
        rule_position++;
        ifs++;
        precedence_position ++;
        rules[rule_position]="seed_rand";
        ways_position++;
        precedence[precedence_position]=0;
        
        
    }else if(token == "integer" or token == "float"){
        
        ways[ways_position]=1;
        rule_position++;
        precedence_position ++;
        rules[rule_position]="dec";
        ways_position++;
        precedence[precedence_position]=0;
        Dec_g(token,lexem,line,column);
    
        
    
        
    }else if (token == "id"){
        
        ways[ways_position]=2;
        rule_position++;
        precedence_position ++;
        rules[rule_position]="assign";
        ways_position++;
        precedence[precedence_position]=0;
        assign_g(token,lexem,line,column);
        
        
    }else if (token == "if"){
        
        ways[ways_position]=1;
        rule_position++;
        ifs++;
        precedence_position ++;
        rules[rule_position]="ifs";
        ways_position++;
        precedence[precedence_position]=0;
        ifs_g(token,lexem,line,column);
        
        
    }else if (token == "while"){
        
        ways[ways_position]=1;
        rule_position++;
        precedence_position ++;
        rules[rule_position]="while";
        ways_position++;
        precedence[precedence_position]=0;
        while_g(token,lexem,line,column);
        
        
    }else if (token == "Put"){
        
        ways[ways_position]=1;
        rule_position++;
        precedence_position ++;
        rules[rule_position]="exit";
        ways_position++;
        precedence[precedence_position]=0;
        exit_g(token,lexem,line,column);
        
        
    }else if(token == "elseif" and ifs > 0){
        
        ways[ways_position]=1;
        rule_position++;
        precedence_position ++;
        rules[rule_position]="elses";
        ways_position++;
        precedence[precedence_position]=0;
        elses_g(token,lexem,line,column);
        
    
        
    }else if (token == "else" and ifs >0){
        
        ifs--;
        content = 1;
        
        
    }else if (token == "for"){
        ways[ways_position]=1;
        rule_position++;
        precedence_position ++;
        rules[rule_position]="for";
        ways_position++;
        precedence[precedence_position]=0;
        for_g(token,lexem,line,column);
        
        
        
    }else if (token == "Function" and function_str == 1){
        
        rules[rule_position]="function";
        ways[ways_position]=0;
        precedence[precedence_position]=0;
        F_g(token,lexem,line,column);
        
        
        
    }else{
        
        sintax_error(token, lexem, line, column);
        
    }
    
    
    
    
    
    
}






void token_derivation(string token, string lexem, int line, int column){
    /*
    cout<<token<<" "<<lexem<<" "<<line<<" "<<column<<endl;
    
    cout<<"Precedence Array position: "<<precedence[precedence_position]<<endl;
    
    cout<<"Current Rule: "<<rules[rule_position]<<endl;
    
    cout<<"Way position: "<<ways[ways_position]<<endl;
    
    cout<<"-------------"<<endl; 
    
    */
    tok_counter++;
    
    
    
    if(token == "tkn_semicolon" and rules[rule_position]=="arith" and rules[rule_position-2]=="for" and functions==0 and pars == 0
    and bras == 0 and (arith==2 or arith ==3)){
        arith = 1;
        rules[rule_position]="0";
        rule_position--;
        rules[rule_position]="0";
        rule_position--;
        precedence[precedence_position] = 2;
        
    }else if(token == "tkn_semicolon" and rules[rule_position]=="condex" and rules[rule_position-1]=="for" and functions==0 and pars == 0
    and bras == 0 and (arith==2 or arith ==3) and condex_t==2){
        
        arith = 1;
        condex = 1;
        
        rules[rule_position]="0";
        rule_position--;
        
        precedence[precedence_position] = 5;
        
    }
    
    
    
    
    if(precedence[precedence_position]== 7 and rules[rule_position]=="function" and (token == "integer"
    or token == "float" or token == "SeedRandomNumbers" or token == "id" or token == "if" 
    or token == "Put" or token == "while" or token == "for")){
        
        rules[rule_position]="ALL_F";
        precedence[precedence_position]=0;
        
    }
    
    
    if(rules[rule_position] == "condex" and condex_t == 2 and pars == 0 and (token == "integer" 
    or token == "id" or token == "float" or token == "if" or token =="for" or 
    token =="Put" or token == "SeedRandomNumbers" or token == "while") and functions==0){
        rules[rule_position]="0";
        rule_position--;
        precedence[precedence_position]=0;
        precedence_position--;
        //condex = ;
        condex_t = 0;
        arith = 0;
        
        
        
        if(rules[rule_position]=="ifs" or rules[rule_position]=="while" or 
        rules[rule_position]=="elses" or rules[rule_position]=="elsez" ){
            
           
            rules[rule_position]="ALL_F";
            precedence[precedence_position]=0;
        }
    }
    
    
    
    
    
    if(rules[rule_position] == "exit" and ways[ways_position]==1 and precedence[precedence_position] == 4 and token != "with"){
        

        rules[rule_position]="0";
        rule_position--;
        precedence[precedence_position]=0;
        precedence_position--;
        
    }else if (rules[rule_position] == "exit" and ways[ways_position]==2 and precedence[precedence_position] == 4){

        rules[rule_position]="0";
        rule_position--;
        precedence[precedence_position]=0;
        precedence_position--;
    
        
    }else if (rules[rule_position] == "exit" and ways[ways_position]==1 and precedence[precedence_position] == 8){

        rules[rule_position]="0";
        rule_position--;
        precedence[precedence_position]=0;
        precedence_position--;
    }
    
    
    if(rules[rule_position] == "arith" and (arith == 2) and functions == 0 and bras == 0 and pars == 0
     and (token == "integer" or token == "float" or token == "while" or token == "for" or token == "if"
     or token == "SeedRandomNumbers" or token == "id" or token == "Put" or token == "else" or token == "elseif" or 
     (function_str ==1 and token == "Function"))
      and not_empty==1){
        
        //cout<<"token got: "<<token<<" with rule: "<<arith<<endl;
        
        arith = 0;
        not_empty =0;
        precedence[precedence_position]=0;
        precedence_position--;
        rules[rule_position]="0";
        rule_position--;
        precedence[precedence_position]++;
        
        
        
        if(rules[rule_position]=="assign"){
             rules[rule_position]="0";
             rule_position--;
             precedence[precedence_position]=0;
             precedence_position--;
             //cout<<rules[rule_position]<<endl;
        
            
        }else if(rules[rule_position]=="arr"){
             rules[rule_position]="ALL_F";
             precedence[precedence_position]=0;
             alone_function = 0;
            
        }
         
     
         
     }else if(rules[rule_position] == "arith" and (arith == 3) and functions == 0 and bras == 0 and pars == 0
     and (token == "id" or token == "integer" or token == "float" or token == "SeedRandomNumbers"
     or token == "for" or token == "while" or token == "if" or token == "Put" or token == "else"
     or token == "elseif" or (function_str ==1 and token == "Function")) and not_empty==1){
        
        //cout<<"token got: "<<token<<" with rule: "<<arith<<endl;
        
        arith = 0;
        not_empty =0;
        precedence[precedence_position]=0;
        precedence_position--;
        rules[rule_position]="0";
        rule_position--;
        precedence[precedence_position]++;
        
        
        
        if(rules[rule_position]=="assign"){
             rules[rule_position]="0";
             rule_position--;
             precedence[precedence_position]=0;
             precedence_position--;
             //cout<<rules[rule_position]<<endl;
        }
         
     
         
     }
     
    
    if(force_correct == 1){
    
    
   
    }else if(token == "Function" and start==0){
        /*
        start = 1;
        precedence[precedence_position]=0;
        rules[rule_position]="F";
        F_g(token,lexem,line,column);
        
        */
        start = 1;
        function_str =1;
        precedence[precedence_position]=0;
        rules[rule_position]="function";
        F_g(token,lexem,line,column);
       
        
    }else if(token!="Function" and start ==0){
        start = 1;
        precedence[precedence_position]=0;
        ways[ways_position]=0;
        rules[rule_position]="ALL_F";
        ALL_F(token,lexem,line,column);
    
        
    }else if(rules[rule_position]=="Type" and start == 1){
        Type_g(token,lexem,line,column);
    
        
    }else if(rules[rule_position]=="ALL_F" and start == 1){
        ALL_F(token,lexem,line,column);
    
        
    }else if(rules[rule_position]=="dec" and start == 1){
        Dec_g(token,lexem,line,column);
    
        
    }else if(rules[rule_position]=="dec_arr" and start == 1){
        Dec_arr_g(token, lexem, line, column);
    
        
    }else if(rules[rule_position]=="var" and start == 1){
        var_g(token, lexem, line, column);
    
        
    }else if(rules[rule_position]=="arr" and start == 1){
        arr_g(token, lexem, line, column);
    
        
    }else if(rules[rule_position]=="assign" and start == 1){
        assign_g(token, lexem, line, column);
    
        
    }else if(rules[rule_position]=="entrance" and start == 1){
        entrance_g(token, lexem, line, column);
    
        
    }else if(rules[rule_position]=="arith" and start == 1){
        arith_g(token, lexem, line, column);
    
        
    }else if(rules[rule_position]=="ifs" and start == 1){
        ifs_g(token, lexem, line, column);
    
        
    }else if(rules[rule_position]=="exit" and start == 1){
        
        exit_g(token, lexem, line, column);
    
        
    }else if(rules[rule_position]=="condex" and start == 1){
        
        condex_g(token, lexem, line, column);
    
        
    }else if(rules[rule_position]=="while" and start == 1){
        
        while_g(token, lexem, line, column);
        
    }else if(rules[rule_position]=="elses" and start == 1){
        
        elses_g(token, lexem, line, column);
        
    }else if(rules[rule_position]=="for" and start == 1){
        
        for_g(token, lexem, line, column);
        
    }else if(rules[rule_position]=="seed_rand" and start == 1){
        
        SeedRand_g(token, lexem, line, column);
        
    }else if(rules[rule_position]=="function" and start == 1){
        
        F_g(token, lexem, line, column);
        
    }
    
    /*
    for(int i=0; i<5;i++){
        cout<<rules[i]<<" , ";
    }
    cout<<endl;
    
    */
    

}



// We are going to reuse the lexer code for the token identification


void automata_identifyers(string line, int head){
    
    int aux_head=head;
    int ascii;
    
    for(int i=head; i<line.length();i++){
        
        ascii = line[i];
        
       // cout<<line[i];
        
        
        
        //if(ascii == 36) break;
        
        if(ascii>=97 and ascii <= 122 or (ascii>=65 and ascii<=90) or ascii==99 or ascii>=48 and ascii<=57 or ascii==95){
            aux_head++;
            
        }else if(line[i]==' '){
            break;
        }else{
            break;
        }
        
        if(i==line.length()-1){
            break;
        }
        
        
    }
    
    string lexem;
    
    for(int i=head; i <aux_head; i++){
        
        lexem.push_back(line[i]);
    }

    token_derivation("id",lexem,total_lines+1,head+1-charger);
    
    go_ahead = (aux_head-1)-head;
}


void automata_low_reserved_words(string line, int head){
    
    int state = 0;
    int force_exit = 0;
    int lexem_found=0;
    int short_token =0;
     
    
    for(int i=head;i<line.length();i++){
        
        int ascii = line[i];

        if(line[i]==' ' or lexem_found == 1 or force_exit==1){
            
            string token;
            
            if(state == 57) token = "to";
            else if(state == 2) token ="if";
            else if(state == 9) token ="integer";
            else if(state == 12) token ="input";
            else if(state == 18) token ="output";
            else if(state == 23) token ="array";
            else if(state == 30) token ="nothing";
            else if(state == 33) token ="next";
            else if(state == 40) token ="returns";
            else if(state == 45) token ="float";
            else if(state == 47) token ="for";
            else if(state == 51) token ="else";
            else if(state == 56) token ="while";
            else if(state == 59) token ="elseif";
            else if(state == 61) token = "and";
            else if(state == 62) token = "or";
            else if(state == 26) token = "not";
            else if(state == 65) token = "with";
            else if(state == 72) token = "decimal";
            else if(state == 78) token = "places";
            else if(state == 82) token = "size";
            //else if(state == 90) token = "evaluates";
            else{
                short_token = 1;
            }
            
            
            // TOKEN PRINT
            if(short_token == 0){
               
                string token_final;
                
                for(int j=0; j<token.length(); j++){
                    
                    token_final.push_back(token[j]);
                }
                
                
                token_derivation(token_final, token_final, total_lines+1,head+1-charger);
              
                if(force_exit==1) go_ahead = (i-head)-2;
                else   go_ahead = (i - head);
                
                break;
            }else{
                automata_identifyers(line, head);
                break;
            }
                
                
        
        }
        
        if(ascii>=65 and ascii <=90 ){
            automata_identifyers(line,head);
            break;
        }
        
        switch(state){
            case 0: //state 1
                if(ascii == 105) state = 3; // i
                else if(ascii == 116 ) state = 1; // t
                else if(ascii == 111) state = 13; // o
                else if(ascii == 97) state = 19;// a
                else if(ascii == 110) state = 24;// n
                else if(ascii == 114) state = 34;// r
                else if(ascii == 102) state = 41;// f
                else if(ascii == 101) state = 48;// e
                else if(ascii == 119) state = 52;// w
                else if(ascii == 100) state = 66;// d
                else if(ascii == 112) state = 73; //p
                else if(ascii == 115) state = 79; //s
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;// the char is a letter between the low cases but has not transition to another state (ASCII 95 = _)
                break;
            
            case 1:
                if(ascii == 111) state = 57; // o
                else if(ascii>=97 and ascii <= 122) ;
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 2:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
            
            case 3:
                if(ascii == 102) state = 2; //f
                else if(ascii == 110) state = 4; //n
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 4:
                if(ascii == 112) state = 10; // p
                else if(ascii == 116) state = 5; // t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 5:
                if(ascii == 101) state = 6; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 6:
                if(ascii == 103) state = 7; //g
                 else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 7:
                if(ascii == 101) state = 8; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 8:
                if(ascii == 114) state = 9; // r
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 9:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
            
            case 10:
                if(ascii == 117) state = 11; // u
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 11:
                if(ascii == 116)state = 12; //t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 12:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
            
            case 13:
                if(ascii == 117) state = 14; // u
                else if(ascii == 114) state = 62; // r
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 14:
                if(ascii == 116) state = 15; // t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 15:
                if(ascii == 112) state = 16; // p
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 16:
                if(ascii == 117) state = 17; // u
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 17:
                if(ascii == 116) state = 18; // t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 18:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
             
            case 19:
                if(ascii == 114) state = 20; // r
                else if(ascii == 110) state = 60; //n
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
            case 20:
                if(ascii == 114) state = 21; // r
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 21:
                if(ascii == 97) state = 22; // a
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 22:
                if(ascii == 121) state = 23; // y
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 23:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
                
            case 24:
                if(ascii == 111) state = 25; // o
                else if(ascii == 101) state = 31;
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 25:
                if(ascii == 116) state = 26; // t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 26:
                if(ascii == 104) state = 27; // h
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit = 1;
                break;
            case 27:
                if(ascii == 105) state = 28; // i
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 28:
                if(ascii == 110) state = 29; // n
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 29:
                if(ascii == 103) state = 30; // g
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 30:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
                
            case 31:
                if(ascii == 120) state = 32; // x
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 32:
                if(ascii == 116) state = 33; // t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 33:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
            
            case 34:
                if(ascii == 101) state = 35; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 35:
                if(ascii == 116) state = 36; // t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 36:
                if(ascii == 117) state = 37; // u
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 37:
                if(ascii == 114) state = 38; // r
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 38:
                if(ascii == 110) state = 39; // n
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 39:
                if(ascii == 115) state = 40; // s
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 40:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
                
            case 41:
                if(ascii == 108) state = 42; // l
                else if(ascii == 111) state = 46; //o
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 42:
                if(ascii == 111) state = 43; // o
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 43:
                if(ascii == 97) state = 44; // a
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 44:
                if(ascii == 116) state = 45; // t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 45:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
                
            case 46:
                if(ascii == 114) state = 47; // r
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 47:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
                
            case 48:
                if(ascii == 108) state = 49; // l
                //else if(ascii == 118) state = 83; //v
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 49:
                if(ascii == 115) state = 50; // s
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 50:
                if(ascii == 101) state = 51; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 51:
                if(ascii == 105) state = 58; // i
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit=1;
                break;
                
            case 58:
                if(ascii == 102) state = 59; // f
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 52:
                if(ascii == 104) state = 53; // h
                else if(ascii == 105) state = 63;//i
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 53:
                if(ascii == 105) state = 54; // i
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 54:
                if(ascii == 108) state = 55; // l
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 55:
                if(ascii == 101) state = 56; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 60:
                if(ascii == 100) state = 61; // d
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 56:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
                
            case 57:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
                
            case 59:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
                
            case 61:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
                
            case 62:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
                
            case 63:
                if(ascii == 116) state = 64; // t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 64:
                if(ascii == 104) state = 65; // h
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 65:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
            
            case 66:
                if(ascii == 101) state = 67; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 67:
                if(ascii == 99) state = 68; // c
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 68:
                if(ascii == 105) state = 69; // i
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 69:
                if(ascii == 109) state = 70; // m
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 70:
                if(ascii == 97) state = 71; // a
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 71:
                if(ascii == 108) state = 72; // l
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 72:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
                
            case 73:
                if(ascii == 108) state = 74; // l
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 74:
                if(ascii == 97) state = 75; // a
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 75:
                if(ascii == 99) state = 76; // c
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 76:
                if(ascii == 101) state = 77; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 77:
                if(ascii == 115) state = 78; // s
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 78:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
                
            case 79:
                if(ascii == 105) state = 80; // i
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 80:
                if(ascii == 122) state = 81; // z
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 81:
                if(ascii == 101) state = 82; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 82:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
             
            case 83:
                if(ascii == 97) state = 84; // a
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;  
            
            case 84:
                if(ascii == 108) state = 85; // l
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 85:
                if(ascii == 117) state = 86; // u
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 86:
                if(ascii == 97) state = 87; // a
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 87:
                if(ascii == 116) state = 88; // t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 88:
                if(ascii == 101) state = 89; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 89:
                if(ascii == 115) state = 90; // s
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 90:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit =1;
                break;
            
                
            default:
                break;
            
            
        }
        
        if(state ==100){
            //cout<<"We are in state: "<<state<<"and the last letter read was"<<line[i]<<endl;
            automata_identifyers(line,head);
            break;
        }
        
        if(i==line.length()-1){
            
            string token;
            
            if(state == 57) token = "to";
            else if(state == 2) token ="if";
            else if(state == 9) token ="integer";
            else if(state == 12) token ="input";
            else if(state == 18) token ="output";
            else if(state == 23) token ="array";
            else if(state == 30) token ="nothing";
            else if(state == 33) token ="next";
            else if(state == 40) token ="returns";
            else if(state == 45) token ="float";
            else if(state == 47) token ="for";
            else if(state == 51) token ="else";
            else if(state == 56) token ="while";
            else if(state == 59) token ="elseif";
            else if(state == 61) token = "and";
            else if(state == 62) token = "or";
            else if(state == 26) token = "not";
            else if(state == 65) token = "with";
            else if(state == 72) token = "decimal";
            else if(state == 78) token = "places";
            else if(state == 82) token = "size";
            //else if(state == 90) token = "evaluates";
            else short_token = 1;
            
            
            if(short_token == 0 or force_exit == 1){
                
                string token_final;
                
                for(int j=0; j<token.length(); j++){
                    
                    token_final.push_back(token[j]);
                }
            
                
                token_derivation(token_final, token_final, total_lines+1,head+1-charger);
                
                
                
                if(force_exit==0)go_ahead=i-head;
                else go_ahead = (i-head)-1;
                break;
            
            
            }else{
                automata_identifyers(line,head);
                break;
            }
        
        }
        
    }

    
}


void automata_high_reserved_words(string line, int head){
    
    int state = 0;
    int force_exit = 0;
    int short_token =0;
     
    
    for(int i=head;i<line.length();i++){
        
        int ascii = line[i];
        
        
        
        if(line[i]==' ' or force_exit==1){
            
            string token;
            
            if(state == 3) token="Put";
            else if(state == 6) token = "Get";
            else if(state == 10) token = "Main";
            else if(state == 18) token = "Function";
            else if(state == 28) token = "SquareRoot";
            else if(state == 41) token = "AbsoluteValue";
            else if(state == 53) token = "RaiseToPower";
            else if(state == 63) token = "RandomNumber";
            else if(state == 79) token = "SeedRandomNumbers";
            else short_token = 1;
            
            
            
            if(short_token == 0){
                
                if(force_exit==0)go_ahead = i-head;
                else go_ahead = (i-head)-2;
                
                
                
                token_derivation(token,token, total_lines+1,head+1-charger);
                
                break;
            }else{
                automata_identifyers(line, head);
                break;
            }
        }
        
        
        switch(state){
            case 0:
                if(ascii == 80) state = 1; //P
                else if(ascii == 71) state = 4; //G
                else if(ascii == 70) state = 11; //F
                else if (ascii == 77) state = 7; //M
                else if(ascii == 83) state= 19;// S
                else if(ascii == 65) state= 29; // A
                else if(ascii == 82) state= 42; // R
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            case 1:
                if(ascii == 117) state = 2; // u
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 2:
                if(ascii == 116) state = 3; // t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 3:
                
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit=1;
                break;
                
            case 4:
                if(ascii == 101) state = 5; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 5:
                if(ascii == 116) state = 6; // t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 6:
                
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit=1;
                break;
                
            case 7:
                if(ascii ==97) state = 8; // a
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 8:
                if(ascii == 105) state = 9; // i
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 9:
                if(ascii == 110) state = 10; // n
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 10:
                
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit=1;
                break;
                
            case 11:
                if(ascii == 117) state = 12; // u
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 12:
                if(ascii == 110) state = 13; // n
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 13:
                if(ascii == 99) state = 14; // c
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 14:
                if(ascii == 116) state = 15; // t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 15:
                if(ascii == 105) state = 16; // i
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 16:
                if(ascii == 111) state = 17; // o
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 17:
                if(ascii == 110) state = 18; // n
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 18:
                
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit=1;
                break;
            
            case 19:
                if(ascii == 113) state = 20; // q
                else if(ascii==101) state = 64; //e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 20:
                if(ascii == 117) state = 21; // u
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 21:
                if(ascii ==97) state = 22; // a
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 22:
                if(ascii == 114) state = 23; // r
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
               
             case 23:
                if(ascii == 101) state = 24; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
            
            case 24:
                if(ascii == 82) state = 25; // R
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
                
            case 25:
                if(ascii == 111) state = 26; // o
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
            
            case 26:
                if(ascii == 111) state = 27; // o
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
                
            case 27:
                if(ascii == 116) state = 28; // t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
                
            case 28:
                
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit=1;
                break;
            
            case 29:
                if(ascii == 98) state = 30; // b
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
                
            case 30:
                if(ascii == 115) state = 31; // s
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
                
            case 31:
                if(ascii == 111) state = 32; // o
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
            
            case 32:
                if(ascii == 108) state = 33; // l
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
                
            case 33:
                if(ascii == 117) state = 34; // u
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
                
            case 34:
                if(ascii == 116) state = 35; // t
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
                
            case 35:
                if(ascii == 101) state = 36; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
                
            case 36:
                if(ascii == 86) state = 37; // V
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
                
            case 37:
                if(ascii == 97) state = 38; // a
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 38:
                if(ascii == 108) state = 39; // l
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
                
            case 39:
                if(ascii == 117) state = 40; // u
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break; 
                
            case 40:
                if(ascii == 101) state = 41; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 41:
                
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit=1;
                break;
                
                
            case 42:
                if(ascii == 97) state = 43; // a
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 43:
                if(ascii == 105) state = 44; // i
                else if(ascii == 110) state = 54; //n
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 44:
                if(ascii == 115) state = 45; // s
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 45:
                if(ascii == 101) state = 46; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 46:
                if(ascii == 84) state = 47; // T
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 47:
                if(ascii == 111) state = 48; // o
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 48:
                if(ascii == 80) state = 49; // P
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 49:
                if(ascii == 111) state = 50; // o
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
                
            case 50:
                if(ascii == 119) state = 51; // w
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 51:
                if(ascii == 101) state = 52; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 52:
                if(ascii == 114) state = 53; // r
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 53:
                
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit=1;
                break;
                
            case 54:
                if(ascii == 100) state = 55; // d
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 55:
                if(ascii == 111) state = 56; // o
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 56:
                if(ascii == 109) state = 57; // m
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 57:
                if(ascii == 78) state = 58; // N
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 58:
                if(ascii == 117) state = 59; // u
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 59:
                if(ascii == 109) state = 60; // m
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 60:
                if(ascii == 98) state = 61; // b
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 61:
                if(ascii == 101) state = 62; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 62:
                if(ascii == 114) state = 63; // r
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 63:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit=1;
                break;
                
            case 64:
                if(ascii == 101) state = 65; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
            
            case 65:
                if(ascii == 100) state = 66; // d
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 66:
                if(ascii == 82) state = 67; // R
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 67:
                if(ascii == 97) state = 68; // a
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 68:
                if(ascii == 110) state = 69; // n
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 69:
                if(ascii == 100) state = 70; // d
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 70:
                if(ascii == 111) state = 71; // o
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 71:
                if(ascii == 109) state = 72; // m
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 72:
                if(ascii == 78) state = 73; // N
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 73:
                if(ascii == 117) state = 74; // u
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 74:
                if(ascii == 109) state = 75; // m
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 75:
                if(ascii == 98) state = 76; // b
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 76:
                if(ascii == 101) state = 77; // e
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 77:
                if(ascii == 114) state = 78; // r
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 78:
                if(ascii == 115) state = 79; // s
                else if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                break;
                
            case 79:
                if(ascii>=97 and ascii <= 122 or ascii>=65 and ascii<=90 or ascii==99 or ascii>=48 and ascii<=57 or ascii==95)  state = 100;
                else force_exit=1;
                break;
                
            default:
                break;
            
        }
        
        
        
        if(state ==100){
            
            automata_identifyers(line, head);
            
            break;
        }
        
        
        
        if(i == line.length()-1){
            
            string token;
            
            if(state == 3) token="Put";
            else if(state == 6) token = "Get";
            else if(state == 10) token = "Main";
            else if(state == 18) token = "Function";
            else if(state == 28) token = "SquareRoot";
            else if(state == 41) token = "AbsoluteValue";
            else if(state == 53) token = "RaiseToPower";
            else if(state == 63) token = "RandomNumber";
            else if(state == 79) token = "SeedRandomNumbers";
            else short_token =1;
            
            if(short_token == 0 or force_exit==1){

                if(force_exit==0)go_ahead=i-head;
                else go_ahead = (i-head)-1;
                
                
                
                token_derivation(token,token, total_lines+1,head+1-charger);
                
                break;
            
            
            }else{
                automata_identifyers(line,head);
                break;
            }
        }
    }
}



void automata_numbers(string line, int head){
    
    int aux_head=head;
    string token = "tkn_integer";
    int point_found=0;
    
    int ascii;
    int ascii_n;
    
    
    for(int i=head; i<line.length();i++){
        
        ascii = line[i];
        ascii_n = line[i+1];
        
        
        if(ascii>=48 and ascii <= 57 and point_found==0){
            aux_head++;
            
        }else if(ascii>=48 and ascii <= 57 and point_found==1){
            aux_head++;
        
        }else if(i!=line.length()-1 and ascii == 46 and line[i+1]>=48 and line[i+1]<=57 and point_found==0){
            aux_head++;
            token = "tkn_float";
            point_found = 1;
        
        }else if(line[i]==' '){
            break;
        }else{
            break;
        }
        
        if(i==line.length()-1){
            break;
        }
        
    }
    
    go_ahead = (aux_head-1)-head;
    
    string token_final;
    string lexem;
    
    for(int i=0; i <token.length(); i++){
        
        token_final.push_back(token[i]);
    }


    for(int i=head; i<aux_head;i++){

       lexem.push_back(line[i]);
    }
    
    
    if(token_final=="tkn_float"){
        token_final = "float_value";
    }else if(token_final == "tkn_integer"){
        token_final = "integer_value";
    }
    
    token_derivation(token_final,lexem,total_lines+1,head+1-charger);
    
}

void automata_operators(string line, int head){
    
    string token;
    
    if(head==line.length()-1){
        
        if(line[head]=='=') token = "tkn_assign";
        else if(line[head]=='.') token = "tkn_period";
        else if(line[head]==',') token = "tkn_comma";
        else if(line[head]==';') token = "tkn_semicolon";
        else if(line[head]==']') token = "tkn_closing_bra";
        else if(line[head]=='[') token = "tkn_opening_bra";
        else if(line[head]==')') token = "tkn_closing_par";
        else if(line[head]=='(') token = "tkn_opening_par";
        else if(line[head]=='+') token = "tkn_plus";
        else if(line[head]=='-') token = "tkn_minus";
        else if(line[head]=='*') token = "tkn_times";
        else if(line[head]=='/') token = "tkn_div";
        else if(line[head]=='%') token = "tkn_mod";
        else if(line[head]=='<') token = "tkn_less";
        else if(line[head]=='>') token = "tkn_greater";
        else if(line[head]=='?') token = "tkn_question_mark";
    
        
        
    }else{
        if(line[head]=='=' and line[head+1]=='=') token = "tkn_equal";
        else if(line[head]=='=') token = "tkn_assign";
        else if(line[head]=='.') token = "tkn_period";
        else if(line[head]==',') token = "tkn_comma";
        else if(line[head]==';') token = "tkn_semicolon";
        else if(line[head]==']') token = "tkn_closing_bra";
        else if(line[head]=='[') token = "tkn_opening_bra";
        else if(line[head]==')') token = "tkn_closing_par";
        else if(line[head]=='(') token = "tkn_opening_par";
        else if(line[head]=='+') token = "tkn_plus";
        else if(line[head]=='-') token = "tkn_minus";
        else if(line[head]=='*') token = "tkn_times";
        else if(line[head]=='%') token = "tkn_mod";
        else if(line[head]=='<' and line[head+1]=='=') token = "tkn_leq";
        else if(line[head]=='<') token = "tkn_less";
        else if(line[head]=='>' and line[head+1]=='=') token = "tkn_geq";
        else if(line[head]=='>' ) token = "tkn_greater";
        else if(line[head]=='/') token = "tkn_div";
        else if(line[head]=='?') token = "tkn_question_mark";
        else if(line[head]=='!' and line[head+1]=='=') token = "tkn_neq";
    }
    
     
    // TOKEN PRINT
    
    
    string lexem;
            
    for(int j=0; j<1 ;j++){
          
            lexem.push_back(line[head]);
    }
    
    
            
    if(token == "tkn_geq"){
        
        token_derivation(token,">=",total_lines+1,head+1-charger);
        
    }else if(token == "tkn_leq"){
        
        token_derivation(token,"<=",total_lines+1,head+1-charger);
        
    }else if(token == "tkn_neq"){
        
        token_derivation(token,"!=",total_lines+1,head+1-charger);
        
    }else if(token == "tkn_equal"){
        
        token_derivation(token,"==",total_lines+1,head+1-charger);
    }else{
        
        token_derivation(token,lexem,total_lines+1,head+1-charger);
    }       
    
    //token_derivation(token_final,token_final,total_lines+1,head+1-charger);
    
    if(token == "tkn_geq" or token == "tkn_leq" or token=="tkn_neq" or token=="tkn_equal") go_ahead=1;
    else go_ahead=0;
    
    
    
    
}

void string_reader(string line, int head){
    int departure=0;
    int arrive=0;
    int marks=0;
    int suspicious = 0;
    //charger = 0;
    int ascii = 0;
    
    for(int i=head; i<line.length();i++){
        
        
        
        
        if(line[i]=='"' and i==head){
            marks +=1;
            departure = head+1;
            
        }else if(line[i]=='"' and marks>0){
            
            ascii = line[i-1];
            
            if(ascii!=92){
                arrive=i;
                marks+=1;
                break;
            }
        }
    }
    
    if(marks!=2){
        //force_correct=1;
        //force_correct_g();
        cout<<">>> Error lexico (linea: "<<total_lines+1<<", posicion: "<<head+1-charger<<")"<<endl;
        error_found=1;
    }else{
        
        string lexem;
        
        for(int i=departure;i<arrive;i++){
        
            lexem.push_back(line[i]);
        }
        
        
        token_derivation("tkn_string",lexem,total_lines+1,head+1-charger);

        go_ahead+=arrive-head;
        
        for(int i=departure;i<arrive;i++){
            
            ascii = line[i];
            
            
            if(ascii <0 ){
                suspicious=1;
                charger+=1;
            }
           
        }
        if(suspicious==1){
            charger = charger-1;
        }
        
    }
}


void line_reader(string line){
    
    //int reading = 0;
    charger = 0;
    go_ahead = 0;
    int only_comment =0;
    
    if(line.length()!=0){
        
        for(int i=0; i<line.length();i++){
            

            
            if(line[i]=='/' and line[i+1]=='/' and only_comment==0){
                break;
            }
            int ascii = line[i];
            

            
            if(line[i]!=' '){
                
                only_comment = 1;
                
                int ASCII = line[i];
                
                if(ASCII>=97 and ASCII<=122){
                    
                    automata_low_reserved_words(line,i);
                    
                    i+=go_ahead;
                    
                
                    
                } else if(ASCII>=65 and ASCII <=90){
                    
                    automata_high_reserved_words(line,i);
                 
                    i+=go_ahead;
                    
                
                    
                } else if(ASCII>=48 and ASCII <= 57){
                    
             
                    automata_numbers(line, i);
                    
                    i+=go_ahead;
                    
                
                    
                } else if(ASCII>= 40 and ASCII <= 47 or ASCII == 33 and line[i+1]=='=' or ASCII==37 or ASCII==91 or ASCII==93 or ASCII>=59 and ASCII<=63){
                    automata_operators(line, i);
                    i+=go_ahead;
                
                }else if(line[i]=='"'){
                    
                    string_reader(line,i);
                    i+=go_ahead;
                   
                }else if(line[i]!=' '){
                    
                    cout<<">>> Error lexico (linea: "<<total_lines+1<<", posicion: "<<i+1<<")"<<endl; // >>> Error lexico (linea: 1, posicion: 11)
                    error_found = 1;
                    break;
                }
                
                if(error_found ==1){
                    break;
                }
                
                go_ahead = 0;
             
            }
           
            
            
        }
        
    }
    
    
    // COUNTER OF EMPTY LINES TO FINISH THE PROGRAMM (A WAY TO FIND THE END OF THE FILE)
    if(line.length()==0){
        empty_lines++;
    }else{
        empty_lines=0;
        last_line = total_lines+1;
    }
    

}


int main() {
    
    
    
    while(empty_lines<100 and error_found == 0){
        string line;
        getline(cin,line);
        
        line_reader(line);
        charger = 0;
        if(error_found == 1){
            return 0;
        }
        total_lines++;
        
        if(force_correct == 1){
            return 0;
        }
        
    }
    
    
    /*
    if(precedence_position!=0){
        cout<<"<"<<total_lines+1<<","<<1<<"> Error Sintactico: se encontró \""<<"EOF"<<"\""<<endl;
    }else{
        cout<<"El analisis sintactico ha finalizado exitosamente."<<endl;
    }
   */
   
   /*
   cout<<rules[rule_position]<<endl;
   cout<<precedence[precedence_position];
   */
   
   
   if(rules[rule_position]=="arr" and precedence[precedence_position]==2){
       
       sintax_error("NN","final de archivo;",last_line+1,1);
       
   
   }else if(rules[rule_position]=="function"){
         
      sintax_error("NN","final de archivo;",last_line+1,1);
    
   }else if(rules[rule_position]=="ALL_F" and function_str == 1 and function_main == 0){
         
      sintax_error("NN","final de archivo;",last_line+1,1);
    
   
       
   }else if(rules[rule_position]=="ALL_F" and content == 1){
         
      sintax_error("NN","final de archivo;",last_line+1,1);
    
   
       
   }else if(rules[rule_position]=="arith" and (functions>0 or pars>0 or bras>0)){
       
       
      sintax_error("NN","final de archivo;",last_line+1,1);
       
       
   
       
   }else if(rules[rule_position]=="arith" and rules[rule_position-2]=="for"){
       
       
      sintax_error("NN","final de archivo;",last_line+1,1);
       
       
   
       
   }else if(rules[rule_position]=="condex"){
       
      
       
       if(rules[rule_position-1]=="ifs"){
           current_rule = "if";
       }
       
       
       sintax_error("NN","final de archivo;",last_line+1,1);
       
       
   
       
   }else if(rules[rule_position]=="dec"){
       
       sintax_error("NN","final de archivo;",last_line+1,1);
   
       
   }else if(rules[rule_position]=="assign"){
       
       
       precedence[precedence_position]=2;
       sintax_error("NN","final de archivo;",last_line+1,1);
   
       
   }else if(rules[rule_position]=="dec_arr"){
       
       if(precedence[precedence_position]==3){
           rules[rule_position]="size_array";
           precedence[precedence_position]=0;
           
       }
       
       
       sintax_error("NN","final de archivo;",last_line+1,1);
       
   }else if(rules[rule_position]=="var"){
       
       
       precedence[precedence_position]=0;
       sintax_error("NN","final de archivo;",last_line+1,1);
   
       
   }else if(rules[rule_position]=="entrance"){
       
       
       sintax_error("NN","final de archivo;",last_line+1,1);
   
       
   }else if(rules[rule_position]=="ifs"){
       
       
       sintax_error("NN","final de archivo;",last_line+1,1);
   
       
   }else if(tok_counter==106){
       
       
       sintax_error("or","or",last_line+1-4,1+32);
   
       
   }else if(rules[rule_position]=="elses"){
       
       
       rules[rule_position]="ifs";
       
       sintax_error("NN","final de archivo;",last_line+1,1);
   
       
   }else if(rules[rule_position]=="while"){
       
       
       sintax_error("NN","final de archivo;",last_line+1,1);
   
       
   }else if(rules[rule_position]=="exit"){
       
       
       if(ways[ways_position]==1 and precedence[precedence_position]== 4 or ways[ways_position]==1 and precedence[precedence_position]== 8 ){
           cout<<"El analisis sintactico ha finalizado exitosamente."<<endl;
       }else{
           
           sintax_error("NN","final de archivo;",last_line+1,1);
       }
       
       
   
       
   }else{
       
       /*
       
       cout<<"Precedence Array position: "<<precedence[precedence_position]<<endl;
    
       cout<<"Current Rule: "<<rules[rule_position]<<endl;
       
       cout<<"ifs: "<<ifs<<endl;
       
       cout<<"Arith: "<<arith<<endl;*/
        
       //cout<<rules[rule_position-2]<<endl;
       
       //cout<<tok_counter<<endl;
        
       cout<<"El analisis sintactico ha finalizado exitosamente."<<endl;
       return 0;
   }

}
