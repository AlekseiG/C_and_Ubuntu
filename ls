#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main (int argc, char** argv) {
  FILE* f = fopen ("output.txt", "w");
	if (!strcmp (argv[1],"-ls")){
			if (argc == 2){
			 DIR *mydir = opendir("/");
			    if(mydir == NULL) {
			        perror("opendir");
			        fprintf(f,"fail\n");
			        return -1;
			    }
			    struct dirent *entry;
			    while (entry = readdir(mydir)) fprintf(f,"%s\n", entry->d_name);
			    closedir(mydir);
			}
			if (argc == 3){
				DIR *mydir = opendir(argv[2]);
					if(mydir == NULL) {
					       perror("opendir");
					       return -1;
					}
				struct dirent *entry;
				while (entry = readdir(mydir)) fprintf(f,"%s\n", entry->d_name);
				closedir(mydir);
			}

		}
	return 0;
}
