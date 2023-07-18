/*
    Title: File Input and Output
    Description: Learning about File IOs.
    FileName: FileIO.c
    Modified: July 18th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>

/*
    Chapter 24 File Input and Output.
    * fopen function: 
        => A function that creates a stream to connect the file to the program and stores its address to the file structure variable.
        e.g. FILE* fopen(const char* filename, const char* mode);
            => Return an address of the file structure variable if successful. Otherwise, return a null pointer.
        => filename: The name of the file into which to form the stream.
        => mode: The type of stream that will be formed.
            => Input Stream: "rt", Output Stream: "wt"
        => The pointer of the program will point to the file structure variable which is managed by the OS. 
        => The Major Features of the Fopen Function:
            1) When the fopen function is called, a file structure variable is created.
            2) An information of a file will be stored in the created file structure variable.
            3) The pointer to the file structure variable actually serves as an 'indicator' pointing to a file.
    * fclose function:
        => A function to free the activated stream.
        e.g. int fclose(FILE* stream);
            => Return O on successful, return EOF on failure.
            => The reasons for closing:
                1) Returning the allocated system resources(mainly, the memories) from the OS.
                2) Print out(Or release) the data that have been buffering. 
    * fflush function:
        => A function to free the buffer without closing the stream.
        e.g. int fflush(FILE* stream);
            => Return O on successful, return EOF on failure.
            => Flushing:
                1) Flushing Output buffer: Transfer the data stored in the output buffer.
                2) Flushing input buffer: Remove the data stored in the input buffer.
                3) The flush function is only used to flush the output buffer. (not for the input buffer)
            => The same is true for the case of the file output stream flushing.
            => On the other hand, there is no need to flush an input file steam.
                => The data in the file are always readable, and the read data would be removed from the input stream. 
                => Also, there is no such specific case that an input stream should be flushed.
    * Type of streams:
        => Data READ stream: Read only.
            e.g. mode 'r', If File not exist => ERROR
        => Data WRITE stream: Write only.
            e.g. mode 'w', If File not exist => CREATE FILE
        => Data APPEND stream: Write to append only.
            e.g. mode 'a', If File not exist => CREATE FILE
        => Data READ/WRITE stream: Read and Write availabe.
            e.g. mode 'r+'(R&W), If File not exist => ERROR
            e.g. mode 'w+'(R&W), If File not exist => CREATE FILE
            e.g. mode 'a+'(R&A), If File not exist => CREATE FILE
        => '+' mode(Read/Write) would need require the flushing jobs more often!.
    * Text file and Binary file:
        => Text file: A type of file contains readable letters.
            e.g. notepad file, word file, etc.
            e.g. mode "t" => rt, wt, at, r+t(rt+), w+t(wt+), a+t(at+)
            e.g. default mode is also text mode => r, w, a, r+, w+, a+
        => Binary file: A type of file perceived by computers.
            e.g. video file, music file, etc.
            e.g. mode "b" => rb, wb, ab, r+b(wb+), w+b(wb+), a+b(ab+)
    * Newline Character: Can be varied from system to system.
        => File from General programming language (C included): \n
        => File from the MS-DOS (Windows) system: \r\n
        => File from the Mac(Mackintosh) system: \r
        => File from Unix system: \n
        => In C program, it can be dealt with in text mode to avoid newline errors.
    * feof function: 
        => A function that checks whether it is a file end of the file.
        e.g. int feof(FILE* stream);
            => Return a non-zero value when it is a file end.
    * IO of binary data: fread, fwrite functions.
        => fread function: An Input stream function for the binary files.
        e.g. size_t fread(void* buffer, size_t size, size_t count, FILE* stream);
            => Return count argument if successful, return a smaller value than count if failed or met the file end.
            => Read “count” times of data, of which has “size” bytes each, then save them to the “buffer”, from “stream”.
        => fwrite function: An Output stream function for the binary files.
        e.g. size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
            => Return count argument if successful, return a smaller value than count if failed. 
            => Read “count” times of data, of which has “size” bytes each, then save them to the “stream”, from “buffer”.
    * IO of Compound files: fprintf, fscanf functions.
        => Similar to the scanf and printf functions but used for the file instead of the console.
        => The fwrite and fread functions can use a struct type variable for IO of compound files.
    * A File position indicator for the random access: fseek, ftell functions.
        => There exists a member of the IO functions that records and updates the current position within a file.
        => The indicator will point to the front when opening the file for the first time.
        => After reading a string, the indicator will point to the next position of the current position + the size of the read string.
        => fseek function: A function that moves the indicator's current position to the target position.
        e.g. int fseek(FILE* stream, long offset, int wherefrom);
        => Return 0 if successful, otherwise return nonzero.
        => Argument 'wherefrom': Indicates from where to start moving.
            SEEK_SET(0): Move from the initial position.
            SEEK_CUR(1): Move from the current position.
            SEEK_END(2): Move from the file end position(EOF).
        => Argument 'offset': The number of bytes by which the indicator will move. (Positive to backward, negative to forward)
        => ftell function: A function returns a current position of the indicator.
        e.g. long ftell(FILE* stream);
            => Returns the indicator's current position information.
*/

