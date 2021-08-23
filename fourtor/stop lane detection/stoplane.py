import cv2
import numpy as np
import matplotlib.pyplot as plt
import math
import copy
from scipy import ndimage

def draw_lines(img, lines, color=[255, 0, 0], thickness=3):
    # If there are no lines to draw, exit.
    if lines is None:
        return
    # Make a copy of the original image.
    img = np.copy(img)
    # Create a blank image that matches the original in size.
    line_img = np.zeros(
        (
            img.shape[0],
            img.shape[1],
            3
        ),
        dtype=np.uint8,
    )
    # Loop over all lines and draw them on the blank image.
    for line in lines:
        for x1, y1, x2, y2 in line:
            cv2.line(line_img, (x1, y1), (x2, y2), color, thickness)
    # Merge the image with the lines onto the original.
    img = cv2.addWeighted(img, 0.8, line_img, 1.0, 0.0)
    # Return the modified image.
    return img

IMAGE_H = 350
IMAGE_W = 1280

src = np.float32([[0, IMAGE_H], [1280, IMAGE_H], [0, 0], [IMAGE_W, 0]])
dst = np.float32([[530, IMAGE_H], [730, IMAGE_H], [0, 0], [IMAGE_W, 0]])

M = cv2.getPerspectiveTransform(src, dst)
#src를 dst로 변경할때 사용하는 행렬을 만드는 함수
Minv = cv2.getPerspectiveTransform(dst, src)
#dst를 src로 변경할때 사용하는 행렬을 만드는 함수

img = cv2.imread('./3.png') # 이미지를 읽어온 후,
img2 = copy.deepcopy(img)
img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
img3 = img2[370:720, 0:1280]
blur = cv2.GaussianBlur(img,(5,5),0)
#kernel = np.array([[0, 0, -1, 0, 0], [0, -1, -2, -1, 0], [0,0,0,0,0], [0, 1, 2, 1, 0], [0, 0, 1, 0, 0]])
#conv_img = cv2.filter2D(blur, -1, kernel)

blur = blur[370:720, 0:1280] # 사진을 원하는 부분만큼 잘라서
warped_img = cv2.warpPerspective(blur, M, (IMAGE_W, IMAGE_H)) #함수에 적용
warped_img2 = cv2.warpPerspective(img3, M, (IMAGE_W, IMAGE_H))
conv_img = copy.deepcopy(warped_img[:, 440:820])

img_sobel_x = cv2.Sobel(conv_img, cv2.CV_64F, 0, 1, ksize = 3)

img_sobel_x2 = copy.deepcopy(img_sobel_x)

for y in range(img_sobel_x.shape[0]):
    for x in range(img_sobel_x.shape[1]):
        if img_sobel_x[y, x] > 50:
            img_sobel_x[y, x] = 150
        elif img_sobel_x[y, x] < -50:
            img_sobel_x[y, x] = -150
        else:
            img_sobel_x[y, x] = 0

for x in range(img_sobel_x.shape[1]):
    for y in range(img_sobel_x.shape[0]):
        if img_sobel_x[y, x] < 0:
            cnt = 0
            for z in range(y-10, y-5):
                if img_sobel_x[z, x] > 0:
                    cnt += 1
            if cnt == 0:
                img_sobel_x[y, x] = 0

img_sobel_x3 = copy.deepcopy(img_sobel_x)

for x in range(img_sobel_x.shape[1]):
    for y in range(img_sobel_x.shape[0]):
        if img_sobel_x[y, x] < 0:
            img_sobel_x[y, x] = 255
        else:
            img_sobel_x[y, x] = 0

