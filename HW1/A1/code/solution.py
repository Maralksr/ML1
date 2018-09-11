from matplotlib import pyplot as plt
import numpy as np 
import math
import matplotlib.pyplot as plt

'''
Homework1: perceptron classifier
'''
def load_data(dataloc):
	data = np.loadtxt(dataloc, unpack='true')
	data = np.transpose(data, (1,0))
	return data	


def extract_feature(image):
	image = np.reshape(image, (16, 16))
	flip_image = np.flip(image, 1)
	diff = abs(image-flip_image)
	sys  = -sum(sum(diff))/256
	intense = sum(sum(image))/256
	return sys, intense


def load_features(dataloc):
	data = load_data(dataloc)
	n, _ = data.shape
	data_set = []
	for i in range(n):
		label = 1 if data[i, 0]==1 else -1
		image = data[i, 1:]
		sys, intense = extract_feature(image)
		data_set.append([label, 1, sys, intense])
	return np.array(data_set)[:,1:], np.array(data_set)[:,0]
a,b= load_features("../data/train.txt")


def equal(x, y):
	return True if abs(x-y) < 0.001 else False


def sign(x):
	return 1 if x > 0 else -1

#-------------- Implement your code Below -------------#
    

def show_images(data):
    Data=load_data(data)
    #Images=Data[0:2,1:]
    #Image1= np.reshape(Images[0,:],(16,16))
    #Image2= np.reshape(Images[1,:],(16,16))
    Image1= data[0:16,:]
    Image2=data[16:,:]
    fig= plt.figure()
    plt.title('Displaying the first two images from data')
    fig0=plt.gca()
    fig0.axes.get_xaxis().set_visible(False)
    fig0.axes.get_yaxis().set_visible(False)
    
    fig.add_subplot(121)
    plt.imshow(Image1)
    fig1=plt.gca()
    fig1.axes.get_xaxis().set_visible(False)
    fig1.axes.get_yaxis().set_visible(False)
    
    fig.add_subplot(122)
    plt.imshow(Image2)
    fig2=plt.gca()
    fig2.axes.get_xaxis().set_visible(False)
    fig2.axes.get_yaxis().set_visible(False)
    
    plt.show()
    
    '''
    This function is used for plot image and save it.
    Args
    data: Two images from train data with shape (2, 16, 16). The shape represents total 2
	      images and each image has size 16 by 16. 
          Returns:
		Do not return any arguments, just save the images you plot for your report.
    
        '''
        
#show_images("../data/train.txt")

#show_images("../data/test.txt")


def show_features(data, label):
    x=data[:,1]
    y=data[:,2]
    plt.figure()
    plt.xlabel('Average Intensity', rotation= 'horizontal')
    plt.ylabel('Symmetry', rotation= 'vertical')
    for ii in range(len(x)):
        if label[ii]==1:
            plt.scatter(x[ii], y[ii], c='r', marker='*')
        elif label[ii]==-1:
            plt.scatter(x[ii],y[ii], c='b', marker= '+')
    plt.title('Feature Visualization')
            
feature, label= load_features("../data/train.txt")
show_features(feature,label)

'''
	This function is used for plot a 2-D scatter plot of the features and save it. 

	Args:
	data: train features with shape (1561, 2). The shape represents total 1561 samples and 
	      each sample has 2 features.
	label: train data's label with shape (1561,1). 
		   1 for digit number 1 and -1 for digit number 5.
	
	Returns:
	Do not return any arguments, just save the 2-D scatter plot of the features you plot for your report.
	'''

def perceptron(data, label, max_iter, learning_rate):
    w= [1,1,1]
    for i in range(max_iter):
        for k in range(len(label)):
            b=np.dot(w,data[k])
            if not equal(sign(b), label[k]):
                w= w+ label[k]* data[k]
    return w


feature, label= load_features("../data/train.txt")
H=perceptron(feature, label, 30,1)
	

'''
	The perceptron classifier function.

	Args:
	data: train data with shape (1561, 3), which means 1561 samples and 
		  each sample has 3 features.(1, symmetry, average internsity)
	label: train data's label with shape (1561,1). 
		   1 for digit number 1 and -1 for digit number 5.
	max_iter: max iteration numbers
	learning_rate: learning rate for weight update
	
	Returns:
		w: the seperater with shape (1, 3). You must initilize it with w = np.zeros((1,d))
	'''


def show_result(data, label, w):
    x=data[:,1]
    y=data[:,2]
    plt.figure()
    plt.xlabel('Average Intensity', rotation= 'horizontal')
    plt.ylabel('Symmetry', rotation= 'vertical')
    for ii in range(len(x)):
        if label[ii]==1:
            plt.scatter(x[ii], y[ii], c='r', marker='*')
        elif label[ii]==-1:
            plt.scatter(x[ii],y[ii], c='b', marker= '+')
    plt.plot(x,-(w[0]+x*w[1])/w[2], '-') 
    plt.xlim(-1, .25)
    plt.ylim(-1, .25)
    plt.title('Feature Visualization and Separator')
    

featuret, labelt= load_features("../data/train.txt")
W=perceptron(feature, label, 200,1)
show_result(featuret, labelt, W)


'''
	This function is used for plot the test data with the separators and save it.
	
	Args:
	data: test features with shape (424, 2). The shape represents total 424 samples and 
	      each sample has 2 features.
	label: test data's label with shape (424,1). 
		   1 for digit number 1 and -1 for digit number 5.
	
	Returns:
	Do not return any arguments, just save the image you plot for your report.
	'''


#-------------- Implement your code above ------------#
def accuracy_perceptron(data, label, w):
    n, _ = data.shape
    mistakes = 0
    for i in range(n):
        if sign(np.dot(data[i,:],np.transpose(w))) != label[i]:
            mistakes += 1
    return mistakes , (n-mistakes)/n
   


def test_perceptron(max_iter, learning_rate):
	#get data
	traindataloc,testdataloc = "../data/train.txt", "../data/test.txt"
	train_data,train_label = load_features(traindataloc)
	test_data, test_label = load_features(testdataloc)
	#train perceptron
	w = perceptron(train_data, train_label, max_iter, learning_rate)
	train_acc = accuracy_perceptron(train_data, train_label, w)	
	#test perceptron model
	test_acc = accuracy_perceptron(test_data, test_label, w)
	return w, train_acc, test_acc

nAcc ,Acc= accuracy_perceptron(feature, label, H)
nAcct ,Acct= accuracy_perceptron(featuret, labelt, H)