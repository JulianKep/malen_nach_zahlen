import example
import cv2
import numpy as np

""" image = [
    [[255, 0, 0], [0, 255, 0]],
    [[0, 0, 255], [255, 255, 255]],
    [[128, 128, 128], [64, 64, 64]]
] """

colors = np.array([[100, 100, 100], [200, 200, 200]])

image = cv2.imread('image.jpg')
image = np.array(example.choose_colors(image, colors))

cv2.imshow('My Image', image)
cv2.waitKey(0)
cv2.destroyAllWindows()

""" print(example.add(3, 5))
print(example.sub(8, 7)) """

""" print(example.process_image(image)) """

print(example.choose_colors(image))