 #include <stdio.h>
#define max 10

struct emp {
    char name[100];
    long int EmpID;
    long int Salary;
    char designation[100];
    int exp;
    int age;
};

int n = 0;
struct emp e[max];
void showMenu();
void buildtable();
void insert();
void deletentry();
void delindex(int i);
void search();

int main() {
    showMenu();
    return 0;
}

void showMenu() {
    int opt;
    printf("-------------------------\n");
    printf("Employee Management System\n");
    printf("-------------------------\n");
    printf("1. Build Table\n");
    printf("2. Insert New Entry\n");
    printf("3. Delete Entry\n");
    printf("4. Search Record\n");
    printf("5. Exit\n");
    printf("Enter your option: ");
    scanf("%d", &opt);

    switch (opt) {
        case 1:
            buildtable();
            break;
        case 2:
            insert();
            break;
        case 3:
            deletentry();
            break;
        case 4:
            search();
            break;
        case 5:
            return;
        default:
            printf("Invalid option. Try again.\n");
            showMenu();
    }
}

void buildtable() {
    printf("Build the Table\n");
    printf("Enter the number of entries required: ");
    scanf("%d", &n);

    if (n > max) {
        printf("**!!Warning!!**\n");
        printf("Maximum entries allowed are %d.\n", max);
        n = max;
    }

    printf("Enter the following data:-\n");
    for (int i = 0; i < n; i++) {
        printf("Name of Employee: ");
        scanf(" %[^\n]%*c", e[i].name);
        printf("EmpID: ");
        scanf("%ld", &e[i].EmpID);

        printf("Salary: ");
        scanf("%ld", &e[i].Salary);

        printf("Designation: ");
        scanf(" %[^\n]%*c", &e[i].designation);

        printf("Experience (Yrs): ");
        scanf("%d", &e[i].exp);

        printf("Age: ");
        scanf("%d", &e[i].age);
    }
    printf("    Data inserted successfully!\n");
    showMenu();
}

void insert() {
    if (n < max) {
        int i = n;

        printf("Enter the Employee Information\n");
        printf("Name of Employee: ");
        scanf(" %[^\n]%*c", e[i].name);

        printf("EmpID: ");
        scanf("%ld", &e[i].EmpID);

        printf("Salary: ");
        scanf("%ld", &e[i].Salary);

        printf("Designation: ");
        scanf(" %[^\n]%*c", e[i].designation);

        printf("Experience (Yrs): ");
        scanf("%d", &e[i].exp);

        printf("Age: ");
        scanf("%d", &e[i].age);
        printf("   Data Inserted Successfully!!\n ");

        n++;
    } else {
        printf("   Table is full!\n");
    }
    showMenu();
}

void deletentry() {
    long int id;
    printf("Enter the EmpID to delete the record: ");
    scanf("%ld", &id);

    for (int i = 0; i < n; i++) {
        if (e[i].EmpID == id) {
            delindex(i);
            n--;
            printf("     Record deleted successfully!\n");
            break;
        }
    }
    showMenu();
}

void delindex(int i) {
    for (int j = i; j < n - 1; j++) {
        e[j] = e[j + 1];
    }
}

void search() {
    long int id;
    printf("Enter the EmpID to search the record: ");
    scanf("%ld", &id);

    for (int i = 0; i < n; i++) {
        if (e[i].EmpID == id) {
            printf("Name of Employee: %s\n", e[i].name);
            printf("EmpID: %ld\n", e[i].EmpID);
            printf("Salary: %ld\n", e[i].Salary);
            printf("Designation: %s\n", e[i].designation);
            printf("Experience: %d years\n", e[i].exp);
            printf("Age: %d\n", e[i].age);
            break;
        }
        else{
            printf("    No Record Found!\n");
        }
    }
    showMenu();
}
