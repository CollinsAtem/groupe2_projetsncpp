//#include <windows.h>
//#include <string>
//
//
//string allDrive
//wait(){
//    char usbLetter = getUsb();
//
//    while(true){
//        usbLetter = getUsb();
//        if(usbLetter != '0'){
//            printf("%c \n ", usbLetter());
//            sleep(1000);
//        }
//    }
//    return 0;
//}
//
//getUsb(){
//    char usb = '0';
//    char sizeLocalDrive[MAX_PATH];
//    DWORD dResult = GetLogicalDriveStrings(MAX_PATH, sizeLocalDrive);
//    string currentUsb = "";
//    for(int i = 0; i < dResult; i++){
//        if(sizeLocalDrive[i] > 64 && sizeLocalDrive[i] < 90){
//            currentDrive.append(1, sizeLocalDrive[i]);
//            if(allDrive.find(sizeLocalDrive[i]) > 100){
//                drive = sizeLocalDrive[i];
//            }
//        }
//    }
//    allDrive = currentDrive;
//
//    return drive;
//}
//
//
