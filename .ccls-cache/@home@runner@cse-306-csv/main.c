#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
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
            // strcpy(newheader[counter], output);
            newheader[counter] = strdup(output);
            i = 0;
            counter += 1;
        } else {
            output[i] = newchar;
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
    // item = strtok(line, ",");
   
    // int acc = 0;
    // while(item != NULL )
    // {
    //     item = strtok(NULL, ",");
    //     acc = acc + 1;
    //     if (acc == col){
    //       if( item  == value){
    //       printf("item : %s\n", item);
    //        printf("answers : %s\n", line);
    //        }
    //     }
    // }




    
    char *linedup = strdup(line);
    arr = strtok(linedup, ",");
    printf("line: %s", line);
    printf("col: %d\n", col);
    printf("line[col]: %d\n\n\n", linedup[col] );
    if((linedup[col] - '0') == atoi(value)){
      printf("answers : %s\n", line);
    }
    free(linedup);
   }
  rewind(fp);
  return 0;
} 

/*
 * Converts string to uppercase
*/
char *to_upper(char *in) {
    for(int i = 0; in[i] != '\0'; i++) {
        if(in[i] >= 'a' && in[i] <= 'z') {
            in[i] = in[i] - 32;
        }
    }
    return in;
}

/*
 * @param errorfield stores -min/-max/-mean to indicate what flag failed
 * Makes sure that there is a field after the -min/-max/-mean flags
*/
void mmm_input_validate(int argc, int i, char *errorfield) {
    if(i + 1 >= argc - 1) {
        printf("Missing argument after %s\n", errorfield);
        exit(EXIT_FAILURE);
    }
}

/*
 * Finds the column number that corresponds with userinput
*/
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
        printf("Wrong number of arguments\n");
        exit(EXIT_FAILURE);
    }
    fp = fopen(argv[argc - 1], "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
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





