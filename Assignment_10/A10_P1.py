import random

# Function to check if a position (row, col) is safe for placing a queen
def is_safe(board, row, col):
    # Check the column
    for i in range(row):
        if board[i] == col or abs(board[i] - col) == row - i:
            return False
    return True

# Function to find a random solution to the 8-queens problem
def solve_8_queens():
    # Initialize the board with -1 (indicating no queens are placed yet)
    board = [-1] * 8
    
    while True:
        # Randomly shuffle columns for each row
        board = random.sample(range(8), 8)
        
        # Check if this random configuration is safe
        safe = True
        for row in range(8):
            if not is_safe(board, row, board[row]):
                safe = False
                break
        
        # If a valid solution is found, return it
        if safe:
            return board

# Function to display the chessboard with queens placed
def print_board(board):
    for row in range(8):
        line = ['Q' if col == board[row] else '.' for col in range(8)]
        print(' '.join(line))

# Main function to solve the problem
if __name__ == "__main__":
    solution = solve_8_queens()
    print("Solution to the 8-queens problem:")
    print_board(solution)
