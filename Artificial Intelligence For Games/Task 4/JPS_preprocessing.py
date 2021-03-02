import sys
import math
import numpy as np

TILE_WALL = 1
GROUND = 0


class Point():
    def __init__(self, nw = 0, north = 0, ne = 0, west = 0, east = 0, sw = 0, south = 0, se = 0):
        self.nw = nw
        self.north = north
        self.ne = ne
        self.west = west
        self.east = east
        self.sw = sw
        self.south = south
        self.se = se


class Game():
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.terrain = np.zeros(shape = (self.height, self.width))
        self.distances = [[Point() for _ in range(width)] for _ in range(height)]
        self.jump_points = [[Point() for _ in range(width)] for _ in range(height)]

    def add_row(self, row, row_number):
        self.terrain[row_number, :] = row

    def find_primary_jump_points(self):
        # down
        for col in range(self.width):
            for row in range(1, self.height):
                if self.terrain[row][col] != TILE_WALL and self.terrain[row-1][col] != TILE_WALL:
                    if ((col > 0 and self.terrain[row-1][col-1] == TILE_WALL and self.terrain[row][col-1] != TILE_WALL) or
                        (col < self.width-1 and self.terrain[row-1][col+1] == TILE_WALL and self.terrain[row][col+1] != TILE_WALL)):
                            self.jump_points[row][col].south = 1
        # up
        for col in range(self.width):
            for row in range(self.height - 2, -1, -1):
                if self.terrain[row][col] != TILE_WALL and self.terrain[row+1][col] != TILE_WALL:
                    if ((col > 0 and self.terrain[row+1][col-1] == TILE_WALL and self.terrain[row][col-1] != TILE_WALL) or
                        (col < self.width-1 and self.terrain[row+1][col+1] == TILE_WALL and self.terrain[row][col+1] != TILE_WALL)):
                            self.jump_points[row][col].north = 1 

        # right
        for row in range(self.height):
            for col in range(1, self.width):
                if self.terrain[row][col] != TILE_WALL and self.terrain[row][col-1] != TILE_WALL:
                    if((row > 0 and self.terrain[row-1][col-1] == TILE_WALL and self.terrain[row-1][col] != TILE_WALL) or
                       (row < self.height-1 and self.terrain[row+1][col-1] == TILE_WALL and self.terrain[row+1][col] != TILE_WALL)):
                        self.jump_points[row][col].east = 1

        # left
        for row in range(self.height):
            for col in range(self.width - 2, -1, -1):
                if self.terrain[row][col] != TILE_WALL and self.terrain[row][col+1] != TILE_WALL:
                    if((row > 0 and self.terrain[row-1][col+1] == TILE_WALL and self.terrain[row-1][col] != TILE_WALL) or
                       (row < self.height-1 and self.terrain[row+1][col+1] == TILE_WALL and self.terrain[row+1][col] != TILE_WALL)):
                        self.jump_points[row][col].west = 1

    def calculate_horizontal_distances(self):
        for r in range(self.height):
            count = -1
            jumpPointLastSeen = False
            for c in range(self.width):
                if self.terrain[r][c] == TILE_WALL:
                    count = -1
                    jumpPointLastSeen = False
                    self.distances[r][c].west = 0
                    continue

                count += 1
                if jumpPointLastSeen: self.distances[r][c].west = count
                else: self.distances[r][c].west = -count
                if self.jump_points[r][c].west:
                    count = 0
                    jumpPointLastSeen = True

        for r in range(self.height):
            count = -1
            jumpPointLastSeen = False
            for c in range(self.width - 1, -1, -1):
                if self.terrain[r][c] == TILE_WALL:
                    count = -1
                    jumpPointLastSeen = False
                    self.distances[r][c].east = 0
                    continue

                count += 1
                if jumpPointLastSeen: self.distances[r][c].east = count
                else: self.distances[r][c].east = -count
                if self.jump_points[r][c].east:
                    count = 0
                    jumpPointLastSeen = True        

    def calculate_vertical_distances(self):
        for c in range(self.width):
            count = -1
            jumpPointLastSeen = False
            for r in range(self.height):
                if self.terrain[r][c] == TILE_WALL:
                    count = -1
                    jumpPointLastSeen = False
                    self.distances[r][c].north = 0
                    continue
                    
                count += 1
                if jumpPointLastSeen: self.distances[r][c].north = count
                else: self.distances[r][c].north = -count
                if self.jump_points[r][c].north:
                    count = 0
                    jumpPointLastSeen = True    
                    
        for c in range(self.width):
            count = -1
            jumpPointLastSeen = False
            for r in range(self.height - 1, -1, -1):
                if self.terrain[r][c] == TILE_WALL:
                    count = -1
                    jumpPointLastSeen = False
                    self.distances[r][c].south = 0
                    continue
                    
                count += 1
                if jumpPointLastSeen: self.distances[r][c].south = count
                else: self.distances[r][c].south = -count
                if self.jump_points[r][c].south:
                    count = 0
                    jumpPointLastSeen = True 
                    
    def calculate_nw_distances(self):
        for r in range(self.height):
            for c in range(self.width):
                if self.terrain[r][c] != TILE_WALL:
                    if (r == 0 or c == 0 or self.terrain[r-1][c] == TILE_WALL or
                        self.terrain[r][c-1] == TILE_WALL or self.terrain[r-1][c-1] == TILE_WALL):
                        self.distances[r][c].nw = 0
                    elif (self.distances[r-1][c-1].north > 0 or self.distances[r-1][c-1].west > 0):
                        self.distances[r][c].nw = 1
                    else:
                        jump_distance = self.distances[r-1][c-1].nw
                        if jump_distance > 0:
                            self.distances[r][c].nw = 1 + jump_distance
                        else:
                            self.distances[r][c].nw = -1 + jump_distance
    
    def calculate_ne_distances(self):
        for r in range(self.height):
            for c in range(self.width - 1, -1, -1):
                if self.terrain[r][c] != TILE_WALL:
                    if (r == 0 or c == self.width-1 or self.terrain[r-1][c] == TILE_WALL or
                        self.terrain[r][c+1] == TILE_WALL or self.terrain[r-1][c+1] == TILE_WALL):
                        self.distances[r][c].ne = 0
                    elif (self.distances[r-1][c+1].north > 0 or self.distances[r-1][c+1].east > 0):
                        self.distances[r][c].ne = 1
                    else:
                        jump_distance = self.distances[r-1][c+1].ne
                        if jump_distance > 0:
                            self.distances[r][c].ne = 1 + jump_distance
                        else:
                            self.distances[r][c].ne = -1 + jump_distance
            
            
    def calculate_sw_distances(self):
        for r in range(self.height - 1, -1, -1):
            for c in range(self.width):
                if self.terrain[r][c] != TILE_WALL:
                    if (r == self.height-1 or c == 0 or self.terrain[r][c-1] == TILE_WALL or
                        self.terrain[r+1][c-1] == TILE_WALL or self.terrain[r+1][c] == TILE_WALL):
                        self.distances[r][c].sw = 0
                    elif (self.distances[r+1][c-1].south > 0 or self.distances[r+1][c-1].west > 0):
                        self.distances[r][c].sw = 1
                    else:
                        jump_distance = self.distances[r+1][c-1].sw
                        if jump_distance > 0:
                            self.distances[r][c].sw = 1 + jump_distance
                        else:
                            self.distances[r][c].sw = -1 + jump_distance
                            
            
    def calculate_se_distances(self):
        for r in range(self.height - 1, -1, -1):
            for c in range(self.width -1, -1, -1):
                if self.terrain[r][c] != TILE_WALL:
                    if (r == self.height-1 or c == self.width -1 or self.terrain[r][c+1] == TILE_WALL or
                        self.terrain[r+1][c+1] == TILE_WALL or self.terrain[r+1][c] == TILE_WALL):
                        self.distances[r][c].se = 0
                    elif (self.distances[r+1][c+1].south > 0 or self.distances[r+1][c+1].east > 0):
                        self.distances[r][c].se = 1
                    else:
                        jump_distance = self.distances[r+1][c+1].se
                        if jump_distance > 0:
                            self.distances[r][c].se = 1 + jump_distance
                        else:
                            self.distances[r][c].se = -1 + jump_distance                            
            
    def calculate_distances(self):
        self.calculate_horizontal_distances()
        self.calculate_vertical_distances()
        self.calculate_nw_distances()
        self.calculate_ne_distances()
        self.calculate_sw_distances()
        self.calculate_se_distances()
                

# Compute the proper wall / jump point distances, according to the preprocessing phase of the JPS+ algorithm.
# width: Width of the map
# height: Height of the map


debug = False
width, height = [int(i) for i in input().split()]
game = Game(width, height)
for i in range(height):
    row = input()
    row = list(map(lambda x: 0 if x == '.' else 1, list(row)))
    game.add_row(row, i)

# Write an action using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)
if debug:
    print(game.terrain)
    game.find_primary_jump_points()
    game.calculate_distances()
else:
    game.find_primary_jump_points()
    game.calculate_distances()
    for r in range(height):
        for c in range(width):
            if game.terrain[r][c] != TILE_WALL:
                print(f"{c} {r} {game.distances[r][c].north} {game.distances[r][c].ne} {game.distances[r][c].east} {game.distances[r][c].se} {game.distances[r][c].south} {game.distances[r][c].sw} {game.distances[r][c].west} {game.distances[r][c].nw}")
# For each empty tile of the map, a line containing "column row N NE E SE S SW W NW".