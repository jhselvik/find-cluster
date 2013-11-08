#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NCOLUMNS 10
#define NROWS 10
#define FALSE 0
#define TRUE !FALSE



void print2darray(int a[][NCOLUMNS]) {
	int i, j;

	for (j = 0; j < NROWS; j++) {
		printf("Row %d: ", j);

		for (i = 0; i < NCOLUMNS; i++) {
			printf("%d ", a[i][j]);
		}

		printf("\n");
	}
	printf("\n");
}


void checkBorder(int a[][NCOLUMNS], int m[][NCOLUMNS], int marker, int i, int j) {
	// Check each border for a hit and not marked

	// Check top - need to avoid going past borders
	if ((j-1 < 0) == FALSE) {
		if (a[i][j-1] == 1 && m[i][j-1] == 0) {
			// Found part of the cluster, mark it
			m[i][j-1] = marker;

			// Continue to mark out the cluster
			checkBorder(a, m, marker, i, j-1);
		}
	}

	// Check right
	if ((i+1 > NROWS) == FALSE) {
		if (a[i+1][j]) {
			m[i+1][j] = marker;
			checkBorder(a, m, marker, i+1, j);
		}
	}

	// Check bottom
	if ((j+1 > NCOLUMNS) == FALSE) {
		if (a[i][j+1]) {
			m[i][j+1] = marker;
			checkBorder(a, m, marker, i, j+1);
		}
	}

	// Check left
	if ((i-1 < 0) == FALSE) {
		if (a[i-1][j]) {
			m[i-1][j] = marker;
			checkBorder(a, m, marker, i-1, j);
		}
	}
}




int findNumClusters(int a[][NCOLUMNS]) {
	int numClusters = 0;
	int map[NROWS][NCOLUMNS];
	int i, j;

	// fill map with 0's
	for (j = 0; j < NROWS; j++) {
		for (i = 0; i < NCOLUMNS; i++) {
			map[i][j] = 0;
		}
	}
	print2darray(map);

	// Iterate through complete array
	for (j = 0; j < NROWS; j++) {
		for (i = 0; i < NCOLUMNS; i++) {

			// If we find a hit and it has not been marked on the map
			if (a[i][j] == 1 && map[i][j] == 0) {
				// This is a new cluster so create a new marker
				numClusters++;
				map[i][j] = numClusters;

				// Mark out the cluster recursivly
				checkBorder(a, map, numClusters, i, j);
			}
		}
	}//end iteration through array

	print2darray(map);

	return numClusters;
}


int main(int argc, char *argv[]) {
	int i, j;
	int r;

	int array[NROWS][NCOLUMNS];
	int row0[] = {0, 1, 0, 1, 0, 0, 0, 0, 0, 0};
	int row1[] = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	int row2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
	int row3[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1};
	int row4[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
	int row5[] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
	int row6[] = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	int row7[] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0};
	int row8[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int row9[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};


	for (i = 0; i < NROWS; i ++) {
		array[i][0] = row0[i];
	}
	for (i = 0; i < NROWS; i ++) {
		array[i][1] = row1[i];
	}
	for (i = 0; i < NROWS; i ++) {
		array[i][2] = row2[i];
	}
	for (i = 0; i < NROWS; i ++) {
		array[i][3] = row3[i];
	}
	for (i = 0; i < NROWS; i ++) {
		array[i][4] = row4[i];
	}
	for (i = 0; i < NROWS; i ++) {
		array[i][5] = row5[i];
	}
	for (i = 0; i < NROWS; i ++) {
		array[i][6] = row6[i];
	}
	for (i = 0; i < NROWS; i ++) {
		array[i][7] = row7[i];
	}
	for (i = 0; i < NROWS; i ++) {
		array[i][8] = row8[i];
	}
	for (i = 0; i < NROWS; i ++) {
		array[i][9] = row9[i];
	}


	// To pass array
	print2darray(array);

	printf("%d\n\n", findNumClusters(array));

}