import example
import cv2
import numpy as np

image = [
    [[255, 0, 0], [0, 255, 0]],
    [[0, 0, 255], [255, 255, 255]],
    [[128, 128, 128], [64, 64, 64]]
]


""" image = cv2.imread('image.jpg')
cv2.imshow('My Image', image)
cv2.waitKey(0)
cv2.destroyAllWindows() """

""" print(example.add(3, 5))
print(example.sub(8, 7)) """

print(example.process_image(image))