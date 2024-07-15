/******************************************************************************
 * Copyright (C) 2024 by @author
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Jericho Lagang is not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief C language programming exercise, 
 *			Performig statistical functions on data
 *
 *
 * @author Jericho Lagang
 * @date 2024-07-14
 *
 *
 */

#include <stdio.h>
#include <stdint.h>
#include "stats.h"


/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90,};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  stat Array;

  Array.numArray = test;
  Array.arrayLength = SIZE;
  Array.max = 0;
  Array.min = 0xFF;
  Array.mean = 0;
  Array.median = 0;

  sort_array(Array.numArray, Array.arrayLength);
  Array.min = find_min(Array.numArray, Array.arrayLength);
  Array.max = find_max(Array.numArray, Array.arrayLength);
  Array.mean = find_mean(Array.numArray, Array.arrayLength);
  Array.median = find_median(Array.numArray, Array.arrayLength);
  print_array(Array.numArray, Array.arrayLength);
  print_statistics(Array);
}

void print_statistics(stat ArrayStats){
  printf("Array Min: %u\n", ArrayStats.min);
  printf("Array Max: %u\n", ArrayStats.max);
  printf("Array Mean: %u\n", ArrayStats.mean);
  printf("Array Median: %u\n", ArrayStats.median);
  printf("Array Size: %u\n", ArrayStats.arrayLength);
}

void print_array(uint8_t *arrayPtr, uint8_t arrayLength){

  for(uint8_t i=0; i<arrayLength; i++){
    printf("array[%u]: %u\n", i, *(arrayPtr + sizeof(char)*i));
  }
  printf("\n");
  return;
}

void sort_array(uint8_t *arrayPtr, uint8_t arrayLength){
  uint8_t i, j = 0;
  uint8_t temp;
  // Sort Array
  for(i=0; i<arrayLength; i++){
    for(j=i+1; j<arrayLength; j++){
      if(arrayPtr[i]<arrayPtr[j]){
        temp = arrayPtr[i];
        arrayPtr[i]=arrayPtr[j];
        arrayPtr[j]=temp;
      }
    }
  }
}

uint8_t find_min(uint8_t *arrayPtr, uint8_t arrayLength){
  uint8_t minValue=0xFF;

  for (uint8_t i=0; i<arrayLength; i++){
    if (arrayPtr[i] < minValue){
      minValue = arrayPtr[i];
    }
  }

  return minValue;
}

uint8_t find_max(uint8_t *arrayPtr, uint8_t arrayLength){
  uint8_t maxValue=0;

  for (uint8_t i=0; i<arrayLength; i++){
    if (arrayPtr[i] > maxValue){
      maxValue = arrayPtr[i];
    }
  }

  return maxValue;
}

uint8_t find_mean(uint8_t *arrayPtr, uint8_t arrayLength){
  uint32_t avg=0;

  for(uint8_t i=0; i<arrayLength; i++){
    avg+= arrayPtr[i];
  }
  
  return (avg/arrayLength);
}

uint8_t find_median(uint8_t *arrayPtr, uint8_t arrayLength){

  sort_array(arrayPtr, arrayLength);


  if (arrayLength%2){
    return arrayPtr[arrayLength/2];
  }

  uint8_t avg = (arrayPtr[arrayLength/2 - 1]+arrayPtr[arrayLength/2])/2;
  return avg;
}