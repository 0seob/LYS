import cv2
import numpy as np
import matplotlib.pyplot as plt
import sys
import math
"""
theta = math.pi/2
h = 1000
f = 50
ku = 160
kv = 90
u0 = 640
v0 = 360
R = np.array([[1, 0, 0, 0], [0, math.cos(theta), -math.sin(theta), 0], [0, math.sin(theta), math.cos(theta), 0], [0, 0, 0, 1]])
T = np.array([[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, -h/math.sin(theta)], [0, 0, 0, 1]])
K = np.array([[f*ku, 0, u0, 0], [0, f*kv, v0, 0], [0, 0, 1, 0]])

KT = np.dot(K, T)
KTR = np.dot(KT, R)
ipm = np.delete(KTR, 1, axis = 1)
ipm = np.linalg.inv(ipm)
img = cv2.imread('./1.jpeg') # Read the test img
rows, cols = img.shape[:2]


ipmimg = cv2.warpPerspective(img, ipm, (cols, rows))
plt.imshow(cv2.cvtColor(ipmimg, cv2.COLOR_BGR2RGB))
plt.show()
"""

np.set_printoptions(precision = 10, threshold = np.inf)
sys.stdout = open('output4.yml', 'w')

IMAGE_H = 720
IMAGE_W = 1280

src = np.float32([[0, 720], [IMAGE_W, 720], [0, 0], [IMAGE_W, 0]])
dst = np.float32([[280, 640], [360, 640], [0, 0], [640, 0]])
M = cv2.getPerspectiveTransform(src, dst) # The transformation matrix
Minv = cv2.getPerspectiveTransform(dst, src) # Inverse transformation

img = cv2.imread('./1.jpeg') # Read the test img
#img = img[80:(80+IMAGE_H), 0:IMAGE_W] # Apply np slicing for ROI crop

img2 = cv2.warpPerspective(img, M, (IMAGE_W, IMAGE_H)) # Image warping
img2 = img2[0:640, 0:640]
plt.imshow(cv2.cvtColor(img2, cv2.COLOR_BGR2RGB)) # Show results
plt.show()

img_inv = cv2.warpPerspective(img2, Minv, (IMAGE_W, IMAGE_H)) # Inverse transformation
plt.imshow(cv2.cvtColor(img_inv, cv2.COLOR_BGR2RGB))
plt.show()



before = []
for x in range(img2.shape[1]):
    for y in range(img2.shape[0]):
        point = [x, y, 1]
        before.append(point)
before = np.array(before).transpose()

after = np.matmul(Minv, before)
after = after / after[2, :]
after = after[:2, :]
after2 = np.round(after, 10).astype(np.int)
after3 = np.round(after, 10).astype(np.float)

print("%YAML:1.0")
print("---")
print("remap_ipm_x: !!opencv-matrix")
print("   rows: 640")
print("   cols: 640")
print("   dt: f")
print("   data: ", after3[0].transpose().tolist())

print("remap_ipm_y: !!opencv-matrix")
print("   rows: 640")
print("   cols: 640")
print("   dt: f")
print("   data: ", after3[1].transpose().tolist())

height, width, _ = img.shape
result = np.zeros((height, width, 3), dtype = np.uint8)
for pt1, pt2 in zip(before[:2, :].transpose(), after2.transpose()):
    if pt2[1] >= height or pt2[0] >= width:
        continue

    if np.sum(pt2 < 0) >= 1:
        continue

    result[pt1[1], pt1[0]] = img[pt2[1], pt2[0]]

plt.imshow(cv2.cvtColor(result, cv2.COLOR_BGR2RGB))
plt.show()
