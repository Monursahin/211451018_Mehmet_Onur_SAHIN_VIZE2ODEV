#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000
typedef struct NODE
{

    int no;
    char *name;
    char *lastname;
    float midterm;
    float final;
    struct NODE *next;
    struct NODE *previous;
} NODE;

NODE *CreateNode(NODE *previous, int no, char *name, char *lastname, float midterm, float final)
{
    NODE *node;
    node = (NODE *)malloc(sizeof(NODE));
    if (node)
    {
        node->no = no;
        node->name = name;
        node->lastname = lastname;
        node->midterm = midterm;
        node->final = final;

        node->next = NULL;

        if (previous)
        {
            node->previous = previous;
            previous->next = node;
        }
        else
        {
            node->previous = NULL;
        }
    }
    return node;
}

void RemoveNode(NODE *node)
{
    NODE *tmp;
    if (node->previous)
    {

        tmp = node->previous;
        tmp->next = node->next;
    }
    if (node->next)
    {
        tmp = node->next;
        tmp->previous = node->previous;
    }
    free(node);
    return;
}

void PrintListLeft(NODE *last)
{
    NODE *tmp = last;
    while (tmp)
    {

        printf("Öğrenci No     : %d\n", tmp->no);
        printf("Öğrenci Adı    : %s\n", tmp->name);
        printf("Öğrenci Soyadı : %s\n", tmp->lastname);
        printf("Vize Notu      : %.2f\n", tmp->midterm);
        printf("Final Botu     : %.2f\n", tmp->final);
        printf("-------------------------------\n");
        tmp = tmp->previous;
    }
    return;
}

void PreviousAndNext(NODE *last)
{
    NODE *tmp = last;

    printf("Öğrenci No     : %d\n", tmp->no);
    printf("Öğrenci Adı    : %s\n", tmp->name);
    printf("Öğrenci Soyadı : %s\n", tmp->lastname);
    printf("Vize Notu      : %.2f\n", tmp->midterm);
    printf("Final Botu     : %.2f\n", tmp->final);
    printf("-------------------------------\n");
    printf("Çıkış : 0, Ileri : 1, Geri : 2\n");

    int ques1;

    printf("Lütfen bir seçim yapınız : ");
    scanf("%d", &ques1);

    if (ques1 == 0)
    {
        return;
    }
    else if (ques1 == 1)
    {

        tmp = tmp->next;
        PreviousAndNext(tmp);
    }
    else if (ques1 == 2)
    {
        tmp = tmp->previous;
        PreviousAndNext(tmp);
    }
}



int main()
{
    int i;
    int newStudentKey = 0;
    int no_;
    char name_[100];
    char lastname_[100];
    float midterm_;
    float final_;
    NODE *tmp = NULL;
    NODE *node = NULL;
    NODE *root = NULL;

    // // Öğrenci ekleme
    // root = CreateNode(NULL, 2022001, "ogrAd", "OgrSoyad", 34.4, 56.6);
    // node = root;

    // tmp = CreateNode(node, 2022002, "OgrAd", "OgrSoyad", 34.4, 56.6);
    // node->next = tmp;
    // node = tmp;

    // tmp = CreateNode(node, 2022003, "OgrAd", "OgrSoyad", 34.4, 56.6);
    // node->next = tmp;
    // node = tmp;

    // tmp = CreateNode(node, 2022004, "OgrAd", "OgrSoyad", 34.4, 56.6);
    // node->next = tmp;
    // node = tmp;

    int ques;

    while (1)
    {

        printf("---------------------------------\n");

        printf("Öğrenci Kaydı Ekleme   : 1\n");
        printf("Öğrenci Kaydı Silme    : 2\n");
        printf("Öğrencileri Listele    : 3\n");
        printf("Öğrencileri Görüntüle  : 4\n");

        printf("Çıkış için           : 0\n");
        printf("---------------------------------\n");
        printf("Lütfen bir seçim yapınız : ");

        scanf("%d", &ques);

        if (ques == 0)
        {
            break;
        }
        else if (ques == 1)
        {

            printf("Yeni Öğrenci Numarsını giriniz :");
            scanf("%d", &no_);
            printf("Yeni Öğrenci Adını giriniz :");
            scanf("%s", &name_);
            printf("Yeni Öğrenci Soyadını giriniz :");
            scanf("%s", &lastname_);
            printf("Yeni Öğrenci Vize Notunu giriniz :");
            scanf("%f", &midterm_);
            printf("Yeni Öğrenci Final Notunu giriniz :");
            scanf("%f", &final_);

            if (newStudentKey != 0)
            {
                tmp = CreateNode(node, no_, name_, lastname_, midterm_, final_);
                node->next = tmp;
                node = tmp;
            }
            else
            {
                root = CreateNode(NULL, no_, name_, lastname_, midterm_, final_);
                node = root;
                newStudentKey = 1;
            }
        }

        else if (ques == 2)
        {
            int removeStudentNo;
            printf("Kaydı Silinecek Öğrenci Numarasını Giriniz :");
            scanf("%d", &removeStudentNo);
            node = root;
            tmp = NULL;

            while (node)
            {
                if (node->no == removeStudentNo)
                {
                    if (tmp == NULL)
                    {

                        root = node->next;
                    }

                    RemoveNode(node);
                    break;
                }

                tmp = node;
                node = node->next;
            }
        }
        else if (ques == 3)
        {
            PrintListLeft(tmp);
        }

        else if (ques == 4)
        {
            PreviousAndNext(tmp);
        }
    }

    return 0;
}
