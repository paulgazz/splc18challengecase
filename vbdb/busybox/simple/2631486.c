
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

struct dnode {
   int val;
   struct dnode *next;
};

#ifdef CONFIG_FEATURE_LS_RECURSIVE
void dfree(struct dnode **arr, int size)
{
  if (arr == NULL)
    return;

  int counter=0;
  struct dnode *tmp;
  struct dnode *cur = arr[0]; // is no longer the head
  while (cur != NULL) {
    //    printf("%d\n", cur->val);
    tmp = cur;
    cur = cur->next;
    free(tmp);
    tmp=NULL;
    counter++;
  }

  assert(counter==size);
}
#endif

void showdirs(struct dnode **arr, int size)
{
  for (int i = 0; i < size; ++i) {
    printf("\n%d", arr[i]->val);
    if(arr[i]->next==NULL)
      printf("\nTail\n");
  }
  
#ifdef CONFIG_FEATURE_LS_RECURSIVE
  dfree(arr, size); //ERROR
#endif
}

#ifdef CONFIG_FEATURE_LS_SORTFILES
void sort(struct dnode **arr, int size)
{
  struct dnode temp;
  int i, j;

  if (arr == NULL || size < 1)
    return;

  for(i=0;i<size;i++) {
    for(j=i;j<size;j++) {
      if(arr[i]->val > arr[j]->val) {
        temp=*arr[i];
        *arr[i]=*arr[j];
        *arr[j]=temp;
      }
    }
  }
}
#endif

int main(int argc, char **argv)
{
  struct dnode *curr, *head;
  int size = 5;
  struct dnode *arr[size];
  int values[]={3,6,2,5,7};
  head=NULL;
  for (int i = 0; i < size; i++) {
    curr = (struct dnode *) malloc(sizeof(struct dnode));
    curr->val = values[i];
    curr->next = head;
    head = curr;
    arr[(size-1)-i] = curr;
  }

#ifdef CONFIG_FEATURE_LS_SORTFILES
    sort(arr, size);
#endif
    showdirs(arr,size);
  return 0;
}
