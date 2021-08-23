import cv2
import numpy as np
import matplotlib.pyplot as plt
import math
import copy
from scipy import ndimage

IMAGE_H = 350
IMAGE_W = 1280

src = np.float32([[0, IMAGE_H], [1280, IMAGE_H], [0, 0], [IMAGE_W, 0]])
dst = np.float32([[530, IMAGE_H], [730, IMAGE_H], [0, 0], [IMAGE_W, 0]])

M = cv2.getPerspectiveTransform(src, dst)
print(M)
#src를 dst로 변경할때 사용하는 행렬을 만드는 함수
Minv = cv2.getPerspectiveTransform(dst, src)
print(Minv)
#dst를 src로 변경할때 사용하는 행렬을 만드는 함수

img = cv2.imread('./3.png') # 이미지를 읽어온 후,
img2 = copy.deepcopy(img)
img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
img3 = img2[370:720, 0:1280]
blur = cv2.GaussianBlur(img,(5,5),0)
blur = blur[370:720, 0:1280] # 사진을 원하는 부분만큼 잘라서
warped_img = cv2.warpPerspective(blur, M, (IMAGE_W, IMAGE_H)) #함수에 적용
back_img = cv2.warpPerspective(warped_img, Minv, (IMAGE_W, IMAGE_H))
plt.subplot(221)
plt.imshow(warped_img,cmap = 'gray')
plt.title('wpm'), plt.xticks([]), plt.yticks([])
plt.subplot(222)
plt.imshow(back_img,cmap = 'gray')
plt.title('og'), plt.xticks([]), plt.yticks([])
plt.subplot(223)
plt.imshow(img2,cmap = 'gray')
plt.title('og'), plt.xticks([]), plt.yticks([])
plt.show()
