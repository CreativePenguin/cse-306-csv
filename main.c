#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
<<<<<<< HEAD
#include<ctype.h>

 #define MAX 100000
    char *item;
    char line[MAX];

int dash_f(FILE *fp){
    rewind(fp);
    fgets(line, MAX, fp);
    item = strtok(line, ",");
   
    int acc = 0;
    while(item != NULL)
    {
        item = strtok(NULL, ",");
        acc = acc + 1;
    }
    rewind(fp);
    return acc;
}

int dash_d(FILE *fp){
   rewind(fp);
   int acc = 0;
   while (feof(fp) != true)
    {
        fgets(line, MAX, fp);
        
        acc = acc + 1;
    }
  rewind(fp);
  return acc - 1;
  
}

/*
 * Stores array of header values into header variable
*/
=======

struct FileDetails {
    char **header;
    int numcols;
};

>>>>>>> origin/main
char** dash_h(FILE *fp, char*** header) {
    rewind(fp);
    char output[40];
    char newchar;
    int counter = 0;
    char **newheader = *header;

    int i = 0;

    do {
        newchar = fgetc(fp);
        if(newchar == ',' || newchar == '\n') {
            output[i] = '\0';
<<<<<<< HEAD
            // strcpy(newheader[counter], output);
            newheader[counter] = strdup(output);
=======
            printf("copying %s\n", output);
            // strcpy(newheader[counter], output);
            newheader[counter] = strdup(output);
            printf("copied\n");
>>>>>>> origin/main
            i = 0;
            counter += 1;
        } else {
            output[i] = newchar;
<<<<<<< HEAD
            i += 1;
        }
    } while(newchar != '\n');
    rewind(fp);
    return newheader;
}

int min(FILE *fp, int col) {
  rewind(fp);
  char line[MAX];
  char *array;
  int least = 10000;
  
  while(fgets(line,MAX,fp)) {
    
    array = strtok(line, ",");
    int newYear = atoi(array);
    if (isdigit(newYear) == 1) {
      if (least > newYear) {
        least = newYear;
      }
    }
    else {
      return -1;
    }
  }
  return least;
}

int max(FILE *fp, int col) {
  rewind(fp);
  char line[MAX];
  char *array;
  int max = 0;
  
  while(fgets(line,MAX,fp)) {
    
    array = strtok(line, ",");
    int newYear = atoi(array);
    if (isdigit(newYear) == 1) {
      if (max < newYear) {
        max = newYear;
      }
    else {
      return -1;
    }
    }
  }
  return max;
}

int mean(FILE *fp, int col) {
  rewind(fp);
  char line[MAX];
  char *arr;
  int acc;
  int count;
  while(fgets(line, MAX,fp)) {

    arr = strtok(line, ",");
    acc += atoi(arr[col]); 
    count++;
  }
  
    return (acc/count);
}

int records(FILE *fp, int col ,char *value){
  rewind(fp);
  char *arr;
  while(feof(fp) != true) {
   
    fgets(line, MAX, fp);
    item = strtok(line, ",");
   
    int acc = 0;
    while(item != NULL )
    {
        item = strtok(NULL, ",");
    
        acc = acc + 1;
        if (acc == col){
           printf("item : %s\n", item);
           printf("answers : %s\n", line);
          if( item  == (value - '0')){
           printf("item : %s\n", item);
           printf("answers : %s\n", line);
           }
        }
    }




    
  //   char *linedup = strdup(line);
  //   arr = strtok(linedup, ",");
  //   printf("line: %s", line);
  //   printf("col: %d\n", col);
  //   printf("line[col]: %d\n\n\n", linedup[col] );
  //   if((linedup[col] - '0') == atoi(value)){
  //     printf("answers : %s\n", line);
  //   }
  //   free(linedup);
  //  }
  rewind(fp);
  return 0;
} 

/*
 * Converts string to uppercase
*/
char *to_upper(char *in) {
    for(int i = 0; in[i] != '\0'; i++) {
=======
            printf("%c\n", output[i]);
            i += 1;
        }
    } while(newchar != '\n');
    printf("copying finished\n");
    for(i = 0; i < counter; i++) {
        printf("value: %s\n", newheader[i]);
    }
    rewind(fp);
    // free(file_output);
    return newheader;
}

