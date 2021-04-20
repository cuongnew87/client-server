#include <stdio.h>
#include <string.h>
    int main()
    {
 
        char name[10][8], tname[10][8], temp[8];
        int n;
 
        printf("Nhap so luong ten:\n");
        scanf("%d", &n);
        printf("Nhap %d ten:\n", n);
 
        for (int i = 0; i < n; i++) 
        {
            scanf("%s", name[i]);
            strcpy(tname[i], name[i]);
        }
 
        for (int i = 0; i < n - 1 ; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (strcmp(name[i], name[j]) > 0) 
                {
                    strcpy(temp, name[i]);
                    strcpy(name[i], name[j]);
                    strcpy(name[j], temp);
                }
            }
        }
 
        printf("\n----------------------------------------\n");
        printf("Input NamestSorted names\n");
        printf("------------------------------------------\n");
 
        for (int i = 0; i < n; i++) 
        {
            printf("%s\t\t%s\n", tname[i], name[i]);
        }
    }
