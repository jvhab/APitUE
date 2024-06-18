#include <unistd.h>
#include <stdio.h>
#include <sys/utsname.h>

int main(int argc, char* argv[]) {
    /*
     * Стандарт POSIX.1 определяет функцию uname, которая возвращает сведения о текущем хосте и операционной системе.
     * #include <sys/utsname.h>
     * int uname(struct utsname *name);
     * Возвращает неотрицательное значение в случае успеха, –1 — в случае ошибки
     */

    /*
     * В качестве аргумента передается адрес структуры utsname, и функция заполняет ее.
     * Стандартом POSIX.1 определен лишь минимальный набор полей в этой структуре,
     * каждое из которых является массивом символов, а размеры этих массивов
     * определяются конкретными реализациями. Некоторые реализации добавляют
     * в эту структуру дополнительные поля.
     * struct utsname {
     * char sysname[];   имя операционной системы
     * char nodename[];  имя узла сети
     * char release[];   номер выпуска операционной системы
     * char version[];   номер версии этого выпуска
     * char machine[];   тип аппаратной архитектуры
     * }
     */
    struct utsname name;
    uname(&name);
    printf("sysname: %s \n nodename: %s \n release: %s \n version: %s \n machine: %s", name.sysname, name.nodename, name.release, name.version, name.machine);
    return 0;
}