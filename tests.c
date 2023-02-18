#include<stdio.h>
#include<criterion/criterion.h>
#include "main.c"


void dash_f_test(FILE *fp, int expected) {
    int actual = dash_d(fp);
    cr_assert_eq(actual, expected, "-d was expected to be %d, but was %d", expected, actual);
}

Test(dash_f, test1) {
    FILE *f = fopen("05020004-eng.csv", "-r");
    dash_f_test(f, 8);
    fclose(f);
}

