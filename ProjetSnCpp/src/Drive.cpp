#include <iostream>
#include <windows.h>
#include <filesystem>
#include <fstream>
#include <string>
#include "Drive.h"

using namespace std;

Drive::Drive()
{

}

Drive::detect(){

}

Drive::~Drive()
{
    wait();
}

    string allDrives;

char Drive::getUsb(){
    char usb = '0';
    char sizeLocalDrive[MAX_PATH];
    DWORD dResult = GetLogicalDriveStrings(MAX_PATH, sizeLocalDrive);
    string currentUsb = "";
    for(int i = 0; i < dResult; i++){
        if(sizeLocalDrive[i] > 64 && sizeLocalDrive[i] < 90){
            currentUsb.append(1, sizeLocalDrive[i]);
            if(allDrives.find(sizeLocalDrive[i]) > 100){
                usb = sizeLocalDrive[i];
            }
        }
    }
    allDrives = currentUsb;

    return usb;
}

void Drive::wait(){
    char usbLetter = getUsb();

    while(true){
        usbLetter = getUsb();
        if(usbLetter != '0'){
            printf("%c\n ", usbLetter);
            sync(usbLetter);
            Sleep(1000);
        }
    }
}

void Drive::sync(char usb){
    string filename(1, usb);
    filename += ":\\keyce_drive";
    cout << filename;
    if(filesystem::is_directory(filename)){
        for(const auto & entry : filesystem::directory_iterator(filename)){
//            cout << entry.path() << endl;
            kCopy(entry.path().string(), entry.path().filename().string());
        }
    }
}

void Drive::kCopy(string file, string name){
    cout << file;
    //ofstream ofile ("C:\\Users\\user\\Desktop\\keyce_drive\\"+ name);
    ofstream ofile ("C:\\Users\\HP\\Desktop\\keyce_drive\\"+ name,std::ios_base::binary);
    ifstream sfile (file,std::ios_base::binary);
    char buffer[1025];
    while(sfile.read(buffer, sizeof(buffer))){
        ofile.write(buffer, sfile.gcount());
    }
//    ofile.write(buffer, sfile.gcount());

    ofile.close();
    sfile.close();
}