typedef struct fren
{
    char name[10];
    char gender;
    int age;
} Friend;

int firstFileWrite(void)
{    
    FILE* fp = fopen("BASIC_C/Ch24/data.txt","wt");
    
    if(fp==NULL) {
        puts("File Read Failure!");
        return -1; // abnormal termination.
    }

    fputc('H',fp);
    fputc('E',fp);
    fputc('L',fp);
    fputc('L',fp);
    fputc('O',fp);
    
    fclose(fp); // Stream destroy.

    return 0;
}

int firstFileRead(void)
{
    int ch;
    FILE* fp = fopen("BASIC_C/Ch24/data.txt","rt");
    
    if(fp==NULL) {
        puts("File Read Failure!");
        return -1; // abnormal termination.
    }
    
    for(int i=0; i<5; i++)
    {
        ch=fgetc(fp);
        printf("%c", ch);
    }
    printf("\n");

    fclose(fp);

    return 0;
}

int textDataFileWrite(void)
{
    FILE * fp = fopen("BASIC_C/Ch24/simple.txt","wt");
    if(fp==NULL){
        puts("FILE OPEN ERROR!");
        return -1;
    }

    fputc('A',fp);
    fputc('B',fp);
    fputs("My name is Hong \n", fp);
    fputs("Your name is Yoon \n", fp);
    
    fclose(fp);

    return 0;
}

int textDataFileRead(void)
{
    int ch;
    char str[30];
    FILE * fp = fopen("BASIC_C/Ch24/simple.txt","rt");
    
    if(fp==NULL){
        puts("FILE OPEN ERROR!");
        return -1;
    }

    ch=fgetc(fp);
    printf("%c \n", ch);
    ch=fgetc(fp);
    printf("%c \n", ch);

    fgets(str, sizeof(str), fp);
    printf("%s", str);
    fgets(str, sizeof(str), fp);
    printf("%s", str);

    fclose(fp);

    return 0;
}

int textCharFileCopy(void)
{
    FILE* src = fopen("BASIC_C/Ch24/data.txt", "rt");
    FILE* des = fopen("BASIC_C/Ch24/data_des.txt", "wt");
    int ch;

    if(src == NULL || des == NULL){
        puts("FILE OPEN ERROR!");
        return -1;
    }

    while((ch=fgetc(src)) != EOF) fputc(ch, des); // Until it gets an EOF.

    if(feof(src) != 0) puts("Completed file copy."); // Check if it is the true file end.

    fclose(src);
    fclose(des);

    return 0;
}

int textStringFileCopy(void)
{
    FILE* src = fopen("BASIC_C/Ch24/simple.txt", "rt");
    FILE* des = fopen("BASIC_C/Ch24/simple_des.txt", "wt");
    char str[20];

    if(src == NULL || des == NULL){
        puts("FILE OPEN ERROR!");
        return -1;
    }

    while(fgets(str, sizeof(str), src) != NULL) fputs(str, des); // Until it gets a NULL.

    if(feof(src) != 0) puts("Completed file copy."); // Check if it is the true file end.

    fclose(src);
    fclose(des);

    return 0;
}

