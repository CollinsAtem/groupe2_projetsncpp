#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "Config.h"

Config::Config()
{
    //ctor
}
///------------------------------FUNCTION TO READ FILE CSV----------------------------------
vector <string> Config::readFiles()
{

    vector <string> myFile;

    //----------------------------OPEN FILE IN LECTURE--------------------
	FILE* file = fopen("C:\\Users\\HP\\Desktop\\csv\\projetSn.csv", "r");

	if (!file)
	{
		printf("Could not open the file\n");

	}

	char content[1024];

	while (fgets(content, 1024, file))
	{
		char* v = strtok(content, ";");
		while (v)
		{
		    myFile.push_back(v);
			//printf("%s ", v);
			v = strtok(NULL, ";");
		}
		printf("\n");
	}

	fclose(file);

   return myFile;

}

Config::~Config()
{
    //dtor
}
