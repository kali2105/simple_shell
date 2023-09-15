#include "main.h"

char *location(char *command){
    char *path, *path_c,*token,*file_path;
    int clength,dlength;
    struct stat buff;

    path = getenv("PATH");

    if(path){
    	/* copy the path str */	    
    	path_c = strdup(path);
    	/* get the length of the command */
    	clength = strlen(command);
    	/* break down the path */
    	token = strtok(path_c, ":");
    	while(token != NULL){
    	        /* get the len of the directory */
    		dlength = strlen(token);
		/* allocate the memory */
                file_path = malloc(clength + dlength + 2);
		/* copy the directory path and concatenate the command to it */
                strcpy(file_path, token);
                strcat(file_path, "/");
                strcat(file_path, command);
                strcat(file_path, "\0");
               /* test the path exist or no */
               if (stat(path, &buff) == 0){
                  /* return value of 0 means success implying that the file_path is valid*/
                  /* free up allocated memory before returning your file_path */
                  free(path_c);

                    return (file_path);
               }
	       else{
                   /* free the path memory */
		   free(file_path);
	           token = strtok(NULL, ":"); 
	       }	   

           }

           /* free the path_c */
	   free(path_c);

	   /* test if the path exist */
	   if (stat(command, &buff) == 0)
           {
		   return (command);
           }
	   return (NULL);
	 }

    return (NULL);
   }

