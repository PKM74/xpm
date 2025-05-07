/*Copyright 2025
Tyler McGurrin*/

#include <stdio.h>
#include <string.h>

#define VERSION "RD-00001"
#define AUTHOR "Xircon"
#define USAGE "Xircon's Package Manager (XPM):\nVersion               [-v] - Displays Version Info\nHelp                  [-h] - Displays this List\nInstall               [-i] - Installs a Package (xpm -i package)"

int main(int argC,char *argV[]) {
	if (argC > 1) {
	    for (int i = 1; i < argC; i++) {
	        if (strcmp(argV[i], "-v") == 0) {
	            printf("Xircon's Pacage Manager (XPM) %s\nMade By: %s\n", VERSION, AUTHOR);
                return true;
	        } else if (strcmp(argV[i], "-h") == 0) {
	            printf("%s\n",USAGE);
	            return true;
	        } else if (strcmp(argV[1], "-i") == 0) {
                int n = 2;
                while (n < 256) {
                    if (argV[n] == NULL) return true;
                    int x = 1;
                    char *packages[255];
                    strcpy(argV[n], packages[x]);
                    printf("%s ",argV[n]);
                    n++;
                    x++;
                }
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

int install(char package) { // function that decompresses and installs packages

}