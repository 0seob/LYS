import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import cv2
import numpy as np

img = mpimg.imread('3.png')
img = (img*255).astype(np.uint8)
img = img[:,:,:3]

def grayscale(img):
    return cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)

def gaussian_blur(img, kernel_size):
    return cv2.GaussianBlur(img, (kernel_size, kernel_size), 0)

def canny(img, low_threshold, high_threshold):
    return cv2.Canny(img, low_threshold, high_threshold)

def region_of_interest(img, vertices):
    mask = np.zeros_like(img)

    if len(img.shape) > 2:
        channel_count = img.shape[2]
        ignore_mask_color = (255, ) * channel_count
    else:
        ignore_mask_color = 255

    cv2.fillPoly(mask, vertices, ignore_mask_color)

    masked_image = cv2.bitwise_and(img, mask)
    return masked_image

def draw_lines(img, lines, color=[255, 0, 0], thickness = 5):
    for line in lines:
        for x1, y1, x2, y2 in line:
            cv2.line(img, (x1, y1), (x2, y2), color, thickness)

def hough_lines(img, rho, theta, threshold, min_line_len, max_line_gap):
    lines = cv2.HoughLinesP(img, rho, theta, threshold, np.array([]), minLineLength = min_line_len, maxLineGap = max_line_gap)
    line_img = np.zeros((img.shape[0], img.shape[1], 3), dtype = np.uint8)
    draw_lines(line_img, lines)
    return line_img

def weighted_img(img, initial_img, a, b, c):
    return cv2.addWeighted(initial_img, a, img, b, c)

gray = grayscale(img)

kernel_size = 5
blur_gray = gaussian_blur(gray, kernel_size)

low_threshold = 30
high_threshold = 200
edges = canny(blur_gray, low_threshold, high_threshold)

imshape = img.shape
vertices = np.array([[(100, 550),
                      (100, 350),
                      (imshape[1]-100, 350),
                      (imshape[1]-100, 550)]], dtype = np.int32)
mask = region_of_interest(edges, vertices)

rho = 2
theta = np.pi/1800
threshold = 90
min_line_len = 600
max_line_gap = 150

lines = hough_lines(mask, rho, theta, threshold, min_line_len, max_line_gap)

print(img.shape)
print(gray.shape)
print(lines.shape)

lines_edges = weighted_img(lines, img, 0.8, 1, 0)

plt.subplot(221)
plt.imshow(edges, cmap = 'gray')
plt.subplot(222)
plt.imshow(mask, cmap = 'gray')
plt.subplot(223)
plt.imshow(lines, cmap = 'gray')
plt.subplot(224)
plt.imshow(lines_edges, cmap = 'gray')
plt.show()
