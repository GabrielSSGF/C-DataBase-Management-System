#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    int id;
    char name[50];
} Record;

typedef struct Index {
    int id;
    int memoryPosition;
} Index;

#define MAX_DATABASE_SIZE 1000

Record database[MAX_DATABASE_SIZE];
Index index[MAX_DATABASE_SIZE];
int databaseSize = 0;

const char *DATA_FILE = "database.dat";

void loadDatabaseFromFile() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo de dados.\n");
        return;
    }

    databaseSize = fread(database, sizeof(Record), MAX_DATABASE_SIZE, file);
    fclose(file);

    for (int i = 0; i < databaseSize; i++) {
        index[i].id = database[i].id;
        index[i].memoryPosition = i;
    }
}

void saveDatabaseToFile() {
    FILE *file = fopen(DATA_FILE, "wb");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo de dados para escrita.\n");
        return;
    }

    fwrite(database, sizeof(Record), databaseSize, file);
    fclose(file);
}

void createRecord(int id, const char *name) {
    if (databaseSize < MAX_DATABASE_SIZE) {
        Record newRecord;
        newRecord.id = id;
        strncpy(newRecord.name, name, sizeof(newRecord.name));
        database[databaseSize] = newRecord;

        index[databaseSize].id = id;
        index[databaseSize].memoryPosition = databaseSize;

        databaseSize++;
        printf("Registro criado com sucesso.\n");

        saveDatabaseToFile();
    } else {
        printf("O banco de dados está cheio. Não é possível adicionar mais registros.\n");
    }
}

void readRecord(int id) {
    for (int i = 0; i < databaseSize; i++) {
        if (index[i].id == id) {
            printf("ID: %d, Nome: %s\n", database[i].id, database[i].name);
            return;
        }
    }
    printf("Registro não encontrado.\n");
}

void updateRecord(int id, const char *name) {
    for (int i = 0; i < databaseSize; i++) {
        if (index[i].id == id) {
            strncpy(database[i].name, name, sizeof(database[i].name));
            printf("Registro atualizado com sucesso.\n");

            saveDatabaseToFile();
            return;
        }
    }
    printf("Registro não encontrado.\n");
}

void deleteRecord(int id) {
    for (int i = 0; i < databaseSize; i++) {
        if (index[i].id == id) {
            for (int j = i; j < databaseSize - 1; j++) {
                database[j] = database[j + 1];
                index[j] = index[j + 1];
            }
            databaseSize--;
            printf("Registro excluído com sucesso.\n");

            saveDatabaseToFile();
            return;
        }
    }
    printf("Registro não encontrado.\n");
}

int main() {
    loadDatabaseFromFile();

    int choice;
    int id;
    char name[50];

    while (1) {
        printf("Escolha uma operação:\n");
        printf("1. Criar registro\n");
        printf("2. Ler registro\n");
        printf("3. Atualizar registro\n");
        printf("4. Excluir registro\n");
        printf("5. Sair\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o ID e o nome: ");
                scanf("%d %s", &id, name);
                createRecord(id, name);
                break;
            case 2:
                printf("Digite o ID a ser lido: ");
                scanf("%d", &id);
                readRecord(id);
                break;
            case 3:
                printf("Digite o ID e o novo nome: ");
                scanf("%d %s", &id, name);
                updateRecord(id, name);
                break;
            case 4:
                printf("Digite o ID a ser excluído: ");
                scanf("%d", &id);
                deleteRecord(id);
                break;
            case 5:
                saveDatabaseToFile();
                exit(0);
            default:
                printf("Escolha inválida.\n");
        }
    }

    return 0;
}
