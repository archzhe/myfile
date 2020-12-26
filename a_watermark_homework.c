/*
myfile-01: a watermark homework.
Copyright <2020> <archzhe>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

End license text.
*/
#include <stdio.h>
#include <string.h>

const int map[10] = {0, 0, 1, 0, 1, 1, 0, 1, 0, 1};

void change_id_into_matrix(const char* s, int (*a)[3]){
    if(strlen(s) != 8){
        printf("not id!\n");
        return;
    }

    for (int i = 0; i < 9; ++i)
    {
        a[i/3][i%3] = 155 + s[i+1] -'0';
    }
    
}

void set_watermark(int (*a)[3], int (*b)[3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int n = 0;
            while(map[a[i][j] + n - 155] != b[i][j]){
                ++n;
            }
            a[i][j] += n;
        }
    }
}

void get_watermark(int (*a)[3], int (*b)[3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            b[i][j] = map[a[i][j] - 155];
        }
    }
}

void print(int (*a)[3]) {
    printf("[[%d, %d, %d],\n [%d, %d, %d],\n [%d, %d, %d]]\n\n",
        a[0][0], a[0][1], a[0][2], 
        a[1][0], a[1][1], a[1][2], 
        a[2][0], a[2][1], a[2][2]);
}

void print_help(){
    printf("\n1. open cmd && powershell\n\
2. cd [filepath]\n\
3. ./d 1916270143\n\n");
}

int main(int argc, char** argv) {

    int a[3][3] = {{155, 157, 156}, 
                    {159, 158, 159}, 
                    {160, 161, 162}};
    int b[3][3] = {{1, 0, 1}, 
                    {1, 1, 0}, 
                    {0, 0, 0}};
    int c[3][3];

    if(argc == 2)
        change_id_into_matrix(argv[1], a);
    else
        print_help();
    
    printf("\"Watermarked image\" matrix:\n");
    set_watermark(a, b);
    print(a);
    get_watermark(a, c);
    printf("\"Extracted watermark\" matrix:\n");
    print(c);
}