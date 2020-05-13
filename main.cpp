#include <iostream>
#include <fstream>
#include <stdio.h>
#include <memory>
#include <string>
#include <vector>
#include<chrono>
#include <map>
#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"

#include "Factory.hpp"
#include "FactoryH.hpp"
#include "FactoryV.hpp"

#include "functions.hpp"
#include "autotest.hpp"
//#pragma once
using namespace std;

int main(){
        chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
    autotest();
        chrono::time_point<chrono::system_clock> t_autotest = chrono::system_clock::now();
        int elapsed_ms1 = static_cast<int>( chrono::duration_cast<chrono::milliseconds>(t_autotest-start).count() );
    /*scan("t2.txt");
    chrono::time_point<chrono::system_clock> t_scan = chrono::system_clock::now();
    int elapsed_ms2 = static_cast<int>( chrono::duration_cast<chrono::milliseconds>(t_scan - t_autotest).count() );*/
    fun("t2.txt");
        chrono::time_point<chrono::system_clock> t_fun = chrono::system_clock::now();
        int elapsed_ms3 = static_cast<int>( chrono::duration_cast<chrono::milliseconds>(t_fun - t_autotest).count() );
    BigStrTest("BigStr.txt");
        auto t_bstr = chrono::system_clock::now();
        int between = static_cast<int>( chrono::duration_cast<chrono::milliseconds>(t_bstr - t_fun).count() );

int elapsed_ms = static_cast<int>( chrono::duration_cast<chrono::milliseconds>(t_bstr - start).count() );



    cout << "Addition autotest runtime is "<< elapsed_ms1 << " ms\n";
    //cout << "Addition scan runtime is "<< elapsed_ms2 << " ms\n";
    cout << "Addition fun runtime is "<< elapsed_ms3 << " ms\n";
    cout << "Addition BigStr runtime is "<< between << " ms\n";

    cout << "Addition ALL runtime is "<< elapsed_ms << " ms\n";

    return 0;
}
