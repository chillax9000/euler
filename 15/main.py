# Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

# How many such routes are there through a 20×20 grid?

# idea: the number of routes originating from a given point is the sum of the 
#       number of routes originating its direct neighbours (successors)

# modelization:
# end_point : (0, 0), left_neighbour: (1, 0), top_neighbour: (0, 1), etc...

N = 20

def is_inbounds(point):
    x, y = point
    return 0 <= x <= N and 0 <= y <= N

def get_successors(point):
    x, y = point
    return filter(is_inbounds, ((x-1, y), (x, y-1)))

def count_from(point, n_ways):
    if point == (0, 0):
        return 1
    if point in n_ways:
        return n_ways[point]

    _n = sum([count_from(succ, n_ways) for succ in get_successors(point)])
    n_ways[point] = _n
    return _n

print(count_from((N, N), {}))
