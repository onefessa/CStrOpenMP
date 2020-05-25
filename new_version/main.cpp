#include <iostream>
#include <fstream>
#include <stdio.h>
#include <memory>
#include <string>
#include <vector>
#include<chrono>
#include <map>
#include "omp.h"
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
        BigStrTest("BigStr.txt");
    auto t_bstr = chrono::system_clock::now();
    int between = static_cast<int>( chrono::duration_cast<chrono::milliseconds>(t_bstr - start).count() );

    cout << "Addition BigStr runtime is "<< between << " ms\n\n";

    return 0;
}
