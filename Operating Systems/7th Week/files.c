#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 20. Write a C program to implement the various file organization techniques.

struct Record
{
   int id;
   char name[30];
};

void sequential()
{
   FILE *fp;
   struct Record r;
   int n;
   fp = fopen("sequential.dat", "wb+");
   printf("\n--- Sequential File ---\n");
   printf("Enter number of records: ");
   scanf("%d", &n);
   for (int i = 0; i < n; i++)
   {
      printf("Enter ID and Name: ");
      scanf("%d %s", &r.id, r.name);
      fwrite(&r, sizeof(r), 1, fp);
   }
   rewind(fp);
   while (fread(&r, sizeof(r), 1, fp))
      printf("%d %s\n", r.id, r.name);
   fclose(fp);
}

void direct()
{
   FILE *fp;
   struct Record r;
   int pos;
   fp = fopen("direct.dat", "wb+");
   printf("\n--- Direct File ---\n");
   for (int i = 0; i < 3; i++)
   {
      printf("Enter record position (0-2), ID and Name: ");
      scanf("%d %d %s", &pos, &r.id, r.name);
      fseek(fp, pos * sizeof(r), SEEK_SET);
      fwrite(&r, sizeof(r), 1, fp);
   }
   rewind(fp);
   while (fread(&r, sizeof(r), 1, fp))
      printf("%d %s\n", r.id, r.name);
   fclose(fp);
}

void indexedSequential()
{
   FILE *fp;
   struct Record r;
   struct Record index[10];
   int n;
   fp = fopen("indexed.dat", "wb+");
   printf("\n--- Indexed Sequential File ---\n");
   printf("Enter number of records: ");
   scanf("%d", &n);
   for (int i = 0; i < n; i++)
   {
      printf("Enter ID and Name: ");
      scanf("%d %s", &r.id, r.name);
      index[i] = r;
      fwrite(&r, sizeof(r), 1, fp);
   }
   for (int i = 0; i < n; i++)
      printf("Index %d -> %d %s\n", i, index[i].id, index[i].name);
   fclose(fp);
}

int main()
{
   sequential();
   direct();
   indexedSequential();
   return 0;
}