img_sobel_x = np.uint8(img_sobel_x)
lines = cv2.HoughLinesP(img_sobel_x, rho = 6, theta = np.pi/180, threshold = 130, lines = np.array([]), minLineLength = 100, maxLineGap = 10)
if lines.all():
    lines[:, :, [0, 2]] += 440

    before1 = []
    before2 = []
    for line in lines:
        for x1, y1, x2, y2 in line:
            point1 = [x1, y1, 1]
            point2 = [x2, y2, 1]
            before1.append(point1)
            before2.append(point2)
    before1 = np.array(before1).transpose()
    before2 = np.array(before2).transpose()

    after1 = np.matmul(Minv, before1)
    after2 = np.matmul(Minv, before2)
    after1 = after1 / after1[2]
    after2 = after2 / after2[2]
    after1 = after1[:2]
    after1 = after1.astype(int)
    after2 = after2[:2]
    after2 = after2.astype(int)

    inv = []
    for i in range(len(after1[0])):
        point = [[after1[0, i], after1[1, i], after2[0, i], after2[1, i]]]
        inv.append(point)

    invr = np.array(inv)

    dl = draw_lines(img2, invr)
    dl2 = draw_lines(warped_img2, lines)
    dl3 = draw_lines(img3, invr)
    invr[:, :, [1, 3]] += 370
    dl4 = draw_lines(img2, invr)

    plt.subplot(334)
    plt.imshow(img_sobel_x2,cmap = 'gray')
    plt.title('filter'), plt.xticks([]), plt.yticks([])
    plt.subplot(335)
    plt.imshow(img_sobel_x3,cmap = 'gray')
    plt.title('Trinarizied'), plt.xticks([]), plt.yticks([])
    plt.subplot(336)
    plt.imshow(img_sobel_x,cmap = 'gray')
    plt.title('Threshold'), plt.xticks([]), plt.yticks([])
    plt.subplot(331)
    plt.imshow(img2,cmap = 'gray')
    plt.title('merge'), plt.xticks([]), plt.yticks([])
    plt.subplot(332)
    plt.imshow(blur,cmap = 'gray')
    plt.title('crop'), plt.xticks([]), plt.yticks([])
    plt.subplot(333)
    plt.imshow(warped_img,cmap = 'gray')
    plt.title('wpm'), plt.xticks([]), plt.yticks([])
    plt.subplot(337)
    plt.imshow(dl2,cmap = 'gray')
    plt.title('merge2'), plt.xticks([]), plt.yticks([])
    plt.subplot(338)
    plt.imshow(dl3,cmap = 'gray')
    plt.title('merge3'), plt.xticks([]), plt.yticks([])
    plt.subplot(339)
    plt.imshow(dl4,cmap = 'gray')
    plt.title('merge4'), plt.xticks([]), plt.yticks([])

    plt.show()

else:
    plt.subplot(234)
    plt.imshow(img_sobel_x2,cmap = 'gray')
    plt.title('filter'), plt.xticks([]), plt.yticks([])
    plt.subplot(235)
    plt.imshow(img_sobel_x3,cmap = 'gray')
    plt.title('Trinarizied'), plt.xticks([]), plt.yticks([])
    plt.subplot(236)
    plt.imshow(img_sobel_x,cmap = 'gray')
    plt.title('Threshold'), plt.xticks([]), plt.yticks([])
    plt.subplot(231)
    plt.imshow(img2,cmap = 'gray')
    plt.title('merge'), plt.xticks([]), plt.yticks([])
    plt.subplot(232)
    plt.imshow(blur,cmap = 'gray')
    plt.title('crop'), plt.xticks([]), plt.yticks([])
    plt.subplot(233)
    plt.imshow(warped_img,cmap = 'gray')
    plt.title('wpm'), plt.xticks([]), plt.yticks([])

    plt.show()

"""
ret_z, conv_img = cv2.threshold(conv_img, 30, 200, cv2.THRESH_BINARY)


img_sobel_y = cv2.Sobel(blur, cv2.CV_64F, 1, 0, ksize = 3)
ret_x, img_sobel_x = cv2.threshold(img_sobel_x, 30, 200, cv2.THRESH_BINARY)
ret_y, img_sobel_y = cv2.threshold(img_sobel_y, 30, 200, cv2.THRESH_BINARY)
"""



"""
plt.subplot(223),plt.imshow(img_sobel_x,cmap = 'gray')
plt.title('SobelX Image'), plt.xticks([]), plt.yticks([])
plt.subplot(224),plt.imshow(img_sobel_y,cmap = 'gray')
plt.title('SobelY Image'), plt.xticks([]), plt.yticks([])
"""
plt.show()
