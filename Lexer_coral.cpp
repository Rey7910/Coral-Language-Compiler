/*
***
 REY 7910                         *
 CORAL LEXER                      *  
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


using namespace std;


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
    
    cout<<"<id,";
    
    for(int i=head; i <aux_head; i++){
        cout<<line[i];
    }
    
    go_ahead = (aux_head-1)-head;
    cout<<","<<total_lines+1<<","<<head+1-charger<<">"<<endl;
}


void automata_low_reserved_words(string line, int head){
    
    int state = 0;
    int force_exit = 0;
    int lexem_found=0;
    int short_token =0;
     
    
    for(int i=head;i<line.length();i++){
        
        int ascii = line[i];
        //cout<<"We are in state: "<<state<<endl;
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
            else if(state == 90) token = "evaluates";
            else{
                short_token = 1;
            }
            
            
            // TOKEN PRINT
            if(short_token == 0){
                cout<<"<";
                
                for(int j=0; j<token.length(); j++){
                    cout<<token[j];
                }
                
                
                cout<<","<<total_lines+1<<","<<head+1-charger<<">"<<endl;
                
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
            else if(state == 90) token = "evaluates";
            else short_token = 1;
            
            
            // TOKEN PRINT
            
            if(short_token == 0 or force_exit == 1){
                cout<<"<";
                
                for(int j=0; j<token.length(); j++){
                    cout<<token[j];
                }
                
                
                cout<<","<<total_lines+1<<","<<head+1-charger<<">"<<endl;
                
                
                
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
        
        
        //cout<<"We are in state: "<<state<<endl;
        
        
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
                cout<<"<";
                
                for(int j=0; j<token.length(); j++){
                    cout<<token[j];
                }
                
                
                cout<<","<<total_lines+1<<","<<head+1-charger<<">"<<endl;
                
                
                if(force_exit==0)go_ahead = i-head;
                else go_ahead = (i-head)-2;
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
            //cout<<"We are in state: "<<state<<"and the last letter read was"<<line[i]<<endl;
            //cout<<"<id, algo,"<<total_lines+1<<","<<i+1<<">"<<endl;
            //cout<<"Estado 100"<<endl;
            
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
                cout<<"<";
                
                for(int j=0; j<token.length(); j++){
                    cout<<token[j];
                }
                
                
                cout<<","<<total_lines+1<<","<<head+1-charger<<">"<<endl;
                
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
    
    cout<<"<";
    
    for(int i=0; i <token.length(); i++){
        cout<<token[i];
    }
    cout<<",";
    
    for(int i=head; i<aux_head;i++){
        cout<<line[i];
    }
    cout<<","<<total_lines+1<<","<<head+1-charger<<">"<<endl;
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
    cout<<"<";
            
    for(int j=0; j<token.length(); j++){
            cout<<token[j];
    }
            
            
    cout<<","<<total_lines+1<<","<<head+1-charger<<">"<<endl;
    
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
        cout<<">>> Error lexico (linea: "<<total_lines+1<<", posicion: "<<head+1-charger<<")"<<endl;
        error_found=1;
    }else{
        
        cout<<"<tkn_str,";
        
        for(int i=departure;i<arrive;i++){
        
            cout<<line[i];
        }
        cout<<","<<total_lines+1<<","<<head+1-charger<<">"<<endl;
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
            
            //cout<<line[i]<<endl;
            
            if(line[i]=='/' and line[i+1]=='/' and only_comment==0){
                break;
            }
            int ascii = line[i];
            
            //cout<<ascii<<endl;
            
            if(line[i]!=' '){//reading == 0 and line[i]!=' '){
                
                only_comment = 1;
                
                int ASCII = line[i];
                
                if(ASCII>=97 and ASCII<=122){
                    
                    automata_low_reserved_words(line,i);
                    //cout<<"Go Ahead: "<<go_ahead<<endl;
                    i+=go_ahead;
                    
                
                    
                } else if(ASCII>=65 and ASCII <=90){
                    
                    automata_high_reserved_words(line,i);
                    //cout<<"Go Ahead: "<<go_ahead<<endl;
                    i+=go_ahead;
                    
                
                    
                } else if(ASCII>=48 and ASCII <= 57){
                    
                    //cout<<"Go Ahead: "<<go_ahead<<endl;
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

    }

}
