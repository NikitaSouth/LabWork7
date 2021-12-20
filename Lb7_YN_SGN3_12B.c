//Лабораторная работа №7 Вариант 0
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int** memoryAllocate(int matrixHeight, int matrixWidth);
void matrixFree(int** matrixName, int matrixHight);
void matrixInput(int** matrixName, int matrixHight, int matrixWidth);
void matrixOutput(int** matrixName, int matrixHeight, int matrixWidth);
void matrixShuffle(int** matrixName, int matrixHeight, int matrixWidth);
int formatCheck(int** matrixName, int matrixHeight, int matrixWidth);
void bubbleSort(int** matrixName, int matrixHeight, int matrixWidth);

int main()
{
	int** matrix;
	int matrixWidth, matrixHeight;
	printf("Please, enter width and height of the matrix: ");
	scanf_s("%d%d", &matrixWidth, &matrixHeight);
	if(matrixWidth <= 1) {
		printf("Incorrect width of the matrix\a");
		return 0;
	} else if (matrixHeight <= 1) {
		printf("Incorrect height of the matrix\a");
		return 0;
	}
	matrix = memoryAllocate(matrixHeight, matrixWidth);
	if(matrix == NULL){
		printf("An error in memory allocation has occured\a");
		return 0;
	}
	matrixInput(matrix, matrixHeight, matrixWidth);
	printf("Original matrix: ");
	matrixOutput(matrix, matrixHeight, matrixWidth);
	printf("\nSorted matrix: ");
	matrixShuffle(matrix, matrixHeight, matrixWidth);
	matrixOutput(matrix, matrixHeight, matrixWidth);
	return 0;
}

int** memoryAllocate(int matrixHeight, int matixWidth)
{
	int** matrix = (int**)malloc(sizeof(int*) * matrixHeight);
	if (matrix == NULL) {
		return matrix;
	}
	for (int i = 0; i < matrixHeight; i++) {
		*(matrix + i) = (int*)malloc(sizeof(int) * matixWidth);
		if (*(matrix + i) == NULL) {
			matrixFree(matrix, i);
			return matrix;
		}
	}
	return matrix;
}

void matrixFree(int** matrixName, int matrixHight)
{
	for (int i = 0; i < matrixHight; i++){
		free(*(matrixName + i));
	}
	free(matrixName);
}

void matrixInput(int** matrixName, int matrixHeigth, int matrixWidth)
{
	for (int i = 0; i < matrixHeigth; i++){
		for (int j = 0; j < matrixWidth; j++) {
			printf("Matrix [%d][%d] = ", i, j);
			scanf_s("%d", &*(*(matrixName + i) + j));
		}
	}
}

void matrixOutput(int** matrixName, int matrixHeight, int matrixWidth)
{
	for (int i = 0; i < matrixHeight; i++) {
		printf("\n");
		for (int j = 0; j < matrixWidth; j++) {
			printf("[%d]", *(*(matrixName + i) + j));
		}
	}
}

void matrixShuffle(int** matrixName, int matrixHeight, int matrixWidth)
{

}

int formatCheck(int** matrixName, int matrixHeight, int matrixWidth)
{
	for (int i = 0; i < matrixHeight; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < matrixWidth; j++) {
				if (*(*(matrixName + i) + j) > *(*(matrixName + i) + j)) {
					return 0;
				}
			}
		} else {
			for (int j = 0; j < matrixWidth; j++) {
				if (*(*(matrixName + i) + j) < *(*(matrixName + i) + j)) {
					return 0;
				}
			}
		}
	}
	for (int i = 0; i < matrixHeight; i++) {
		if (i % 2 == 0) {
			j = matrixWidth - 1;
		} else {
			j = 0;
		}
		if ((*(*matrixName + i + 1) + j) < (*(*matrixName + i) + j)) {
			return 0;
		}
	}
	return 1;
}

void bubbleSort(int** matrixName, int matrixHeight, int matrixWidth) {
	int temp;
	for (int k = 0; k < matrixHeight; k++) {
		if (k % 2 == 0) {
			for (int i = 0; i < matrixWidth; i++){
				for (int j = 0; )
			}
		}
	}
}