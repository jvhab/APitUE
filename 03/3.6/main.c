#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

const char* FILENAME = "test.txt";
const off_t SEEK = 5;

int main(int argc, char* argv[]) {
    char buf[] = "qwertyuiop[]";
    char bufSeek[] = "SEEK";
    char bufResult[4096];
    char bufResultSec[4096];
    ssize_t writeByte;
    ssize_t result;
    off_t currPos;

    int fd = open(FILENAME, O_RDWR | O_APPEND);
    /*
     * При завершении процесса все открытые им файлы автоматически закрываются ядром.
     * Многие приложения используют это обстоятельство и не закрывают файлы явно.
     */
    size_t lenBuf = sizeof(buf) / sizeof(buf[0]);
    size_t lenBufSeek = sizeof(bufSeek) / sizeof(bufSeek[0]);
    printf("Len Buf: %zu\n", lenBuf);
    printf("Len BufSeek: %zu\n\n", lenBufSeek);

    writeByte = write(fd, buf, lenBuf);
    printf("Write byte in file: %zd\n\n", writeByte);

    currPos = lseek(fd, SEEK, SEEK_SET);
    printf("Position of offset: %lld\n", currPos);
    result = read(fd, bufResult, 4096);
    printf("Read byte: %zd\n", result);
    printf("%.*s\n\n", 4096, bufResult);

    currPos = lseek(fd, SEEK, SEEK_SET);
    printf("Position of offset: %lld\n", currPos);
    writeByte = write(fd, bufSeek, lenBufSeek);
    printf("Write byte in file: %zd\n", writeByte);
    result = read(fd, bufResultSec, 4096);
    printf("Read byte: %zd\n", result);
    printf("%.*s\n\n", 4096, bufResultSec);

    /*
     * 1. Можно читать из произвольного места если сделать lseek.
     * 2. Запись все равно произойдет в конец.
     */

    return 0;
}