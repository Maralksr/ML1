# -*- coding: utf-8 -*-
"""
Created on Fri Sep  7 20:28:33 2018

@author: maral
"""

def extract_feature(image):
	image = np.reshape(image, (16, 16))
	flip_image = np.flip(image, 1)
	diff = abs(image-flip_image)
	sys  = -sum(sum(diff))/256
	intense = sum(sum(image))/256
	return sys, intense
