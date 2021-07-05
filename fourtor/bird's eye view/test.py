import cv2
import numpy as np
import matplotlib.pyplot as plt

IMAGE_H = 223
IMAGE_W = 1280

src = np.float32([[34, IMAGE_H], [1280, IMAGE_H], [0, 0], [IMAGE_W, 0]])
dst = np.float32([[490, IMAGE_H], [790, IMAGE_H], [0, 0], [IMAGE_W, 0]])
M = cv2.getPerspectiveTransform(src, dst) # The transformation matrix
Minv = cv2.getPerspectiveTransform(dst, src) # Inverse transformation
print("M : \n", M)
print("Minv : \n", Minv)
img = cv2.imread('./1.png') # Read the test img
img = img[413:(413+IMAGE_H), 0:IMAGE_W] # Apply np slicing for ROI crop
warped_img = cv2.warpPerspective(img, M, (IMAGE_W, IMAGE_H)) # Image warping
plt.imshow(cv2.cvtColor(warped_img, cv2.COLOR_BGR2RGB)) # Show results
plt.show()

img_inv = cv2.warpPerspective(warped_img, Minv, (IMAGE_W, IMAGE_H)) # Inverse transformation
plt.imshow(cv2.cvtColor(img_inv, cv2.COLOR_BGR2RGB))
plt.show()
