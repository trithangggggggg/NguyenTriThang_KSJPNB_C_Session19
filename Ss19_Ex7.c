#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phone[15];
} student;

void delete(int id, student arr[], int *length) {
    int found = 0;
    for (int i = 0; i < *length; i++) {
        if (arr[i].id == id) {
            found = 1;
            for (int j = i; j < *length - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*length)--;
            printf("Sinh vien ID %d da xoa.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien ID %d.\n", id);
    }
}

void printStudents(student arr[], int length) {
    if (length == 0) {
        printf("Danh sach rong.\n");
    } else {
        for (int i = 0; i < length; i++) {
            printf("ID: %d, Ten: %s, Tuoi: %d, So dien thoai: %s\n",
                   arr[i].id, arr[i].name, arr[i].age, arr[i].phone);
        }
    }
}

int main() {
    student students[5] = {
        {1, "trithang", 18, "0123456789"},
        {2, "thanhha", 18, "0123456876"},
        {3, "minhthang", 5, "012348765"},
        {4, "manhhhung", 5, "012345345"},
        {5, "tuanminh", 5, "01234876589"}
    };
    int length = 5;

    printf("Danh sach sinh vien ban dau:\n");
    printStudents(students, length);

    int Iddelete;
    printf("Nhap ID cua sinh vien can xoa: ");
    scanf("%d", &Iddelete);

    delete(Iddelete, students, &length);

    printf("\nDanh sach sinh vien sau khi xoa:\n");
    printStudents(students, length);

    return 0;
}

