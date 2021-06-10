#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main() {
    fstream fileObj;
    fileObj.open("datas.txt",  ios::in);

    if(fileObj.fail()) {
        cout<<" file not open"<<endl;
        return -1;
    }

    string fileLine;
    int lineTemp = 0;
    while(!fileObj.eof()){
        getline(fileObj , fileLine);
//        cout<< fileLine <<endl;
        if(fileLine.find("[**] [") != std::string::npos){
            lineTemp = 3;
//            cout<<"find"<<endl;
        }
        lineTemp--;
        if(lineTemp == 0){
            string blockData;
            size_t position =0;
            string delimiter = " ";
            int blockLineTemp = 2;
            cout<< fileLine <<endl;
            while ((position = fileLine.find(delimiter)) != std::string::npos){
                blockData = fileLine.substr(0 , position);
                blockLineTemp--;

                if(blockLineTemp == 0)
                    cout<<blockData<<endl;

                fileLine.erase(0 , position + delimiter.length());
            }
        }
    }

    cin.get();
    return 0;
}