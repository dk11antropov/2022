#include "single_list.h"
#include <stdio.h>
#include <stdlib.h>

SingleListFloatElement *createSingleListFloatElement (float value){
  SingleListFloatElement *result = (SingleListFloatElement *)malloc(sizeof(SingleListFloatElement));

  if (NULL != result){
    result->value = value;
    result->next = NULL;
  }
  return result;
}
void deleteSingleListFloatElement (SingleListFloatElement *element){
   if (NULL != element ){
       free(element);
   }
}
void printSingleListFloatElement(SingleListFloatElement  *element){
   if (NULL != element){
    printf("%f", element->value);
   }
}
FloatSingleList *createFloatSingleList(void){
   FloatSingleList *result = (FloatSingleList *)malloc(sizeof(FloatSingleList));

   if (NULL != result){
    result->head = NULL;
   }
   return result;
}
void deleteFloatSingleList(FloatSingleList *list){
   if (NULL == list){
    return;
   }
   SingleListFloatElement *element = list->head;

   while (NULL != element) {
    SingleListFloatElement *tmp = element->next;
    deleteSingleListFloatElement(element);
    element = tmp;
   }
   free(list);
}

void printFloatSingleList(FloatSingleList  *list){

    if (NULL == list){
        printf("Invalid a pointer to the list\n");
        return;
    }
    printf("[");
   // SingleListIntElement *element = list->head;

   // while(NULL != element){
    //SingleListIntElement *tmp = element->next;
   // printSingleListIntElement(element);
   // element = tmp;
   for (SingleListFloatElement *element = list->head; element != NULL; element = element->next){
    printSingleListFloatElement(element);
    if (element->next != NULL){
    printf(",");
   }
   }
    printf("]\n");

}

long countOfFloatSingleList(FloatSingleList *list){
   if (NULL == list){
        return 0;
    }
    long count = 0;

   for(SingleListFloatElement *element = list->head; element != NULL; element = element->next, count ++);
    return count;
}
 int addFloatValueToSingleList(FloatSingleList *list, float value)
{
    if (NULL == list){
        return 0;
    }
    SingleListFloatElement *element = createSingleListFloatElement(value);
    if (NULL == element){
        return 0;
    }
    if (NULL == list->head){
        list->head = element;
        return 1;
    }
    SingleListFloatElement *tail = list->head;

    while(NULL != tail->next){
    tail = tail->next;
    }
    tail->next = element;
    return 1;
}
void removeLastElementFromFloatSingleList(FloatSingleList *list)
{
    if (NULL == list){
        return 0;
    }
    if (NULL == list->head){
        return;
    }
     SingleListFloatElement *element = list->head;

     if (NULL == element->next){
        list->head = NULL;
        deleteSingleListFloatElement(element);
        return;
     }

    while(NULL != element->next && NULL != element->next->next){
    element = element->next;
    }
    deleteSingleListFloatElement(element->next);
    element->next = NULL;
}
void removeFirstElementFromFloatSingleList(FloatSingleList *list)
{
    if (NULL == list){
        return 0;
    }
    if (NULL == list->head){
        return;
    }
    SingleListFloatElement *element = list->head->next;
    deleteSingleListFloatElement(list->head);
    list->head = element;

}

int insertFloatElementToFloatSingleListAtIndex(FloatSingleList *list, int index, float value)
{
    if (NULL == list){
        return 0;
    }
    long count = countOfFloatSingleList(list);

    if (count == index){
       return addFloatValueToSingleList(list, value);
    }
    SingleListFloatElement *element = createSingleListFloatElement(value);
    if (NULL == element){
        return 0;
    }
    if (0 == index){
        element->next = list->head;
        list->head = element;
    } else{
        int current = 0;
        SingleListFloatElement *ex_element = list->head;
        for( ex_element != NULL && current < index - 1; ex_element = ex_element->next; current ++);

        element->next = ex_element->next;
        ex_element->next = element;

    }
    return 1;
}
int removeFloatElementFromFloatSingleListAtIndex(FloatSingleList *list, int index)
{
    if (NULL == list){
        return 0;
    }
    long count = countOfFloatSingleList(list);
    if (index >= count){
        return 0;
    }
    if (0 == index){
        removeFirstElementFromFloatSingleList(list);
        return 1;
    }else if(index == count - 1){
        removeLastElementFromFloatSingleList(list);
        return 1;
    }else{
        int current = 0;
        SingleListFloatElement *ex_element = list->head;
        for( ex_element != NULL && current < index - 1; ex_element = ex_element->next; current ++){
        SingleListFloatElement *to_delete = ex_element->next;
        ex_element->next = to_delete->next;
        deleteSingleListFloatElement(to_delete);
    }
    }
    return 1;
}