char **dash_h2(FILE *fp) {
    int i;
    char newchar;
    int numcols = 0;
    int *comma_index = calloc(64, sizeof(int)); // holds length of all comma's
    char word[64];

    for(i = 0; (newchar = fgetc(fp)) != EOF && newchar != '\n'; i++) {
        // printf("newchar: %c\t i: %d\t numcols: %d\n", newchar, i, numcols);
        if(newchar == ',') {
            // (comma_index + numcols * sizeof(int)) = i;
            comma_index[numcols] = i;
            numcols += 1;
            i = 0;
            // fgetc(fp);
        }
    }
    // printf("woah\n");
    rewind(fp);

    char *header[numcols];
    for(i = 0; i < numcols; i++) {
        header[i] = malloc((comma_index[numcols] + 1) * sizeof(char));
    }
    char *row_output = malloc(1000);
    printf("fgets: %s output %s\n", fgets(row_output, 999, fp), row_output);
    int fgets_pointer = 0;
    int j;
    for(i = 0; i < numcols; i++) {
        for(j = 0; j < comma_index[i]; j++) {
            word[j] = row_output[fgets_pointer];
            fgets_pointer += 1;
        }
        word[j] = '\0';
        // fgets_pointer += 1;
        strcpy(header[i], word);
    }
    for(i = 0; i < numcols; i++) {
        printf("headerval: %s\n", header[i]);
    }
    
    free(row_output);
    free(comma_index);

    return header;
}

char *to_upper(char *in) {
    for(int i = 0; in[i] != NULL; i++) {
>>>>>>> origin/main
        if(in[i] >= 'a' && in[i] <= 'z') {
            in[i] = in[i] - 32;
        }
    }
    return in;
}

<<<<<<< HEAD
/*
 * @param errorfield stores -min/-max/-mean to indicate what flag failed
 * Makes sure that there is a field after the -min/-max/-mean flags
*/
=======
>>>>>>> origin/main
void mmm_input_validate(int argc, int i, char *errorfield) {
    if(i + 1 >= argc - 1) {
        printf("Missing argument after %s\n", errorfield);
        exit(EXIT_FAILURE);
    }
}

<<<<<<< HEAD
/*
 * Finds the column number that corresponds with userinput
*/
=======
>>>>>>> origin/main
int mmm_input_calc_col(char **header, char *userinput) {
    userinput = to_upper(userinput);
    for(int j = 0; header[j] != NULL; j++) {
        if(strcmp(to_upper(header[j]), userinput) == 0) { return j; }
    }
    printf("header not found\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    FILE *fp;
    /**
     * Open file so it can be passed as argument into separate functions
    */
    if (argc < 2) {
<<<<<<< HEAD
        printf("Wrong number of arguments\n");
        exit(EXIT_FAILURE);
=======
        printf("wrong num arguments\n");
	exit(EXIT_FAILURE);
>>>>>>> origin/main
    }
    fp = fopen(argv[argc - 1], "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
<<<<<<< HEAD
    char **header = calloc(1000, sizeof(char*));
    bool isdashh = false;   // USE THIS TO DETERMINE IF -h IS USED
    for(int i = 1;i < argc-1;i++){
      
    
        if (argc >= 2) {
            
            if(strcmp("-f",argv[i]) == 0) {
              printf("%d\n", dash_f(fp));
            }
            if(strcmp("-r",argv[i]) == 0){
              if(isdashh) {
                printf("%d\n", dash_d(fp) - 1);
              } else {  
                printf("%d\n", dash_d(fp));
              }
            }
            if(strcmp("-h",argv[i]) == 0){
                isdashh = true;
                dash_h(fp, &header);
            }
            if(strcmp("-max",argv[i]) == 0){
                mmm_input_validate(argc, i, "-max");
                //set column value depending on whether -h is used
                int col = isdashh ? mmm_input_calc_col(header, argv[i + 1]) : atoi(argv[i + 1]);
    
            }
            if(strcmp("-min",argv[i]) == 0){
                mmm_input_validate(argc, i, "-min");
                //set column value depending on whehter -h is used.
                int col = isdashh ? mmm_input_calc_col(header, argv[i + 1]) : atoi(argv[i + 1]);
            }
            if(strcmp("-mean",argv[i]) == 0){
                mmm_input_validate(argc, i, "-mean");
                //set column value depending on whether -h is used.
                int col = isdashh ? mmm_input_calc_col(header, argv[i + 1]) : atoi(argv[i + 1]);
            }
            if(strcmp("-records",argv[i]) == 0){
                printf("col:%s and value:%s\n",argv[i+1],argv[i+2]);
              
                records(fp, atoi(argv[i+1]), argv[i+2]);
            }
        }
    }
    if(isdashh) {
        for(int i = 0; header[i] != NULL; i++) {
            free(header[i]);
        }
    }
    free(header);
    return(EXIT_SUCCESS);
}





=======

    //IMPORTANT CODE DO NOT DELETE
    //if(strcmp("-mean",argv[i]) == 0){
    //    mmm_input_validate(argc, i, "-mean");
    //    //set column value depending on whether -h is used.
    //    int col = isdashh ? mmm_input_calc_col(header, argv[i + 1]) : atoi(argv[i + 1]);
    //}

    fclose(fp);

    return(EXIT_SUCCESS);
}
>>>>>>> origin/main
