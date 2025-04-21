import example
import cv2
import numpy as np


image = cv2.imread('image.jpg')

image = image.tolist()

print(image)

image = example.choose_colors(image, [[0, 0, 0], [102,146,68]])

image =np.array(image, dtype=np.uint8)

image_bgr = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)

cv2.imshow("Image", image_bgr)
cv2.waitKey(0)  # Waits for a key press
cv2.destroyAllWindows()