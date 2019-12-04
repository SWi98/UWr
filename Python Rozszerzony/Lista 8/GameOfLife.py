import numpy as np 
import pylab as plt

def print_game(how_many, data):
    for i in range(how_many):
        if i > 0:
            data = new_data(data)
        plt.imshow(data, cmap = 'hot_r')
        plt.xticks([])
        plt.yticks([])
        plt.draw()
        plt.pause(0.2)


def new_data(old_data):
    rows_count = old_data.shape[0]
    columns_count = old_data.shape[1]
    res = np.full((rows_count, columns_count), 0, dtype=int)

    for i in range(rows_count):
        for j in range(columns_count):
            living_neigh = 0
            x_axis = [1, -1, 0, 1, -1, 0, 1, -1]
            y_axis = [0, 0, -1, -1, -1, 1, 1, 1]
            for k in range(8):
                new_x = x_axis[k] + i
                new_y = y_axis[k] + j
                if new_x >= 0 and new_x < rows_count and new_y >= 0 and new_y < columns_count:
                    if old_data[new_x][new_y] == 1:
                        living_neigh += 1
            if (old_data[i][j] == 0 and living_neigh == 3) or (old_data[i][j] == 1 and (living_neigh == 2 or living_neigh == 3)):
                res[i][j] = 1

    return res            
                        

print_game(200000, np.random.randint(0, 2, (40, 40)))

