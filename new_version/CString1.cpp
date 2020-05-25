#include "CString1.hpp"
#include <fstream>
#include<iostream>
#include <string.h>
#include<string>
#include<chrono>
#include <omp.h>
using namespace std;

/*const CString1 CString1::operator + (const CString &s){
       // chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();

    CString *tmp = new CString1;
    tmp->f_name  = f_name;

//    #pragma omp parallel for //shared (s, tmp)
    tmp->str = str + s.str;
    tmp->len = len + s.len;

        //chrono::time_point<chrono::system_clock> end = chrono::system_clock::now();
        //int elapsed_ms = static_cast<int>( chrono::duration_cast<chrono::milliseconds>(end - start).count() );
        //cout << "Addition operator+ runtime1 is "<< elapsed_ms << " ms\n";

    return *tmp;
}*/

const CString1 CString1::operator + (const CString &s){
    //chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
    CString *tmp = new CString1;
    tmp->f_name  = f_name;
    tmp->len = len + s.len;

    string tmp_str;
    tmp_str.resize (tmp->len);

//    #pragma omp parallel
    {
    #pragma omp parallel for
    for (int i = 0; i < len; i++)//begin(str); i!= end(str); i++)
        tmp_str[i] = str[i];// + s.str;
    #pragma omp parallel for
    for (int i=0; i < s.len; i++)
        tmp_str[len+i] = s.str[i];
    }

    tmp->str = tmp_str;
    return *tmp;
}
int CString1::output() {
    ofstream myfile(this->f_name, ios_base::app);
    if( !myfile.is_open() ) {
        cout<<"Can't open your file"<<this->f_name<<endl;
        return 1;
    }
    else {
        for (auto iter = str.begin(); iter != str.end(); iter++){
            myfile << *iter << "\n";
        }
       // myfile<<str;
        myfile<<"\n";
        myfile.close();
    }
return 0;
}
CString1::~CString1(){
   // std::cout<<" ~1 ";
}
