def find_l_shaped_links(matrix, x, y):
    # Create a stack to keep track of the current path
    stack = []

    # Create a set to keep track of visited cells
    visited = set()

    # Add the starting cell to the stack and mark it as visited
    stack.append((x, y))
    visited.add((x, y))

    # Create a list to store the L-shaped links that are found
    links = []

    while stack:
        # Get the current cell from the top of the stack
        x, y = stack[-1]

        # Check the cell above, below, to the left, and to the right of the current cell
        for dx, dy in [(0, -1), (0, 1), (-1, 0), (1, 0)]:
            # Calculate the coordinates of the new cell
            x2, y2 = x + dx, y + dy

            # Ignore the new cell if it is out of bounds or has already been visited
            if x2 < 0 or x2 >= len(matrix) or y2 < 0 or y2 >= len(matrix[0]) or (x2, y2) in visited:
                continue

            # If the new cell contains a 1, add it to the path and mark it as visited
            if matrix[x2][y2] == 1:
                stack.append((x2, y2))
                visited.add((x2, y2))
                break

        # If no new cells were found, pop the current cell off the stack
        else:
            stack.pop()

        # If the current path forms an L-shaped link to another 1, add it to the list of links
        if len(stack) >= 3 and (x + 1, y + 1) in stack and (x - 1, y + 1) in stack:
            links.append(stack.copy())

    return links

