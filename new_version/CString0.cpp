#include "CString0.hpp"
#include <fstream>
#include<iostream>
#include <string.h>
#include<string>
#include<chrono>
#include "omp.h"
using namespace std;

const CString0 CString0::operator + (const CString &s){
    chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
    CString *tmp = new CString0;
    tmp->f_name  = f_name;
    tmp->len = len + s.len;

    string tmp_str;
    tmp_str.resize (tmp->len);

   // #pragma omp parallel
    {
    #pragma omp parallel for
    for (int i = 0; i < len; i++)//begin(str); i!= end(str); i++)
        tmp_str[i] = str[i];// + s.str;
    #pragma omp parallel for
    for (int i=0; i < s.len; i++)
        tmp_str[len+i] = s.str[i];
    }
    tmp->str = tmp_str;

    chrono::time_point<chrono::system_clock> end = chrono::system_clock::now();
        int elapsed_ms = static_cast<int>( chrono::duration_cast<chrono::milliseconds>(end - start).count() );
        cout << "Addition operator+ runtime1 is "<< elapsed_ms << " ms\n";

    return *tmp;
}
/*
CString0& CString0::operator = (const CString0 &s){
    str = s.str;
    return *this;
}*/
int CString0::output() {
    ofstream myfile(this->f_name, ios_base::app);
    if( !myfile.is_open() ) {
        cout<<"Can't open your file"<<this->f_name<<endl;
        return 1;
    }
    else {
        myfile<<str;
        myfile<<"\n\n";
        myfile.close();
    }
return 0;
}
CString0::~CString0(){
    //std::cout<<" ~0 ";
}

/*
void CString0::out(){
    cout<<str<<" ";
}
*/
