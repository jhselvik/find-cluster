// Example input array:
//    - cells with 0 are shown as blank for visual clarity
//    - the size of this example is arbitrary, the input parameter is a 2-D array of any size
// +-+-+-+-+-+-+-+-+
// | |1| |1| | | | |
// +-+-+-+-+-+-+-+-+
// | |1|1|1| | |1| |
// +-+-+-+-+-+-+-+-+
// | | | | | | |1|1|
// +-+-+-+-+-+-+-+-+
// | | |1|1| | |1| |
// +-+-+-+-+-+-+-+-+
// | | |1|1|1| | | |
// +-+-+-+-+-+-+-+-+
// | | | | | | | |1|
// +-+-+-+-+-+-+-+-+

// +-+-+-+-+-+-+-+-+
// | |1| | | | | | |
// +-+-+-+-+-+-+-+-+
// | |1|1| | | |a| |
// +-+-+-+-+-+-+-+-+
// | | | |l|m|n|b|c|
// +-+-+-+-+-+-+-+-+
// | | |j|k| | |d| |
// +-+-+-+-+-+-+-+-+
// | | |i|h|g|f|e| |
// +-+-+-+-+-+-+-+-+
// | | | | | | | |1|
// +-+-+-+-+-+-+-+-+

// Same array, annotated to show each cluster:
//    - There are 4 clusters in this example
// +-+-+-+-+-+-+-+-+
// | |1| | | | | | |
// +-+-+-+-+-+-+-+-+
// | |1|1| | | |4| |
// +-+-+-+-+-+-+-+-+
// | | | |2| | |4|4|
// +-+-+-+-+-+-+-+-+
// | | |2|2| | |4| |
// +-+-+-+-+-+-+-+-+
// | | |2|2|2| | | |
// +-+-+-+-+-+-+-+-+
// | | | | | | | |3|
// +-+-+-+-+-+-+-+-+

// In this example, the return value for the function would be the integer 4.




int findNumClusters(int *array, int x, int y)
    int numClusters = 0;
    int *map[x][y];
    
    int i = 0;    //rows
    int j = 0;    //coll
    
    for (j = 0; j < y; j++) {
        for (i=0; i < x; i++) {
            if (array[i][j] == 1 && map[i][j] == 0)
                numClusters++;
                checkBounds(map, numClusters, i, j);
        }
    }
}

    
    
    
void checkBounds(int *map, int *array, int marker, int i, int j){
    if(array[i][j-1] == 1 && map[i][j-1] == 0)
        checkBounds(map, array, marker, i, (j-1));
    if(array[i+1][j] == 1 && map[i][j-1] == 0)
        checkBounds(map, array, marker, i, (j-1));
        

}