/*
 * main.c
 *
 *  Created on: 2015. 4. 16.
 *      Author: Administrator
 */

#include <stdio.h>

#define NODE_NUM 5
#define MAX 999

// recursion
void PrintPath(int path[][NODE_NUM], int src, int des)
{
	if(path[src][des] != 0)
	{
		PrintPath(path, src, path[src][des]);
		printf(" v%d ->", path[src][des]);
		PrintPath(path, path[src][des], des);
	}
}

int main(){
	int start;
	int i, j, k;

/*	int data[NODE_NUM][NODE_NUM] = {
			{ 0, 50, 10, MAX, 45, MAX},
			{ MAX, 0, 15, MAX, 10, MAX},
			{ 20, MAX, 0, 15, MAX, MAX},
			{ MAX, 20, MAX, 0, 35, MAX},
			{ MAX, MAX, MAX, 30, 0, MAX},
			{ MAX, MAX, MAX, 3, MAX, 0}
	};*/

	int data[NODE_NUM][NODE_NUM] = {
			{0, 10, 50, 15, 10},
			{MAX, 0, 5, MAX, MAX},
			{MAX, MAX, 0, MAX, MAX},
			{MAX, MAX, 10, 0, MAX},
			{MAX, MAX, MAX, 5, 0}
	};

	int result[NODE_NUM][NODE_NUM] = {};
	int path[NODE_NUM][NODE_NUM] = {};


	printf("Start Vertex (0~%d) : ", NODE_NUM-1);
	scanf("%d", &start);

	// init
	for(i = 0; i < NODE_NUM; i++){
		for(j = 0; j < NODE_NUM; j++){
			result[i][j] = data[i][j];
		}
	}

	// calc
	for(k = 0; k < NODE_NUM; k++){
		for(i = 0; i < NODE_NUM; i++){
			for(j = 0; j < NODE_NUM; j++){
				if (result[i][j] > result[i][k] + result[k][j]){
					result[i][j] = result[i][k] + result[k][j];
					path[i][j] = k;
				}
			}
		}
	}

//	// result array print
//	for(i = 0; i < NODE_NUM; i++){
//		for(j = 0; j < NODE_NUM; j++){
//			printf("%d ",result[i][j]);
//		}
//		printf("\n");
//	}
//	for(i = 0; i < NODE_NUM; i++){
//		for(j = 0; j < NODE_NUM; j++){
//			printf("%d ",path[i][j]);
//		}
//		printf("\n");
//	}

	// print
	for(i = 0; i < NODE_NUM ; i++){
		if(start == i)
			continue;
		else {
			if(result[start][i] != MAX) {
				printf("v%d ->", start);
				PrintPath(path, start, i);
				printf(" v%d\t\t%d\n", i, result[start][i]);
			}
		}
	}

	return 0;
}
