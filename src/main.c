/*Copyright 2025
Tyler McGurrin*/

#include <stdio.h>
#include <string.h>

#define VERSION "RD-00001"
#define AUTHOR "Xircon"
#define USAGE "Xircon's Package Manager (XPM):\nVersion               [-v]\nHelp                  [-h]\nInstall               [-i]"

int main(int argC,char *argV[]) {
	if (argC > 1) {
	    for (int i = 1; i < argC; i++) {
	        if (strcmp(argV[i], "-v") == 0) {
	            printf("Xircon's Pacage Manager (XPM) %s\nMade By: %s\n", VERSION, AUTHOR);
	            return true;
	        } else if (strcmp(argV[i], "-h") == 0) {
	            printf("%s\n",USAGE);
	            return true;
	        } else {
	            printf("Unknown option: %s\n", argV[i]);
	            return false;
	        }
	    }
    } else {
        printf("%s\n",USAGE);
	    return true;
    }
}