int binaryFileCopy(void)
{
    FILE* src = fopen("BASIC_C/Ch24/binary.bin", "rb");
    FILE* des = fopen("BASIC_C/Ch24/binary_des.bin", "wb");
    char buf[20];
    int readCnt;

    if(src == NULL || des == NULL)
    {
        puts("File open failure!");
        return -1; 
    }    

    while(1)
    {
        readCnt=fread((void*)buf, 1, sizeof(buf), src);

        if(readCnt<sizeof(buf)) // File end of Error
        {
            if(feof(src) != 0){
                fwrite((void*)buf, 1, readCnt, des); // Write the remainder that is smaller than sizeof(buf).
                puts("Completed binary file copy.");
            }
            else puts("Copy failure!");
            
            break;
        }
        fwrite((void*)buf, 1, sizeof(buf), des);
    }

    fclose(src);
    fclose(des);

    return 0;
}

int complexFileWrite(void)
{
    char name[10];
    char gender;
    int age;

    FILE* fp = fopen("BASIC_C/Ch24/friend.txt", "wt");
    
    for(int i=0; i< 3; i++)
    {
        printf("[ENTER] NAME GENDER AGE:");
        scanf("%s %c %d", name, &gender, &age);
        getchar(); // Remove the newline charater.
        fprintf(fp, "%s %c %d \n", name, gender, age);
    }

    fclose(fp);

    return 0;
}

int complexFileRead(void)
{
    char name[10];
    char gender;
    int age;

    FILE* fp = fopen("BASIC_C/Ch24/friend.txt", "rt");
    int ret;

    while(1)
    {
       ret = fscanf(fp, "%s %c %d", name, &gender, &age);
       if(ret==EOF) break;
       printf("%s %c %d \n", name, gender, age);
    }

    fclose(fp);

    return 0;
}

int structFileWriteRead(void)
{
    FILE* fp;
    Friend myFren1, myFren2;

    /*** file write ***/
    fp = fopen("BASIC_C/Ch24/friend.bin", "wb");
    printf("[ENTER] NAME GENDER AGE: ");
    scanf("%s %c %d", myFren1.name, &myFren1.gender, &myFren1.age);
    fwrite((void*)&myFren1, sizeof(myFren1), 1, fp); // Use and Write a struct data as a binary form.
    fclose(fp);

    /*** file read ***/
    fp = fopen("BASIC_C/Ch24/friend.bin", "rb");
    fread((void*)&myFren2, sizeof(myFren2), 1, fp); // Use and Read a struct data as a binary form.
    printf("%s %c %d \n", myFren2.name, myFren2.gender, myFren2.age);
    fclose(fp);

    return 0;
}

int moveFileReWrPos(void)
{
    // File Write
    FILE* fp = fopen("BASIC_C/Ch24/text.txt", "wt");
    fputs("123456789", fp);
    fclose(fp);

    // File Read
    fp = fopen("BASIC_C/Ch24/text.txt", "rt");

    // SEEK_END test
    fseek(fp, -2, SEEK_END); // 8 = EOF 9 8
    putchar(fgetc(fp));

    // SEEK_SET test
    fseek(fp, 2, SEEK_SET); // 3 = 1 2 3
    putchar(fgetc(fp));
    
    // SEEK_CUR test
    fseek(fp, 2, SEEK_CUR); // 6 = 4 5 6
    putchar(fgetc(fp));

    fclose(fp);

    return 0;
}

int tellFileReWrPos(void)
{
    long fpos;

    // File Write
    FILE* fp = fopen("BASIC_C/Ch24/text2.txt", "wt");
    fputs("1234-", fp);
    fclose(fp);

    // File Read
    fp = fopen("BASIC_C/Ch24/text2.txt", "rt");

    // ftell test
    for(int i=0; i<4; i++){
        putchar(fgetc(fp)); // 1 2 3 4
        fpos=ftell(fp); // the current position of indicator
        fseek(fp, -1, SEEK_END); 
        putchar(fgetc(fp)); // -
        fseek(fp, fpos, SEEK_SET); // go back to current position
    }

    fclose(fp);
    
    return 0;
}

int main(void)
{
    firstFileWrite();
    printf("\n");
    firstFileRead();
    printf("\n");
    textDataFileWrite();
    printf("\n");
    textDataFileRead();
    printf("\n");
    textCharFileCopy();
    printf("\n");
    textStringFileCopy();
    printf("\n");
    binaryFileCopy();
    printf("\n");
    complexFileWrite();
    printf("\n");
    complexFileRead();
    printf("\n");
    structFileWriteRead();
    printf("\n");
    tellFileReWrPos();
    printf("\n");    

    return 0;
}