#include <stdio.h>
#include <string.h>

#define SIZE 100

struct abonent {
    char name[10];
    char second_name[10];
    char tel[10];
};

int main() {
    struct abonent users[SIZE];
    int input = -1, count = 0;
    while (1) {
        printf("\n1) Добавить абонента\n");
        printf("2) Удалить абонента\n");
        printf("3) Поиск абонетов по имени\n");
        printf("4) Вывод всех записей\n");
        printf("5) Выход\n");
        printf("Выберите пункт: ");
        scanf("%d", &input);
        switch (input){
        case 1:
            if (count <= 100) {
                printf("\nВведите имя: ");
                scanf("%10s", users[count].name);
                printf("Введите фамилию: ");
                scanf("%10s", users[count].second_name);
                printf("Введите телефон: ");
                scanf("%10s", users[count].tel);
                count++;
            } else {
                printf("Cправочник переполнeн");
            }
            break;
        case 2:
            char nameToDelete[10];
            printf("\nВведите имя для удаления: ");
            scanf("%10s", nameToDelete);
            int delete = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(users[i].name, nameToDelete) == 0) {
                    memset(&users[i], 0, sizeof(struct abonent));
                    printf("Абонент удален\n");
                    delete = 1;
                    break;
                }
            }

            if (!delete) {
                printf("\nАбонент с именем %s не найден\n", nameToDelete);
            }
            break;
        case 3:
            char searchName[10];
            printf("\nВведите имя для поиска: ");
            scanf("%10s", searchName);
            int search = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(users[i].name, searchName) == 0) {
                    search = 1;
                    printf("Имя: %s, Фамилия: %s, Телефон: %s\n", users[i].name, users[i].second_name, users[i].tel);
                }
            }
            if (!search) {
                printf("\nАбонент с именем %s не найден\n", searchName);
            }
            break;
        case 4:
            printf("\nСписок всех абонентов:\n");
            for (int i = 0; i < count; i++) {
                printf("Имя: %s, Фамилия: %s, Телефон: %s\n", users[i].name, users[i].second_name, users[i].tel);
            }

            break;
        case 5:
            return 0;
            break;
        default:
            printf("Неизвестная команда");
            break;
        }
    }

    return 0;
}
