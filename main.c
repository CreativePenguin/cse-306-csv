#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

struct FileDetails {
    char **header;
    int numcols;
};

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
            printf("copying %s\n", output);
            // strcpy(newheader[counter], output);
            newheader[counter] = strdup(output);
            printf("copied\n");
            i = 0;
            counter += 1;
        } else {
            output[i] = newchar;
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
        if(in[i] >= 'a' && in[i] <= 'z') {
            in[i] = in[i] - 32;
        }
    }
    return in;
}

void mmm_input_validate(int argc, int i, char *errorfield) {
    if(i + 1 >= argc - 1) {
        printf("Missing argument after %s\n", errorfield);
        exit(EXIT_FAILURE);
    }
}

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
        printf("wrong num arguments\n");
	exit(EXIT_FAILURE);
    }
    fp = fopen(argv[argc - 1], "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    //IMPORTANT CODE DO NOT DELETE
    //if(strcmp("-mean",argv[i]) == 0){
    //    mmm_input_validate(argc, i, "-mean");
    //    //set column value depending on whether -h is used.
    //    int col = isdashh ? mmm_input_calc_col(header, argv[i + 1]) : atoi(argv[i + 1]);
    //}

    fclose(fp);

    return(EXIT_SUCCESS);
}
