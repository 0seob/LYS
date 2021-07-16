import cv2
import numpy as np
import matplotlib.pyplot as plt
import sys

ipm_remap_file_path='./output4.yml'

fs = cv2.FileStorage(ipm_remap_file_path, cv2.FILE_STORAGE_READ)
remap_to_ipm_x = fs.getNode('remap_ipm_x').mat()
remap_to_ipm_y = fs.getNode('remap_ipm_y').mat()
ret = {
    'remap_to_ipm_x': remap_to_ipm_x,
    'remap_to_ipm_y': remap_to_ipm_y,
}
fs.release()

remap_to_ipm_x = ret['remap_to_ipm_x']
remap_to_ipm_y = ret['remap_to_ipm_y']


tmp_mask = cv2.imread('./1.png')
tmp_ipm_mask = cv2.remap(
    tmp_mask,
    remap_to_ipm_x,
    remap_to_ipm_y,
    interpolation=cv2.INTER_NEAREST
)
plt.imshow(cv2.cvtColor(tmp_ipm_mask, cv2.COLOR_BGR2RGB))
plt.show()
