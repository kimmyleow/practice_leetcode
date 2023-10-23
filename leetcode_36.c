bool isValidSudoku(char** board, int boardSize, int boardColSize){
    int row = 0;
    int col = 0;
    int gridrow = 0;
    int gridcol = 0;
    int num = 0;
    int map[10];

    //if(boardSize != 9 || boardColSize != 9) return false;

    for(row=0; row<9; row++){
        memset(map, 0, sizeof(map));
        for(col=0; col<9; col++){
            if(board[row][col] == '.') continue; //skip checking empty cell
            if(board[row][col] < '0' || board[row][col] > '9') return false; //check value within 0-9
            num = board[row][col] - '0';
            if(map[num] != 0) return false;
            map[num] = 1;
        }
    }

    for(col=0; col<9; col++){
        memset(map, 0, sizeof(map));
        for(row=0; row<9; row++){
            if(board[row][col] == '.') continue; //skip checking empty cell
            num = board[row][col] - '0';
            if(map[num] != 0) return false;
            map[num] = 1;
        }
    }

    for(row=0; row<9; row+=3){
        for(col=0; col<9; col+=3){
            memset(map, 0, sizeof(map));
            for(gridrow=row; gridrow<row+3; gridrow++){
                for(gridcol=col; gridcol<col+3; gridcol++){
                    if(board[gridrow][gridcol] == '.') continue;
                    num = board[gridrow][gridcol] - '0';
                    if(map[num] != 0) return false;
                    map[num] = 1;
                }
            }
        }
    }

    return true;
}