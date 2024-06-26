# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/4/2 10:30
# @Author            : kasperfan
# @Site              : 
# @File              : read_data.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
from torch.utils.data import Dataset
import cv2
from PIL import Image
import os

# cv2.
class MyData(Dataset):

    def __init__(self, root_dir, label_dir):
        self.root_dir = root_dir
        self.label_dir = label_dir
        self.path = os.path.join(root_dir, label_dir)
        self.img_path = os.listdir(self.path)

    def __getitem__(self, idx):
        img_name = self.img_path[idx]
        img_item_path = os.path.join(self.root_dir, self.label_dir, img_name)
        img = Image.open(img_item_path)
        label = self.label_dir
        return img, label

    def __len__(self):
        return len(self.img_path)


root_dir = "PyTorchLearn/dataset/train"
ants_label_dir = "ants"
bees_label_dir = "bees"
ants_dataset = MyData(root_dir, ants_label_dir)
bees_dataset = MyData(root_dir, bees_label_dir)



