#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    /*
     * Функция umask устанавливает маску режима создания файлов для процесса
     * и возвращает предыдущее значение.
     * Это одна из немногих функций, которые не возвращают признак ошибки.
     */

    mode_t result_1 = umask(1411);
    printf("now mask: %3o\n", result_1);

    mode_t result_2 = umask(1411);
    printf("after: %3o", result_2);

    /*
     * 2603	rw---S-wx	SGID	read & write	no access	write & execute
     */
    return 0;
}