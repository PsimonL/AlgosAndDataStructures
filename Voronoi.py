import matplotlib.pyplot as plt
import math
from PIL import Image
import random


def generate_voronoi_diagram(width, height, no_of_cells):
    Voronoi = Image.new("RGB", (width, height))
    place_pixel = Voronoi.putpixel
    image_x, image_y = Voronoi.size
    list_x = [250, 150, 400]
    list_y = [200, 300, 450]
    red = []
    green = []
    blue = []

    for i in range(no_of_cells):
        # list_x.append(random.randrange(image_x))
        # list_y.append(random.randrange(image_y))
        red.append(random.randint(0, 256))
        green.append(random.randint(0, 256))
        blue.append(random.randint(0, 256))

    temp = 0
    for OY in range(image_y):
        for OX in range(image_x):
            dmin = math.hypot(image_x - 1, image_y - 1)
            temp = -1
            for k in range(no_of_cells):
                d = math.hypot(list_x[k] - OX, list_y[k] - OY)
                if d < dmin:
                    dmin = d
                    temp = k
                else:
                    pass
            #place_pixel((OX, OY), (red[temp], green[temp], blue[temp]))
    Voronoi.save("Voronoi.png", "PNG")
    Voronoi.show()

    print(list_x)
    print(list_y)
    OX, OY = list_x, list_y
    plt.scatter(OX, OY, color='blue')
    plt.title('dots')
    plt.show()
# MOSTLY BASED ON:
# https://stackoverflow.com/questions/55545400/how-to-draw-a-point-in-an-image-using-given-coordinate
# https://www.youtube.com/watch?v=j2c3kumwoAk
# https://cs.brown.edu/courses/cs252/misc/resources/lectures/pdf/notes10.pdf


if __name__ == "__main__":
    generate_voronoi_diagram(800, 800, 3)
