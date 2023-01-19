#include<iostream>
#include"config.h"
#include<fstream>

using namespace std;
void config()
{
	// file pointer
	fstream fout;

	// opens an existing csv file or creates a new file.
	fout.open("config.csv", ios::out | ios::app);

	string folder, extension, extension1,extension2,extension3,extension4, date;

	folder = "keyce_drive";
	extension = ".mp4";
	extension1 = ".pptx";
	extension2 = ".pdf";
	extension3 = ".png";
	extension4 = ".jpg";

	fout << "folder" << ";"
			<< folder << "\n"
			<< "extension" << ";"
			<< extension << "\n"
			<< "extension" << ";"
			<< extension1 << "\n"
			<< "extension" << ";"
			<< extension2 << "\n"
			<< "extension" << ";"
			<< extension3 << "\n"
			<< "extension" << ";"
			<< extension4 << "\n"
			<< "date" << ";"
			<< date << "\n";


}
